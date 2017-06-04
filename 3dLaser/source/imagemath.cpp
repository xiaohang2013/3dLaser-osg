#include "imagemath.h"

imageMath::imageMath()
{

}

bool imageMath::convertColorMapToGray(osg::Image *image)
{
    if(!image || image->isMipmap()) return false; //暂不处理mipmap
    if(!image->isDataContiguous()) return false; //暂不处理非连续情况（其实此处也可放开它）
    unsigned int channel = image->getPixelSizeInBits()/8;//像素通道数
    if(channel<3 || channel>4) return false;

    int h = image->t();
    int w = image->s();
    int d = image->r();
    int gray = 0;

    for(int imgNum=0; imgNum<d; ++imgNum)//depth扫描
    {
        for(int j=0; j<h; ++j)//行扫描
        {
            for(int i=0; i<w; ++i)//列扫描
            {
                unsigned char *p = getImageData(image, i,j,imgNum);
                //彩图转灰度图心理学公式
                //整数运算提高速度，+500为了四舍五入
                gray = (p[0]*299 + p[1]*587 + p[2]*114 + 500) / 1000;
                char g = (char)gray;
                p[0] = g;
                p[1] = g;
                p[2] = g;
            }
        }
    }

    return true;
}

/// 参见http://blog.csdn.net/maozefa/article/details/7069001
/// Photoshop对于对比度增量调整法
/// 以及最常用的非线性亮度调整（Phoposhop CS3以下版本也是这种亮度调整方式，CS3及以上版本也保留了该亮度调整方式的选项）
bool imageMath::adjustBrightAndContrast(osg::Image *image, int bright, int contrast, unsigned char threshold)
{
    if(!image || image->isMipmap()) return false; //暂不处理mipmap
    if(!image->isDataContiguous()) return false; //暂不处理非连续情况（其实此处也可放开它）
    unsigned int channel = image->getPixelSizeInBits()/8;//像素通道数
    if(channel!=1 && channel!=3 && channel!=4) return false;
    if (bright == 0 && contrast == 0)
        return false;

    float cv = contrast <= -255? -1.0f : contrast / 255.0f;
    if (contrast > 0 && contrast < 255)
        cv = 1.0f / (1.0f - cv) - 1.0f;

    unsigned char values[256];
    for (int i = 0; i < 256; i++)
    {
        int v = contrast > 0? checkValue(i + bright) : i;
        if (contrast >= 255)
            v = v >= threshold? 255 : 0;
        else
            v = checkValue(v + (int)((v - threshold) * cv + 0.5f)); // +0.5f是为了四舍五入
        values[i] = contrast <= 0? checkValue(v + bright) : v;
    }

    int h = image->t();
    int w = image->s();
    int d = image->r();

    if(channel>=3)
    {
        for(int imgNum=0; imgNum<d; ++imgNum)//depth扫描
        {
            for(int j=0; j<h; ++j)//行扫描
            {
                for(int i=0; i<w; ++i)//列扫描
                {
                    unsigned char *p = getImageData(image, i,j,imgNum);

                    p[0] = values[p[0]];
                    p[1] = values[p[1]];
                    p[2] = values[p[2]];
                }
            }
        }
    }
    else if(channel==1)
    {
        for(int imgNum=0; imgNum<d; ++imgNum)//depth扫描
        {
            for(int j=0; j<h; ++j)//行扫描
            {
                for(int i=0; i<w; ++i)//列扫描
                {
                    unsigned char *p = getImageData(image, i,j,imgNum);

                    p[0] = values[p[0]];
                }
            }
        }
    }

    return true;
}

/// 锐化图像
/// image: 待锐化的图像数据，将直接在该数据基础上锐化并保存
/// blurredImg: blur后的图像数据
/// amount: 锐化倍数
/// threshold: 锐化阈值
bool imageMath::sharpenImage(osg::Image *image, osg::Image *blurredImg, float amount, char threshold)
{
    if(!image) return false;
    if(amount<=0) return false;
    if(!blurredImg) return false;
    int width = image->s();
    int height = image->t();
    int channel = image->getPixelSizeInBits()/8;
    int cn = 1;
    cn = channel==1? 1 : (channel==3 || channel==4)? 3:channel;
    if(cn!=1 && cn!=3) return false;

    osg::ref_ptr<osg::Image> imgCopy = new osg::Image(*blurredImg, osg::CopyOp::SHALLOW_COPY);

    for(int j=0; j<height; ++j)//行扫描
    {
        for(int i=0; i<width; ++i)//列扫描
        {
            unsigned char *pCopy = getImageData(imgCopy.get(), i,j,0);
            unsigned char *pSrc = getImageData(image, i,j,0);

            for(int k=0; k<cn; k++)
            {
                int value;
                value = pSrc[k]-pCopy[k];
                if(abs(value)>threshold)
                {
                    value = (int)(pSrc[k] + amount*value);
                    pSrc[k] = (unsigned char)checkValue(value);
                }
            }
        }
    }

    return true;
}

/// 锐化图像
/// image: 待锐化的图像数据，将直接在该数据基础上锐化并保存
/// amount: 锐化倍数
/// radius: 高斯模糊半径
/// sigma: 高斯模糊sigma方差参数
/// threshold: 锐化阈值
bool imageMath::sharpenImage(osg::Image *image, float amount, int radius, float sigma, char threshold)
{
    if(!image) return false;
    if(amount<=0) return false;
    int width = image->s();
    int height = image->t();
    int channel = image->getPixelSizeInBits()/8;
    int cn = 1;
    cn = channel==1? 1 : (channel==3||channel==4)? 3:channel;
    if(cn!=1 && cn!=3) return false;

    osg::ref_ptr<osg::Image> imgCopy = new osg::Image(*image, osg::CopyOp::SHALLOW_COPY);

//    // 网友优化的高斯模糊
//    unsigned char *srcImg = image->data();
//    unsigned char *dstImg = (unsigned char*)malloc(sizeof(unsigned char)*width*height*channel);
//    memcpy(dstImg, srcImg, sizeof(char)*width*height*channel);
//    gaussianBlur(srcImg, dstImg, /*radius, */width, height, sigma, channel);
//    memcpy(/*image*/imgCopy->data(), dstImg, sizeof(char)*width*height*channel);
//    free(dstImg);

    // 原生的高斯模糊
    gaussianBlur(imgCopy.get(), radius, sigma);


    for(int j=0; j<height; ++j)//行扫描
    {
        for(int i=0; i<width; ++i)//列扫描
        {
            unsigned char *pCopy = getImageData(imgCopy.get(), i,j,0);
            unsigned char *pSrc = getImageData(image, i,j,0);

            for(int k=0; k<cn; k++)
            {
                int value;
                value = pSrc[k]-pCopy[k];
                if(abs(value)>threshold)
                {
                    value = (int)(pSrc[k] + amount*value);
                    pSrc[k] = (unsigned char)checkValue(value);
                }
            }
        }
    }

    return true;
}

/// 水平竖直分开的高斯模糊
/// 速度快，效果还可以
/// 通常radius取1，sigma取1
bool imageMath::gaussianBlurRowColSeparate(osg::Image *image, int radius, float sigma)
{
    if(!image || image->isMipmap()) return false; //暂不处理mipmap
    if(!image->isDataContiguous()) return false; //暂不处理非连续情况（其实此处也可放开它）
    if(radius<0 || abs(sigma)<=0) return false;

    int width = image->s();
    int height = image->t();
    int channel = image->getPixelSizeInBits()/8;
    //只能处理 8, 24， 32 channel
    if(channel != 1 && channel != 3 && channel != 4)
        return false;

    int size = radius +1;
    float *kernalData = (float *)malloc(sizeof(float*)*size);
    if(!kernalData)//分配失败
    {
        free(kernalData);
        return false;
    }
    // ‘高斯核’
    float k1 = -0.5f / (sigma*sigma);
    for(int i=0; i<size; i++)
        kernalData[i] = exp(k1*i*i);
    // 模板加权和
    float sum = 0.f;
    for(int i=0; i<size; i++)
        sum += kernalData[i];
    // 归一化
    sum = 1.0f / sum;
    for(int i=0; i<size; i++)
        kernalData[i] *= sum;

    // Blur
    int RowCol, row, col, subRow, subCol, MaxVal, x, x1;
    int *pSubVal, *pRefVal;
    float result[3];
    osg::ref_ptr<osg::Image> imgCopy;
    for(RowCol=0; RowCol<2; RowCol++)
    {
        if(RowCol==0)//水平方向
        {
            pSubVal = &subCol;
            pRefVal = &col;
            MaxVal = width - 1;
        }
        else if(RowCol==1)//竖直方向
        {
            pSubVal = &subRow;
            pRefVal = &row;
            MaxVal = height - 1;
        }

        imgCopy = new osg::Image(*image, osg::CopyOp::SHALLOW_COPY);

        for(row=0; row<height; row++)
        {
            for(col=0; col<width; col++)
            {
                result[0] = 0.f;
                result[1] = 0.f;
                result[2] = 0.f;

                subRow = row;
                subCol = col;

                for(x = -radius; x<radius; x++)
                {
                    x1 = (x >= 0) ? x : (-x);
                    *pSubVal = *pRefVal + x;

                    // 边界处理：Photoshop 采用的是此方法1。
                    // 取边缘像素（图像边缘像素向内部扩散！）
                    if(*pSubVal < 0) *pSubVal = 0;
                    else if(*pSubVal > MaxVal) *pSubVal = MaxVal;

                    const unsigned char *pCopy = getImageData(imgCopy.get(), subCol, subRow, 0);

                    result[0] += pCopy[0] * kernalData[x1];
                    if(channel==3 || channel==4)
                    {
                        result[1] += pCopy[1] * kernalData[x1];
                        result[2] += pCopy[2] * kernalData[x1];
                    }
                }

                unsigned char *pSrc = getImageData(image, col, row, 0);
                pSrc[0] = (unsigned char)result[0];
                if(channel==3 || channel==4)
                {
                    pSrc[1] = (unsigned char)result[1];
                    pSrc[2] = (unsigned char)result[2];
                }
            }
        }
    }

    free(kernalData);
    return true;
}

/// 原生的高斯模糊
/// 速度相对较慢，效果还可以
/// 通常radius取1，sigma取1
bool imageMath::gaussianBlur(osg::Image *image, int radius, float sigma)
{
    if(!image || image->isMipmap()) return false; //暂不处理mipmap
    if(!image->isDataContiguous()) return false; //暂不处理非连续情况（其实此处也可放开它）

    int width = image->s();
    int height = image->t();
    int channel = image->getPixelSizeInBits()/8;
    //只能处理 8, 24， 32 channel
    if(channel != 1 && channel != 3 && channel != 4)
        return false;

    osg::ref_ptr<osg::Image> imgCopy = new osg::Image(*image, osg::CopyOp::SHALLOW_COPY);

    int size = 2*radius +1;
    float sigma22 = 2*sigma*sigma;
    float sigma22PI = (float)M_PI * sigma22;
    float **kernalData;
    float sum=0.f;

    kernalData = (float**)malloc(sizeof(float*)*size);
    for(int i=0; i<size; i++) kernalData[i]=(float*)malloc(sizeof(float)*size);

    //计算高斯核
    int row = 0;
    for(int i=-radius; i<=radius; i++)
    {
        int column = 0;
        for(int j=-radius; j<=radius; j++)
        {
            float xDistance = i*i;
            float yDistance = j*j;
            kernalData[row][column] = (float)exp(-(xDistance + yDistance)/sigma22)/sigma22PI;
            column++;
        }
        row++;
    }
    //二维高斯结果
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            sum +=kernalData[i][j];

    //取加权平均，得权重矩阵
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            kernalData[i][j] = kernalData[i][j]/sum;

    unsigned char r=0, g=0, b=0;
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            float sr=0, sg=0, sb=0;
            // 二维高斯窗口
            for(int i=-radius; i<=radius; i++)
            {
                int roffset = row+i;
                if(roffset<0) //处理边界情况左溢出
                    roffset = row-i<height?row-i:0;
                if(roffset>=height)//处理边界情况右溢出
                    roffset = row-i>=0?row-i:height-1;

                for(int j=-radius; j<=radius; j++)
                {
                    int coffset = col+j;
                    if(coffset<0) //处理边界情况左溢出
                        coffset = col-j<width?col-j:0;
                    if(coffset>=width)//处理边界情况右溢出
                        coffset = col-j>=0?col-j:width-1;


                    unsigned char *pCopy = getImageData(imgCopy.get(), coffset, roffset, 0);
                    sr += (float)pCopy[0]*kernalData[i+radius][j+radius];
                    if(channel>=3)
                    {
                        sg += (float)pCopy[1]*kernalData[i+radius][j+radius];
                        sb += (float)pCopy[2]*kernalData[i+radius][j+radius];
                    }
                }
            }

            unsigned char *pSrc = getImageData(image, col, row, 0);
            r = (unsigned char)(sr+0.5f);//0.5用于四舍五入
            g = (unsigned char)(sg+0.5f);
            b = (unsigned char)(sb+0.5f);
            pSrc[0] = r;
            if(channel>=3)
            {
                pSrc[1] = g;
                pSrc[2] = b;
            }
        }
    }

    //释放内存
    for(int i=0;i<size;i++) free(kernalData[i]);
    free(kernalData);

    return true;
}

/// 原生的高斯模糊
/// 速度相对较慢，效果还可以
/// 通常radius取1，sigma取1
bool imageMath::gaussianBlur(unsigned char *src, unsigned char *&dst, int radius, int width, int height, float sigma, int channel)
{
    if(!src || !dst) return false;
    //只能处理 8, 24， 32 channel
    if(channel != 1 && channel != 3 && channel != 4)
        return false;

    int size = 2*radius +1;
    float sigma22 = 2*sigma*sigma;
    float sigma22PI = (float)M_PI * sigma22;
    float **kernalData;
    float sum=0.f;

    kernalData = (float**)malloc(sizeof(float*)*size);
    for(int i=0; i<size; i++) kernalData[i]=(float*)malloc(sizeof(float)*size);

    //计算高斯核
    int row = 0;
    for(int i=-radius; i<=radius; i++)
    {
        int column = 0;
        for(int j=-radius; j<=radius; j++)
        {
            float xDistance = i*i;
            float yDistance = j*j;
            kernalData[row][column] = (float)exp(-(xDistance + yDistance)/sigma22)/sigma22PI;
            column++;
        }
        row++;
    }
    //二维高斯结果
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            sum +=kernalData[i][j];

    //取加权平均，得权重矩阵
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            kernalData[i][j] = kernalData[i][j]/sum;

    char r=0, g=0, b=0;
    for(int row=0; row<height; row++)
    {
        int offset = row*width*channel;
        for(int col=0; col<width; col++)
        {
            float sr=0, sg=0, sb=0;
            // 二维高斯窗口
            for(int i=-radius; i<=radius; i++)
            {
                int roffset = row+i;
                if(roffset<0) //处理边界情况左溢出
                    roffset = row-i<height?row-i:0;
                if(roffset>=height)//处理边界情况右溢出
                    roffset = row-i>=0?row-i:height-1;

                int pixoffsetInRow = roffset*width*channel;
                for(int j=-radius; j<=radius; j++)
                {
                    int coffset = col+j;
                    if(coffset<0) //处理边界情况左溢出
                        coffset = col-j<width?col-j:0;
                    if(coffset>=width)//处理边界情况右溢出
                        coffset = col-j>=0?col-j:width-1;

                    int pixoffset = pixoffsetInRow + coffset*channel;
                    sr += (float)src[pixoffset]*kernalData[i+radius][j+radius];
                    if(channel>=3)
                    {
                        sg += (float)src[pixoffset+1]*kernalData[i+radius][j+radius];
                        sb += (float)src[pixoffset+2]*kernalData[i+radius][j+radius];
                    }
                }
            }
            r = (int)(sr+0.5f);//0.5用于四舍五入
            g = (int)(sg+0.5f);
            b = (int)(sb+0.5f);
            dst[offset+col*channel] = r;
            if(channel>=3)
            {
                dst[offset+col*channel+1] = g;
                dst[offset+col*channel+2] = b;
            }
        }
    }

    //释放内存
    for(int i=0;i<size;i++) free(kernalData[i]);
    free(kernalData);
    return true;
}

///
/// 网友优化后的高斯模糊，验证可行
bool imageMath::gaussianBlur(unsigned char *src, unsigned char *&dst, int width, int height, float sigma, int chan)
{
    if(!src || !dst) return false;
    //只能处理 8, 24， 32 channel
    if(chan != 1 && chan != 3 && chan != 4)
        return false;

    int    i            = 0;
    int    row            = 0;
    int    col            = 0;
    int    pos            = 0;
    int    channel        = 0;
    int    n            = 0;
    int    bufsize        = 0;
    int size        = 0;
    int rowstride    = 0;
    int itemp0        = 0;
    int itemp1        = 0;
    float temp      = 0;
    int    channelsize = width*height;

    if (width>height)
    {
        bufsize = width;
    }
    else
    {
        bufsize = height;
    }

    float* w1    = (float *) malloc (bufsize * sizeof (float));
    float *w2    = (float *) malloc (bufsize * sizeof (float));
    float *in    = (float *) malloc (channelsize * sizeof (float));
    float *out    = (float *) malloc (channelsize * sizeof (float));

    //----------------计算高斯核---------------------------------------//
    float  q    = 0;
    float  q2, q3;
    double b0;
    double b1;
    double b2;
    double b3;
    double B    = 0;

    if (sigma >= 2.5)
    {
        q = 0.98711 * sigma - 0.96330;
    }
    else if ((sigma >= 0.5) && (sigma < 2.5))
    {
        q = 3.97156 - 4.14554 * (float) sqrt ((double) 1 - 0.26891 * sigma);
    }
    else
    {
        q = 0.1147705018520355224609375;
    }

    q2 = q * q;
    q3 = q * q2;
    b0 = (1.57825+(2.44413*q)+(1.4281 *q2)+(0.422205*q3));
    b1 = (        (2.44413*q)+(2.85619*q2)+(1.26661 *q3));
    b2 = (                   -((1.4281*q2)+(1.26661 *q3)));
    b3 = (                                 (0.422205*q3));
    B = 1.0-((b1+b2+b3)/b0);

    //加速方法 减少循环多次/b0
    b1 /= b0;
    b2 /= b0;
    b3 /= b0;
    //----------------计算高斯核结束---------------------------------------//

    // 处理图像的多个通道
    for (channel = 0; channel < chan; channel++)
    {
        // 获取一个通道的所有像素值
        for (i = 0, pos = channel; i < channelsize ; i++, pos += chan)
        {
            /* 0-255 => 1-256 */
            in[i] = (float)(src[pos] + 1.0);
        }

        //纵向处理
        for (row=0 ;row < height; row++)
        {
            pos =  row * width;
            size        = width;
            rowstride    = 1;
            bufsize        = size;
            size        -= 1;

            temp =  (in + pos)[0];
            w1[0] = temp;  // ！！！计算需要相同初值（否则噪声），但是赋值的时候不能用相同的（否则像素重复或缺失）！！！
            w1[1] =temp;
            w1[2] =temp;



            for (  n=3; n <= size ; n++)
            {
                w1[n] = (float)(B*(in + pos)[n*rowstride] +    ((b1*w1[n-1] +     b2*w1[n-2] + b3*w1[n-3] )));

            }
            w1[0] =  (in + pos)[0];  // 左边产生噪声（使用不同初始值时产生），右边有3像素黑色不变（out最后3个像素未设定）
            w1[1] =(in + pos)[1];
            w1[2] =  (in + pos)[2];

            (out + pos)[size]= w2[size]= (float)w1[size]; // 效果比较好
            (out + pos)[size-1]=w2[size-1]=(float)(1.0*w1[size-1]) ;
            (out + pos)[size-2]=w2[size-2]= (float)((1.0)*w1[size-2]);
            w2[size]= (float)w1[size-2];
            w2[size-1]= (float)w1[size-2];
            w2[size-2]= (float)w1[size-2];

            for (n = size-3; n>= 0; n--) // 不该是size-1?
            {
                (out + pos)[n * rowstride] = w2[n] = (float)(B*w1[n] +    ((b1*w2[n+1] +    b2*w2[n+2] + b3*w2[n+3] ))); // 得到一行的输出

            }
        }


        //横向处理
        for (col=0; col < width; col++)  // wbp 在纵向处理的基础上继续横向处理
        {
            size        = height;
            rowstride    = width;
            bufsize        = size;
            size        -= 1;

            temp  = (out + col)[0*rowstride];  // wbp 第col列的第一个数据，复制3份，开始前向滤波
            w1[0] = temp;
            w1[1] = temp;
            w1[2] = temp;
            for ( n=3; n <= size ; n++)
            {
                w1[n] = (float)(B*(out + col)[n*rowstride] + ((b1*w1[n-1] +    b2*w1[n-2] + b3*w1[n-3] )));

            }
            w1[0] =  (out + col)[0];
            w1[1] =  (out + col)[rowstride];
            w1[2] =  (out + col)[2*rowstride];


            temp        = w1[size];
            w2[size]    = temp;
            w2[size-1]    = temp;
            w2[size-2]    = temp;
            (in + col)[size * rowstride]=w1[size];
            (in + col)[(size-1) * rowstride]=w1[size-1];
            (in + col)[(size-2) * rowstride]=w1[size-2];

            for (n = size-3; n >= 0; n--)
            {
                (in + col)[n * rowstride] =w2[n]= (float)(B*w1[n] +    ((b1*w2[n+1] +     b2*w2[n+2] + b3*w2[n+3] )));

            }
        }

        //修正偏移的拷贝方法, 但是修正后图像右边及下边会丢失数据？？？// wbp 并且图像左边及上边多出数据
        for(int y=0; y<height; y++)
        {
            itemp0 = y*width*chan;
            itemp1 = (y)*width;                                // +3  数据没丢失，但是是拷贝而不是原数据
            for (int x=0; x<width; x++)
            {
                dst[itemp0+x*chan + channel]=in[itemp1+x]-1;    // +3
            }
        }
    }

    free (w1);
    free (w2);
    free (in);
    free (out);

    return true;
}

/// 将图片层的图片生成点云-随机数方法
/// 只能用于以长方形为载体的图片，且该长方形的点序为左上-左下-右下-右上
/// 该长方形法向与Z轴平行，且关于X，Y轴中心对称
osg::Vec3Array *imageMath::buildPictureLayerToPointCloud(const osg::Image *image, osg::Vec3Array *vertexArray, osg::Vec2Array *texCoordArray, pictureParameter prm)
{
    if(!image || !vertexArray || !texCoordArray) return NULL;
    // 以长方形绘制体为载体显示的图片
    if(vertexArray->size()!=4 || texCoordArray->size()!=4) return NULL;

    osg::ref_ptr<osg::Vec3Array> points=new osg::Vec3Array;
    pictureParameter::LayerAddingType aType = prm.layerAddingType;
    float pDis = prm.pointDis;
    int laynum = prm.layerNum;
    float lDis = prm.layerDis;
    float lAtt = prm.layerAttenuation;

    osg::Vec3 vt_a(vertexArray->at(0));
    osg::Vec3 vt_b(vertexArray->at(1));
    osg::Vec3 vt_c(vertexArray->at(2));
    osg::Vec3 vt_d(vertexArray->at(3));
    osg::Vec2 tc_a(texCoordArray->at(0));
    osg::Vec2 tc_b(texCoordArray->at(1));
    osg::Vec2 tc_c(texCoordArray->at(2));
    osg::Vec2 tc_d(texCoordArray->at(3));

    if(laynum<=0 || lAtt<0 || lAtt>1) return NULL;
    if(abs(vt_a.z())+abs(vt_b.z())+abs(vt_c.z())+abs(vt_d.z())>1e-5)//四点的z=0
        return NULL;

    osg::ref_ptr<osg::Image> imgGary = new osg::Image(*image, osg::CopyOp::SHALLOW_COPY);
    convertColorMapToGray(imgGary.get());
    int channel = imgGary->getPixelSizeInBits()/8;
    int iwidth = imgGary->s();//图像像素宽高
    int iheight = imgGary->t();

    float layerZstart = -(float)(laynum-1)*lDis/2.0f;
    float layerZend = -layerZstart;//对称
    osg::Vec3 vertical = vt_b - vt_a;
    osg::Vec3 horizantal = vt_d - vt_a;
    float w = horizantal.length();//图像几何尺寸宽高
    float h = vertical.length();
    float xstart = ceil(vt_a.x()/pDis)*pDis;
    float ystart = ceil(vt_b.y()/pDis)*pDis;

    float t;
    osg::Vec2 UV1, UV2, UV;
    unsigned int U,V;
    float percent = 1-lAtt;
    int level = 255;//生成点云时，灰度的分辨等级
    init_Random(3333);

    for(float x=xstart; x<=vt_d.x(); x+=pDis)
    {
        for(float y=ystart; y<=vt_a.y(); y+=pDis)
        {
            t = abs(x-vt_a.x())/w;
            UV1 = tc_a*(1-t) + tc_d*t;
            UV2 = tc_b*(1-t) + tc_c*t;
            t = abs(y-vt_b.y())/h;
            UV = UV2*(1-t) + UV1*t;
            U = (unsigned int)(UV.x()*(iwidth-1));
            V = (unsigned int)(UV.y()*(iheight-1));

            unsigned char *pImg = getImageData(imgGary.get(), U, V, 0);
            unsigned char gray = pImg[0];
            if((channel==4 && pImg[3]==0)||gray==0)
                continue;

            //由前述条件，gray一定大于0；因此,...
            for(int i=0; i<laynum; i++)
            {
                float prob = normalizedRand();//0~1.0
                float graylevel = (float)gray/level;

                if(graylevel>prob)
                {
                    if(aType == pictureParameter::CONCAVE)
                        points->push_back(osg::Vec3(x, y, layerZend - i*lDis));
                    else
                        points->push_back(osg::Vec3(x, y, layerZstart + i*lDis));
                }

                gray *= percent;
            }
        }
    }

//    for(int i=0; i<laynum; i++)
//    {
//        for(int j=0; j<level; j++)
//        {
//            for(float x=xstart; x<=vt_d.x(); x+=(j/10+1)*pDis)
//            {
//                for(float y=ystart; y<=vt_a.y(); y+=(j/10+1)*pDis)
//                {
//                    t = abs(x-vt_a.x())/w;
//                    UV1 = tc_a*(1-t) + tc_d*t;
//                    UV2 = tc_b*(1-t) + tc_c*t;
//                    t = abs(y-vt_b.y())/h;
//                    UV = UV2*(1-t) + UV1*t;
//                    U = (unsigned int)(UV.x()*(iwidth-1));
//                    V = (unsigned int)(UV.y()*(iheight-1));

//                    unsigned char *pImg = getImageData(imgGary.get(), U, V, 0);
//                    unsigned char gray = pImg[0];
//                    if((channel==4 && pImg[3]==0)||gray==0)
//                        continue;

//                    gray *= pow(percent, i);
//                    if(gray<=0) continue;
//                    //                    if(gray<112) continue;
//                    if(gray>255-(j+1)*255/(float)level && gray<=255-j*255/(float)level)
//                    {
//                        if(aType == pictureParameter::CONCAVE)
//                            points->push_back(osg::Vec3(x, y, layerZend - i*lDis));
//                        else
//                            points->push_back(osg::Vec3(x, y, layerZstart + i*lDis));
//                    }

//                }
//            }
//        }
//    }




    return points.release();
}



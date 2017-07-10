#ifndef PCGMATH_H
#define PCGMATH_H

#include <stdlib.h>

#include <QProgressDialog>

class pcgMath
{
public:
    /** Axis XYZ enum map*/
    enum Axis
    {
        /** Axis X.*/
        AXISX = 0,
        /** Axis Y.*/
        AXISY = 1,
        /** Axis Z.*/
        AXISZ = 2
    };

public:
    pcgMath();


public:
    static void init_Random(unsigned int seed = 3333){srand(seed);}
    static inline float normalizedRand(){return (float)(rand()/double(RAND_MAX));}

protected:
    // 开辟2维unsigned char 数组，第一维数numRow，第二维度numColumn
    // 开辟了空间，不用时应及时释放；因此，与下面方法一起配合使用
    void malloc2D_ucArray(unsigned char **&p, int numRow, int numColumn);

    // 释放2维unsigned char数组
    void free2D_ucArray(unsigned char **&p, int numRow);

    // 更新外部的进度窗
    static inline void updateProgressDialog(QProgressDialog *progressDlg, int i)
    {
        i = i<=progressDlg->maximum()? i:progressDlg->maximum();
        progressDlg->setValue(i);
    }
};

#endif // PCGMATH_H

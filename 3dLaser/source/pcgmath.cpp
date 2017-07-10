#include "pcgmath.h"

#include <cstring>

pcgMath::pcgMath()
{

}

void pcgMath::malloc2D_ucArray(unsigned char **&p, int numRow, int numColumn)
{
    p = (unsigned char**)malloc(sizeof(unsigned char*)*numRow);
    for(int i=0; i<numRow; i++)
    {
        p[i]=(unsigned char*)malloc(sizeof(unsigned char)*numColumn);
        memset(p[i], (unsigned char)0, sizeof(unsigned char)*numColumn);
    }
    //注意：如此申请的二维数组，行与行之间地址不连续，同行的列地址连续
}

void pcgMath::free2D_ucArray(unsigned char **&p, int numRow)
{
    for(int i=0;i<numRow;i++) free(p[i]);
    free(p);
}


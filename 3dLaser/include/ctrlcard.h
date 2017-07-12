#ifndef CTRLCARD_H
#define CTRLCARD_H
#include "osg/Referenced"

#define FIFONUM 2048
#define TIMEVAL 8
#define MAXAXIS  3    //最大轴数
#define SUDDEN_STOP 0
#define DEC_STOP 1
#define AXIS_X 1
#define AXIS_Y 2
#define AXIS_Z 3
#define CARD_0 0
#define ADTDRV_OK 0
#define ADTDRV_FAIL 1
#define INPUT_L 0
#define INPUT_H 1
#define INPUT_ERR -1
#define OUTPUT_L 0
#define OUTPUT_H 1
#define LASER_ON 1
#define LASER_OFF 0
#define LIMIT_ON  1
#define LIMIT_OFF 0
#define X_LIMIT_P 17
#define X_LIMIT_N 4
#define Y_LIMIT_P 3
#define Y_LIMIT_N 2
#define Z_LIMIT_P 0
#define Z_LIMIT_N 1

class CtrlCard: public osg::Referenced
{
public:
    CtrlCard();
    ~CtrlCard();
    void setPwm(long freq,float value);
    void setDA(int index,int value);
    int Get_Status(int axis, int &value, int mode);
    int stopRun(int axis,int mode);
    int Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed);
    int Interp_Move3(long value1,long value2,long value3);
    int Interp_Move2(int axis1,int axis2,long value1,long value2);
    int Axis_Pmove(int axis, long value);
    int setSpeed(int axis,long startv,long speed,long add);
    int initBoard();
    void clearCount();
    int writeOutput(int number, int value);
    int readInput(int number);
    int getHardWareVer();
    int setLimit(int cardNo,int axis,int lmtP,int lmtN,int logic);
    int setLaser(int cardNo, int status, int freq, int ratio);
    int setLaserOutDelay(int cardNo, int delay);
private:
    int Result;
    int g_HardwareVer;
};



#endif // CTRLCARD_H

#ifndef CTRLCARD_H
#define CTRLCARD_H
#include "osg/Referenced"
#define  MAXAXIS  3    //最大轴数
#ifndef SUDDEN_STOP
#define SUDDEN_STOP 0
#endif
#ifndef DEC_STOP
#define DEC_STOP 1
#endif
#ifndef AXIS_X
#define AXIS_X 0
#endif
#ifndef AXIS_Y
#define AXIS_Y 1
#endif
#ifndef AXIS_Z
#define AXIS_Z 2
#endif
#ifndef CARD_0
#define CARD_0 0
#endif
#ifndef DRV_OK
#define DRV_OK 0
#endif
#ifndef DRV_FAIL
#define DRV_FAIL 1
#endif
#ifndef IO_L
#define IO_L 0
#endif
#ifndef IO_H
#define IO_H 1
#endif
#ifndef LASER_ON
#define LASER_ON 1
#endif
#ifndef LASER_OFF
#define LASER_OFF 0
#endif
#ifndef LIMIT_ON
#define LIMIT_ON  1
#endif
#ifndef LIMIT_OFF
#define LIMIT_OFF 0
#endif
#ifndef INMAX
#define INMAX 22
#endif
#ifndef OOTMAX
#define OUTMAX 9
#endif
class CtrlCard: public osg::Referenced
{
public:
    CtrlCard();
    ~CtrlCard();
    void Set_Pwm(long freq,float value);
    void Set_DA(int ch,int value);
    int Get_Status(int axis, int &value, int mode);
    int StopRun(int axis,int mode);
    int Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed);
    int Interp_Move3(long value1,long value2,long value3);
    int Interp_Move2(int axis1,int axis2,long value1,long value2);
    int Axis_Pmove(int axis, long value);
    int Setup_Speed(int axis,long startv,long speed,long add);
    int Init_Board();
    void Clear_Count();
    int Write_Output(int number, int value);
    int Read_Input(int number);
    int Get_HardWareVer();
    int set_limit(int cardno,int axis,int lmtP,int lmtN,int logic);
    int Set_Laser(int cardno, int val);
    int get_IO_Status();
    const int get_InNum();
    const int get_outNum();
private:
    const int inNum = 22;
    const int outNum = 9;
    int Result;
    int g_HardwareVer;
//    int IO[];
};



#endif // CTRLCARD_H

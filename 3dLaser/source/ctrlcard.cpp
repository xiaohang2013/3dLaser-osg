#include "adt8933.h"
#include "ctrlcard.h"

#define FIFONUM 2048
#define TIMEVAL 8

CtrlCard::CtrlCard()
{
    g_HardwareVer = 0;
}
CtrlCard::~CtrlCard()
{
}
/*******************初始化函数************************

    该函数中包含了控制卡初始化常用的库函数，这是调用

    其他函数的基础，所以必须在示例程序中最先调用

    返回值<=0表示初始化失败，返回值>0表示初始化成功

*****************************************************/
int CtrlCard::initBoard()
{
    Result = adt8933_initial() ;         //卡初始化函数
    if (Result <= 0) return Result;
    g_HardwareVer = get_hardware_version(0); //获取卡的硬件版本

    if(g_HardwareVer >= 0x3311)
    {
        //加缓存功能的卡
        g_HardwareVer = 2;
    }
    else
    {
        //未加缓存功能的卡
        g_HardwareVer = 1;
    }

    for (int i = 1; i<=MAXAXIS; i++)
    {
       setLimit (0, i, 0, 0, 1);   //设定限位模式
       set_command_pos (0, i, 0);        //清逻辑计数器
       //set_pulse_mode(0, i, 1, 0, 0);  //默认脉冲+方向 正逻辑脉冲 方向输出信号正逻辑
      // set_startv (0, i, 100);          //设定起始速度
      // set_speed (0, i, 2000);           //设定驱动速度
    }
    set_actual_pos (0, 1, 0);         //清实位计数器
    set_actual_pos (0, 2, 0);         //清实位计数器
    fifo_set_laser_control(0,0);      //关闭激光

    return 1;
}

int CtrlCard::getHardWareVer()
{
    return g_HardwareVer;
}

/**********************设置速度模块***********************

    依据参数的值，判断是匀速还是加减速

    返回值=0正确，返回值=1错误

*********************************************************/
int CtrlCard::setSpeed(int axis, long startv, long speed, long add)
{
    if (startv - speed >= 0)
    {
        Result = set_startv(0, axis, startv);
        set_speed (0, axis, startv);
    }
    else
    {
        Result = set_startv(0, axis, startv);
        set_speed (0, axis, speed);
        set_acc (0, axis, add/125);
    }

    return Result;
}

/*********************单轴驱动函数**********************

    该函数用于驱动单个运动轴运动

    返回值=0正确，返回值=1错误

*******************************************************/
int CtrlCard::Axis_Pmove(int axis, long value)
{
    Result = pmove(0, axis, value);

    return Result;
}

/*******************任意两轴插补函数********************

    该函数用于驱动任意两轴进行插补运动

    返回值=0正确，返回值=1错误

*******************************************************/
int CtrlCard::Interp_Move2(int axis1, int axis2, long value1, long value2)
{
    Result = inp_move2(0, axis1, axis2, value1, value2);

    return Result;
}

/*******************任意三轴插补函数***********************

    该函数用于驱动任意三轴进行插补运动

    返回值=0正确，返回值=1错误

**********************************************************/
int CtrlCard::Interp_Move3( long value1, long value2, long value3)
{
    Result = inp_move3(0,  value1, value2, value3);

    return Result;
}

/*****************获取运动信息******************************

    该函数用于反馈轴当前的逻辑位置，实际位置和运行速度

    返回值=0正确，返回值=1错误

************************************************************/
int CtrlCard::Get_CurrentInf(int axis, long &LogPos, long &ActPos, long &Speed)
{

    get_command_pos(0, axis, &LogPos);

    if (axis==1 || axis==2)
        get_actual_pos (0, axis, &ActPos);
    else
        ActPos=0;

    get_speed (0, axis, &Speed);

    return 0;
}

/*****************停止轴驱动******************************

    该函数用于立即或减速停止轴的驱动

    返回值=0正确，返回值=1错误

************************************************************/
int CtrlCard::stopRun(int axis, int mode)
{
    if (SUDDEN_STOP == mode)
        Result = sudden_stop(CARD_0, axis);
    else if (DEC_STOP == mode)
        Result = dec_stop(0, axis);
    else
        Result = sudden_stop(CARD_0, axis);

    if(g_HardwareVer == 2)
        reset_fifo(CARD_0);

    return Result;
}

/*****************获取轴的驱动状态**************************

    该函数用于获取单轴的驱动状态或插补驱动状态

    返回值=0正确，返回值=1错误

************************************************************/
int CtrlCard::Get_Status(int axis, int &value, int mode)
{
    if (mode==0)
        Result=get_status(0,axis,&value);
    else
        Result=get_inp_status(0,&value);

    return Result;
}

/*******************清空计数器函数*******************************

    清空三轴的逻辑计数器

    清空一路实位计数器

****************************************************************/

void CtrlCard::clearCount()
{

    for (int i = 1; i<4; i++)

        set_command_pos (0, i, 0);

    set_actual_pos (0, 1, 0);

    set_actual_pos (0, 2, 0);
}


/*******************DA输出函数*******************************

    ch(1-3)

    value(-32768--32767)

****************************************************************/
void CtrlCard::setDA(int index, int value)
{
    if(g_HardwareVer == 2)
    {
        int nNum;
        read_fifo(0,&nNum);
        while(nNum >= FIFONUM)
        {
            read_fifo(0,&nNum);
        }
        fifo_set_daout(0,index,value);
    }
    else
    {
        set_daout(0,index,value);
    }
}
/*******************PWM输出函数*******************************

    freq(250-100000)

    value(0--1)

****************************************************************/
void CtrlCard::setPwm(long freq, float value)
{
    fifo_set_laser_control(0,1);
    if(g_HardwareVer == 2)
    {
        int nNum;
        read_fifo(0,&nNum);
        while(nNum >= FIFONUM - 1)
        {
            read_fifo(0,&nNum);
        }
        fifo_set_pwm_freq1(0,(int)1.0/freq*1000000*TIMEVAL);
        fifo_set_pwm_freq2(0,(int)(1.0/freq*1000000*value*TIMEVAL));
    }
    else
    {
        set_pwm(0,freq,value);
    }
}

int CtrlCard::writeOutput(int number, int value)
{
    Result = write_bit(0, number, value);

    return Result;

}

int CtrlCard::readInput(int number)
{
    Result = read_bit(0, number);

    return Result;
}

int CtrlCard::setLimit(int cardNo, int axis, int lmtP, int lmtN, int logic)
{
    int rtn = ADTDRV_OK;
    rtn = set_limit_mode(cardNo, axis, lmtP, lmtN, logic);
    return rtn;
}

int CtrlCard::setLaser(int cardNo, int status, int freq, int ratio)
{
    int rtn = ADTDRV_OK;
    rtn = fifo_set_laser_control(cardNo, status);
    if(g_HardwareVer == 2)
    {
        int nNum;
        read_fifo(0,&nNum);
        while(nNum >= FIFONUM - 1)
        {
            read_fifo(0,&nNum);
        }
        fifo_set_pwm_freq1(0,(int)1.0/freq*1000000*TIMEVAL);
        fifo_set_pwm_freq2(0,(int)(1.0/freq*1000000*ratio*TIMEVAL));
    }
    else
    {
        set_pwm(0,freq,ratio);
    }
    return rtn;
}

int CtrlCard::setLaserOutDelay(int cardNo, int delay)
{
    return fifo_set_delay_time1(cardNo, delay*TIMEVAL);
}

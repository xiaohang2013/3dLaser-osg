int _stdcall adt8933_initial(void);
int _stdcall set_pulse_mode(int cardno,int axis,int value,int logic,int dir_logic);
int _stdcall set_limit_mode(int cardno,int axis,int v1,int v2,int logic);
int _stdcall set_stop0_mode(int cardno,int axis,int v,int logic);
int _stdcall set_stop1_mode(int cardno,int axis,int v,int logic);
int _stdcall get_status(int cardno,int axis,int *v);
int _stdcall get_inp_status(int cardno,int *v);

int _stdcall set_acc(int cardno, int axis,long add);
int _stdcall set_startv(int cardno, int axis,long speed);
int _stdcall set_speed(int cardno, int axis,long speed);
int _stdcall set_command_pos(int cardno, int axis,long pos);
int _stdcall set_actual_pos(int cardno, int axis,long pos);
int _stdcall get_command_pos(int cardno,int axis,long *pos);
int _stdcall get_actual_pos(int cardno,int axis,long *pos);
int _stdcall get_speed(int cardno,int axis,long *speed);
int _stdcall pmove(int cardno,int axis,long pos);
int _stdcall dec_stop(int cardno,int axis);
int _stdcall sudden_stop(int cardno,int axis);
int _stdcall inp_move2(int cardno,int axis1,int axis2,long pulse1,long pulse2);
int _stdcall inp_move3(int cardno,long pulse1,long pulse2,long pulse3);

int _stdcall read_bit(int cardno,int number);
int _stdcall write_bit(int cardno,int number,int value);

int _stdcall set_daout(int cardno,int ch,int value);//ch 1-3
int _stdcall set_pwm(int cardno,long freq,float value); 
int _stdcall set_delay_time(int cardno,int value);//延时时间 单位为 1/16uS
int _stdcall get_delay_status(int cardno,int *v);//
int _stdcall get_lib_version();

//-----------------------------------------------------------//
//               硬件缓存类函数 2008.9.10                    //
//-----------------------------------------------------------//

int _stdcall get_hardware_version(int cardno);
/******************************获取硬件版本号******************************
cardno	卡号
	返回值	 硬件版本号（0x33XX）
******************************************************************/

int _stdcall read_fifo(int cardno,int *value);
/******************************获取缓存指令数******************************
	cardno	卡号
value     当前缓存指令数指针
	返回值	 0：正确   1：错误
************************************************************************/

int _stdcall reset_fifo(int cardno);
/******************************重置缓存******************************
	cardno	卡号
	返回值	 0：正确   1：错误
******************************************************************/

int _stdcall get_fifo_status(int cardno,int *status);
/******************************获取缓存状态******************************
cardno	卡号
value     当前缓存指令数指针
	返回值	 0：正确   1：错误
******************************************************************/

int _stdcall fifo_set_pwm_freq1(int cardno,int value);
/******************************缓存PWM频率输出*****************************
cardno	卡号
	value     PWM输出周期时间（时间单位为1/8us）
频率 = 1(s) / 周期时间
******************************************************************/

int _stdcall fifo_set_pwm_freq2(int cardno,int value);
/******************************缓存PWM占空比输出*****************************
cardno	卡号
	value     PWM输出有效电平时间（时间单位为1/8us）
  占空比 = 有效电平时间 / 周期时间
******************************************************************/

int _stdcall fifo_set_delay_time1(int cardno,int value);
/******************************缓存硬件延时*****************************
cardno	卡号
	value     硬件延时时间（时间单位为1/8us）
  注：每连续调用一次fifo_set_daout对端口1和端口2输出后将延时此函数设置的延时时间
******************************************************************/

int _stdcall fifo_set_delay_time2(int cardno,int value);
/******************************缓存硬件延时*****************************
cardno	卡号
	value     硬件延时时间（时间单位为1/8us）
  注：每连续调用一次fifo_set_daout对端口1和端口2输出后将延时此函数设置的延时时间
******************************************************************/

int _stdcall fifo_set_daout(int cardno,int ch,int value);
/******************************缓存DA输出*****************************
cardno	卡号
	ch        端口号(1,4)
	value     DA输出值(-32768,32767)
注：value为-32768输出为-5V，value为0输出为0V，value为32767输出为5V，其余依次类推。
******************************************************************/

int _stdcall fifo_set_delay_time3(int cardno,int value);

int _stdcall fifo_set_delay_time4(int cardno,int value);

int _stdcall fifo_set_laser_control(int cardno,int value);
/******************************缓存激光开光*****************************
cardno	卡号
value 	1  ：开     0 ：关
******************************************************************/
int _stdcall fifo_set_pwm_freq3(int cardno,int value);
int _stdcall fifo_set_pwm_freq4(int cardno,int value);
int _stdcall fifo_set_pwm_freq5(int cardno,int value);
int _stdcall fifo_set_pwm_freq6(int cardno,int value);
int _stdcall fifo_set_pwm_trans(int cardno,int value);


#pragma once

#include "H28_C_SERVO.h"

inline
C_SERVO :: 
C_SERVO (T_DATA_8 _arg_num)
{
	_mem_servo_data._bit._num = _arg_num;
	_mem_servo_data._bit._angle = 0;
}

inline void 
C_SERVO :: 
Set (T_DATA_8 _arg_angle)
{
	_mem_servo_data._bit._angle = _arg_angle;
}

inline T_DATA_8 
C_SERVO :: 
Ret ()
{
	return _mem_servo_data._byte;
}

inline T_DATA_8 
C_SERVO :: 
Ret_angle ()
{
	return _mem_servo_data._bit._angle;
}

inline T_DATA_8 
C_SERVO :: 
Ret_num ()
{
	return _mem_servo_data._bit._num;
}

inline void 
C_SERVO :: 
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_off();
	
	_arg_uart_t.Out(_mem_servo_data._byte);
}

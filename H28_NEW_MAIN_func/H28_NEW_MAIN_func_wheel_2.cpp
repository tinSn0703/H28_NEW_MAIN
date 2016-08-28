
#pragma once

#include "H28_NEW_MAIN_func_wheel_2.h"

inline void
F_Set_wheel_2
(
	C_MD_MAIN _arg_motor[2],
	E_DIRECY _arg_direc_move,
	T_PWM _arg_pwm
)
{
	_arg_motor[0].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
	_arg_motor[1].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
}

inline void
F_Set_wheel_turn_2
(
	C_MD_MAIN _arg_motor[2],
	BOOL _arg_turn_0,
	BOOL _arg_turn_1,
	T_PWM _arg_pwm,
	BOOL _arg_sig_base = TRUE,
	BOOL _arg_nf_turn = FALSE
)
{
	E_SIG _sig = SET_SIG(_arg_sig_base);
	
	BOOL _turn_0 = FALSE;
	BOOL _turn_1 = FALSE;
	
	switch (_arg_nf_turn)
	{
		case TRUE:
			_turn_0 = _arg_turn_1;
			_turn_1 = _arg_turn_0;
		break;
		case FALSE:
			_turn_0 = _arg_turn_0;
			_turn_1 = _arg_turn_1;
		break;
	}
	
	if (_turn_0)
	{
		_arg_motor[0].Set_data(  _sig,_arg_pwm);
		_arg_motor[1].Set_data(ES_STOP,_arg_pwm);
	}
	
	if (_turn_1)
	{
		_arg_motor[0].Set_data(ES_STOP,_arg_pwm);
		_arg_motor[1].Set_data(   _sig,_arg_pwm);
	}
}

inline void
F_Set_wheel_turn_2
(
	C_MD_MAIN _arg_motor[2],
	E_DIRECX _arg_direc_x,
	T_PWM _arg_pwm,
	BOOL _arg_turn_sig_base = TRUE
)
{
	E_SIG _sig = SET_SIG(_arg_turn_sig_base);
	
	switch (_arg_direc_x)
	{
		case ED_EAST:
		{
			_arg_motor[0].Set_data(  _sig,_arg_pwm);
			_arg_motor[1].Set_data(ES_STOP,_arg_pwm);
		}
		break;
		case ED_WEST:
		{
			_arg_motor[0].Set_data(ES_STOP,_arg_pwm);
			_arg_motor[1].Set_data(   _sig,_arg_pwm);
		}
		break;
		case ED_XZERO:
		break;
	}
}

inline void
F_Set_wheel_p_turn_2
(
	C_MD_MAIN _arg_motor[2],
	BOOL _arg_turn_0,
	BOOL _arg_turn_1,
	T_PWM _arg_pwm,
	BOOL _arg_nf_turn = FALSE
)
{
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	BOOL _turn_0 = FALSE;
	BOOL _turn_1 = FALSE;
	
	switch (_arg_nf_turn)
	{
		case TRUE:
			_turn_0 = _arg_turn_1;
			_turn_1 = _arg_turn_0;
		break;
		case FALSE:
			_turn_0 = _arg_turn_0;
			_turn_1 = _arg_turn_1;
		break;
	}
	
	if (_turn_0)
	{
		_sig_0 = ES_TRUE;
		_sig_1 = ES_FALSE;
	}
	
	if (_turn_1)
	{
		_sig_0 = ES_FALSE;
		_sig_1 = ES_TRUE;
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_1,_arg_pwm);
}

inline void
F_Set_wheel_p_turn_2
(
	C_MD_MAIN _arg_motor[2],
	E_DIRECX _arg_direc_x,
	T_PWM _arg_pwm
)
{
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	switch (_arg_direc_x)
	{
		case ED_EAST:
		{
			_sig_0 = ES_TRUE;
			_sig_1 = ES_FALSE;
		}
		break;
		case ED_WEST:
		{
			_sig_0 = ES_FALSE;
			_sig_1 = ES_TRUE;
		}
		break;
		case ED_XZERO:
		break;
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_1,_arg_pwm);
}

#pragma once

#include "H28_NEW_MAIN_func_E_SIG.h"

inline E_SIG 
SET_SIG (BOOL _arg_set_tf)
{
	return (E_SIG)(0b01 << _arg_set_tf);
}

inline E_SIG 
SET_SIG (E_DIRECY _arg_set_direc_y)
{
	return (E_SIG)TURN_DIREC_Y(_arg_set_direc_y);
}

inline E_SIG 
SET_SIG (E_DIRECX _arg_set_direc_x)
{
	return (E_SIG)TURN_DIREC_X(_arg_set_direc_x);
}

inline E_SIG 
SET_SIG
(
	BOOL _arg_set_tf_1, 
	BOOL _arg_set_tf_0
)
{
	return (E_SIG)((_arg_set_tf_1 << 1) | (_arg_set_tf_0 << 0));
}

inline E_SIG 
SET_SIG
(
	E_DIRECY _arg_set_direc_y, 
	E_DIRECX _arg_set_direc_x
)
{
	return (E_SIG)((usint)_arg_set_direc_y & (usint)_arg_set_direc_x);
}

inline E_SIG 
TURN_SIG_ROTATE (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b11011000 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline E_SIG 
TURN_SIG_FIX (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b00100111 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline BOOL 
CHECK_MOVE (E_SIG _arg_check_sig_mode)
{
	return (BOOL)((0b0110 >> _arg_check_sig_mode) & 1);
}

inline T_PWM
CHECK_MOVE 
(
	E_SIG _arg_check_sig_mode,
	T_PWM _arg_check_pwm
)
{
	return (T_PWM)(((0b0110 >> _arg_check_sig_mode) & 1) * _arg_check_pwm);
}

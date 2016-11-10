
#pragma once

inline E_SIG
F_Func_sig (BOOL _arg_bool)
{
	return (E_SIG)(0b01 << _arg_bool);
}

inline E_SIG
F_Func_sig (E_DIRECY _arg_direc_y)
{
	return (E_SIG)F_Turn_direc_y(_arg_direc_y);
}

inline E_SIG
F_Func_sig (E_DIRECX _arg_direc_x)
{
	return (E_SIG)F_Turn_direc_x(_arg_direc_x);
}

inline E_SIG
F_Func_sig
(
	BOOL _arg_bool_1,
	BOOL _arg_bool_0
)
{
	return (E_SIG)((_arg_bool_1 << 1) | (_arg_bool_0 << 0));
}

inline E_SIG
F_Func_sig
(
	E_DIRECY _arg_direc_y,
	E_DIRECX _arg_direc_x
)
{
	return (E_SIG)((usint)_arg_direc_y & (usint)_arg_direc_x);
}

inline E_SIG
F_Turn_sig_rotate (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b11011000 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline E_SIG
F_Turn_sig_fix (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b00100111 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline BOOL
F_Check_pwm (E_SIG _arg_check_sig_mode)
{
	return (BOOL)((0b0110 >> _arg_check_sig_mode) & 1);
}

inline T_PWM
F_Check_pwm
(
	E_SIG _arg_check_sig_mode,
	T_PWM _arg_check_pwm
)
{
	return (T_PWM)(((0b0110 >> _arg_check_sig_mode) & 1) * _arg_check_pwm);
}

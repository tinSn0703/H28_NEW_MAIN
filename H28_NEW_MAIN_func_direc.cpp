
#pragma once

inline E_DIRECX
F_Func_direc_x
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((__DIREC_SET__ >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

inline E_DIRECX
F_Func_direc_x
(
	BOOL _arg_direc_x_east,
	BOOL _arg_direc_x_west
)
{
	usint _direc_num = (((_arg_direc_x_east << 0) | (_arg_direc_x_west << 1)) * 2);
	
	return (E_DIRECX)((__DIREC_SET__ >> _direc_num) & 3);
}

inline E_DIRECX
F_Func_turn_direc_x
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((__DIREC_TURN_SET__ >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

inline E_DIRECX
F_Turn_direc_x (E_DIRECX _arg_direc_x )
{
	return (E_DIRECX)((__DIREC_TURN__ >> (((usint)_arg_direc_x) * 2)) & 3);
}

inline BOOL 
F_Check_direc_east (E_DIRECX _arg_direc_x)
{
	return (BOOL)((0b0010 >> _arg_direc_x) & 1);
}

inline BOOL
F_Check_direc_west (E_DIRECX _arg_direc_x)
{
	return (BOOL)((0b0100 >> _arg_direc_x) & 1);
}

inline BOOL
F_Check_direc_zero (E_DIRECX _arg_direc_x)
{
	return (BOOL)((0b1000 >> _arg_direc_x) & 1);
}

inline E_DIRECY
F_Func_direc_y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((__DIREC_SET__ >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

inline E_DIRECY
F_Func_direc_y
(
	BOOL _arg_direc_y_north,
	BOOL _arg_direc_y_south
)
{
	usint _direc_num = (((_arg_direc_y_north << 1) | (_arg_direc_y_south << 0)) * 2);
	
	return (E_DIRECY)((__DIREC_SET__ >> _direc_num) & 3);
}

inline E_DIRECY
F_Func_turn_direc_y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((__DIREC_TURN_SET__ >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

inline E_DIRECY
F_Turn_direc_y (E_DIRECY _arg_direc_y )
{
	return (E_DIRECY)((__DIREC_TURN__ >> (((usint)_arg_direc_y) * 2)) & 3);
}

inline BOOL
F_Check_direc_north (E_DIRECY _arg_direc_y)
{
	return (BOOL)((0b0010 >> _arg_direc_y) & 1);
}

inline BOOL
F_Check_direc_south (E_DIRECY _arg_direc_y)
{
	return (BOOL)((0b0100 >> _arg_direc_y) & 1);
}

inline BOOL
F_Check_direc_zero (E_DIRECY _arg_direc_y)
{
	return (BOOL)((0b1000 >> _arg_direc_y) & 1);
}
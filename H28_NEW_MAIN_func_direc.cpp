
#pragma once

#include "H28_NEW_MAIN_func_direc.h"

inline E_DIRECX
SET_DIREC_X
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((__DIREC_SET__ >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

inline E_DIRECX
SET_DIREC_X
(
	BOOL _arg_direc_x_east,
	BOOL _arg_direc_x_west
)
{
	usint _direc_num = (((_arg_direc_x_east << 0) | (_arg_direc_x_west << 1)) * 2);
	
	return (E_DIRECX)((__DIREC_SET__ >> _direc_num) & 3);
}

inline E_DIRECX
SET_TURN_DIREC_X
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((__DIREC_TURN_SET__ >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

inline E_DIRECX
TURN_DIREC_X (E_DIRECX _arg_direc_x )
{
	return (E_DIRECX)((__DIREC_TURN__ >> (((usint)_arg_direc_x) * 2)) & 3);
}

inline E_DIRECY
SET_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((__DIREC_SET__ >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

inline E_DIRECY
SET_DIREC_Y
(
	BOOL _arg_direc_y_north,
	BOOL _arg_direc_y_south
)
{
	usint _direc_num = (((_arg_direc_y_north << 1) | (_arg_direc_y_south << 0)) * 2);
	
	return (E_DIRECY)((__DIREC_SET__ >> _direc_num) & 3);
}

inline E_DIRECY
SET_TURN_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((__DIREC_TURN_SET__ >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

inline E_DIRECY
TURN_DIREC_Y (E_DIRECY _arg_direc_y )
{
	return (E_DIRECY)((__DIREC_TURN__ >> (((usint)_arg_direc_y) * 2)) & 3);
}
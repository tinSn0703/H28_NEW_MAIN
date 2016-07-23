
#pragma once

#include <H28_AVR/H28_AVR.h>
#include <FallMoon/akilcd_nm.h>
/* CONTROLER ************************************************************/
#define NOREA 1
#define SOUWE 2
#define ZERO  3

/*CONTROLER : cross rsti lsti*/
enum E_DIRECX
//X軸方向 2bit
{
	ED_EAST  = NOREA, /*右*/
	ED_WEST  = SOUWE, /*左*/
	ED_XZERO = ZERO,  /*無*/
};

/************************************************************************/

inline E_DIRECX 
SET_DIREC_X
(
	T_DATA _arg_direc_x_data,	//探すデータ
	T_NUM _arg_direc_x_bit		//探す位置の0bit目
)
/*
データ中のあるbitとbit + 1から設定されたE_DIRECXを返す

	_arg_direc_x_data	: 探すデータ
	_arg_direc_x_bit	: 探す位置の0bit目

	bit + 1 | bit + 0 | 結果
	   0	|    0    | ED_XZERO
	   0	|    1    | ED_EAST
	   1	|    0    | ED_WEST
 	   1	|    1    | ED_XZERO
*/
{
	return (E_DIRECX)((0b11100111 >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

/************************************************************************/

inline E_DIRECX 
SET_TURN_DIREC_X
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
/*
データ中のあるbitとbit + 1から設定されたE_DIRECXを返す
E_DIRECXとは逆になる

	_arg_direc_x_data	: 探すデータ
	_arg_direc_x_bit	: 探す位置の0bit目

	bit + 1 | bit + 0 | 結果
	   0	|    0    | ED_XZERO
	   0	|    1    | ED_WEST
	   1	|    0    | ED_EAST
 	   1	|    1    | ED_XZERO
*/
{
	return (E_DIRECX)((0b11011011 >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

/************************************************************************/

inline E_DIRECX 
SET_DIREC_X
(
	E_LOGIC _arg_direc_x_east,
	E_LOGIC _arg_direc_x_west
)
/*
2つのE_LOGICから設定されたE_DIRECXを返す

	_arg_direc_x_east : 東に影響
	_arg_direc_x_west : 西に影響

	 east  | west  | 結果
	 FALES | FALES | ED_XZERO
	 FALES | TRUE  | ED_WEST
	 TRUE  | FALES | ED_EAST
	 TRUE  | TRUE  | ED_XZERO
*/
{
	usint _direc_num = (((_arg_direc_x_east << 1) | (_arg_direc_x_west << 0)) * 2);
	
	return (E_DIRECX)((0b11100111 >> _direc_num) & 3);
}

/************************************************************************/

inline E_DIRECX 
TURN_DIREC_X (E_DIRECX _arg_direc_x )
/*
_arg_direc_xを反転させた値を返す

	ED_EAST  -> ED_WEST
	ED_WEST  -> ED_EAST
	ED_XZERO -> ED_XZERO
*/
{
	return (E_DIRECX)((0b11011000 >> (((usint)_arg_direc_x) * 2)) & 3);
}

/************************************************************************/

enum E_DIRECY
//Y軸方向 2bit
{
	ED_NORTH = NOREA, /*上*/
	ED_SOUTH = SOUWE, /*下*/
	ED_YZERO = ZERO,  /*無*/
};

/************************************************************************/

inline E_DIRECY 
SET_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
/*
データ中のあるbitとbit + 1から設定されたE_DIRECYを返す

	_arg_direc_y_data	: 探すデータ
	_arg_direc_y_bit	: 探す位置の0bit目

	bit + 1 | bit + 0 | 結果
	   0	|    0    | ED_YZERO
	   0	|    1    | ED_NORTH
	   1	|    0    | ED_SOUTH
 	   1	|    1    | ED_YZERO
*/
{
	return (E_DIRECY)((0b11011011 >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

/************************************************************************/

inline E_DIRECY 
SET_TURN_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
/*
データ中のあるbitとbit + 1から設定されたE_DIRECYを返す
SET_DIREC_Yとは逆になる

	_arg_direc_y_data	: 探すデータ
	_arg_direc_y_bit	: 探す位置の0bit目

	bit + 1 | bit + 0 | 結果
	   0	|    0    | ED_YZERO
	   0	|    1    | ED_SOUTH
	   1	|    0    | ED_NORTH
 	   1	|    1    | ED_YZERO
*/
{
	return (E_DIRECY)((0b11100111 >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

/************************************************************************/

inline E_DIRECY 
SET_DIREC_Y
(
	E_LOGIC _arg_direc_y_north,
	E_LOGIC _arg_direc_y_south
)
/*
2つのE_LOGICから設定されたE_DIRECYを返す

	_arg_direc_y_north : 北に影響
	_arg_direc_y_south : 南に影響

	 north | south | 結果
	 FALES | FALES | ED_YZERO
	 FALES | TRUE  | ED_SOUTH
	 TRUE  | FALES | ED_NORTH
	 TRUE  | TRUE  | ED_YZERO
*/
{
	usint _direc_num = (((_arg_direc_y_north << 1) | (_arg_direc_y_south << 0)) * 2);
	
	return (E_DIRECY)((0b11100111 >> _direc_num) & 3);
}

/************************************************************************/

inline E_DIRECY 
TURN_DIREC_Y (E_DIRECY _arg_direc_y )
/*
_arg_direc_yを反転させた値を返す
	ED_NORTH -> ED_SOUTH
	ED_SOUTH -> ED_NORTH
	ED_YZERO -> ED_YZERO
*/
{
	return (E_DIRECY)((0b11011000 >> (((usint)_arg_direc_y) * 2)) & 3);
}

/************************************************************************/

/* MD *******************************************************************/
typedef unsigned char T_PWM;

#ifndef PWM_NOR
#	define PWM_NOR 0x0a
#endif

enum E_SIG
//SIG_MODE 2bit
{
	ES_FREE  = 0,
	ES_FALES = 1,
	ES_TRUE  = 2,
	ES_STOP  = 3,
};

/************************************************************************/

inline E_SIG 
SET_SIG (E_LOGIC _arg_set_tf)
/*
_arg_set_tfから設定したE_SIGを返す

	TRUE  -> ES_TRUE
	FALES -> ES_FALES
*/
{
	return (E_SIG)(0b01 << _arg_set_tf);
}

/************************************************************************/

inline E_SIG 
SET_SIG (E_DIRECY _arg_set_direc_y)
/*
_arg_set_direc_yから設定したE_SIGを返す

	ED_NORTH -> ES_TRUE
	ED_SOUTH -> ES_FALES
	ED_YZERO -> ES_STOP
*/
{
	return (E_SIG)TURN_DIREC_Y(_arg_set_direc_y);
}

/************************************************************************/

inline E_SIG 
SET_SIG (E_DIRECX _arg_set_direc_x)
/*
_arg_set_direc_xから設定したE_SIGを返す

	ED_EAST  -> ES_TRUE
	ED_WEST  -> ES_FALES
	ED_XZERO -> ES_STOP
*/
{
	return (E_SIG)TURN_DIREC_X(_arg_set_direc_x);
}

/************************************************************************/

inline E_SIG 
SET_SIG
(
	E_LOGIC _arg_set_tf_1, 
	E_LOGIC _arg_set_tf_0
)
/*
_arg_set_tf_0,_arg_set_tf_1をもとに設定したSIGをreturnする

	  1   |   0   | 結果
	TRUE  | TRUE  | ES_STOP
	FALES | TRUE  | ES_FALES
	TRUE  | FALES | ES_TRUE
	FALES | FALES | ES_FREE
 */
{
	return (E_SIG)((_arg_set_tf_1 << 1) | (_arg_set_tf_0 << 0));
}

/************************************************************************/

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
/*
_arg_turn_sigの正転逆転を反転させたものをreturnする

	_arg_turn_sig : 確認する引数

	ES_TRUE  -> ES_FALES
	ES_FALES -> ES_TRUE
*/
{
	return (E_SIG)(0b11011000 >> ((usint)_arg_turn_sig * 2));
}

/************************************************************************/

inline E_SIG 
TURN_SIG_FIX (E_SIG _arg_turn_sig)
/*
_arg_turn_sigのフリー、ブレーキを反転させたものをreturnする

	ES_STOP -> ES_FREE
	ES_FREE -> ES_STOP
*/
{
	return (E_SIG)(0b00100111 >> ((usint)_arg_turn_sig * 2));
}

/************************************************************************/

inline E_LOGIC 
CHECK_MOVE (E_SIG _arg_check_sig_mode)
/*
PWMを0にすべきかの判断。E_LOGICで返す
	
	_arg_check_sig_mode : 確認するもの

	TRUE  -> しなくていい
	FALES -> しよう 
*/
{
	return (E_LOGIC)(0b0110 >> _arg_check_sig_mode);
}

/************************************************************************/

/* AIR ******************************************************************/
#define AIR_NUM 8

/************************************************************************/

#include "H28_NEW_MAIN/H28_NEW_MAIN_class.h"
#include "H28_NEW_MAIN/H28_NEW_MAIN_func.cpp"
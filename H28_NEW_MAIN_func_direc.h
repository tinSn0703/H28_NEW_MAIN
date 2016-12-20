
#pragma once

/*************************************************************************

「E_DIRECX」「E_DIRECY」を扱うための関数たち

*************************************************************************/

#define __DIREC_SET__		0b11100111
#define __DIREC_TURN_SET__	0b11011011
#define __DIREC_TURN__		0b11011000

/************************************************************************/
/*	宣言																*/
/************************************************************************/

/**
 * \brief 
 * データ中のあるbitとbit + 1から設定されたE_DIRECXを返す 
 *
 * \param _arg_direc_x_data : 探すデータ
 * \param _arg_direc_x_bit  : 探す位置の0bit目
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | 結果
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_EAST
 *		1	|    0    | ED_WEST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX F_Func_direc_x (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief 2つのBOOLから設定されたE_DIRECXを返す
 * 
 * \param _arg_direc_x_east : 東に影響
 * \param _arg_direc_x_west : 西に影響
 * 
 * \return E_DIRECX
 *	east  | west  | 結果
 *	FALES | FALES | ED_XZERO
 *	FALES | TRUE  | ED_WEST
 *	TRUE  | FALES | ED_EAST
 *	TRUE  | TRUE  | ED_XZERO
 */
inline E_DIRECX F_Func_direc_x (BOOL _arg_direc_x_east, BOOL _arg_direc_x_west);

/**
 * \brief 
 * データ中のあるbitとbit + 1から設定されたE_DIRECXを返す
 * SET_DIREC_Xとは逆になる
 * 
 * \param _arg_direc_x_data : 探すデータ
 * \param _arg_direc_x_bit  : 探す位置の0bit目
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | 結果
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_WEST
 *		1	|    0    | ED_EAST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX F_Func_turn_direc_x (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief _arg_direc_xを反転させた値を返す
 * 
 * \param _arg_direc_x : 元
 * 
 * \return E_DIRECX
 *	ED_EAST  -> ED_WEST
 *	ED_WEST  -> ED_EAST
 *	ED_XZERO -> ED_XZERO
 */
inline E_DIRECX F_Turn_direc_x (E_DIRECX _arg_direc_x );

/**
 * \brief 
 * _arg_direc_xがED_EASTのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_east (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_xがED_WESTのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_west (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_xがED_XZEROのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_zero (E_DIRECX _arg_direc_x);

/************************************************************************/

/**
 * \brief データ中のあるbitとbit + 1から設定されたE_DIRECYを返す
 * 
 * \param _arg_direc_y_data : 探すデータ
 * \param _arg_direc_y_bit  : 探す位置の0bit目
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | 結果
 *		0	|    0    | ED_YZERO
 *	 	0	|    1    | ED_NORTH
 *	 	1	|    0    | ED_SOUTH
 *	 	1	|    1    | ED_YZERO
 */
inline E_DIRECY F_Func_direc_y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief 2つのBOOLから設定されたE_DIRECYを返す
 * 
 * \param _arg_direc_y_north : 北に影響
 * \param _arg_direc_y_south : 南に影響
 * 
 * \return E_DIRECY
 *	 north | south | 結果
 *	 FALES | FALES | ED_YZERO
 *	 FALES | TRUE  | ED_SOUTH
 *	 TRUE  | FALES | ED_NORTH
 *	 TRUE  | TRUE  | ED_YZERO
 */
inline E_DIRECY F_Func_direc_y (BOOL _arg_direc_y_north, BOOL _arg_direc_y_south);

/**
 * \brief 
 * データ中のあるbitとbit + 1から設定されたE_DIRECYを返す
 * SET_DIREC_Yとは逆になる
 * 
 * \param _arg_direc_y_data : 探すデータ
 * \param _arg_direc_y_bit  : 探す位置の0bit目
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | 結果
 *		0	|    0    | ED_YZERO
 *		0	|    1    | ED_SOUTH
 *		1	|    0    | ED_NORTH
 *		1	|    1    | ED_YZERO
 */
inline E_DIRECY F_Func_turn_direc_y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief _arg_direc_yを反転させた値を返す
 * 
 * \param _arg_direc_y : 元
 * 
 * \return E_DIRECY
 *	ED_NORTH -> ED_SOUTH
 *	ED_SOUTH -> ED_NORTH
 *	ED_YZERO -> ED_YZERO
 */
inline E_DIRECY F_Turn_direc_y (E_DIRECY _arg_direc_y );

/**
 * \brief 
 * _arg_direc_yがED_NORTHのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_north (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_yがED_SOUTHのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_south (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_yがED_YZEROのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL F_Check_direc_zero (E_DIRECY _arg_direc_y);

/************************************************************************/
/*	実装																*/
/************************************************************************/

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

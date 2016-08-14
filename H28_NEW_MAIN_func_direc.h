
#pragma once

#define __DIREC_SET__		0b11100111
#define __DIREC_TURN_SET__	0b11011011
#define __DIREC_TURN__		0b11011000

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
inline E_DIRECX SET_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

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
inline E_DIRECX SET_DIREC_X (BOOL _arg_direc_x_east, BOOL _arg_direc_x_west);

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
inline E_DIRECX SET_TURN_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

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
inline E_DIRECX TURN_DIREC_X (E_DIRECX _arg_direc_x );

/**
 * \brief 
 * _arg_direc_xがED_EASTのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_E (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_xがED_WESTのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_W (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_xがED_XZEROのときTRUEを返す
 * 
 * \param _arg_direc_x : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_Z (E_DIRECX _arg_direc_x);

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
inline E_DIRECY SET_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

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
inline E_DIRECY SET_DIREC_Y (BOOL _arg_direc_y_north, BOOL _arg_direc_y_south);

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
inline E_DIRECY SET_TURN_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

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
inline E_DIRECY TURN_DIREC_Y (E_DIRECY _arg_direc_y );

/**
 * \brief 
 * _arg_direc_yがED_NORTHのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_N (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_yがED_SOUTHのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_S (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_yがED_YZEROのときTRUEを返す
 * 
 * \param _arg_direc_y : 確認対象
 * 
 * \return BOOL 上記の通り。それ以外はFALSE
 */
inline BOOL CHEN_DIREC_TF_Z (E_DIRECY _arg_direc_y);

#include "H28_NEW_MAIN_func_direc.cpp"

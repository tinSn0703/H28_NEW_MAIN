
#pragma once

#define __DIREC_SET__		0b11100111
#define __DIREC_TURN_SET__	0b11011011
#define __DIREC_TURN__		0b11011000

/**
 * \brief 
 * ƒf[ƒ^’†‚Ì‚ ‚ébit‚Æbit + 1‚©‚çÝ’è‚³‚ê‚½E_DIRECX‚ð•Ô‚· 
 *
 * \param _arg_direc_x_data : ’T‚·ƒf[ƒ^
 * \param _arg_direc_x_bit  : ’T‚·ˆÊ’u‚Ì0bit–Ú
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | Œ‹‰Ê
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_EAST
 *		1	|    0    | ED_WEST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX SET_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief 2‚Â‚ÌBOOL‚©‚çÝ’è‚³‚ê‚½E_DIRECX‚ð•Ô‚·
 * 
 * \param _arg_direc_x_east : “Œ‚É‰e‹¿
 * \param _arg_direc_x_west : ¼‚É‰e‹¿
 * 
 * \return E_DIRECX
 *	east  | west  | Œ‹‰Ê
 *	FALES | FALES | ED_XZERO
 *	FALES | TRUE  | ED_WEST
 *	TRUE  | FALES | ED_EAST
 *	TRUE  | TRUE  | ED_XZERO
 */
inline E_DIRECX SET_DIREC_X (BOOL _arg_direc_x_east, BOOL _arg_direc_x_west);

/**
 * \brief 
 * ƒf[ƒ^’†‚Ì‚ ‚ébit‚Æbit + 1‚©‚çÝ’è‚³‚ê‚½E_DIRECX‚ð•Ô‚·
 * SET_DIREC_X‚Æ‚Í‹t‚É‚È‚é
 * 
 * \param _arg_direc_x_data : ’T‚·ƒf[ƒ^
 * \param _arg_direc_x_bit  : ’T‚·ˆÊ’u‚Ì0bit–Ú
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | Œ‹‰Ê
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_WEST
 *		1	|    0    | ED_EAST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX SET_TURN_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief _arg_direc_x‚ð”½“]‚³‚¹‚½’l‚ð•Ô‚·
 * 
 * \param _arg_direc_x : Œ³
 * 
 * \return E_DIRECX
 *	ED_EAST  -> ED_WEST
 *	ED_WEST  -> ED_EAST
 *	ED_XZERO -> ED_XZERO
 */
inline E_DIRECX TURN_DIREC_X (E_DIRECX _arg_direc_x );

/**
 * \brief ƒf[ƒ^’†‚Ì‚ ‚ébit‚Æbit + 1‚©‚çÝ’è‚³‚ê‚½E_DIRECY‚ð•Ô‚·
 * 
 * \param _arg_direc_y_data : ’T‚·ƒf[ƒ^
 * \param _arg_direc_y_bit  : ’T‚·ˆÊ’u‚Ì0bit–Ú
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | Œ‹‰Ê
 *		0	|    0    | ED_YZERO
 *	 	0	|    1    | ED_NORTH
 *	 	1	|    0    | ED_SOUTH
 *	 	1	|    1    | ED_YZERO
 */
inline E_DIRECY SET_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief 2‚Â‚ÌBOOL‚©‚çÝ’è‚³‚ê‚½E_DIRECY‚ð•Ô‚·
 * 
 * \param _arg_direc_y_north : –k‚É‰e‹¿
 * \param _arg_direc_y_south : “ì‚É‰e‹¿
 * 
 * \return E_DIRECY
 *	 north | south | Œ‹‰Ê
 *	 FALES | FALES | ED_YZERO
 *	 FALES | TRUE  | ED_SOUTH
 *	 TRUE  | FALES | ED_NORTH
 *	 TRUE  | TRUE  | ED_YZERO
 */
inline E_DIRECY SET_DIREC_Y (BOOL _arg_direc_y_north, BOOL _arg_direc_y_south);

/**
 * \brief 
 * ƒf[ƒ^’†‚Ì‚ ‚ébit‚Æbit + 1‚©‚çÝ’è‚³‚ê‚½E_DIRECY‚ð•Ô‚·
 * SET_DIREC_Y‚Æ‚Í‹t‚É‚È‚é
 * 
 * \param _arg_direc_y_data : ’T‚·ƒf[ƒ^
 * \param _arg_direc_y_bit  : ’T‚·ˆÊ’u‚Ì0bit–Ú
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | Œ‹‰Ê
 *		0	|    0    | ED_YZERO
 *		0	|    1    | ED_SOUTH
 *		1	|    0    | ED_NORTH
 *		1	|    1    | ED_YZERO
 */
inline E_DIRECY SET_TURN_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief _arg_direc_y‚ð”½“]‚³‚¹‚½’l‚ð•Ô‚·
 * 
 * \param _arg_direc_y : Œ³
 * 
 * \return E_DIRECY
 *	ED_NORTH -> ED_SOUTH
 *	ED_SOUTH -> ED_NORTH
 *	ED_YZERO -> ED_YZERO
 */
inline E_DIRECY TURN_DIREC_Y (E_DIRECY _arg_direc_y );

#include "H28_NEW_MAIN_func_direc.cpp"

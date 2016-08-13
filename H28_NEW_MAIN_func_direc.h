
#pragma once

#define __DIREC_SET__		0b11100111
#define __DIREC_TURN_SET__	0b11011011
#define __DIREC_TURN__		0b11011000

/**
 * \brief 
 * �f�[�^���̂���bit��bit + 1����ݒ肳�ꂽE_DIRECX��Ԃ� 
 *
 * \param _arg_direc_x_data : �T���f�[�^
 * \param _arg_direc_x_bit  : �T���ʒu��0bit��
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | ����
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_EAST
 *		1	|    0    | ED_WEST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX SET_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief 2��BOOL����ݒ肳�ꂽE_DIRECX��Ԃ�
 * 
 * \param _arg_direc_x_east : ���ɉe��
 * \param _arg_direc_x_west : ���ɉe��
 * 
 * \return E_DIRECX
 *	east  | west  | ����
 *	FALES | FALES | ED_XZERO
 *	FALES | TRUE  | ED_WEST
 *	TRUE  | FALES | ED_EAST
 *	TRUE  | TRUE  | ED_XZERO
 */
inline E_DIRECX SET_DIREC_X (BOOL _arg_direc_x_east, BOOL _arg_direc_x_west);

/**
 * \brief 
 * �f�[�^���̂���bit��bit + 1����ݒ肳�ꂽE_DIRECX��Ԃ�
 * SET_DIREC_X�Ƃ͋t�ɂȂ�
 * 
 * \param _arg_direc_x_data : �T���f�[�^
 * \param _arg_direc_x_bit  : �T���ʒu��0bit��
 * 
 * \return E_DIRECX
 *	bit + 1 | bit + 0 | ����
 *		0	|    0    | ED_XZERO
 *		0	|    1    | ED_WEST
 *		1	|    0    | ED_EAST
 *		1	|    1    | ED_XZERO
 */
inline E_DIRECX SET_TURN_DIREC_X (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

/**
 * \brief _arg_direc_x�𔽓]�������l��Ԃ�
 * 
 * \param _arg_direc_x : ��
 * 
 * \return E_DIRECX
 *	ED_EAST  -> ED_WEST
 *	ED_WEST  -> ED_EAST
 *	ED_XZERO -> ED_XZERO
 */
inline E_DIRECX TURN_DIREC_X (E_DIRECX _arg_direc_x );

/**
 * \brief �f�[�^���̂���bit��bit + 1����ݒ肳�ꂽE_DIRECY��Ԃ�
 * 
 * \param _arg_direc_y_data : �T���f�[�^
 * \param _arg_direc_y_bit  : �T���ʒu��0bit��
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | ����
 *		0	|    0    | ED_YZERO
 *	 	0	|    1    | ED_NORTH
 *	 	1	|    0    | ED_SOUTH
 *	 	1	|    1    | ED_YZERO
 */
inline E_DIRECY SET_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief 2��BOOL����ݒ肳�ꂽE_DIRECY��Ԃ�
 * 
 * \param _arg_direc_y_north : �k�ɉe��
 * \param _arg_direc_y_south : ��ɉe��
 * 
 * \return E_DIRECY
 *	 north | south | ����
 *	 FALES | FALES | ED_YZERO
 *	 FALES | TRUE  | ED_SOUTH
 *	 TRUE  | FALES | ED_NORTH
 *	 TRUE  | TRUE  | ED_YZERO
 */
inline E_DIRECY SET_DIREC_Y (BOOL _arg_direc_y_north, BOOL _arg_direc_y_south);

/**
 * \brief 
 * �f�[�^���̂���bit��bit + 1����ݒ肳�ꂽE_DIRECY��Ԃ�
 * SET_DIREC_Y�Ƃ͋t�ɂȂ�
 * 
 * \param _arg_direc_y_data : �T���f�[�^
 * \param _arg_direc_y_bit  : �T���ʒu��0bit��
 * 
 * \return E_DIRECY
 *	bit + 1 | bit + 0 | ����
 *		0	|    0    | ED_YZERO
 *		0	|    1    | ED_SOUTH
 *		1	|    0    | ED_NORTH
 *		1	|    1    | ED_YZERO
 */
inline E_DIRECY SET_TURN_DIREC_Y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

/**
 * \brief _arg_direc_y�𔽓]�������l��Ԃ�
 * 
 * \param _arg_direc_y : ��
 * 
 * \return E_DIRECY
 *	ED_NORTH -> ED_SOUTH
 *	ED_SOUTH -> ED_NORTH
 *	ED_YZERO -> ED_YZERO
 */
inline E_DIRECY TURN_DIREC_Y (E_DIRECY _arg_direc_y );

#include "H28_NEW_MAIN_func_direc.cpp"

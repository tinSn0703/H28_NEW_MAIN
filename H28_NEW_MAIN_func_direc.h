
#pragma once

/*************************************************************************

�uE_DIRECX�v�uE_DIRECY�v���������߂̊֐�����

*************************************************************************/

#define __DIREC_SET__		0b11100111
#define __DIREC_TURN_SET__	0b11011011
#define __DIREC_TURN__		0b11011000

/************************************************************************/
/*	�錾																*/
/************************************************************************/

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
inline E_DIRECX F_Func_direc_x (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

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
inline E_DIRECX F_Func_direc_x (BOOL _arg_direc_x_east, BOOL _arg_direc_x_west);

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
inline E_DIRECX F_Func_turn_direc_x (T_DATA _arg_direc_x_data, T_NUM _arg_direc_x_bit);

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
inline E_DIRECX F_Turn_direc_x (E_DIRECX _arg_direc_x );

/**
 * \brief 
 * _arg_direc_x��ED_EAST�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_x : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_east (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_x��ED_WEST�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_x : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_west (E_DIRECX _arg_direc_x);

/**
 * \brief 
 * _arg_direc_x��ED_XZERO�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_x : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_zero (E_DIRECX _arg_direc_x);

/************************************************************************/

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
inline E_DIRECY F_Func_direc_y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

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
inline E_DIRECY F_Func_direc_y (BOOL _arg_direc_y_north, BOOL _arg_direc_y_south);

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
inline E_DIRECY F_Func_turn_direc_y (T_DATA _arg_direc_y_data, T_NUM _arg_direc_y_bit);

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
inline E_DIRECY F_Turn_direc_y (E_DIRECY _arg_direc_y );

/**
 * \brief 
 * _arg_direc_y��ED_NORTH�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_y : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_north (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_y��ED_SOUTH�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_y : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_south (E_DIRECY _arg_direc_y);

/**
 * \brief 
 * _arg_direc_y��ED_YZERO�̂Ƃ�TRUE��Ԃ�
 * 
 * \param _arg_direc_y : �m�F�Ώ�
 * 
 * \return BOOL ��L�̒ʂ�B����ȊO��FALSE
 */
inline BOOL F_Check_direc_zero (E_DIRECY _arg_direc_y);

/************************************************************************/
/*	����																*/
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

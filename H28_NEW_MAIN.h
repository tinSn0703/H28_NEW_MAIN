
#pragma once

//#define USED_H28_AM_640

#include <H28_AVR/H28_AVR.h>
#include <FallMoon/akilcd_nm.h>

/* CONTROLER ************************************************************/
#define NOREA 0b01
#define SOUWE 0b10
#define ZERO  0b11

#define DIREC_SET		0b11100111
#define DIREC_TURN_SET	0b11011011
#define DIREC_TURN		0b11011000

/**
 * X������ 2bit
 */
enum E_DIRECX
{
	ED_EAST  = NOREA, //�E
	ED_WEST  = SOUWE, //��
	ED_XZERO = ZERO,  //��
};

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
inline E_DIRECX 
SET_DIREC_X
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((DIREC_SET >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

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
inline E_DIRECX 
SET_DIREC_X
(
	BOOL _arg_direc_x_east,
	BOOL _arg_direc_x_west
)
{
	usint _direc_num = (((_arg_direc_x_east << 0) | (_arg_direc_x_west << 1)) * 2);
	
	return (E_DIRECX)((DIREC_SET >> _direc_num) & 3);
}

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
inline E_DIRECX 
SET_TURN_DIREC_X
(
	T_DATA _arg_direc_x_data,
	T_NUM _arg_direc_x_bit
)
{
	return (E_DIRECX)((DIREC_TURN_SET >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

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
inline E_DIRECX 
TURN_DIREC_X (E_DIRECX _arg_direc_x )
{
	return (E_DIRECX)((DIREC_TURN >> (((usint)_arg_direc_x) * 2)) & 3);
}

/************************************************************************/

/**
 * Y������ 2bit
 */
enum E_DIRECY
{
	ED_NORTH = NOREA, //��
	ED_SOUTH = SOUWE, //��
	ED_YZERO = ZERO,  //��
};

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
inline E_DIRECY 
SET_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((DIREC_SET >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

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
inline E_DIRECY 
SET_DIREC_Y
(
	BOOL _arg_direc_y_north,
	BOOL _arg_direc_y_south
)
{
	usint _direc_num = (((_arg_direc_y_north << 1) | (_arg_direc_y_south << 0)) * 2);
	
	return (E_DIRECY)((DIREC_SET >> _direc_num) & 3);
}

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
inline E_DIRECY 
SET_TURN_DIREC_Y
(
	T_DATA _arg_direc_y_data,
	T_NUM _arg_direc_y_bit
)
{
	return (E_DIRECY)((DIREC_TURN_SET >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

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
inline E_DIRECY 
TURN_DIREC_Y (E_DIRECY _arg_direc_y )
{
	return (E_DIRECY)((DIREC_TURN >> (((usint)_arg_direc_y) * 2)) & 3);
}

/************************************************************************/

/* MD *******************************************************************/
typedef unsigned char T_PWM;

#ifndef PWM_NOR
#	define PWM_NOR 0x0a
#endif

/**
 * MOTOR_MODE 2bit
 */
enum E_SIG
{
	ES_FREE  = 0,
	ES_FALES = 1,
	ES_TRUE  = 2,
	ES_STOP  = 3,
};

/**
 * \brief _arg_set_tf����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_tf : ��
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALES
 */
inline E_SIG 
SET_SIG (BOOL _arg_set_tf)
{
	return (E_SIG)(0b01 << _arg_set_tf);
}

/**
 * \brief _arg_set_direc_y����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_direc_y : ��
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALES
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG 
SET_SIG (E_DIRECY _arg_set_direc_y)
{
	return (E_SIG)TURN_DIREC_Y(_arg_set_direc_y);
}

/**
 * \brief _arg_set_direc_x����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_direc_x : ��
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALES
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG 
SET_SIG (E_DIRECX _arg_set_direc_x)
{
	return (E_SIG)TURN_DIREC_X(_arg_set_direc_x);
}

/**
 * \brief _arg_set_tf_0,_arg_set_tf_1�����Ƃɐݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_tf_1 : ��1
 * \param _arg_set_tf_0 : ��0
 * 
 * \return E_SIG
 * 		 1   |   0   | ����
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALES
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
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

/**
 * \brief _arg_turn_sig�̐��]�t�]�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALES
 *	ES_FALES -> ES_TRUE
 */
inline E_SIG 
TURN_SIG_ROTATE (E_SIG _arg_turn_sig)
{
	return (E_SIG)(0b11011000 >> ((usint)_arg_turn_sig * 2));
}

/**
 * \brief _arg_turn_sig�̃t���[�A�X�g�b�v�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG 
TURN_SIG_FIX (E_SIG _arg_turn_sig)
{
	return (E_SIG)(0b00100111 >> ((usint)_arg_turn_sig * 2));
}

/**
 * \brief PWM��0�ɂ��ׂ����̔��f�BBOOL�ŕԂ�
 * 
 * \param _arg_check_sig_mode : �m�F����sig
 * 
 * \return BOOL
 *	TRUE  -> ���Ȃ��Ă���
 *	FALES -> ���悤
 */
inline BOOL 
CHECK_MOVE (E_SIG _arg_check_sig_mode)
{
	return (BOOL)((0b0110 >> _arg_check_sig_mode) & 1);
}

/**
 * \brief sig�ɂ���ĕω�������pwm��Ԃ�
 * 
 * \param _arg_check_sig_mode : �m�F����sig
 * \param _arg_check_pwm : ��pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALES -> ���̂܂�
 */
inline T_PWM
CHECK_MOVE 
(
	E_SIG _arg_check_sig_mode,
	T_PWM _arg_check_pwm
)
{
	return (T_PWM)(((0b0110 >> _arg_check_sig_mode) & 1) * _arg_check_pwm);
}

/************************************************************************/

/* AIR ******************************************************************/

#define AIR_NUM 8

/************************************************************************/

#include "H28_NEW_MAIN/H28_NEW_MAIN_class.h"
#include "H28_NEW_MAIN/H28_NEW_MAIN_func.h"
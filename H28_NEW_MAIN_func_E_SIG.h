
/*
	E_SIG���������߂̊֐��Q�B
*/

#pragma once

/**
 * \brief 
 *	BOOL����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_bool : ��
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool);

/**
 * \brief E_DIREC_Y����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_direc_y : ��
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y);

/**
 * \brief E_DIREC_X����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_direc_x : ��
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECX _arg_direc_x);

/**
 * \brief 
 *	�ӂ���BOOL�����Ƃɐݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_bool_1 : ��1
 * \param _arg_bool_0 : ��0
 * 
 * \return E_SIG
 * 		 1   |   0   | ����
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool_1, BOOL _arg_bool_0);

/**
 * \brief 
 * E_DIREC_Y��E_DIREC_X���������̂�����E_SIG��Ԃ�
 * ���J�i���̂��߂ɍ�����悤�Ȃ���
 * 
 * \param _arg_direc_y : �ޗ�����0
 * \param _arg_direc_x : �ޗ�����1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			���̑�		-> ES_FREE 
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y, E_DIRECX _arg_direc_x);

/**
 * \brief _arg_turn_sig�̐��]�t�]�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG F_Turn_sig_rotate (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sig�̃t���[�A�X�g�b�v�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG F_Turn_sig_fix (E_SIG _arg_turn_sig);

/**
 * \brief PWM��0�ɂ��ׂ����̔��f�BBOOL�ŕԂ�
 * 
 * \param _arg_check_sig : �m�F����sig
 * 
 * \return BOOL
 *	TRUE  -> ���Ȃ��Ă���
 *	FALES -> ���悤
 */
inline BOOL F_Check_pwm (E_SIG _arg_check_sig);

/**
 * \brief sig�ɂ���ĕω�������pwm��Ԃ�
 * 
 * \param _arg_check_sig : �m�F����sig
 * \param _arg_pwm : ��pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> ���̂܂�
 */
inline T_PWM F_Check_pwm (E_SIG _arg_check_sig, T_PWM _arg_pwm);

#include "H28_NEW_MAIN_func_E_SIG.cpp"

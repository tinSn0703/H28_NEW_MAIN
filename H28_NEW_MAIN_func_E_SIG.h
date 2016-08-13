
#pragma once

/**
 * \brief _arg_set_tf����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_tf : ��
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf);

/**
 * \brief _arg_set_direc_y����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_direc_y : ��
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y);

/**
 * \brief _arg_set_direc_x����ݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_direc_x : ��
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_set_tf_0,_arg_set_tf_1�����Ƃɐݒ肵��E_SIG��Ԃ�
 * 
 * \param _arg_set_tf_1 : ��1
 * \param _arg_set_tf_0 : ��0
 * 
 * \return E_SIG
 * 		 1   |   0   | ����
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf_1, BOOL _arg_set_tf_0);

/**
 * \brief 
 * direc_y��direc_x���������̂�����E_SIG��Ԃ�
 * ���J�i���̂��߂ɍ�����悤�Ȃ���
 * 
 * \param _arg_set_direc_y : �ޗ�����0
 * \param _arg_set_direc_x : �ޗ�����1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			���̑�		-> ES_FREE 
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y, E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_turn_sig�̐��]�t�]�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG TURN_SIG_ROTATE (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sig�̃t���[�A�X�g�b�v�𔽓]���������̂�Ԃ�
 * 
 * \param _arg_turn_sig : ��
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG TURN_SIG_FIX (E_SIG _arg_turn_sig);

/**
 * \brief PWM��0�ɂ��ׂ����̔��f�BBOOL�ŕԂ�
 * 
 * \param _arg_check_sig_mode : �m�F����sig
 * 
 * \return BOOL
 *	TRUE  -> ���Ȃ��Ă���
 *	FALES -> ���悤
 */
inline BOOL CHECK_MOVE (E_SIG _arg_check_sig_mode);

/**
 * \brief sig�ɂ���ĕω�������pwm��Ԃ�
 * 
 * \param _arg_check_sig_mode : �m�F����sig
 * \param _arg_check_pwm : ��pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> ���̂܂�
 */
inline T_PWM CHECK_MOVE (E_SIG _arg_check_sig_mode, T_PWM _arg_check_pwm);

#include "H28_NEW_MAIN_func_E_SIG.cpp"

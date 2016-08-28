
#pragma once

/**
 * \brief : 2�ւ������֐��B
 * 
 * \param _arg_motor : �v�f��2�̔z��ɂ��Ƃ��Ă�
 * \param _arg_direc_move : �i�ޕ���
 * \param _arg_pwm : PWM
 */
inline void F_Set_wheel_2(C_MD_MAIN _arg_motor[2], E_DIRECY _arg_direc_move, T_PWM _arg_pwm);

/**
 * \brief ��ւ̐M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_turn_0 : _arg_motor[0]����]������
 * \param _arg_turn_1 : _arg_motor[1]����]������
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 * \param _arg_sig_base : ���񎞂̐��t�]�̐ݒ�
 */
inline void F_Set_wheel_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_sig_base, BOOL _arg_nf_turn);

/**
 * \brief ��ւ̐M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_direc_x : ���񂷂�����̑I���B
 *		EAST -> [0]��
 *		WEST -> [1]��
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 * \param _arg_sig_base : ���񎞂̐��t�]�̐ݒ�
 */
inline void F_Set_wheel_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn, BOOL _arg_sig_base);

/**
 * \brief ��ւ̒��M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_turn_0 : _arg_motor[0]����]������
 * \param _arg_turn_1 : _arg_motor[1]����]������
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 */
inline void F_Set_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_nf_turn);

/**
 * \brief ��ւ̒��M�n����B
 * 
 * \param _arg_motor   : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_direc_x : ���񂷂�����̑I���B
 *		EAST -> [0]��
 *		WEST -> [1]��
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 */
inline void F_Set_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn);

#include "H28_NEW_MAIN_func_wheel_2.cpp"

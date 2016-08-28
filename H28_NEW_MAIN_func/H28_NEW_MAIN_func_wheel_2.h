
#pragma once

/**
 * \brief : 2輪を扱う関数。
 * 
 * \param _arg_motor : 要素数2の配列にしといてね
 * \param _arg_direc_move : 進む方向
 * \param _arg_pwm : PWM
 */
inline void F_Set_wheel_2(C_MD_MAIN _arg_motor[2], E_DIRECY _arg_direc_move, T_PWM _arg_pwm);

/**
 * \brief 二輪の信地旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は2
 * \param _arg_turn_0 : _arg_motor[0]を回転させる
 * \param _arg_turn_1 : _arg_motor[1]を回転させる
 * \param _arg_pwm : 設定するPWM
 * \param _arg_nf_turn : 操作の反転
 * \param _arg_sig_base : 旋回時の正逆転の設定
 */
inline void F_Set_wheel_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_sig_base, BOOL _arg_nf_turn);

/**
 * \brief 二輪の信地旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は2
 * \param _arg_direc_x : 旋回する向きの選択。
 *		EAST -> [0]側
 *		WEST -> [1]側
 * \param _arg_pwm : 設定するPWM
 * \param _arg_nf_turn : 操作の反転
 * \param _arg_sig_base : 旋回時の正逆転の設定
 */
inline void F_Set_wheel_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn, BOOL _arg_sig_base);

/**
 * \brief 二輪の超信地旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は2
 * \param _arg_turn_0 : _arg_motor[0]を回転させる
 * \param _arg_turn_1 : _arg_motor[1]を回転させる
 * \param _arg_pwm : 設定するPWM
 * \param _arg_nf_turn : 操作の反転
 */
inline void F_Set_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_nf_turn);

/**
 * \brief 二輪の超信地旋回。
 * 
 * \param _arg_motor   : 旋回させるモータ。要素数は2
 * \param _arg_direc_x : 旋回する向きの選択。
 *		EAST -> [0]側
 *		WEST -> [1]側
 * \param _arg_pwm : 設定するPWM
 * \param _arg_nf_turn : 操作の反転
 */
inline void F_Set_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn);

#include "H28_NEW_MAIN_func_wheel_2.cpp"

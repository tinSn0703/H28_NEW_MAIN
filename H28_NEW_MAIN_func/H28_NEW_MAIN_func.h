
#pragma once

#define __MULTIPLE_OMUNI__ 0.2

#define __WHEEL_RI_FR__	0
#define __WHEEL_LE_FR__	1
#define __WHEEL_LE_BA__	2
#define __WHEEL_RI_BA__	3

/**
 * \brief 3輪メカナムニの信地旋回
 * 
 * \param _arg_motor	  : 旋回させるモータ。要素数は3
 * \param _arg_turn_left  : 左旋回
 * \param _arg_turn_right : 右旋回
 * \param _arg_pwm		  : PWM
 */
inline void F_Do_mowheeel_turn_3(C_MD_MAIN _arg_motor[3], const BOOL _arg_turn_left, const BOOL _arg_turn_right, const T_PWM _arg_pwm);

/**
 * \brief 4輪の旋回
 * 
 * \param _arg_motor  : 旋回させるモータ。要素数は4
 * \param _arg_turn_0 : 全正転
 * \param _arg_turn_1 : 全逆転
 * \param _arg_pwm : PWM
 */
inline void F_Do_wheel_turn_4(C_MD_MAIN _arg_motor[4], const BOOL _arg_turn_0, const BOOL _arg_turn_1, const T_PWM _arg_pwm);

/**
 * \brief 3輪メカナムニの超信地旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は3
 * \param _arg_turn_left  : 左旋回
 * \param _arg_turn_right : 右旋回
 * \param _arg_pwm : 設定するPWM
 */
inline void F_Do_mowheel_p_turn_3(C_MD_MAIN _arg_motor[3], const BOOL _arg_turn_left, const BOOL _arg_turn_right, const T_PWM _arg_pwm);

inline void F_Do_wheel_4 (C_MD_MAIN _arg_motor[4], const E_DIRECY _arg_move, const T_PWM _arg_pwm, const BOOL _arg_base_sig);

/**
 * \brief 
 * 四輪メカナムを扱う関数
 * ちゃんと動くかはわからん
 * 
 * \param _arg_motor
 *  動かすモータ。要素数は4
 *  0を右前,1を右後,2を左前,3を左後にすること
 *
 * \param _arg_direc_x : x軸方向
 * \param _arg_direc_y : y軸方向
 * \param _arg_pwm : PWM
 */
inline void F_Do_mwheel_4(C_MD_MAIN _arg_motor[4], const E_DIRECX _arg_direc_x, const E_DIRECY _arg_direc_y, const T_PWM _arg_pwm, const BOOL _arg_nf_turn_x , const BOOL _arg_nf_turn_y);

/**
 * \brief 
 * 三輪メカナムニを扱う関数
 * 斜めには動けない
 * 
 * \param _arg_motor
 *	動かすモータ。要素数は3
 *	0を前(オムニ),1を左(メカナム),2を右(メカナム)に設定すること
 *
 * \param _arg_direc_x : x
 * \param _arg_direc_y : y
 * \param _arg_pwm : PWM
 */
inline void F_Do_mowheel_3(C_MD_MAIN _arg_motor[3], const E_DIRECX _arg_direc_x, const E_DIRECY _arg_direc_y, const T_PWM _arg_pwm);

#include "H28_NEW_MAIN_func_wheel_2.h"
#include "H28_NEW_MAIN_func_lcd.h"
#include "H28_NEW_MAIN_func_pwm.h"
#include "H28_NEW_MAIN_func_count.h"

#include "H28_NEW_MAIN_func.cpp"
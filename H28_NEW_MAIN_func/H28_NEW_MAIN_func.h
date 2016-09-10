
#pragma once

#define __MULTIPLE_OMUNI__ 0.2

#define __MEKANAMU_RI_FR__	0
#define __MEKANAMU_RI_BA__	1
#define __MEKANAMU_LE_FR__	2
#define __MEKANAMU_LE_BA__	3

/**
 * \brief _arg_pwmを++か--する
 * 
 * \param _arg_pwm_hl : _arg_pwmを++するか--するか
 *		NORTH,EAST -> ++
 *		SOUTH,WEST -> --
 *
 * \param _arg_pwm  : 変更するPWM
 * \param _arg_flag : 連打防止。外部で作ってね。
 * \param _arg_pwm_recet : _arg_pwmをPWM_NORにする。
 * 
 * \return T_PWM ついで
 */
template <class DIREC>
inline T_PWM F_Set_pwm(const DIREC _arg_pwm_hl, T_PWM &_arg_pwm, BOOL &_arg_flag, const BOOL _arg_pwm_recet = FALSE);

/**
 * \brief _arg_pwmを++,--する。 
 * 
 * \param _arg_nf_pwm_high : TRUEのとき_arg_pwmを++する
 * \param _arg_nf_pwm_low  : TRUEのとき_arg_pwmを--する
 * \param _arg_pwm  : 変更するPWM
 * \param _arg_flag : 連打防止。外部で作ってね。
 * \param _arg_pwm_recet : TRUEのとき_arg_pwmをPWM_NORにする。
 * 
 * \return T_PWM : ついで
 */
inline T_PWM F_Set_pwm(const BOOL _arg_nf_pwm_high, const BOOL _arg_nf_pwm_low, T_PWM &_arg_pwm, BOOL &_arg_flag, const BOOL _arg_pwm_recet);

/**
 * \brief 3輪メカナムニの信地旋回
 * 
 * \param _arg_motor	  : 旋回させるモータ。要素数は3
 * \param _arg_turn_left  : 左旋回
 * \param _arg_turn_right : 右旋回
 * \param _arg_pwm		  : PWM
 */
inline void F_Set_mowheeel_turn_3(C_MD_MAIN _arg_motor[3], const BOOL _arg_turn_left, const BOOL _arg_turn_right, const T_PWM _arg_pwm);

/**
 * \brief 4輪の旋回
 * 
 * \param _arg_motor  : 旋回させるモータ。要素数は4
 * \param _arg_turn_0 : 0番のモータ側を回転させる
 * \param _arg_turn_1 : 2番のモータ側を回転させる
 * \param _arg_pwm : PWM
 */
inline void F_Set_wheel_turn_4(C_MD_MAIN _arg_motor[4], const BOOL _arg_turn_0, const BOOL _arg_turn_1, const T_PWM _arg_pwm);

/**
 * \brief 3輪メカナムニの超信地旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は3
 * \param _arg_turn_left  : 左旋回
 * \param _arg_turn_right : 右旋回
 * \param _arg_pwm : 設定するPWM
 */
inline void F_Set_mowheel_p_turn_3(C_MD_MAIN _arg_motor[3], const BOOL _arg_turn_left, const BOOL _arg_turn_right, const T_PWM _arg_pwm);

/**
 * \brief 
 * 四輪メカナムを扱う関数
 * ちゃんと動くかはわからん
 * 
 * \param _arg_motor
 *  動かすモータ。要素数は4
 *  0を右前,1を右後,2を左前,3を左後に設定すること
 *
 * \param _arg_direc_x : x軸方向
 * \param _arg_direc_y : y軸方向
 * \param _arg_pwm : PWM
 */
inline void F_Set_mwheel_4(C_MD_MAIN _arg_motor[4], const E_DIRECX _arg_direc_x, const E_DIRECY _arg_direc_y, const T_PWM _arg_pwm);

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
inline void F_Set_mowheel_3(C_MD_MAIN _arg_motor[3], const E_DIRECX _arg_direc_x, const E_DIRECY _arg_direc_y, const T_PWM _arg_pwm);

/**
 * \brief 
 * モーターを正逆転させる
 * これメンバでもいい気がしてきた
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_nf_true  : ES_TRUEにする
 * \param _arg_nf_fales : ES_FALESにする
 *
 *		true  | fales | 結果
 *		TRUE  | TRUE  | ES_STOP
 *		TRUE  | FALES | ES_TRUE
 *		FALES | TRUE  | ES_FALSE
 *		FALES | FALES | ES_FREE
 *
 * \param _arg_pwm : 設定するPWM
 */
inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, const BOOL _arg_nf_true, const BOOL _arg_nf_fales, const T_PWM _arg_pwm);

/**
 * \brief 
 * 
 * \param _arg_motor	: 
 * \param _arg_nf		: 
 * \param _arg_flag_nf	: 
 * \param _arg_base		: 
 * \param _arg_pwm		: 
 */
inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, const BOOL _arg_nf, BOOL &_arg_flag_nf, const E_SIG _arg_base, const T_PWM _arg_pwm);

/**
 * \brief モーターを正逆転させる
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_motor_tf : 方向キー y方向
 *
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 *
 * \param _arg_pwm : モーターのPWM
 */
inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, const E_DIRECY _arg_motor_tf, const T_PWM _arg_pwm);

/**
 * \brief モーターを正逆転させる
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_motor_tf : 方向キー x方向
 *
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 *
 * \param _arg_pwm : モーターのPWM
 */
inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, const E_DIRECX _arg_motor_tf, const T_PWM _arg_pwm);

/**
 * \brief 
 * C_COUNTを動かす。
 * _arg_set_highか_arg_set_lowが一度FALESにならないと動かない仕組み
 * 
 * \param _arg_set_high : カウントアップ
 * \param _arg_set_low  : カウントダウン
 * \param _arg_count : カウンタ。変えられるやつ
 */
inline void F_Do_count(const BOOL  _arg_set_high, const BOOL  _arg_set_low, C_COUNT_u1 &_arg_count);

/**
 * \brief 
 * カウンタを利用して_arg_nfのTFを反転させる関数
 * カウンタはループにしとかないでください
 * カウントの++は別のところでやってください。
 * こいつはあくまでカウント完了していたらの関数です
 * カウントを開始すると、カウンタのフラグがTRUEになり、完了するとFALSEになります。
 * 
 * \param _arg_nf_count		: カウントの開始
 * \param _arg_nf			: カウントが完了しているとこいつのTFが反転する
 * \param _arg_count		: カウンタ
 */
inline void F_Count_tf(const BOOL _arg_nf_count, BOOL &_arg_nf, C_COUNT_u1 &_arg_count);

/**
 * \brief 
 * カウンタを利用して_arg_nfのTFを反転させる関数
 * カウンタはループにしとかないでください
 * カウントの++は別のところでやってください。
 * カウンタのフラグが立っていて、_arg_compとカウンタが等しいときに、_arg_nfが変化します
 * 変化するとカウンタの値が++されます。
 *
 * \param _arg_comp	 : 比較する値
 * \param _arg_nf	 : 動かされるやつ
 * \param _arg_flag	 : フラグ。外部で変えないでね
 * \param _arg_count : カウンタ
 */
inline void F_Count_tf(const uchar _arg_comp, BOOL &_arg_nf, BOOL &_arg_flag, C_COUNT_u1 &_arg_count);

#include "H28_NEW_MAIN_func_wheel_2.h"
#include "H28_NEW_MAIN_func_lcd.h"

#include "H28_NEW_MAIN_func.cpp"
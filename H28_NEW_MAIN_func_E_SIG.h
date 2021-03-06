
/*
	E_SIGを扱うための関数群。
*/

#pragma once

/************************************************************************/
/*	宣言																*/
/************************************************************************/

/**
 * \brief	BOOLから設定したE_SIGを返す
 * 
 * \param _arg_bool : 元
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool);

/**
 * \brief E_DIREC_Yから設定したE_SIGを返す
 * 
 * \param _arg_direc_y : 元
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y);

/**
 * \brief E_DIREC_Xから設定したE_SIGを返す
 * 
 * \param _arg_direc_x : 元
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECX _arg_direc_x);

/**
 * \brief	ふたつのBOOLをもとに設定したE_SIGを返す
 * 
 * \param _arg_bool_1 : 元1
 * \param _arg_bool_0 : 元0
 * 
 * \return E_SIG
 * 		 1   |   0   | 結果
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool_1, BOOL _arg_bool_0);

/**
 * \brief 
 * E_DIREC_YとE_DIREC_Xを悪魔合体させたE_SIGを返す
 * メカナムのために作ったようなもの
 * 
 * \param _arg_direc_y : 材料その0
 * \param _arg_direc_x : 材料その1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			その他		-> ES_FREE 
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y, E_DIRECX _arg_direc_x);

/**
 * \brief _arg_turn_sigの正転逆転を反転させたものを返す
 * 
 * \param _arg_turn_sig : 元
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG F_Turn_sig_rotate (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sigのフリー、ストップを反転させたものを返す
 * 
 * \param _arg_turn_sig : 元
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG F_Turn_sig_fix (E_SIG _arg_turn_sig);

/**
 * \brief PWMを0にすべきかの判断。BOOLで返す
 * 
 * \param _arg_check_sig : 確認するsig
 * 
 * \return BOOL
 *	TRUE  -> しなくていい
 *	FALES -> しよう
 */
inline BOOL F_Check_pwm (E_SIG _arg_check_sig);

/**
 * \brief sigによって変化させたpwmを返す
 * 
 * \param _arg_check_sig : 確認するsig
 * \param _arg_pwm : 元pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> 元のまま
 */
inline T_PWM F_Check_pwm (E_SIG _arg_check_sig, T_PWM _arg_pwm);

/************************************************************************/
/*	実装																*/
/************************************************************************/

inline E_SIG
F_Func_sig (BOOL _arg_bool)
{
	return (E_SIG)(0b01 << _arg_bool);
}

inline E_SIG
F_Func_sig (E_DIRECY _arg_direc_y)
{
	return (E_SIG)F_Turn_direc_y(_arg_direc_y);
}

inline E_SIG
F_Func_sig (E_DIRECX _arg_direc_x)
{
	return (E_SIG)F_Turn_direc_x(_arg_direc_x);
}

inline E_SIG
F_Func_sig
(
BOOL _arg_bool_1,
BOOL _arg_bool_0
)
{
	return (E_SIG)((_arg_bool_1 << 1) | (_arg_bool_0 << 0));
}

inline E_SIG
F_Func_sig
(
	const E_DIRECY _arg_direc_y,
	const E_DIRECX _arg_direc_x
)
{
	return (E_SIG)((usint)_arg_direc_y & (usint)_arg_direc_x);
}

inline E_SIG
F_Turn_sig_rotate (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b11011000 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline E_SIG
F_Turn_sig_fix (E_SIG _arg_turn_sig)
{
	return (E_SIG)((0b00100111 >> ((usint)_arg_turn_sig * 2)) & 3);
}

inline BOOL
F_Check_pwm (E_SIG _arg_check_sig_mode)
{
	return (BOOL)((0b0110 >> _arg_check_sig_mode) & 1);
}

inline T_PWM
F_Check_pwm
(
	E_SIG _arg_check_sig_mode,
	T_PWM _arg_check_pwm
)
{
	return (T_PWM)(((0b0110 >> _arg_check_sig_mode) & 1) * _arg_check_pwm);
}


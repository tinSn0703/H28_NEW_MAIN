
#pragma once

/**
 * \brief _arg_set_tfから設定したE_SIGを返す
 * 
 * \param _arg_set_tf : 元
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf);

/**
 * \brief _arg_set_direc_yから設定したE_SIGを返す
 * 
 * \param _arg_set_direc_y : 元
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y);

/**
 * \brief _arg_set_direc_xから設定したE_SIGを返す
 * 
 * \param _arg_set_direc_x : 元
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_set_tf_0,_arg_set_tf_1をもとに設定したE_SIGを返す
 * 
 * \param _arg_set_tf_1 : 元1
 * \param _arg_set_tf_0 : 元0
 * 
 * \return E_SIG
 * 		 1   |   0   | 結果
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf_1, BOOL _arg_set_tf_0);

/**
 * \brief 
 * direc_yとdirec_xを悪魔合体させたE_SIGを返す
 * メカナムのために作ったようなもの
 * 
 * \param _arg_set_direc_y : 材料その0
 * \param _arg_set_direc_x : 材料その1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			その他		-> ES_FREE 
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y, E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_turn_sigの正転逆転を反転させたものを返す
 * 
 * \param _arg_turn_sig : 元
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG TURN_SIG_ROTATE (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sigのフリー、ストップを反転させたものを返す
 * 
 * \param _arg_turn_sig : 元
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG TURN_SIG_FIX (E_SIG _arg_turn_sig);

/**
 * \brief PWMを0にすべきかの判断。BOOLで返す
 * 
 * \param _arg_check_sig_mode : 確認するsig
 * 
 * \return BOOL
 *	TRUE  -> しなくていい
 *	FALES -> しよう
 */
inline BOOL CHECK_MOVE (E_SIG _arg_check_sig_mode);

/**
 * \brief sigによって変化させたpwmを返す
 * 
 * \param _arg_check_sig_mode : 確認するsig
 * \param _arg_check_pwm : 元pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> 元のまま
 */
inline T_PWM CHECK_MOVE (E_SIG _arg_check_sig_mode, T_PWM _arg_check_pwm);

#include "H28_NEW_MAIN_func_E_SIG.cpp"


/*
	E_SIG‚ðˆµ‚¤‚½‚ß‚ÌŠÖ”ŒQB
*/

#pragma once

/**
 * \brief _arg_set_tf‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_set_tf : Œ³
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf);

/**
 * \brief _arg_set_direc_y‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_set_direc_y : Œ³
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y);

/**
 * \brief _arg_set_direc_x‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_set_direc_x : Œ³
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG SET_SIG (E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_set_tf_0,_arg_set_tf_1‚ð‚à‚Æ‚ÉÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_set_tf_1 : Œ³1
 * \param _arg_set_tf_0 : Œ³0
 * 
 * \return E_SIG
 * 		 1   |   0   | Œ‹‰Ê
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG SET_SIG (BOOL _arg_set_tf_1, BOOL _arg_set_tf_0);

/**
 * \brief 
 * direc_y‚Ædirec_x‚ðˆ«–‚‡‘Ì‚³‚¹‚½E_SIG‚ð•Ô‚·
 * ƒƒJƒiƒ€‚Ì‚½‚ß‚Éì‚Á‚½‚æ‚¤‚È‚à‚Ì
 * 
 * \param _arg_set_direc_y : Þ—¿‚»‚Ì0
 * \param _arg_set_direc_x : Þ—¿‚»‚Ì1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			‚»‚Ì‘¼		-> ES_FREE 
 */
inline E_SIG SET_SIG (E_DIRECY _arg_set_direc_y, E_DIRECX _arg_set_direc_x);

/**
 * \brief _arg_turn_sig‚Ì³“]‹t“]‚ð”½“]‚³‚¹‚½‚à‚Ì‚ð•Ô‚·
 * 
 * \param _arg_turn_sig : Œ³
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG TURN_SIG_ROTATE (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sig‚ÌƒtƒŠ[AƒXƒgƒbƒv‚ð”½“]‚³‚¹‚½‚à‚Ì‚ð•Ô‚·
 * 
 * \param _arg_turn_sig : Œ³
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG TURN_SIG_FIX (E_SIG _arg_turn_sig);

/**
 * \brief PWM‚ð0‚É‚·‚×‚«‚©‚Ì”»’fBBOOL‚Å•Ô‚·
 * 
 * \param _arg_check_sig_mode : Šm”F‚·‚ésig
 * 
 * \return BOOL
 *	TRUE  -> ‚µ‚È‚­‚Ä‚¢‚¢
 *	FALES -> ‚µ‚æ‚¤
 */
inline BOOL CHECK_MOVE (E_SIG _arg_check_sig_mode);

/**
 * \brief sig‚É‚æ‚Á‚Ä•Ï‰»‚³‚¹‚½pwm‚ð•Ô‚·
 * 
 * \param _arg_check_sig_mode : Šm”F‚·‚ésig
 * \param _arg_check_pwm : Œ³pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> Œ³‚Ì‚Ü‚Ü
 */
inline T_PWM CHECK_MOVE (E_SIG _arg_check_sig_mode, T_PWM _arg_check_pwm);

#include "H28_NEW_MAIN_func_E_SIG.cpp"

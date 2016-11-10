
/*
	E_SIG‚ðˆµ‚¤‚½‚ß‚ÌŠÖ”ŒQB
*/

#pragma once

/**
 * \brief 
 *	BOOL‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_bool : Œ³
 * 
 * \return E_SIG
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALSE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool);

/**
 * \brief E_DIREC_Y‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_direc_y : Œ³
 * 
 * \return E_SIG
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALSE
 *	ED_YZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y);

/**
 * \brief E_DIREC_X‚©‚çÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_direc_x : Œ³
 * 
 * \return E_SIG
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALSE
 *	ED_XZERO -> ES_STOP
 */
inline E_SIG F_Func_sig (E_DIRECX _arg_direc_x);

/**
 * \brief 
 *	‚Ó‚½‚Â‚ÌBOOL‚ð‚à‚Æ‚ÉÝ’è‚µ‚½E_SIG‚ð•Ô‚·
 * 
 * \param _arg_bool_1 : Œ³1
 * \param _arg_bool_0 : Œ³0
 * 
 * \return E_SIG
 * 		 1   |   0   | Œ‹‰Ê
 *	   TRUE  | TRUE  | ES_STOP
 *	   FALES | TRUE  | ES_FALSE
 *	   TRUE  | FALES | ES_TRUE
 *	   FALES | FALES | ES_FREE
 */
inline E_SIG F_Func_sig (BOOL _arg_bool_1, BOOL _arg_bool_0);

/**
 * \brief 
 * E_DIREC_Y‚ÆE_DIREC_X‚ðˆ«–‚‡‘Ì‚³‚¹‚½E_SIG‚ð•Ô‚·
 * ƒƒJƒiƒ€‚Ì‚½‚ß‚Éì‚Á‚½‚æ‚¤‚È‚à‚Ì
 * 
 * \param _arg_direc_y : Þ—¿‚»‚Ì0
 * \param _arg_direc_x : Þ—¿‚»‚Ì1
 * 
 * \return E_SIG
 *		 NORTH |  EAST 	-> ES_FALSE
 *		 SOUTH |  WEST 	-> ES_TRUE
 *		 YZERO | XZERO	-> ES_STOP
 *			‚»‚Ì‘¼		-> ES_FREE 
 */
inline E_SIG F_Func_sig (E_DIRECY _arg_direc_y, E_DIRECX _arg_direc_x);

/**
 * \brief _arg_turn_sig‚Ì³“]‹t“]‚ð”½“]‚³‚¹‚½‚à‚Ì‚ð•Ô‚·
 * 
 * \param _arg_turn_sig : Œ³
 * 
 * \return E_SIG
 *	ES_TRUE  -> ES_FALSE
 *	ES_FALSE -> ES_TRUE
 */
inline E_SIG F_Turn_sig_rotate (E_SIG _arg_turn_sig);

/**
 * \brief _arg_turn_sig‚ÌƒtƒŠ[AƒXƒgƒbƒv‚ð”½“]‚³‚¹‚½‚à‚Ì‚ð•Ô‚·
 * 
 * \param _arg_turn_sig : Œ³
 * 
 * \return E_SIG
 *	ES_STOP -> ES_FREE
 *	ES_FREE -> ES_STOP
 */
inline E_SIG F_Turn_sig_fix (E_SIG _arg_turn_sig);

/**
 * \brief PWM‚ð0‚É‚·‚×‚«‚©‚Ì”»’fBBOOL‚Å•Ô‚·
 * 
 * \param _arg_check_sig : Šm”F‚·‚ésig
 * 
 * \return BOOL
 *	TRUE  -> ‚µ‚È‚­‚Ä‚¢‚¢
 *	FALES -> ‚µ‚æ‚¤
 */
inline BOOL F_Check_pwm (E_SIG _arg_check_sig);

/**
 * \brief sig‚É‚æ‚Á‚Ä•Ï‰»‚³‚¹‚½pwm‚ð•Ô‚·
 * 
 * \param _arg_check_sig : Šm”F‚·‚ésig
 * \param _arg_pwm : Œ³pwm
 * 
 * \return T_PWM
 *	ES_FREE,ES_STOP  -> pwm = 0
 *	ES_TRUE,ES_FALSE -> Œ³‚Ì‚Ü‚Ü
 */
inline T_PWM F_Check_pwm (E_SIG _arg_check_sig, T_PWM _arg_pwm);

#include "H28_NEW_MAIN_func_E_SIG.cpp"

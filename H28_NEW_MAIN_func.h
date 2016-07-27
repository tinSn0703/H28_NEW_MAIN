
#pragma once

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
inline 
T_PWM F_Set_pwm
(
	DIREC _arg_pwm_hl, 
	T_PWM &_arg_pwm, 
	BOOL &_arg_flag,
	BOOL _arg_pwm_recet = FALES
)
{
	if (_arg_pwm_recet)
	{
		_arg_pwm = PWM_NOR;
		
		return _arg_pwm;
	}
	
	switch (_arg_pwm_hl)
	{
		case NOREA:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x1f))
			{
				_arg_pwm++;
				
				_arg_flag = FALES;
			}
			
			break;
		}
		case SOUWE:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))
			{
				_arg_pwm--;
				
				_arg_flag = FALES;
			}
			
			break;
		}
		case ZERO:
		{
			_arg_flag = TRUE;
			
			break;
		}
	}
	
	return _arg_pwm;
}

/**
 * \brief : _arg_pwmを++,--する。 
 * 
 * \param _arg_nf_pwm_high : TRUEのとき_arg_pwmを++する
 * \param _arg_nf_pwm_low  : TRUEのとき_arg_pwmを--する
 * \param _arg_pwm  : 変更するPWM
 * \param _arg_flag : 連打防止。外部で作ってね。
 * \param _arg_pwm_recet : TRUEのとき_arg_pwmをPWM_NORにする。
 * 
 * \return T_PWM : ついで
 */
inline T_PWM 
F_Set_pwm
(
	BOOL _arg_nf_pwm_high, 
	BOOL _arg_nf_pwm_low, 
	T_PWM &_arg_pwm, 
	BOOL &_arg_flag, 
	BOOL _arg_pwm_recet = FALES
)
{
	if (_arg_pwm_recet)
	{
		_arg_pwm = PWM_NOR;
		
		return _arg_pwm;
	}
	
	if (_arg_nf_pwm_high)
	{
		if ((_arg_flag == TRUE) && (_arg_pwm != 0x1f))
		{
			_arg_pwm ++;
			
			_arg_flag = FALES;
		}
	}
	else if (_arg_nf_pwm_low)
	{
		if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))
		{
			_arg_pwm --;
			
			_arg_flag = FALES;
		}
	}
	else
	{
		_arg_flag = TRUE;
	}
	
	return _arg_pwm;
}

/**
 * \brief : 2輪を扱う関数。旋回のほうが優先。
 * 
 * \param _arg_motor : 要素数2の配列にしといてね
 * \param _arg_direc_move : 進む方向
 *
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALES
 *	ES_YZERO -> ES_STOP
 *
 * \param _arg_turn_0 : _arg_motor[0]を回転させる
 * \param _arg_turn_1 : _arg_motor[1]を回転させる
 * \param _arg_pwm : PWM
 * \param _arg_sig_turn_base : 旋回時の正逆転の設定。
 *	
 *	TRUE  -> ES_TRUE
 *	FALES -> ES_FALES
 */
inline void 
F_Set_wheel_2
(
	C_MD_MAIN _arg_motor[2], 
	E_DIRECY _arg_direc_move, 
	BOOL _arg_turn_0, 
	BOOL _arg_turn_1, 
	T_PWM _arg_pwm,
	BOOL _arg_sig_turn_base = TRUE
)
{
	E_SIG _sig_0 = ES_FREE;
	E_SIG _sig_1 = ES_FREE;
	
	if ((_arg_turn_0 | _arg_turn_1) == TRUE)
	{		
		const E_SIG _temp_sig = SET_SIG(_arg_sig_turn_base);
		
		if (_arg_turn_0)
		{
			_sig_0 = _temp_sig;
		}
		
		if (_arg_turn_1)
		{
			_sig_1 = _temp_sig;
		}
	}
	else
	{
		_sig_0 = SET_SIG(_arg_direc_move);
		_sig_1 = SET_SIG(_arg_direc_move);
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_1,_arg_pwm);
}

/**
 * \brief : 2輪を扱う関数。
 * 
 * \param _arg_motor : 要素数2の配列にしといてね
 * \param _arg_direc_move : 進む方向
 
 * \param _arg_pwm : PWM
 */
inline void 
F_Set_wheel_2
(
	C_MD_MAIN _arg_motor[2], 
	E_DIRECY _arg_direc_move,
	T_PWM _arg_pwm
)
{
	_arg_motor[0].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
	_arg_motor[1].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
}

/**
 * \brief 二輪の旋回。
 * 
 * \param _arg_motor : 旋回させるモータ。要素数は2
 * \param _arg_turn_0 : _arg_motor[0]を回転させる
 * \param _arg_turn_1 : _arg_motor[1]を回転させる
 * \param _arg_pwm : 設定するPWM
 * \param _arg_sig_turn_base : 旋回時の正逆転の設定
 */
inline void 
F_Set_wheel_turn_2
(
	C_MD_MAIN _arg_motor[2],
	BOOL _arg_turn_0,
	BOOL _arg_turn_1,
	T_PWM _arg_pwm,
	BOOL _arg_sig_turn_base = TRUE 
)
{
	E_SIG _sig_0 = ES_FREE;
	E_SIG _sig_1 = ES_FREE;
	
	const E_SIG _temp_sig = SET_SIG(_arg_sig_turn_base);
	
	if (_arg_turn_0)
	{
		_sig_0 = _temp_sig;
	}
	
	if (_arg_turn_1)
	{
		_sig_1 = _temp_sig;
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_1,_arg_pwm);
}

/**
 * \brief モーターを正逆転させる
 * これメンバでもいい気がしてきた
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_nf_true  : ES_TRUEにする
 * \param _arg_nf_fales : ES_FALESにする
 *
 *		true  | fales | 結果
 *		TRUE  | TRUE  | ES_STOP
 *		TRUE  | FALES | ES_TRUE
 *		FALES | TRUE  | ES_FALES
 *		FALES | FALES | ES_FREE
 *
 * \param _arg_pwm : 設定するPWM
 */
inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	BOOL _arg_nf_true, 
	BOOL _arg_nf_fales, 
	T_PWM _arg_pwm
)
{
	_arg_motor.Set_data(SET_SIG(_arg_nf_true,_arg_nf_fales),_arg_pwm);
}

/**
 * \brief モーターを正逆転させる
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_motor_tf : 方向キー y方向
 *
 *	ED_NORTH -> ES_TRUE
 *	ED_SOUTH -> ES_FALES
 *	ED_YZERO -> ES_STOP
 *
 * \param _arg_pwm : モーターのPWM
 */
inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	E_DIRECY _arg_motor_tf, 
	T_PWM _arg_pwm
)
{
	_arg_motor.Set_data(SET_SIG(_arg_motor_tf),_arg_pwm);
}

/**
 * \brief モーターを正逆転させる
 * 
 * \param _arg_motor : 設定するモータ
 * \param _arg_motor_tf : 方向キー x方向
 *
 *	ED_EAST  -> ES_TRUE
 *	ED_WEST  -> ES_FALES
 *	ED_XZERO -> ES_STOP
 *
 * \param _arg_pwm : モーターのPWM
 */
inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	E_DIRECX _arg_motor_tf, 
	T_PWM _arg_pwm
)
{
	_arg_motor.Set_data(SET_SIG(_arg_motor_tf),_arg_pwm);
}
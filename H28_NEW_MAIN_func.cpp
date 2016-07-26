
#pragma once

template <class DIREC>
inline 
T_PWM F_Set_pwm
(
	DIREC _arg_pwm_hl, 
	T_PWM &_arg_pwm, 
	BOOL &_arg_flag,
	BOOL _arg_pwm_recet = FALES
)
/*
_arg_pwmを++,--する

	_arg_pwm_hl : _arg_pwmを++するか--するか
		NORTH,EAST -> ++ 
		SOUTH,WEST -> --

	_arg_pwm : 変更するPWM
	_arg_flag : 連打防止。外部で作ってね。
	_arg_pwm_recet : _arg_pwmをPWM_NORにする。

	return : ついでの出力
 */
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

inline T_PWM 
F_Set_pwm
(
	BOOL _arg_nf_pwm_high, 
	BOOL _arg_nf_pwm_low, 
	T_PWM &_arg_pwm, 
	BOOL &_arg_flag, 
	BOOL _arg_pwm_recet = FALES
)
/*
_arg_pwmを++,--する。 

	_arg_pwm_high :	TRUEのとき_arg_pwmを++する
	_arg_pwm_high :	TRUEのとき_arg_pwmを--する
	_arg_pwm : 変更するPWM
	_arg_flag : 連打防止。外部で作ってね。
	_arg_pwm_recet : TRUEのとき_arg_pwmをPWM_NORにする。

	return : ついでの出力
 */
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

inline void 
F_Set_wheel_2
(
	C_MD_MAIN _arg_motor[2], 
	E_DIRECY _arg_direc_move, 
	BOOL _arg_turn_0, 
	BOOL _arg_turn_1, 
	T_PWM _arg_pwm
)
/*
2輪を扱う関数。旋回のほうが優先。

	_arg_motor[2] : 要素数2の配列にしといてね
	_arg_direc_move : 進む方向
	_arg_turn_0 : _arg_motor[0]をES_TRUEにする
	_arg_turn_1 : _arg_motor[1]をES_TRUEにする
	_arg_pwm : PWM
*/
{
	if ((_arg_turn_0 | _arg_turn_1) == TRUE)
	{
		E_SIG _sig_0 = ES_FREE;
		E_SIG _sig_1 = ES_FREE;
		
		if (_arg_turn_0)
		{
			_sig_0 = ES_TRUE;
		}
		
		if (_arg_turn_1)
		{
			_sig_1 = ES_TRUE;
		}
		
		_arg_motor[0].Set_data(_sig_0,_arg_pwm);
		_arg_motor[1].Set_data(_sig_1,_arg_pwm);
	}
	else
	{
		_arg_motor[0].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
		_arg_motor[1].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
	}
}

inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	BOOL _arg_nf_true, 
	BOOL _arg_nf_fales, 
	T_PWM _arg_pwm
)
/*

*/
{
	if (_arg_nf_true == TRUE)
	{
		_arg_motor.Set_data(ES_TRUE,_arg_pwm);
	}
	else if (_arg_nf_fales == TRUE)
	{
		_arg_motor.Set_data(ES_FALES,_arg_pwm);
	}
	else
	{
		_arg_motor.Set_data(ES_STOP);
	}
}

inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	E_DIRECY _arg_motor_tf, 
	T_PWM _arg_pwm
)
/*
モーターを正逆転させる

	_arg_motor : 設定するモータ
	_arg_motor_tf : 方向キー y方向
	
	ED_NORTH -> ES_TRUE
	ED_SOUTH -> ES_FALES
	ED_YZERO -> ES_STOP
	
	_arg_pwm : モーターのPWM
*/
{
	switch (_arg_motor_tf)
	{
		case ED_NORTH:	_arg_motor.Set_data(ES_TRUE,_arg_pwm);	break;
		case ED_SOUTH:	_arg_motor.Set_data(ES_FALES,_arg_pwm);	break;
		case ED_YZERO:	_arg_motor.Set_data(ES_STOP);			break;
	}
}

inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	E_DIRECX _arg_motor_tf, 
	T_PWM _arg_pwm
)
/*
モーターを正逆転させる

	_arg_motor : 設定するモータ
	_arg_motor_tf : 方向キー x方向
	
	ED_EAST  -> ES_TRUE
	ED_WEST  -> ES_FALES
	ED_XZERO -> ES_STOP
	
	_arg_pwm : モーターのPWM
*/
{
	switch (_arg_motor_tf)
	{
		case ED_EAST:	_arg_motor.Set_data(ES_TRUE,_arg_pwm);	break;
		case ED_WEST:	_arg_motor.Set_data(ES_FALES,_arg_pwm);	break;
		case ED_XZERO:	_arg_motor.Set_data(ES_STOP);			break;
	}
}
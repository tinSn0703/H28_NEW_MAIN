
#pragma once

/************************************************************************/
/*	宣言																*/
/************************************************************************/

/**
 * \brief
 * _arg_pwmを++か--する
 * 
 * \param _arg_pwm_hl : _arg_pwmを++するか--するか
 *		NORTH,EAST -> ++
 *		SOUTH,WEST -> --
 *
 * \param _arg_pwm  : 変更するPWM
 * \param _arg_flag : 連打防止。外部で作ってね。
 * 
 * \return T_PWM ついで
 */
template <class DIREC>
inline T_PWM F_Adju_pwm(const DIREC _arg_pwm_hl, T_PWM &_arg_pwm, BOOL &_arg_flag);

/**
 * \brief 
 * _arg_pwmを+、-する。幅は_arg_pwm_divi。
 * 
 * \param _arg_adju		: 値変更。変更幅は_arg_pwm_divi。ED_NORTHで+、ED_SOUTHで-。
 * \param _arg_pwm		: 値を変更する変数。
 * \param _arg_pwm_divi	: 値の変更幅
 * \param _arg_flag		: ボタンを押したときのフラグ。
 * 
 * \return T_PWM ついで
 */
inline T_PWM F_Adju_pwm(const E_DIRECY _arg_adju, T_PWM &_arg_pwm, const T_PWM _arg_pwm_divi, BOOL &_arg_flag);

/**
 * \brief
 * _arg_pwmを++,--する。 
 * 
 * \param _arg_nf_pwm_high : TRUEのとき_arg_pwmを++する
 * \param _arg_nf_pwm_low  : TRUEのとき_arg_pwmを--する
 * \param _arg_pwm  : 変更するPWM
 * \param _arg_flag : 連打防止。外部で作ってね。
 * 
 * \return T_PWM : ついで
 */
inline T_PWM F_Adju_pwm(const BOOL _arg_nf_pwm_high, const BOOL _arg_nf_pwm_low, T_PWM &_arg_pwm, BOOL &_arg_flag);

/************************************************************************/
/*	実装																*/
/************************************************************************/

template <class DIREC>
inline
T_PWM F_Adju_pwm
(
	const DIREC  _arg_pwm_hl,
	T_PWM		&_arg_pwm,
	const BOOL	&_arg_flag
)
{
	switch (_arg_pwm_hl)
	{
		case __NOREA__:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x1f))	_arg_pwm++;
			
			_arg_flag = FALSE;
			
			break;
		}
		case __SOUWE__:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))	_arg_pwm--;
			
			_arg_flag = FALSE;
			
			break;
		}
		case __ZERO__:
		{
			_arg_flag = TRUE;
			
			break;
		}
	}
	
	return _arg_pwm;
}

inline T_PWM
F_Adju_pwm
(
	const E_DIRECY	 _arg_adju,
	T_PWM			&_arg_pwm,
	const T_PWM		 _arg_pwm_divi,
	BOOL			&_arg_flag
)
{
	switch (_arg_adju)
	{
		case ED_NORTH:
		{
			if (_arg_flag)
			{
				if (31 < (_arg_pwm + _arg_pwm_divi))	_arg_pwm  = 31;
				else									_arg_pwm += _arg_pwm_divi;
				
				_arg_flag = FALSE;
			}
			
			break;
		}
		case ED_SOUTH:
		{
			if (_arg_flag)
			{
				if (0 > (_arg_pwm - _arg_pwm_divi))		_arg_pwm  = 0;
				else									_arg_pwm -= _arg_pwm_divi;
				
				_arg_flag = FALSE;
			}
			
			break;
		}
		case ED_YZERO:
		{
			_arg_flag = TRUE;
			
			break;
		}
	}
	
	return _arg_pwm;
}


inline T_PWM
F_Adju_pwm
(
	const BOOL	 _arg_nf_pwm_high,
	const BOOL	 _arg_nf_pwm_low,
	T_PWM		&_arg_pwm,
	BOOL		&_arg_flag
)
{
	if (_arg_nf_pwm_high)
	{
		if ((_arg_flag == TRUE) && (_arg_pwm != 0x1f))	_arg_pwm ++;
		
		_arg_flag = FALSE;
	}
	else if (_arg_nf_pwm_low)
	{
		if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))	_arg_pwm --;
		
		_arg_flag = FALSE;
	}
	else
	{
		_arg_flag = TRUE;
	}
	
	return _arg_pwm;
}

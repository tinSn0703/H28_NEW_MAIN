
#pragma once

/************************************************************************/
/*	�錾																*/
/************************************************************************/

/**
 * \brief
 * _arg_pwm��++��--����
 * 
 * \param _arg_pwm_hl : _arg_pwm��++���邩--���邩
 *		NORTH,EAST -> ++
 *		SOUTH,WEST -> --
 *
 * \param _arg_pwm  : �ύX����PWM
 * \param _arg_flag : �A�Ŗh�~�B�O���ō���ĂˁB
 * 
 * \return T_PWM ����
 */
template <class DIREC>
inline T_PWM F_Adju_pwm(const DIREC _arg_pwm_hl, T_PWM &_arg_pwm, BOOL &_arg_flag);

/**
 * \brief 
 * _arg_pwm��+�A-����B����_arg_pwm_divi�B
 * 
 * \param _arg_adju		: �l�ύX�B�ύX����_arg_pwm_divi�BED_NORTH��+�AED_SOUTH��-�B
 * \param _arg_pwm		: �l��ύX����ϐ��B
 * \param _arg_pwm_divi	: �l�̕ύX��
 * \param _arg_flag		: �{�^�����������Ƃ��̃t���O�B
 * 
 * \return T_PWM ����
 */
inline T_PWM F_Adju_pwm(const E_DIRECY _arg_adju, T_PWM &_arg_pwm, const T_PWM _arg_pwm_divi, BOOL &_arg_flag);

/**
 * \brief
 * _arg_pwm��++,--����B 
 * 
 * \param _arg_nf_pwm_high : TRUE�̂Ƃ�_arg_pwm��++����
 * \param _arg_nf_pwm_low  : TRUE�̂Ƃ�_arg_pwm��--����
 * \param _arg_pwm  : �ύX����PWM
 * \param _arg_flag : �A�Ŗh�~�B�O���ō���ĂˁB
 * 
 * \return T_PWM : ����
 */
inline T_PWM F_Adju_pwm(const BOOL _arg_nf_pwm_high, const BOOL _arg_nf_pwm_low, T_PWM &_arg_pwm, BOOL &_arg_flag);

/************************************************************************/
/*	����																*/
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

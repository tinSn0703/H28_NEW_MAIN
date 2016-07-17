
#ifndef _H28_NEW_MAIN_FUNC_CPP_
#define _H28_NEW_MAIN_FUNC_CPP_ 1

template <class DIREC>
inline T_PWM F_Set_pwm(DIREC _arg_pwm_hl, T_PWM &_arg_pwm, E_LOGIC &_arg_flag)
{
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

inline T_PWM F_Set_pwm(E_LOGIC _arg_nf_pwm_high, E_LOGIC _arg_nf_pwm_low, T_PWM &_arg_pwm, E_LOGIC &_arg_flag, E_LOGIC _arg_pwm_recet = FALES)
{
	if (_arg_pwm_recet)
	{
		_arg_pwm = PWM_NOR;
	}
	else
	{
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
	}
	
	return _arg_pwm;
}

inline void F_Set_wheel_2(C_MD_MAIN _arg_motor[2], E_DIRECY _arg_direc_move, E_LOGIC _arg_turn_right, E_LOGIC _arg_turn_left, T_PWM _arg_pwm)
{
	if ((_arg_turn_right | _arg_turn_left) == TRUE)
	{
		E_SIG _sig_0 = ES_FREE;
		E_SIG _sig_1 = ES_FREE;
		
		if (_arg_turn_right)
		{
			_sig_0 = ES_TRUE;
		}
		
		if (_arg_turn_left)
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

inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, E_LOGIC _arg_nf_true, E_LOGIC _arg_nf_fales, T_PWM _arg_pwm)
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

template <class DIREC>
inline void F_Set_motor_tf_1(C_MD_MAIN &_arg_motor, DIREC _arg_motor_tf, T_PWM _arg_pwm)
{
	switch (_arg_motor_tf)
	{
		case NOREA:	_arg_motor.Set_data(ES_TRUE,_arg_pwm);	break;
		case SOUWE:	_arg_motor.Set_data(ES_FALES,_arg_pwm);	break;
		case ZERO:	_arg_motor.Set_data(ES_STOP);			break;
	}
}

#endif
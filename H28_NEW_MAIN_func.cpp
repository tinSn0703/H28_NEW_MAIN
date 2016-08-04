

#pragma once

#include "H28_NEW_MAIN_func.h"

template <class DIREC>
inline 
T_PWM F_Set_pwm
(
	DIREC _arg_pwm_hl, 
	T_PWM &_arg_pwm, 
	BOOL &_arg_flag,
	BOOL _arg_pwm_recet = FALSE
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
				
				_arg_flag = FALSE;
			}
			
			break;
		}
		case SOUWE:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))
			{
				_arg_pwm--;
				
				_arg_flag = FALSE;
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
	BOOL _arg_pwm_recet = FALSE
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
			
			_arg_flag = FALSE;
		}
	}
	else if (_arg_nf_pwm_low)
	{
		if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))
		{
			_arg_pwm --;
			
			_arg_flag = FALSE;
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
	T_PWM _arg_pwm
)
{
	_arg_motor[0].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
	_arg_motor[1].Set_data(SET_SIG(_arg_direc_move),_arg_pwm);
}

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
	const E_SIG _temp_sig = SET_SIG(_arg_sig_turn_base);
	
	if (_arg_turn_0)
	{
		_arg_motor[0].Set_data(_temp_sig,_arg_pwm);
		_arg_motor[1].Set_data(  ES_STOP,_arg_pwm);
	}
	
	if (_arg_turn_1)
	{
		_arg_motor[0].Set_data(  ES_STOP,_arg_pwm);
		_arg_motor[1].Set_data(_temp_sig,_arg_pwm);
	}
}

inline void 
F_Set_wheel_pivot_turn_2
(
	C_MD_MAIN _arg_motor[2],
	BOOL _arg_turn_0,
	BOOL _arg_turn_1,
	T_PWM _arg_pwm,
	BOOL _arg_sig_turn_base = TRUE
)
{
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	const E_SIG _temp_sig = SET_SIG(_arg_sig_turn_base);
	
	if (_arg_turn_0)
	{
		_sig_0 = _temp_sig;
		_sig_1 = TURN_SIG_ROTATE(_temp_sig);
	}
	
	if (_arg_turn_1)
	{
		_sig_1 = _temp_sig;
		_sig_0 = TURN_SIG_ROTATE(_temp_sig);
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_1,_arg_pwm);
}

inline void 
F_Set_mekanam_4
(
	C_MD_MAIN _arg_motor[4], 
	E_DIRECX _arg_direc_x, 
	E_DIRECY _arg_direc_y, 
	T_PWM _arg_pwm 
)
{
	_arg_motor[0].Set_data(	SET_SIG( TURN_DIREC_Y(_arg_direc_y),				 _arg_direc_x),  _arg_pwm);
	_arg_motor[1].Set_data(	SET_SIG( TURN_DIREC_Y(_arg_direc_y),	TURN_DIREC_X(_arg_direc_x)), _arg_pwm);
	_arg_motor[2].Set_data(	SET_SIG( TURN_DIREC_Y(_arg_direc_y),				 _arg_direc_x),	 _arg_pwm);
	_arg_motor[3].Set_data(	SET_SIG( TURN_DIREC_Y(_arg_direc_y),	TURN_DIREC_X(_arg_direc_x)), _arg_pwm);
}

inline void 
F_Set_motor_tf_1
(
	C_MD_MAIN &_arg_motor, 
	BOOL _arg_nf_true, 
	BOOL _arg_nf_fales, 
	T_PWM _arg_pwm
)
{
	E_SIG _temp_sig = ES_STOP;
	
	if (_arg_nf_true)
	{
		_temp_sig = ES_TRUE;
	}
	else if (_arg_nf_fales)
	{
		_temp_sig = ES_FALSE;
	}
	
	_arg_motor.Set_data(_temp_sig,_arg_pwm);
}

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

inline void
F_Set_tf
(
	BOOL  _arg_set_tf,
	BOOL &_arg_nf,
	BOOL &_arg_flag
)
{
	if (_arg_set_tf)
	{
		if (_arg_flag)
		{
			BOOL _temp_nf = _arg_nf;
			
			_arg_nf = TURN_TF(_temp_nf);
		}
		
		_arg_flag = FALSE;
	}
	else
	{
		_arg_flag = TRUE;
	}
}

inline void 
F_Set_count
(
	BOOL  _arg_set_high,
	BOOL  _arg_set_low,
	BOOL &_arg_flag,
)
{
	if (_arg_set_high | _arg_set_low)
	{
		if (_arg_set_high & _arg_flag)
		{
			_arg_count ++;
		}
		else if (_arg_set_low & _arg_flag)
		{
			_arg_count --;
		}
		
		_arg_flag = FALSE;
	}
	else
	{
		_arg_flag = TRUE;
	}
};

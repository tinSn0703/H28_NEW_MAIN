

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
		case __NOREA__:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x1f))
			{
				_arg_pwm++;
				
				_arg_flag = FALSE;
			}
			
			break;
		}
		case __SOUWE__:
		{
			if ((_arg_flag == TRUE) && (_arg_pwm != 0x00))
			{
				_arg_pwm--;
				
				_arg_flag = FALSE;
			}
			
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
F_Set_mekanamuni_turn_3
(
	C_MD_MAIN _arg_motor[3], 
	BOOL _arg_turn_left, 
	BOOL _arg_turn_right, 
	T_PWM _arg_pwm
)
{	
	if (_arg_turn_left)
	{
		_arg_motor[0].Set_data( ES_TRUE,_arg_pwm);
		_arg_motor[1].Set_data( ES_TRUE,_arg_pwm);
		_arg_motor[2].Set_data( ES_STOP,_arg_pwm);
	}
	else if (_arg_turn_right)
	{
		_arg_motor[0].Set_data(ES_FALSE,_arg_pwm);
		_arg_motor[1].Set_data( ES_STOP,_arg_pwm);
		_arg_motor[2].Set_data( ES_TRUE,_arg_pwm);
	}
}

inline void
F_Set_wheel_turn_4
(
	C_MD_MAIN _arg_motor[4],
	BOOL _arg_turn_0,
	BOOL _arg_turn_1,
	T_PWM _arg_pwm
)
{
	E_SIG _sig_0 = ES_TRUE;
	E_SIG _sig_1 = ES_TRUE;
	
	if (_arg_turn_0)
	{
		_sig_1 = ES_FALSE;
	}
	
	if (_arg_turn_1)
	{
		_sig_0 = ES_FALSE;
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_0,_arg_pwm);
	_arg_motor[2].Set_data(_sig_1,_arg_pwm);
	_arg_motor[3].Set_data(_sig_1,_arg_pwm);
}


inline void 
F_Set_mekanamuni_pivot_turn_3
(
	C_MD_MAIN _arg_motor[3], 
	BOOL _arg_turn_left, 
	BOOL _arg_turn_right, 
	T_PWM _arg_pwm
)
{	
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	if (_arg_turn_left)
	{
		_sig_0 = ES_TRUE;
		_sig_1 = ES_FALSE;
		
	}
	else if (_arg_turn_right)
	{
		_sig_0 = ES_FALSE;
		_sig_1 = ES_TRUE;
	}
	
	_arg_motor[0].Set_data(_sig_0,_arg_pwm);
	_arg_motor[1].Set_data(_sig_0,_arg_pwm);
	_arg_motor[2].Set_data(_sig_1,_arg_pwm);
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
F_Set_mekanamuni_3
(
	C_MD_MAIN _arg_motor[3],
	E_DIRECX _arg_direc_x,
	E_DIRECY _arg_direc_y,
	T_PWM _arg_pwm
)
{
	E_SIG _temp_sig_c = ES_STOP;
	E_SIG _temp_sig_l = ES_STOP;
	E_SIG _temp_sig_r = ES_STOP;
	
	switch (_arg_direc_y)
	{
		case ED_NORTH:
		{
			_temp_sig_l = ES_TRUE;
			_temp_sig_r = ES_TRUE;
		}
		break;
		case ED_SOUTH:
		{
			_temp_sig_l = ES_FALSE;
			_temp_sig_r = ES_FALSE;
		}
		break;
		case ED_YZERO:
		{
			switch (_arg_direc_x)
			{
				case ED_EAST:
				{
					_arg_motor[0].Set_pwm_revis(_arg_pwm * 0.4);
							
					_temp_sig_c = ES_FALSE;
					_temp_sig_l = ES_TRUE;
					_temp_sig_r = ES_FALSE;
				}
				break;
				case ED_WEST:
				{
					_arg_motor[0].Set_pwm_revis(_arg_pwm * 0.4);
									
					_temp_sig_c = ES_TRUE;
					_temp_sig_l = ES_FALSE;
					_temp_sig_r = ES_TRUE;
				}
				break;
				case ED_XZERO:
				break;
			}
		}
		break;
	}
	
	_arg_motor[0].Set_data(_temp_sig_c,_arg_pwm,FALSE);
	_arg_motor[1].Set_data(_temp_sig_l,_arg_pwm,FALSE);
	_arg_motor[2].Set_data(_temp_sig_r,_arg_pwm,FALSE);
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
	C_COUNT_u1 &_arg_count
)
{
	if (_arg_set_high | _arg_set_low)
	{
		if (_arg_set_high & _arg_count.Ret_flag())
		{
			_arg_count ++;
		}
		else if (_arg_set_low & _arg_count.Ret_flag())
		{
			_arg_count --;
		}
		
		_arg_count.Flag_down();
	}
	else
	{
		_arg_count.Flag_up();
	}
};

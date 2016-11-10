
#pragma once

template <class DIREC>
inline 
T_PWM F_Adju_pwm
(
	const DIREC  _arg_pwm_hl, 
	T_PWM		&_arg_pwm, 
	const BOOL	&_arg_flag,
	const BOOL	 _arg_pwm_recet = FALSE,
	const T_PWM  _arg_pwm_nor = PWM_NOR
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
	
	if (_arg_pwm_recet)	_arg_pwm = _arg_pwm_nor;
	
	return _arg_pwm;
}

inline T_PWM 
F_Adju_pwm
(
	const BOOL	 _arg_nf_pwm_high, 
	const BOOL	 _arg_nf_pwm_low, 
	T_PWM		&_arg_pwm, 
	BOOL		&_arg_flag, 
	const BOOL	 _arg_pwm_recet = FALSE,
	const T_PWM  _arg_pwm_nor = PWM_NOR
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
	
	if (_arg_pwm_recet)	_arg_pwm = _arg_pwm_nor;
	
	return _arg_pwm;
}

inline void 
F_Do_mowheeel_turn_3
(
	C_MD_MAIN	_arg_motor[3], 
	const BOOL	_arg_turn_left, 
	const BOOL	_arg_turn_right, 
	const T_PWM _arg_pwm
)
{	
	if (_arg_turn_left)
	{
		_arg_motor[0].Write_data( ES_TRUE,_arg_pwm);
		_arg_motor[1].Write_data( ES_TRUE,_arg_pwm);
		_arg_motor[2].Write_data( ES_STOP,_arg_pwm);
	}
	else if (_arg_turn_right)
	{
		_arg_motor[0].Write_data(ES_FALSE,_arg_pwm);
		_arg_motor[1].Write_data( ES_STOP,_arg_pwm);
		_arg_motor[2].Write_data( ES_TRUE,_arg_pwm);
	}
}

inline void
F_Do_wheel_turn_4
(
	C_MD_MAIN	_arg_motor[4],
	const BOOL	_arg_turn_0,
	const BOOL	_arg_turn_1,
	const T_PWM _arg_pwm
)
{
	E_SIG _sig = ES_STOP;
	
	if (_arg_turn_1)	_sig = ES_TRUE;	
	if (_arg_turn_0)	_sig = ES_FALSE;
	
	_arg_motor[0].Write_data(_sig,_arg_pwm);
	_arg_motor[1].Write_data(_sig,_arg_pwm);
	_arg_motor[2].Write_data(_sig,_arg_pwm);
	_arg_motor[3].Write_data(_sig,_arg_pwm);
}


inline void 
F_Do_mowheel_p_turn_3
(
	C_MD_MAIN	_arg_motor[3], 
	const BOOL	_arg_turn_left, 
	const BOOL	_arg_turn_right, 
	const T_PWM _arg_pwm
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
	
	_arg_motor[0].Write_data(_sig_0,_arg_pwm);
	_arg_motor[1].Write_data(_sig_0,_arg_pwm);
	_arg_motor[2].Write_data(_sig_1,_arg_pwm);
}

inline void 
F_Do_mwheel_4
(
	C_MD_MAIN		_arg_motor[4], 
	const E_DIRECX	_arg_direc_x, 
	const E_DIRECY	_arg_direc_y, 
	const T_PWM		_arg_pwm 
)
{
	E_SIG _temp_sig[4] = {};
	
	switch (_arg_direc_x)
	{
		case ED_WEST:
		{
			_temp_sig[__MEKANAMU_RI_FR__] = ES_TRUE;
			_temp_sig[__MEKANAMU_RI_BA__] = ES_FALSE;
			_temp_sig[__MEKANAMU_LE_FR__] = ES_TRUE;
			_temp_sig[__MEKANAMU_LE_BA__] = ES_FALSE;
			
			break;
		}
		case ED_EAST:
		{
			_temp_sig[__MEKANAMU_RI_FR__] = ES_FALSE;
			_temp_sig[__MEKANAMU_RI_BA__] = ES_TRUE;
			_temp_sig[__MEKANAMU_LE_FR__] = ES_FALSE;
			_temp_sig[__MEKANAMU_LE_BA__] = ES_TRUE;
		
			break;
		}
		case ED_XZERO:
		{
			switch (_arg_direc_y)
			{
				case ED_NORTH:
				{
					_temp_sig[__MEKANAMU_RI_FR__] = ES_TRUE;
					_temp_sig[__MEKANAMU_RI_BA__] = ES_TRUE;
					_temp_sig[__MEKANAMU_LE_FR__] = ES_FALSE;
					_temp_sig[__MEKANAMU_LE_BA__] = ES_FALSE;
				
					break;
				}
				case ED_SOUTH:
				{
					_temp_sig[__MEKANAMU_RI_FR__] = ES_FALSE;
					_temp_sig[__MEKANAMU_RI_BA__] = ES_FALSE;
					_temp_sig[__MEKANAMU_LE_FR__] = ES_TRUE;
					_temp_sig[__MEKANAMU_LE_BA__] = ES_TRUE;
				
					break;
				}
				case ED_YZERO:
				{
					_temp_sig[__MEKANAMU_RI_FR__] = ES_STOP;
					_temp_sig[__MEKANAMU_RI_BA__] = ES_STOP;
					_temp_sig[__MEKANAMU_LE_FR__] = ES_STOP;
					_temp_sig[__MEKANAMU_LE_BA__] = ES_STOP;
				
					break;
				}
			}
			
			break;
		}
	}
	
 	for (usint i = 0; i < 4; i ++)	_arg_motor[i].Write_data(_temp_sig[i], _arg_pwm);
}

inline void
F_Do_mowheel_3
(
	C_MD_MAIN		_arg_motor[3],
	const E_DIRECX	_arg_direc_x,
	const E_DIRECY	_arg_direc_y,
	const T_PWM		_arg_pwm
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
		
			break;
		}
		case ED_SOUTH:
		{
			_temp_sig_l = ES_FALSE;
			_temp_sig_r = ES_FALSE;
			
			break;
		}
		case ED_YZERO:
		{
			switch (_arg_direc_x)
			{
				case ED_EAST:
				{
					_arg_motor[0].Write_pwm_revis(_arg_pwm * __MULTIPLE_OMUNI__);
							
					_temp_sig_c = ES_FALSE;
					_temp_sig_l = ES_TRUE;
					_temp_sig_r = ES_FALSE;
					
					break;
				}
				case ED_WEST:
				{
					_arg_motor[0].Write_pwm_revis(_arg_pwm * __MULTIPLE_OMUNI__);
									
					_temp_sig_c = ES_TRUE;
					_temp_sig_l = ES_FALSE;
					_temp_sig_r = ES_TRUE;
					
					break;
				}
				case ED_XZERO:	break;
			}
			
			break;
		}
	}
	
	_arg_motor[0].Write_data(_temp_sig_c, _arg_pwm);
	_arg_motor[1].Write_data(_temp_sig_l, _arg_pwm);
	_arg_motor[2].Write_data(_temp_sig_r, _arg_pwm);
	
//	_arg_motor[0].Set_data(_temp_sig_c,_arg_pwm,FALSE);
//	_arg_motor[1].Set_data(_temp_sig_l,_arg_pwm,FALSE);
//	_arg_motor[2].Set_data(_temp_sig_r,_arg_pwm,FALSE);
}

inline void 
F_Do_motor_tf_1
(
	C_MD_MAIN	&_arg_motor, 
	const BOOL	 _arg_nf_true, 
	const BOOL	 _arg_nf_fales, 
	const T_PWM  _arg_pwm
)
{
	E_SIG _temp_sig = ES_STOP;
	
	if (_arg_nf_true)			_temp_sig = ES_TRUE;
	else if (_arg_nf_fales)		_temp_sig = ES_FALSE;
	
	_arg_motor.Write_data(_temp_sig,_arg_pwm);
}

inline void 
F_Do_motor_tf_1
(
	C_MD_MAIN	&_arg_motor,
	const BOOL	 _arg_nf,
	BOOL		&_arg_flag_nf,
	const E_SIG  _arg_base,
	const T_PWM  _arg_pwm
)
{
	if (_arg_nf & _arg_flag_nf)
	{
		if (_arg_motor.Ret_sig() == ES_STOP)	_arg_motor.Write_data(_arg_base,_arg_pwm);
		else									_arg_motor.Write_data(ES_STOP,0);
	}
	
	_arg_flag_nf = ~_arg_nf;	
}

inline void 
F_Do_motor_tf_1
(
	C_MD_MAIN		&_arg_motor, 
	const E_DIRECY	 _arg_motor_tf, 
	const T_PWM		 _arg_pwm
)
{
	_arg_motor.Write_data(F_Func_sig(_arg_motor_tf), _arg_pwm);
}

inline void 
F_Do_motor_tf_1
(
	C_MD_MAIN		&_arg_motor, 
	const E_DIRECX	 _arg_motor_tf, 
	const T_PWM		 _arg_pwm
)
{
	_arg_motor.Write_data(F_Func_sig(_arg_motor_tf), _arg_pwm);
}

inline void 
F_Do_count
(
	const BOOL  _arg_set_high,
	const BOOL  _arg_set_low,
	C_COUNT_u1 &_arg_count
)
{
	if (_arg_set_high | _arg_set_low)
	{
		if (_arg_set_high & _arg_count.Ret_flag())		_arg_count ++;
		else if (_arg_set_low & _arg_count.Ret_flag())	_arg_count --;
		
		_arg_count.Flag_down();
	}
	else
	{
		_arg_count.Flag_up();
	}
};

inline void 
F_Start_count
(
	const BOOL	 _arg_nf_start,
	BOOL		&_arg_flag_nf_start,
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_nf_start & _arg_flag_nf_start & ~_arg_count.Ret_flag())
	{
		_arg_count.Min();
		_arg_count.Flag_up();
	}
	
	_arg_flag_nf_start = ~_arg_nf_start;
}

inline void 
F_Nf_count
(
	const BOOL	 _arg_nf_count_start,
	BOOL		&_arg_nf,
	BOOL		&_arg_flag,
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_nf_count_start)
	{
		if (_arg_flag & ~_arg_count.Ret_flag())
		{
			_arg_count.Min();
			_arg_count.Flag_up();
		}
	}
	
	if (_arg_count.Comp_max() & _arg_count.Ret_flag())
	{
		_arg_count.Flag_down();
		
		_arg_nf = ~_arg_nf;
	}
	
	_arg_flag = ~_arg_nf_count_start;
}

inline void 
F_Nf_count
(
	const uchar  _arg_comp,
	BOOL		&_arg_nf,
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_count.Comp(_arg_comp) & _arg_count.Ret_flag())
	{
		_arg_nf = ~_arg_nf;
		
		_arg_count ++;
	}
}

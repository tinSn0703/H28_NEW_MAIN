
#pragma once

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
	
	_arg_motor[0].Write_data(_sig, _arg_pwm);
	_arg_motor[1].Write_data(_sig, _arg_pwm);
	_arg_motor[2].Write_data(_sig, _arg_pwm);
	_arg_motor[3].Write_data(_sig, _arg_pwm);
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
F_Do_wheel_4 
(
	C_MD_MAIN		_arg_motor[4], 
	const E_DIRECY	_arg_direc, 
	const T_PWM		_arg_pwm,
	const BOOL		_arg_nf_turn = FALSE
)
{
	const E_DIRECY _direc = (_arg_nf_turn ? F_Turn_direc_y(_arg_direc) : _arg_direc);
	
	_arg_motor[__WHEEL_RI_FR__].Write_data( F_Func_sig(					_direc ), _arg_pwm);
	_arg_motor[__WHEEL_LE_FR__].Write_data(	F_Func_sig(	F_Turn_direc_y(	_direc)), _arg_pwm);
	_arg_motor[__WHEEL_LE_BA__].Write_data( F_Func_sig(	F_Turn_direc_y(	_direc)), _arg_pwm);
	_arg_motor[__WHEEL_RI_BA__].Write_data(	F_Func_sig(					_direc ), _arg_pwm);
}

inline void 
F_Do_mwheel_4
(
	C_MD_MAIN		_arg_motor[4], 
	const E_DIRECX	_arg_direc_x, 
	const E_DIRECY	_arg_direc_y, 
	const T_PWM		_arg_pwm,
	const BOOL		_arg_nf_turn_x = FALSE,
	const BOOL		_arg_nf_turn_y = FALSE
)
{
	const E_DIRECX _direc_x = (_arg_nf_turn_x ? F_Turn_direc_x(_arg_direc_x) : _arg_direc_x);
	const E_DIRECY _direc_y = (_arg_nf_turn_y ? F_Turn_direc_y(_arg_direc_y) : _arg_direc_y);
	
	E_SIG _temp_sig[4] = {};
	
	_temp_sig[__WHEEL_RI_FR__] = F_Func_sig(	F_Turn_direc_y(	_direc_y),					_direc_x	);
	_temp_sig[__WHEEL_LE_FR__] = F_Func_sig(					_direc_y ,					_direc_x 	);
	_temp_sig[__WHEEL_LE_BA__] = F_Func_sig(					_direc_y ,	F_Turn_direc_x(	_direc_x)	);
	_temp_sig[__WHEEL_RI_BA__] = F_Func_sig(	F_Turn_direc_y(	_direc_y),	F_Turn_direc_x(	_direc_x)	);
	
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

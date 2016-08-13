
#pragma once

/*
H28 05 04 現在のMDのデータをまとめた構造体
PWM 0x1f 段階 , 段々制御有
ver 0.0.0 H28 05 04
ver 1.0.0 H28 05 24 共用体と構造体を活用してみました
*/

#include "H28_C_MD_MAIN.h"

inline 
C_MD_MAIN::
C_MD_MAIN
(
	usint _arg_num_mdc, 
	usint _arg_num_md ,
	BOOL _arg_nf_sig_turn = FALSE ,
	sint _arg_pwm_revis = 0
)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_num_mdc = _arg_num_mdc;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_mdc = _arg_num_mdc;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_num_md = _arg_num_md;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_md = _arg_num_md;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_num_data = MD_DATA_NUM_0;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_data = MD_DATA_NUM_1;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_without = 0;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode = ES_STOP;
	
	_mem_md_main_pwm_revis = _arg_pwm_revis;
	
	_mem_md_main_nf_sig_turn = _arg_nf_sig_turn;
}

inline void 
C_MD_MAIN::
Chan_md (usint  _arg_num_md)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_num_md = _arg_num_md;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_md = _arg_num_md;
}

inline void 
C_MD_MAIN :: 
Chan_turn ()
{
	_mem_md_main_nf_sig_turn = TURN_TF(_mem_md_main_nf_sig_turn);
}

inline void 
C_MD_MAIN::
Set_turn (BOOL _arg_nf_sig_turn)
{
	_mem_md_main_nf_sig_turn = _arg_nf_sig_turn;
}

inline void 
C_MD_MAIN::
Set_pwm (T_PWM _arg_pwm_value)
{
	if (_arg_pwm_value != 0)
	{
		_arg_pwm_value += _mem_md_main_pwm_revis;
	}
	
	if (_arg_pwm_value > 31)
	{
		_arg_pwm_value = 31;
	}
	
	_mem_md_main_data_1._md_1_data_bit._md_1_pwm_value = _arg_pwm_value;
}

inline void 
C_MD_MAIN::
Set_sig (E_SIG _arg_sig_mode)
{
	if (CHECK_MOVE(_arg_sig_mode) == FALSE)
	{
		_mem_md_main_data_1._md_1_data_bit._md_1_pwm_value = 0;
	}
	
	if (_mem_md_main_nf_sig_turn)
	{
		_arg_sig_mode = TURN_SIG_ROTATE(_arg_sig_mode);
	}
	
	
	_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode = _arg_sig_mode;
}

inline void 
C_MD_MAIN::
Set_steps (BOOL _arg_nf_steps = TRUE)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_nf_steps = _arg_nf_steps;
}

inline void 
C_MD_MAIN::
Set_pwm_revis (sint _arg_pwm_revis)
{
	if ((-31 <= _arg_pwm_revis) && (_arg_pwm_revis <= 30) )
	{
		_mem_md_main_pwm_revis = _arg_pwm_revis;
	}
}

inline void 
C_MD_MAIN::
Set_data
(
	E_SIG _arg_sig_mode, 
	T_PWM _arg_pwm_value = 0, 
	BOOL _arg_nf_steps = TRUE
)
{
	Set_pwm(_arg_pwm_value);
	Set_sig(_arg_sig_mode);
	Set_steps(_arg_nf_steps);
}

void 
C_MD_MAIN::
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_on();
	
	_arg_uart_t << _mem_md_main_data_0._md_0_data;
	_arg_uart_t << _mem_md_main_data_1._md_1_data;
	
	_delay_us(250);
}

void 
C_MD_MAIN::
Lcd_sig_num (T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs,_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode,1,ED_10);
}

void 
C_MD_MAIN::
Lcd_sig_str (T_ADRS _arg_adrs)
{
	switch (_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode)
	{
		case ES_TRUE:	Lcd_put_str(_arg_adrs,"TR");	break;
		case ES_FALSE:	Lcd_put_str(_arg_adrs,"FA");	break;
		case ES_STOP:	Lcd_put_str(_arg_adrs,"ST");	break;
		case ES_FREE:	Lcd_put_str(_arg_adrs,"FR");	break;
	}
}

void 
C_MD_MAIN::
Lcd_pwm
(
	T_ADRS _arg_adrs,
	E_DECIMAL _arg_decimal
)
{
	if ((_arg_decimal != ED_10) && (_arg_decimal != ED_16))
	{
		Lcd_put_str(_arg_adrs,"ERROR");
		return (void)0;
	}
	
	Lcd_put_num(_arg_adrs, _mem_md_main_data_1._md_1_data_bit._md_1_pwm_value, 2, _arg_decimal);
}

void 
C_MD_MAIN::
Lcd_data_2
(
	T_ADRS _arg_adrs,
	usint _arg_num_data
)
{
	switch (_arg_num_data)
	{
		case 0:		
		{
			Lcd_put_num(_arg_adrs,_mem_md_main_data_0._md_0_data,9,ED_02);
			break;
		}
		case 1:
		{
			Lcd_put_num(_arg_adrs,_mem_md_main_data_1._md_1_data,9,ED_02);
			break;
		}
		default:
		{
			Lcd_put_str(_arg_adrs,"ERROR");
			break;
		}
	}
}

void 
C_MD_MAIN::
Lcd_data_16
(
	T_ADRS _arg_adrs,
	usint _arg_num_data
)
{
	switch (_arg_num_data)
	{
		case 0:
		{
			Lcd_put_num(_arg_adrs, _mem_md_main_data_0._md_0_data, 3, ED_16);
			break;
		}
		case 1:
		{
			Lcd_put_num(_arg_adrs, _mem_md_main_data_1._md_1_data, 3, ED_16);
			break;
		}
		default:
		{
			Lcd_put_str(_arg_adrs, "ERROR");
			break;
		}
	}
}

void 
C_MD_MAIN::
Lcd_md_num (T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs, _mem_md_main_data_0._md_0_data_bit._md_0_num_md, 1, ED_10);
}
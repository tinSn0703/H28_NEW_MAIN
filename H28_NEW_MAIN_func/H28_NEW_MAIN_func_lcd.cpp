
#pragma once

#include "H28_NEW_MAIN_func_lcd.h"

inline void 
F_Lcd_mdc_sig 
(
	usint _arg_num_mdc, 
	C_MD_MAIN &_arg_md_0
)
{
	Lcd_put_str(0x40, "M S             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_sig_str(0x45);
}

inline void 
F_Lcd_mdc_sig
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1
)
{
	Lcd_put_str(0x40, "M S             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_sig_str(0x45);
	_arg_md_1.Lcd_sig_str(0x48);
}

inline void 
F_Lcd_mdc_sig
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1, 
	C_MD_MAIN &_arg_md_2
)
{
	Lcd_put_str(0x40, "M S             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_sig_str(0x45);
	_arg_md_1.Lcd_sig_str(0x48);
	_arg_md_2.Lcd_sig_str(0x4b);
}

inline void 
F_Lcd_mdc_sig
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1, 
	C_MD_MAIN &_arg_md_2, 
	C_MD_MAIN &_arg_md_3
)
{
	Lcd_put_str(0x40, "M S             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_sig_str(0x45);
	_arg_md_1.Lcd_sig_str(0x48);
	_arg_md_2.Lcd_sig_str(0x4b);
	_arg_md_3.Lcd_sig_str(0x4e);
}

inline void 
F_Lcd_mdc_pwm 
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0
)
{
	Lcd_put_str(0x40, "M P             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_pwm(0x45, ED_10);
}

inline void 
F_Lcd_mdc_pwm
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1
)
{
	Lcd_put_str(0x40, "M P             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_pwm(0x45, ED_10);
	_arg_md_1.Lcd_pwm(0x48, ED_10);
}

inline void 
F_Lcd_mdc_pwm
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1, 
	C_MD_MAIN &_arg_md_2
)
{
	Lcd_put_str(0x40, "M P             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_pwm(0x45, ED_10);
	_arg_md_1.Lcd_pwm(0x48, ED_10);
	_arg_md_2.Lcd_pwm(0x4b, ED_10);
}

inline void 
F_Lcd_mdc_pwm
(
	usint _arg_num_mdc,
	C_MD_MAIN &_arg_md_0, 
	C_MD_MAIN &_arg_md_1, 
	C_MD_MAIN &_arg_md_2, 
	C_MD_MAIN &_arg_md_3
)
{
	Lcd_put_str(0x40, "M P             ");
	
	Lcd_put_num(0x41, _arg_num_mdc, 1, ED_10);
	
	_arg_md_0.Lcd_pwm(0x45, ED_10);
	_arg_md_1.Lcd_pwm(0x48, ED_10);
	_arg_md_2.Lcd_pwm(0x4b, ED_10);
	_arg_md_3.Lcd_pwm(0x4e, ED_10);
}

inline void 
F_Lcd_air
(
	usint _arg_num_air, 
	C_AIR &_arg_air
)
{
	Lcd_put_str(0x40, "AIR             ");
	
	Lcd_put_num(0x43, _arg_num_air, 1, ED_10);
	
	_arg_air.Lcd_2(0x45);
}
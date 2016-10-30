
#pragma once

#include "H28_C_CONTR_Wii.h"

//public
inline 
C_CONTR_Wii ::
C_CONTR_Wii(BOOL _arg_nf_overwrite = FALSE)
{
	Init();
	
	_mem_contr_wii_nf_overwrite = _arg_nf_overwrite;
}

void 
C_CONTR_Wii ::
In (C_UART_R &_arg_uart_r)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {0x3f,0x7f,0x8f,0xc0};
	
	C_CONTR::In(_arg_uart_r, _temp_data);
	
	_mem_contr_wii_data.Write(_temp_data);
}

void 
C_CONTR_Wii ::
In (C_UART_R2 &_arg_uart_r2)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {0x3f,0x7f,0x8f,0xc0};
	
	C_CONTR::In(_arg_uart_r2,_temp_data);
	
	_mem_contr_wii_data.Write(_temp_data);
}

inline void 
C_CONTR_Wii :: 
Init()
{
	_mem_contr_wii_data._arr_data_byte[0] = 0xff;
	_mem_contr_wii_data._arr_data_byte[1] = 0x0f;
	_mem_contr_wii_data._arr_data_byte[2] = 0x00;
}

inline T_DATA_8 
C_CONTR_Wii :: 
Ret_data (usint _arg_num)
{
	return _mem_contr_wii_data._arr_data_byte[_arg_num];
}

inline void
C_CONTR_Wii ::
Lcd_data (T_ADRS _arg_addr)
{
	Lcd_put_num(_arg_addr + 0,Ret_data(0),2,ED_16);
	Lcd_put_num(_arg_addr + 2,Ret_data(1),2,ED_16);
	Lcd_put_num(_arg_addr + 4,Ret_data(2),2,ED_16);
}

inline void 
C_CONTR_Wii :: 
Lcd_cross (T_ADRS _arg_adrs) 
{
	Lcd_cross_x(_arg_adrs + 0);
	Lcd_cross_y(_arg_adrs + 1);
}

inline void
C_CONTR_Wii ::
Lcd_Rsti (T_ADRS _arg_adrs)
{
	Lcd_Rsti_x(_arg_adrs + 0);
	Lcd_Rsti_y(_arg_adrs + 1);
}

inline void
C_CONTR_Wii ::
Lcd_Lsti (T_ADRS _arg_adrs)
{
	Lcd_Lsti_x(_arg_adrs + 0);
	Lcd_Lsti_y(_arg_adrs + 1);
}

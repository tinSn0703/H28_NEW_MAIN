
#pragma once

#include "H28_C_CONTR_PS2.h"

//public member

inline 
C_CONTR_ps2 :: 
C_CONTR_ps2 ()
{
	Reset();
}

void 
C_CONTR_ps2 :: 
In (C_UART_R &_arg_uart_r)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {};
	
	C_CONTR::In(_arg_uart_r,_temp_data);
	
	_mem_contr_ps2_data.Set_data(_temp_data);
}

void 
C_CONTR_ps2 :: 
In (C_UART_R2 &_arg_uart_r2)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {};
	
	C_CONTR::In(_arg_uart_r2,_temp_data);
	
	_mem_contr_ps2_data.Set_data(_temp_data);
}

inline void 
C_CONTR_ps2 :: 
Reset ()
{
	_mem_contr_ps2_data._arr_data_byte[0] = 0xff;
	_mem_contr_ps2_data._arr_data_byte[1] = 0x0f;
	_mem_contr_ps2_data._arr_data_byte[2] = 0x00;
}

inline T_DATA_8 
C_CONTR_ps2 :: 
Ret_data (usint _arg_num_data)
{
	return _mem_contr_ps2_data._arr_data_byte[_arg_num_data];
}

inline void
C_CONTR_ps2 ::
Lcd_data (T_ADRS _arg_addr)
{
	Lcd_put_num(_arg_addr + 0,Ret_data(0),2,ED_16);
	Lcd_put_num(_arg_addr + 2,Ret_data(1),2,ED_16);
	Lcd_put_num(_arg_addr + 4,Ret_data(2),2,ED_16);
}
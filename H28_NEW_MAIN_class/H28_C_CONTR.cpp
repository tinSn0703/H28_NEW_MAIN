
#pragma once

#include "H28_C_CONTR.h"

inline void
C_CONTR ::
In
(
	C_UART_R & _arg_uart_r,
	T_DATA_8 _arg_arr_data[__CON_BYTE_UART__] 
)
{	
	_arg_uart_r.Check();
	
	if (_arg_uart_r == EU_ERROR) //受信成功
	{
		_arg_arr_data[0] = 0x3f;
		_arg_arr_data[1] = 0x7f;
		_arg_arr_data[2] = 0x8f;
		_arg_arr_data[3] = 0xc0;
		
		FUNC_END;
	}
	
	usint _flag = 0;
	
	for (usint i = 0; i < 15; i++) //さすがに無限ループ化するのはまずいので
	{
		T_DATA_8 _temp = 0;
		
		_arg_uart_r >> _temp;
		
		if (_arg_uart_r != EU_ERROR)
		{
			const usint _num = ((_temp >> 6) & 3);
			
			_arg_arr_data[_num] = _temp;
			
			_flag |= (1 << _num);
		}
		
		if (_flag == 0x0f) break; //全データ受信完了
	}
}

inline void
C_CONTR::
In
(
	C_UART_R2 & _arg_uart_r2,
	T_DATA_8 _arg_arr_data[__CON_BYTE_UART__]
)
{
	_arg_uart_r2.Set_bit9_0(FALSE);
	_arg_uart_r2.Set_bit9_1(FALSE);
	
	_arg_uart_r2.Check();
	
	if (_arg_uart_r2 == EU_ERROR) //受信失敗
	{
		_arg_arr_data[0] = 0x3f;
		_arg_arr_data[1] = 0x7f;
		_arg_arr_data[2] = 0x8f;
		_arg_arr_data[3] = 0xc0;
		
		return (void)0;
	}
	
	usint _flag = 0;
	
	for (usint i = 0; i < 15; i++) //さすがに無限ループ化するのはまずいので
	{
		T_DATA_8 _temp = 0;
		
		_arg_uart_r2 >> _temp;
		
		if (_arg_uart_r2 != EU_ERROR)
		{
			_arg_arr_data[(_temp & 0xc0) >> 6] = _temp;
			
			_flag |= (1 << ((_temp & 0xc0) >> 6));
		}
		
		if (_flag == 0x0f) //データを全て得るまで続く
		{
			break;
		}
	}
}

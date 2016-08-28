
#pragma once

#include "H28_C_AIR.h"

inline 
C_AIR ::
C_AIR (T_DATA_8 _arg_air_data = 0x00)
{
	_mem_air_data._byte = _arg_air_data;
	
	for (usint i = 0; i < 8; i++)	_mem_array_air_flag[i] = TRUE;
}

inline T_DATA_8
C_AIR ::
Ret ()
{
	return _mem_air_data._byte;
}

inline BOOL
C_AIR ::
Ret_num (T_NUM _arg_air_num)
{
	return CHECK_BIT_TF(_mem_air_data._byte,_arg_air_num);
}

inline void 
C_AIR ::
Set (T_DATA_8 _arg_air_data)
{
	_mem_air_data._byte = _arg_air_data;
}

inline void 
C_AIR ::
Set_num
(
	T_NUM _arg_air_num,
	BOOL _arg_air_nf
)
{
	switch (_arg_air_nf)
	{
		case TRUE:	_mem_air_data._byte |=  (1 << _arg_air_num);	break;
		case FALSE:	_mem_air_data._byte &= ~(1 << _arg_air_num);	break;
	}
}

inline void 
C_AIR ::
Turn ()
{
	_mem_air_data._byte = ~(_mem_air_data._byte);
}

inline void 
C_AIR ::
Turn_num (T_NUM _arg_air_num)
{
	switch (_arg_air_num)
	{
		case 0:	Turn_0();	break;
		case 1:	Turn_1();	break;
		case 2:	Turn_2();	break;
		case 3:	Turn_3();	break;
		case 4:	Turn_4();	break;
		case 5:	Turn_5();	break;
		case 6:	Turn_6();	break;
		case 7:	Turn_7();	break;
		default:			break;
	}
}

inline void 
C_AIR ::
Do
(
	T_NUM _arg_air_num, 
	BOOL _arg_air_nf
)
{
	if (_arg_air_nf == TRUE)
	{
		if (_mem_array_air_flag[_arg_air_num] == TRUE)
		{
			Turn_num(_arg_air_num);
		}
		
		_mem_array_air_flag[_arg_air_num] = FALSE;
	}
	else
	{
		_mem_array_air_flag[_arg_air_num] = TRUE;
	}
}

inline void 
C_AIR ::
Do
(
	T_NUM _arg_air_num, 
	BOOL _arg_air_nf, 
	BOOL &_arg_nf_timer
)
{
	if (_arg_air_nf == TRUE)
	{
		if ((_mem_array_air_flag[_arg_air_num] & _arg_nf_timer) == TRUE)
		{
			Turn_num(_arg_air_num);
		}
		
		_mem_array_air_flag[_arg_air_num] = FALSE;
	}
	else
	{
		_mem_array_air_flag[_arg_air_num] = TRUE;
	}
}

inline void 
C_AIR ::
Do
(
	T_NUM _arg_air_num_0, 
	T_NUM _arg_air_num_1, 
	BOOL _arg_air_nf ,
	BOOL &_arg_nf_timer
)
{
	if (_arg_air_nf)
	{
		if (_mem_array_air_flag[_arg_air_num_0])
		{			
			switch (_mem_array_air_flag[_arg_air_num_1])
			{
				case TRUE:	Set_num(_arg_air_num_0,FALSE);	break;
				case FALSE:	Set_num(_arg_air_num_1,FALSE);	break;
			}
			
			_arg_nf_timer = FALSE;
			
			_mem_array_air_flag[_arg_air_num_0] = FALSE;
		}
	}
	else
	{
		_mem_array_air_flag[_arg_air_num_0] = TRUE;
	}
	
	if ((Ret_num(_arg_air_num_0) | Ret_num(_arg_air_num_1) | ~_arg_nf_timer) == FALSE)
	{
		switch (_mem_array_air_flag[_arg_air_num_1])
		{
			case TRUE:	Set_num(_arg_air_num_1,TRUE);	break;
			case FALSE:	Set_num(_arg_air_num_0,TRUE);	break;
		}
		
		_mem_array_air_flag[_arg_air_num_1] = ~_mem_array_air_flag[_arg_air_num_1];
	}
}

void 
C_AIR ::
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_off();
	
	_arg_uart_t << _mem_air_data._byte;
}

void 
C_AIR :: 
Out (C_IO_OUT &_arg_io_out)
{
	_arg_io_out.Out(Ret());
}

void 
C_AIR :: 
Out 
(
	C_IO_OUT &_arg_io_out, 
	usint _arg_air_num
)
{
	_arg_io_out.Out_num(_arg_air_num, Ret_num(_arg_air_num));
}

void 
C_AIR :: 
Out
(
	C_IO_OUT &_arg_io_out, 
	usint _arg_air_num, 
	usint _arg_io_num
)
{
	_arg_io_out.Out_num(_arg_io_num, Ret_num(_arg_air_num));
}

void 
C_AIR :: 
Out
(
	C_IO_OUT_pin &_arg_io_out, 
	usint _arg_air_num
)
{
	_arg_io_out.Out(Ret_num(_arg_air_num));
}

inline void 
C_AIR ::
Lcd_2 (T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs,_mem_air_data._byte,8,ED_02);
}

inline void 
C_AIR ::
Lcd_16 (T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs,_mem_air_data._byte,2,ED_16);
}

inline void 
C_AIR ::
Lcd_num
(
	T_ADRS _arg_adrs,
	T_NUM _arg_air_num
)
{
	Lcd_put_num(_arg_adrs,Ret_num(_arg_air_num),1,ED_02);
}
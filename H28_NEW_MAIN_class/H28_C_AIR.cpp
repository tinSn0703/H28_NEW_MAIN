
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
Set_double
(
	T_NUM _arg_air_num_one, 
	T_NUM _arg_air_num_do, 
	BOOL _arg_air_nf
)
{
	if (Ret_num(_arg_air_num_one) & _arg_air_nf)	FUNC_END;
	//oneがONかつ、doをONにしようとしていた場合
	
	Set_num(_arg_air_num_do, _arg_air_nf);
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
	Set_num(_arg_air_num, ~Ret_num(_arg_air_num));
}

inline void 
C_AIR ::
Do
(
	T_NUM _arg_air_num, 
	BOOL _arg_air_nf
)
{
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num])	Turn_num(_arg_air_num);
	
	_mem_array_air_flag[_arg_air_num] = ~_arg_air_nf;
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
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num] & _arg_nf_timer)	Turn_num(_arg_air_num);
	
	_mem_array_air_flag[_arg_air_num] = ~_arg_air_nf;
}

inline void 
C_AIR ::
Do_double
(
	T_NUM _arg_air_num_ri, 
	T_NUM _arg_air_num_le, 
	BOOL _arg_air_nf ,
	BOOL &_arg_nf_timer
)
{
	//_mem_array_air_flag[_arg_air_num_ri] : _arg_air_nfのフラグとして使用
	//_mem_array_air_flag[_arg_air_num_le] : ONにするPORTの選択用として使用。
	//										 TRUE  -> _arg_air_num_le
	//										 FALSE -> _arg_air_num_ri
	
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num_ri])
	{
		switch (_mem_array_air_flag[_arg_air_num_le]) //ソレノイドをOFFに
		{
			case TRUE:	Set_num(_arg_air_num_ri,FALSE);	break;
			case FALSE:	Set_num(_arg_air_num_le,FALSE);	break;
		}
			
		_arg_nf_timer = FALSE;
	}
	
	_mem_array_air_flag[_arg_air_num_ri] = ~_arg_air_nf;
	
	if ((Ret_num(_arg_air_num_ri) | Ret_num(_arg_air_num_le) | ~_arg_nf_timer) == FALSE)
	//_arg_air_nfがTRUEになってFALSEになってから、一定時間経過後に処理されます。
	{
		switch (_mem_array_air_flag[_arg_air_num_le]) //ソレノイドをONに
		{
			case TRUE:	Set_num(_arg_air_num_le,TRUE);	break;
			case FALSE:	Set_num(_arg_air_num_ri,TRUE);	break;
		}
		
		_mem_array_air_flag[_arg_air_num_le] = ~_mem_array_air_flag[_arg_air_num_le];
	}
	
	if (Ret_num(_arg_air_num_ri) & Ret_num(_arg_air_num_le))	//両方がONになっていないかのチェック
	{
		Set_num(_arg_air_num_ri, FALSE);
		Set_num(_arg_air_num_le, FALSE);
	}
}

void 
C_AIR :: 
Do_double
(
	T_NUM _arg_air_num_one, 
	T_NUM _arg_air_num_do, 
	BOOL _arg_air_nf
)
{
	if ((Ret_num(_arg_air_num_one) & _arg_air_nf) == FALSE)	Do(_arg_air_num_do, _arg_air_nf);
	
	if (Ret_num(_arg_air_num_one) & Ret_num(_arg_air_num_do))	//両方がONになっていないかのチェック
	{
		Set_num(_arg_air_num_one, FALSE);
		Set_num(_arg_air_num_do,  FALSE);
	}
}

void 
C_AIR :: 
Do_double 
(
	T_NUM _arg_air_num_ri, 
	BOOL _arg_air_nf_ri, 
	T_NUM _arg_air_num_le, 
	BOOL _arg_air_nf_le
)
{
	if ((Ret_num(_arg_air_num_le) & _arg_air_nf_ri) == FALSE)	Do (_arg_air_num_ri, _arg_air_nf_ri);
	if ((Ret_num(_arg_air_num_le) & _arg_air_nf_ri) == FALSE)	Do (_arg_air_num_ri, _arg_air_nf_ri);
	
	if (Ret_num(_arg_air_num_ri) & Ret_num(_arg_air_num_le))	//両方がONになっていないかのチェック
	{
		Set_num(_arg_air_num_ri, FALSE);
		Set_num(_arg_air_num_le, FALSE);
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
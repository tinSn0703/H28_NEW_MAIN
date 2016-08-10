
#pragma once

class C_AIR
{
private:
	
	union U_AIR
	{	
		struct S_AIR
		{
			BOOL _air0 :1;
			BOOL _air1 :1;
			BOOL _air2 :1;
			BOOL _air3 :1;
			BOOL _air4 :1;
			BOOL _air5 :1;
			BOOL _air6 :1;
			BOOL _air7 :1;
		};
		
		T_DATA_8 _data_byte :8;
		S_AIR _data_bit;
	};
	
	U_AIR _mem_air_data;
	BOOL _mem_array_air_flag[8];
	
public:
	
	C_AIR(T_DATA_8 );
	
	T_DATA_8 Ret();
	BOOL Ret_num(T_NUM _arg_air_num);
		
	BOOL Ret_0()	{	return _mem_air_data._data_bit._air0;	}
	BOOL Ret_1()	{	return _mem_air_data._data_bit._air1;	}
	BOOL Ret_2()	{	return _mem_air_data._data_bit._air2;	}
	BOOL Ret_3()	{	return _mem_air_data._data_bit._air3;	}
	BOOL Ret_4()	{	return _mem_air_data._data_bit._air4;	}
	BOOL Ret_5()	{	return _mem_air_data._data_bit._air5;	}
	BOOL Ret_6()	{	return _mem_air_data._data_bit._air6;	}
	BOOL Ret_7()	{	return _mem_air_data._data_bit._air7;	}
	
	void Set(T_DATA_8 );
	void Set_num(T_NUM ,BOOL );
	
	void Set_0(BOOL _arg_air_nf_0)	{	_mem_air_data._data_bit._air0 = _arg_air_nf_0;	}
	void Set_1(BOOL _arg_air_nf_1)	{	_mem_air_data._data_bit._air1 = _arg_air_nf_1;	}
	void Set_2(BOOL _arg_air_nf_2)	{	_mem_air_data._data_bit._air2 = _arg_air_nf_2;	}
	void Set_3(BOOL _arg_air_nf_3)	{	_mem_air_data._data_bit._air3 = _arg_air_nf_3;	}
	void Set_4(BOOL _arg_air_nf_4)	{	_mem_air_data._data_bit._air4 = _arg_air_nf_4;	}
	void Set_5(BOOL _arg_air_nf_5)	{	_mem_air_data._data_bit._air5 = _arg_air_nf_5;	}
	void Set_6(BOOL _arg_air_nf_6)	{	_mem_air_data._data_bit._air6 = _arg_air_nf_6;	}
	void Set_7(BOOL _arg_air_nf_7)	{	_mem_air_data._data_bit._air7 = _arg_air_nf_7;	}
	
	void Turn();
	void Turn_num(T_NUM );

	void Turn_0()	{	_mem_air_data._data_bit._air0 = TURN_TF(_mem_air_data._data_bit._air0);	}
	void Turn_1()	{	_mem_air_data._data_bit._air1 = TURN_TF(_mem_air_data._data_bit._air1);	}
	void Turn_2()	{	_mem_air_data._data_bit._air2 = TURN_TF(_mem_air_data._data_bit._air2);	}
	void Turn_3()	{	_mem_air_data._data_bit._air3 = TURN_TF(_mem_air_data._data_bit._air3);	}
	void Turn_4()	{	_mem_air_data._data_bit._air4 = TURN_TF(_mem_air_data._data_bit._air4);	}
	void Turn_5()	{	_mem_air_data._data_bit._air5 = TURN_TF(_mem_air_data._data_bit._air5);	}
	void Turn_6()	{	_mem_air_data._data_bit._air6 = TURN_TF(_mem_air_data._data_bit._air6);	}
	void Turn_7()	{	_mem_air_data._data_bit._air7 = TURN_TF(_mem_air_data._data_bit._air7);	}

	void Do(T_NUM ,BOOL );	
	void Do(T_NUM ,BOOL ,BOOL &);
	void Do(T_NUM ,T_NUM ,BOOL ,BOOL &);
	
	void Out(C_UART_T );
	
	void Lcd_2 (T_ADRS );
	void Lcd_16(T_ADRS );
	
	void Lcd_num(T_ADRS ,T_NUM );
};

inline 
C_AIR::
C_AIR (T_DATA_8 _arg_air_data = 0x00)
{
	_mem_air_data._data_byte = _arg_air_data;
	
	for (usint i = 0; i < 8; i++)	_mem_array_air_flag[i] = TRUE;
}

inline T_DATA_8
C_AIR::
Ret ()
{
	return _mem_air_data._data_byte;
}

inline BOOL
C_AIR::
Ret_num (T_NUM _arg_air_num)
{
	return CHECK_BIT_TF(_mem_air_data._data_byte,_arg_air_num);
}

inline void 
C_AIR::
Set (T_DATA_8 _arg_air_data)
{
	_mem_air_data._data_byte = _arg_air_data;
}

inline void 
C_AIR::
Set_num
(
	T_NUM _arg_air_num,
	BOOL _arg_air_nf
)
{
	switch (_arg_air_nf)
	{
		case TRUE:	_mem_air_data._data_byte |=  (1 << _arg_air_num);	break;
		case FALSE:	_mem_air_data._data_byte &= ~(1 << _arg_air_num);	break;
	}
}

inline void 
C_AIR::
Turn ()
/*
電磁弁の設定を反転させる
*/
{
	_mem_air_data._data_byte = ~(_mem_air_data._data_byte);
}

inline void 
C_AIR::
Turn_num (T_NUM _arg_air_num)
/*
指定された電磁弁ポートの設定を反転させる

	_arg_air_num : 反転させる電磁弁ポート
*/
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
C_AIR::
Do
(
	T_NUM _arg_air_num, 
	BOOL _arg_air_nf
)
/*
3port or 2port電磁弁用

	_arg_air_num : 動かす電磁弁のポートの番号
	_arg_air_nf  : 電磁弁のONOFF。
*/
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
C_AIR::
Do
(
	T_NUM _arg_air_num, 
	BOOL _arg_air_nf, 
	BOOL &_arg_nf_timer
)
/*
3port or 2port電磁弁用。タイマ付き

	_arg_air_num  : 動かす電磁弁のポートの番号
	_arg_air_nf   : 電磁弁のONOFF
	_arg_nf_timer : タイマカウンタのフラグ。外部でカウント完了したら、TRUEにしといてくさい。
*/
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
C_AIR::
Do
(
	T_NUM _arg_air_num_0, 
	T_NUM _arg_air_num_1, 
	BOOL _arg_air_nf ,
	BOOL &_arg_nf_timer
)
/*
5port電磁弁用。タイマ付き

	_arg_air_num_0,_arg_air_num_1  : 動かす電磁弁のポートの番号
	_arg_air_nf   : 電磁弁のONOFF
	_arg_nf_timer : タイマカウンタのフラグ。外部でカウント完了したら、TRUEにしといてくさい。
*/
{	
	if (_arg_air_nf)
	{
		if (_mem_array_air_flag[_arg_air_num_0] == FALSE)
		{			
			return (void)0;
		}
		
		switch (_mem_array_air_flag[_arg_air_num_1])
		{
			case TRUE:
			{
				if (Ret_num(_arg_air_num_1))	_arg_nf_timer = FALSE;
				
				Set_num(_arg_air_num_0,FALSE);
				
				break;
			}
			case FALSE:
			{
				if (Ret_num(_arg_air_num_0))	_arg_nf_timer = FALSE;
				
				Set_num(_arg_air_num_1,FALSE);
				
				break;
			}
		}
	}
	else
	{
		if (_mem_array_air_flag[_arg_air_num_0])
		{			
			if ((Ret_num(_arg_air_num_0) | Ret_num(_arg_air_num_1) | TURN_TF(_arg_nf_timer)))
			{
				return (void)0;
			}
			
			switch (_mem_array_air_flag[_arg_air_num_1])
			{
				case TRUE:	Set_num(_arg_air_num_1,TRUE);	break;
				case FALSE:	Set_num(_arg_air_num_0,TRUE);	break;
			}
			
			_mem_array_air_flag[_arg_air_num_0] = FALSE;
			_mem_array_air_flag[_arg_air_num_1] = TURN_TF(_mem_array_air_flag[_arg_air_num_1]);
		}
		else
		{
			_mem_array_air_flag[_arg_air_num_0] = TRUE;
		}
	}
}

void 
C_AIR::
Out (C_UART_T _arg_air_uart_t)
/*
電磁弁回路へデータを送信する
*/
{
	_arg_air_uart_t.Set_bit9_off();
	
	_arg_air_uart_t << _mem_air_data._data_byte;
}

inline void 
C_AIR::
Lcd_2 (T_ADRS _arg_air_adrs)
/*
電磁弁の設定を2進数8桁でLCDに表示する

	_arg_air_adrs : 表示する場所
*/
{
	Lcd_put_num(_arg_air_adrs,_mem_air_data._data_byte,8,ED_02);
}

inline void 
C_AIR::
Lcd_16 (T_ADRS _arg_air_adrs)
/*
電磁弁の設定を16進数2桁でLCDに表示する

	_arg_air_adrs : 表示する場所
*/
{
	Lcd_put_num(_arg_air_adrs,_mem_air_data._data_byte,2,ED_16);
}

inline void 
C_AIR::
Lcd_num
(
	T_ADRS _arg_air_adrs,
	T_NUM _arg_air_num
)
/*
指定された電磁弁ポートの設定を1桁でLCDに表示する

	_arg_air_adrs : 表示する場所
	_arg_air_num : 表示する電磁弁ポート
*/
{
	Lcd_put_num(_arg_air_adrs,Ret_num(_arg_air_num),1,ED_02);
}
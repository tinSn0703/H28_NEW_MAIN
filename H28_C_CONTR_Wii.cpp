
#pragma once

#include "H28_C_CONTR.cpp"

class C_CONTR_Wii : public C_CONTR
/*
Wiiコントローラ用
*/
{
	protected:
	
	U_CONTR_Wii _mem_contr_wii_data;
	
	public:
	C_CONTR_Wii();
	
	E_DIRECX Ret_cross_x()	{	return _mem_contr_wii_data._data_bit._cross_x;			}
	E_DIRECY Ret_cross_y()	{	return _mem_contr_wii_data._data_bit._cross_y;			}
	E_DIRECX Ret_Rsti_x()	{	return _mem_contr_wii_data._data_bit._stick_right_x;	}
	E_DIRECY Ret_Rsti_y()	{	return _mem_contr_wii_data._data_bit._stick_right_y;	}
	E_DIRECX Ret_Lsti_x()	{	return _mem_contr_wii_data._data_bit._stick_left_x;		}
	E_DIRECY Ret_Lsti_y()	{	return _mem_contr_wii_data._data_bit._stick_left_y;		}
	E_LOGIC  Ret_select()	{	return _mem_contr_wii_data._data_bit._nf_select;		}
	E_LOGIC  Ret_start()	{	return _mem_contr_wii_data._data_bit._nf_start;			}
	E_LOGIC  Ret_home()		{	return _mem_contr_wii_data._data_bit._nf_home;			}
	E_LOGIC  Ret_X()		{	return _mem_contr_wii_data._data_bit._nf_x;				}
	E_LOGIC  Ret_A()		{	return _mem_contr_wii_data._data_bit._nf_a;				}
	E_LOGIC  Ret_Y()		{	return _mem_contr_wii_data._data_bit._nf_y;				}
	E_LOGIC  Ret_B()		{	return _mem_contr_wii_data._data_bit._nf_b;				}
	E_LOGIC  Ret_R()		{	return _mem_contr_wii_data._data_bit._nf_right;			}
	E_LOGIC  Ret_L()		{	return _mem_contr_wii_data._data_bit._nf_left;			}
	E_LOGIC  Ret_ZR()		{	return _mem_contr_wii_data._data_bit._nf_z_right;		}
	E_LOGIC  Ret_ZL()		{	return _mem_contr_wii_data._data_bit._nf_z_left;		}
	
	uchar Ret_data(usint _arg_num_data)	{	return _mem_contr_wii_data._arr_data_byte[_arg_num_data];	}
	
	void In(C_UART_R &);
	void In(C_UART_R2 &);
	void Reset();
	
	void Lcd_data(T_ADRS );
	
	void Lcd_cross_x(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_cross_x(),1,ED_10);	}
	void Lcd_cross_y(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_cross_y(),1,ED_10);	}
	void Lcd_Rsti_x	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_Rsti_x(),1,ED_10);	}
	void Lcd_Rsti_y	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_Rsti_y(),1,ED_10);	}
	void Lcd_Lsti_x	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_Lsti_x(),1,ED_10);	}
	void Lcd_Lsti_y	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_Lsti_y(),1,ED_10);	}
	void Lcd_select	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_select(),1,ED_10);	}
	void Lcd_start	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_start(),1,ED_10);	}
	void Lcd_home	(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_home(),1,ED_10);	}
	void Lcd_X		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_X(),1,ED_10);		}
	void Lcd_A		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_A(),1,ED_10);		}
	void Lcd_Y		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_Y(),1,ED_10);		}
	void Lcd_B		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_B(),1,ED_10);		}
	void Lcd_R		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_R(),1,ED_10);		}
	void Lcd_L		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_L(),1,ED_10);		}
	void Lcd_ZR		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_ZR(),1,ED_10);		}
	void Lcd_ZL		(T_ADRS _arg_contr_wii_addr)	{	Lcd_put_num(_arg_contr_wii_addr,Ret_ZL(),1,ED_10);		}
};

//public
inline 
C_CONTR_Wii::
C_CONTR_Wii()
{
	Reset();
}

void 
C_CONTR_Wii::
In (C_UART_R &_arg_contr_wii_uart_r)
/*
BT_RX回路からの受信。単線時用

	_arg_contr_wii_uart_r : 受信するUART。
*/
{
	T_DATA_8 _temp_data[CON_BYTE_UART] = {};
	
	C_CONTR::In(_arg_contr_wii_uart_r,_temp_data);
	
	_mem_contr_wii_data.Set_data(_temp_data);
}

void 
C_CONTR_Wii::
In (C_UART_R2 &_arg_contr_wii_uart_r2)
/*
BT_RX回路からの受信。2線時用

	_arg_contr_wii_uart_r2 : 受信するUART。
*/
{
	T_DATA_8 _temp_data[CON_BYTE_UART] = {};
	
	C_CONTR::In(_arg_contr_wii_uart_r2,_temp_data);
	
	_mem_contr_wii_data.Set_data(_temp_data);
}

inline void C_CONTR_Wii::Reset()
{
	_mem_contr_wii_data._arr_data_byte[0] = 0xff;
	_mem_contr_wii_data._arr_data_byte[1] = 0x0f;
	_mem_contr_wii_data._arr_data_byte[2] = 0x00;
}

inline void
C_CONTR_Wii::
Lcd_data (T_ADRS _arg_contr_wii_addr)
/*
Wiiコントローラからのデータを全て表示する。
16進数、6桁

	_arg_contr_wii_addr : 表示するLCDの場所
*/
{
	for (usint i = 0; i < CON_BYTE; i++)
	{
		Lcd_put_num(_arg_contr_wii_addr + i * 2,Ret_data(i),2,ED_16);
	}
}
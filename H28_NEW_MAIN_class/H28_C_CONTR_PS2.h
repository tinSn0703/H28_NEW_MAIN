
#pragma once

#include "H28_C_CONTR.h"

/*************************************************************************

PS2コントローラからのデータを扱うためのクラス。

*************************************************************************/

class C_CONTR_ps2 : public C_CONTR
{
protected:
	
	U_CONTR_ps2 _mem_contr_ps2_data;
	
public:
	
	/**
	 * \brief コンストラクタ。データを初期化する
	 */
	C_CONTR_ps2();
	
	/**
	 * \brief BT_RX回路からの受信。(単線時用)
	 * 
	 * \param _arg_uart_r : 受信するUART
	 */
	void In(C_UART_R &_arg_uart_r);
	
	/**
	 * \brief BT_RX回路からの受信。(二線時用)
	 * 
	 * \param _arg_uart_r2 : 受信するUART
	 */
	void In(C_UART_R2 &_arg_uart_r2);
	
	/**
	 * \brief データをリセットする
	 */
	void Init();
	
	/**
	 * \brief データをreturnする
	 * 
	 * \param _arg_num : returnするデータの番号 0 ~ 2
	 * 
	 * \return T_DATA_8 出力
	 */
	T_DATA_8 Ret_data(usint _arg_num_data);
	
	E_DIRECX Ret_cross_x()	{	return _mem_contr_ps2_data._data_bit._btn_cross_x;		}
	E_DIRECY Ret_cross_y()	{	return _mem_contr_ps2_data._data_bit._btn_cross_y;		}
	E_DIRECX Ret_Rsti_x()	{	return _mem_contr_ps2_data._data_bit._stick_right_x;	}
	E_DIRECX Ret_Lsti_x()	{	return _mem_contr_ps2_data._data_bit._stick_left_x;		}
	E_DIRECY Ret_Rsti_y()	{	return _mem_contr_ps2_data._data_bit._stick_right_y;	}
	E_DIRECY Ret_Lsti_y()	{	return _mem_contr_ps2_data._data_bit._stick_left_y;		}
	BOOL  Ret_select()		{	return _mem_contr_ps2_data._data_bit._btn_select;		}
	BOOL  Ret_start()		{	return _mem_contr_ps2_data._data_bit._btn_start;		}
	BOOL  Ret_tri()			{	return _mem_contr_ps2_data._data_bit._btn_tri;			}
	BOOL  Ret_cir()			{	return _mem_contr_ps2_data._data_bit._btn_cir;			}
	BOOL  Ret_squ()			{	return _mem_contr_ps2_data._data_bit._btn_squ;			}
	BOOL  Ret_cro()			{	return _mem_contr_ps2_data._data_bit._btn_cro;			}
	BOOL  Ret_R1()			{	return _mem_contr_ps2_data._data_bit._btn_right_1;		}
	BOOL  Ret_R2()			{	return _mem_contr_ps2_data._data_bit._btn_right_2;		}
	BOOL  Ret_R3()			{	return _mem_contr_ps2_data._data_bit._btn_right_3;		}
	BOOL  Ret_L1()			{	return _mem_contr_ps2_data._data_bit._btn_left_1;		}
	BOOL  Ret_L2()			{	return _mem_contr_ps2_data._data_bit._btn_left_2;		}
	BOOL  Ret_L3()			{	return _mem_contr_ps2_data._data_bit._btn_left_3;		}
	
	/**
	 * \brief 
	 * データを全てLCDに表示する
	 * 16進数 6桁
	 * 
	 * \param _arg_addr : LCDに表示する場所
	 */
	void Lcd_data(T_ADRS _arg_addr);
	
	/**
	 * \brief 十字キーのデータをLCDに表示する
	 *		_arg_adrs + 0 -> cross_x
	 *		_arg_adrs + 1 -> cross_y
	 * 
	 * \param _arg_adrs 表示する場所
	 */
	void Lcd_cross(T_ADRS _arg_adrs);
	
	/**
	 * \brief 右スティックのデータをLCDに表示する
	 *		_arg_adrs + 0 -> Rsti_x
	 *		_arg_adrs + 1 -> Rsti_y
	 * 
	 * \param _arg_adrs 表示する場所
	 */
	void Lcd_Rsti (T_ADRS _arg_adrs);
	
	/**
	 * \brief 左スティックのデータをLCDに表示する
	 *		_arg_adrs + 0 -> Lsti_x
	 *		_arg_adrs + 1 -> Lsti_y
	 * 
	 * \param _arg_adrs 表示する場所
	 */
	void Lcd_Lsti (T_ADRS _arg_adrs);
	
	void Lcd_cross_x(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_cross_x(), 1, ED_10);	}
	void Lcd_cross_y(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_cross_y(), 1, ED_10);	}
	void Lcd_Rsti_x	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_Rsti_x(), 1, ED_10);		}
	void Lcd_Rsti_y	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_Rsti_y(), 1, ED_10);		}
	void Lcd_Lsti_x	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_Lsti_x(), 1, ED_10);		}
	void Lcd_Lsti_y	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_Lsti_y(), 1, ED_10);		}
	void Lcd_select	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_select(), 1, ED_10);		}
	void Lcd_start	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_start(), 1, ED_10);		}
	void Lcd_tri	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_tri(), 1, ED_10);		}
	void Lcd_cir	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_cir(), 1, ED_10);		}
	void Lcd_squ	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_squ(), 1, ED_10);		}
	void Lcd_cro	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_cro(), 1, ED_10);		}
	void Lcd_R1		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_R1(), 1, ED_10);			}
	void Lcd_R2		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_R2(), 1, ED_10);			}
	void Lcd_R3		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_R3(), 1, ED_10);			}
	void Lcd_L1		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_L1(), 1, ED_10);			}
	void Lcd_L2		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_L2(), 1, ED_10);			}
	void Lcd_L3		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr, Ret_L3(), 1, ED_10);			}
};

/************************************************************************/
//public

inline
C_CONTR_ps2 ::
C_CONTR_ps2 ()
{
	Init();
}

void
C_CONTR_ps2 ::
In (C_UART_R &_arg_uart_r)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {};
	
	C_CONTR::In(_arg_uart_r,_temp_data);
	
	_mem_contr_ps2_data.Write(_temp_data);
}

void
C_CONTR_ps2 ::
In (C_UART_R2 &_arg_uart_r2)
{
	T_DATA_8 _temp_data[__CON_BYTE_UART__] = {};
	
	C_CONTR::In(_arg_uart_r2,_temp_data);
	
	_mem_contr_ps2_data.Write(_temp_data);
}

inline void
C_CONTR_ps2 ::
Init ()
{
	_mem_contr_ps2_data._arr_data_byte[0] = 0xff;
	_mem_contr_ps2_data._arr_data_byte[1] = 0x0f;
	_mem_contr_ps2_data._arr_data_byte[2] = 0x00;
}

inline T_DATA_8
C_CONTR_ps2 ::
Ret_data (usint _arg_num_data)
{
	if (_arg_num_data >= 3)	return 0;
	
	return _mem_contr_ps2_data._arr_data_byte[_arg_num_data];
}

inline void
C_CONTR_ps2 ::
Lcd_data (T_ADRS _arg_addr)
{
	Lcd_put_num(_arg_addr + 0, Ret_data(0), 2, ED_16);
	Lcd_put_num(_arg_addr + 2, Ret_data(1), 2, ED_16);
	Lcd_put_num(_arg_addr + 4, Ret_data(2), 2, ED_16);
}

inline void
C_CONTR_ps2 ::
Lcd_cross (T_ADRS _arg_adrs)
{
	Lcd_cross_x(_arg_adrs + 0);
	Lcd_cross_y(_arg_adrs + 1);
}

inline void
C_CONTR_ps2 ::
Lcd_Rsti (T_ADRS _arg_adrs)
{
	Lcd_Rsti_x(_arg_adrs + 0);
	Lcd_Rsti_y(_arg_adrs + 1);
}

inline void
C_CONTR_ps2 ::
Lcd_Lsti (T_ADRS _arg_adrs)
{
	Lcd_Lsti_x(_arg_adrs + 0);
	Lcd_Lsti_y(_arg_adrs + 1);
}
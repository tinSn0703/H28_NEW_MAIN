
#pragma once

#include "H28_C_CONTR.h"

/**
 * Wiiコントローラからデータを受け取る時用
 */
class C_CONTR_Wii : public C_CONTR
{
protected:
	
	U_CONTR_Wii _mem_contr_wii_data;
	
	BOOL _mem_contr_wii_nf_overwrite :1;
	
public:
	
	/**
	 * \brief コンストラクタ。データを初期化する
	 */
	C_CONTR_Wii (BOOL _arg_nf_overweite);
	
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
	void Reset();
	
	void Set_Rsti_x(E_DIRECX _arg_set)	{_mem_contr_wii_data._data_bit._stick_right_x = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._stick_right_x);}
	void Set_Rsti_y(E_DIRECY _arg_set)	{_mem_contr_wii_data._data_bit._stick_right_y = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._stick_right_y);}
	void Set_Lsti_x(E_DIRECX _arg_set)	{_mem_contr_wii_data._data_bit._stick_left_x  = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._stick_left_x);}
	void Set_Lsti_y(E_DIRECY _arg_set)	{_mem_contr_wii_data._data_bit._stick_left_y  = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._stick_left_y);}
	
	void Set_A(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_a = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_a);}
	void Set_B(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_b = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_b);}
	void Set_X(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_x = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_x);}
	void Set_Y(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_y = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_y);}
	
	void Set_R(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_right = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_right);}
	void Set_L(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_left  = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_left);}
	
	void Set_ZR(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_z_right = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_z_right);}
	void Set_ZL(BOOL _arg_set)	{_mem_contr_wii_data._data_bit._nf_z_left  = (_mem_contr_wii_nf_overwrite == TRUE ? _arg_set : _mem_contr_wii_data._data_bit._nf_z_left);}
	
	/**
	 * \brief データをreturnする
	 * 
	 * \param _arg_num : returnするデータの番号
	 * 
	 * \return T_DATA_8 出力
	 */
	T_DATA_8 Ret_data(usint _arg_num);
	
	E_DIRECX Ret_cross_x()	{	return _mem_contr_wii_data._data_bit._cross_x;			}
	E_DIRECY Ret_cross_y()	{	return _mem_contr_wii_data._data_bit._cross_y;			}
	E_DIRECX Ret_Rsti_x()	{	return _mem_contr_wii_data._data_bit._stick_right_x;	}
	E_DIRECY Ret_Rsti_y()	{	return _mem_contr_wii_data._data_bit._stick_right_y;	}
	E_DIRECX Ret_Lsti_x()	{	return _mem_contr_wii_data._data_bit._stick_left_x;		}
	E_DIRECY Ret_Lsti_y()	{	return _mem_contr_wii_data._data_bit._stick_left_y;		}
	BOOL  Ret_select()		{	return _mem_contr_wii_data._data_bit._nf_select;		}
	BOOL  Ret_start()		{	return _mem_contr_wii_data._data_bit._nf_start;			}
	BOOL  Ret_home()		{	return _mem_contr_wii_data._data_bit._nf_home;			}
	BOOL  Ret_X()			{	return _mem_contr_wii_data._data_bit._nf_x;				}
	BOOL  Ret_A()			{	return _mem_contr_wii_data._data_bit._nf_a;				}
	BOOL  Ret_Y()			{	return _mem_contr_wii_data._data_bit._nf_y;				}
	BOOL  Ret_B()			{	return _mem_contr_wii_data._data_bit._nf_b;				}
	BOOL  Ret_R()			{	return _mem_contr_wii_data._data_bit._nf_right;			}
	BOOL  Ret_L()			{	return _mem_contr_wii_data._data_bit._nf_left;			}
	BOOL  Ret_ZR()			{	return _mem_contr_wii_data._data_bit._nf_z_right;		}
	BOOL  Ret_ZL()			{	return _mem_contr_wii_data._data_bit._nf_z_left;		}
	
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
	
	void Lcd_cross_x(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_cross_x(),1,ED_10);	}
	void Lcd_cross_y(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_cross_y(),1,ED_10);	}
	void Lcd_Rsti_x	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_Rsti_x(),1,ED_10);	}
	void Lcd_Rsti_y	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_Rsti_y(),1,ED_10);	}
	void Lcd_Lsti_x	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_Lsti_x(),1,ED_10);	}
	void Lcd_Lsti_y	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_Lsti_y(),1,ED_10);	}
	void Lcd_select	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_select(),1,ED_10);	}
	void Lcd_start	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_start(),1,ED_10);		}
	void Lcd_home	(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_home(),1,ED_10);		}
	void Lcd_X		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_X(),1,ED_10);			}
	void Lcd_A		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_A(),1,ED_10);			}
	void Lcd_Y		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_Y(),1,ED_10);			}
	void Lcd_B		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_B(),1,ED_10);			}
	void Lcd_R		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_R(),1,ED_10);			}
	void Lcd_L		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_L(),1,ED_10);			}
	void Lcd_ZR		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_ZR(),1,ED_10);		}
	void Lcd_ZL		(T_ADRS _arg_addr)	{	Lcd_put_num(_arg_addr,Ret_ZL(),1,ED_10);		}
};

#include "H28_C_CONTR_Wii.cpp"
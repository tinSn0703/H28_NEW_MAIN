
#ifndef _H28_C_CONTR_Wii_CPP_
#define _H28_C_CONTR_Wii_CPP_ 1

class C_CONTR_Wii
/*
Wiiコントローラ用
*/
{
	protected:
	
	#define CON_BYTE_UART 4	//受信したコントローラのデータのバイト数
	#define CON_BYTE 3		//プログラム内で扱うコントローラのデータのバイト数
	
	union U_CONTR_Wii
	{
		struct S_CONTR_Wii
		{
			//Wii controler data
			//byte0 5bit east, 4bit north, 3bit start, 2bit NO, 1bit home, 0bit select
			//byte1 5bit R, 4bit L, 3bit ZR, 2bit ZL, 1bit west, 0bit south
			//byte2 5bit R_west, 4bit R_east, 3bit y, 2bit b, 1bit a, 0bit x
			//byte3 5bit L_south, 4bit L_north, 3bit L_west, 2bit L_east, 1bit R_south, 0bit R_north
			
			//_mem_data_controler[0]
			E_DIRECX _stick_right_x :2; //右スティック x方向 0,1bit
			E_DIRECY _stick_right_y :2; //右スティック y方向 2,3bit
			
			E_DIRECX _stick_left_x :2; //左スティック x方向 4,5bit
			E_DIRECY _stick_left_y :2; //左スティック y方向 6,7bit
			
			//_mem_data_controler[1]
			E_DIRECX _cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY _cross_y :2; //十字キー y軸 2,3bit
			
			E_LOGIC _nf_x :1; //x 4bit
			E_LOGIC _nf_a :1; //a 5bit
			E_LOGIC _nf_y :1; //y 6bit
			E_LOGIC _nf_b :1; //b 7bit
			
			//_mem_data_controler[2]
			E_LOGIC _nf_right :1; //0bit
			E_LOGIC _nf_left  :1; //1bit
			E_LOGIC _nf_z_right :1; //2bit
			E_LOGIC _nf_z_left  :1; //3bit
			
			E_LOGIC _none_		:1; //4bit
			E_LOGIC _nf_home	:1; //5bit
			E_LOGIC _nf_start   :1; //6bit
			E_LOGIC _nf_select  :1; //7bit
		};
		
		uchar _arr_data_byte[CON_BYTE];
		S_CONTR_Wii _data_bit;
	};
	
	U_CONTR_Wii _mem_contr_wii_data;
	
	void Set_data(T_DATA_8 []);
	
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

inline void 
C_CONTR_Wii::
Set_data (T_DATA_8 _arg_contr_wii_data[CON_BYTE_UART])
{	
	_mem_contr_wii_data._data_bit._cross_x = SET_DIREC_X(CHECK_BIT_TF(_arg_contr_wii_data[0],5),CHECK_BIT_TF(_arg_contr_wii_data[1],1));
	_mem_contr_wii_data._data_bit._cross_y = SET_DIREC_Y(CHECK_BIT_TF(_arg_contr_wii_data[0],4),CHECK_BIT_TF(_arg_contr_wii_data[1],0));
	
	_mem_contr_wii_data._data_bit._stick_left_x = SET_DIREC_X(_arg_contr_wii_data[3],2);
	_mem_contr_wii_data._data_bit._stick_left_y = SET_DIREC_Y(_arg_contr_wii_data[3],4);
	
	_mem_contr_wii_data._data_bit._stick_right_x = SET_DIREC_X(_arg_contr_wii_data[2],4);
	_mem_contr_wii_data._data_bit._stick_right_y = SET_DIREC_Y(_arg_contr_wii_data[3],0);
	
	_mem_contr_wii_data._data_bit._nf_start  = CHECK_TURN_BIT_TF(_arg_contr_wii_data[0],3);
	_mem_contr_wii_data._data_bit._nf_select = CHECK_TURN_BIT_TF(_arg_contr_wii_data[0],0);
	_mem_contr_wii_data._data_bit._nf_home   = CHECK_TURN_BIT_TF(_arg_contr_wii_data[0],1);
	
	_mem_contr_wii_data._data_bit._nf_right = CHECK_TURN_BIT_TF(_arg_contr_wii_data[1],5);
	_mem_contr_wii_data._data_bit._nf_z_right = CHECK_TURN_BIT_TF(_arg_contr_wii_data[1],3);
	
	_mem_contr_wii_data._data_bit._nf_left  = CHECK_TURN_BIT_TF(_arg_contr_wii_data[1],4);
	_mem_contr_wii_data._data_bit._nf_z_left  = CHECK_TURN_BIT_TF(_arg_contr_wii_data[1],2);
	
	_mem_contr_wii_data._data_bit._nf_y = CHECK_TURN_BIT_TF(_arg_contr_wii_data[2],3);
	_mem_contr_wii_data._data_bit._nf_b = CHECK_TURN_BIT_TF(_arg_contr_wii_data[2],2);
	_mem_contr_wii_data._data_bit._nf_a = CHECK_TURN_BIT_TF(_arg_contr_wii_data[2],1);
	_mem_contr_wii_data._data_bit._nf_x = CHECK_TURN_BIT_TF(_arg_contr_wii_data[2],0);
}

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
	_arg_contr_wii_uart_r.Set_bit9(FALES);
	
	_arg_contr_wii_uart_r.Check();
	
	if (_arg_contr_wii_uart_r == EU_ERROR) //受信失敗
	{
		Reset();
		return (void)0;
	}
	
	usint _flag = 0;
	
	T_DATA_8 _temp_data[CON_BYTE_UART] = {};
	
	for (usint i = 0; i < 15; i++) //さすがに無限ループ化するのはまずいので
	{
		T_DATA_8 _temp = 0;
		
		_arg_contr_wii_uart_r >> _temp;
		
		if (_arg_contr_wii_uart_r != EU_ERROR)
		{
			_temp_data[(_temp & 0xc0) >> 6] = _temp;
			
			_flag |= (1 << ((_temp & 0xc0) >> 6));
		}
		
		if (_flag == 0x0f) //データを全て得るまで続く
		{
			break;
		}
	}
	
	Set_data(_temp_data);
}

void 
C_CONTR_Wii::
In (C_UART_R2 &_arg_contr_wii_uart_r2)
/*
BT_RX回路からの受信。2線時用

	_arg_contr_wii_uart_r2 : 受信するUART。
*/
{
	_arg_contr_wii_uart_r2.Set_bit9_0(FALES);
	_arg_contr_wii_uart_r2.Set_bit9_1(FALES);
	
	_arg_contr_wii_uart_r2.Check();
	
	if (_arg_contr_wii_uart_r2 == EU_ERROR)
	{
		Reset();
		return (void)0;
	}
	
	usint _flag = 0;
	
	T_DATA_8 _temp_data[CON_BYTE_UART] = {};
	
	for (usint i = 0; i < 15; i++)
	{
		T_DATA_8 _temp = 0;
		
		_arg_contr_wii_uart_r2 >> _temp;
		
		if (_arg_contr_wii_uart_r2 != EU_ERROR)
		{
			_temp_data[(_temp >> 6) & 0x03] = _temp;
			
			_flag |= (1 << ((_temp >> 6) & 0x03));
		}
		
		if (_flag == 0x0f)
		{
			break;
		}
	}
	
	Set_data(_temp_data);
}

inline void C_CONTR_Wii::Reset()
{
	_mem_contr_wii_data._arr_data_byte[0] = 0xff;
	_mem_contr_wii_data._arr_data_byte[1] = 0x0f;
	_mem_contr_wii_data._arr_data_byte[2] = 0x00;
}

#endif
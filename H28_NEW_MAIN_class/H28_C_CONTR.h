
#pragma once

/*************************************************************************
コントローラのデータを受け取るためのクラス。
あと内部にはデータ保持のための共用体があります。
作った意味がどれほどあるかはわかりません
*************************************************************************/

class C_CONTR
{
protected:
	
#	define __CON_BYTE_UART__ 4	//受信したコントローラのデータのバイト数
#	define __CON_BYTE__ 3		//プログラム内で扱うコントローラのデータのバイト数
	
	union U_CONTR_ps2
	{
		struct S_CONTR_ps2
		{
			//PS2 controler data
			//byte0 5bit east, 4bit north, 3bit start, 2bit R3, 1bit L3, 0bit select
			//byte1 5bit R1, 4bit L1, 3bit R2, 2bit L2, 1bit west, 0bit south
			//byte2 5bit R_west, 4bit R_east, 3bit □(squ), 2bit ×(cro), 1bit ○(cir), 0bit △(tri)
			//byte3 5bit L_south, 4bit L_north, 3bit L_west, 2bit L_east, 1bit R_south, 0bit R_north
			
			//_mem_data_controler[0]
			E_DIRECX _stick_right_x :2; //右スティック x方向 0,1bit
			E_DIRECY _stick_right_y :2; //右スティック y方向 2,3bit
			E_DIRECX _stick_left_x :2; //左スティック x方向 4,5bit
			E_DIRECY _stick_left_y :2; //左スティック y方向 6,7bit
			
			//_mem_data_controler[1]
			E_DIRECX _btn_cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY _btn_cross_y :2; //十字キー y軸 2,3bit
			BOOL _btn_tri :1; //三角 4bit
			BOOL _btn_cir :1; //円   5bit
			BOOL _btn_squ :1; //四角 6bit
			BOOL _btn_cro :1; //罰印 7bit
			
			//_mem_data_controler[2]
			BOOL _btn_right_1 :1; //0bit
			BOOL _btn_left_1  :1; //1bit
			BOOL _btn_right_2 :1; //2bit
			BOOL _btn_left_2  :1; //3bit
			BOOL _btn_right_3 :1; //4bit
			BOOL _btn_left_3  :1; //5bit
			BOOL _btn_start   :1; //6bit
			BOOL _btn_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[__CON_BYTE__];
		S_CONTR_ps2 _data_bit;
		
		void Write (T_DATA_8 _arg_arr_data[__CON_BYTE_UART__])
		{
			_data_bit._btn_cross_x = F_Func_direc_x(F_Check_bit_bool(_arg_arr_data[1],1),F_Check_bit_bool(_arg_arr_data[0],5));
			_data_bit._btn_cross_y = F_Func_direc_y(F_Check_bit_bool(_arg_arr_data[0],4),F_Check_bit_bool(_arg_arr_data[1],0));
			
			_data_bit._stick_left_x = F_Func_direc_x(_arg_arr_data[3],2);
			_data_bit._stick_left_y = F_Func_turn_direc_y(_arg_arr_data[3],4);
			
			_data_bit._stick_right_x = F_Func_direc_x(_arg_arr_data[2],4);
			_data_bit._stick_right_y = F_Func_turn_direc_y(_arg_arr_data[3],0);
			
			_data_bit._btn_start   = F_Check_turn_bit_bool(_arg_arr_data[0],3);
			_data_bit._btn_select  = F_Check_turn_bit_bool(_arg_arr_data[0],0);
			
			_data_bit._btn_right_1 = F_Check_turn_bit_bool(_arg_arr_data[1],5);
			_data_bit._btn_right_2 = F_Check_turn_bit_bool(_arg_arr_data[1],3);
			_data_bit._btn_right_3 = F_Check_turn_bit_bool(_arg_arr_data[0],2);
			
			_data_bit._btn_left_1  = F_Check_turn_bit_bool(_arg_arr_data[1],4);
			_data_bit._btn_left_2  = F_Check_turn_bit_bool(_arg_arr_data[1],2);
			_data_bit._btn_left_3  = F_Check_turn_bit_bool(_arg_arr_data[0],1);
			
			_data_bit._btn_squ = F_Check_turn_bit_bool(_arg_arr_data[2],3);
			_data_bit._btn_cro = F_Check_turn_bit_bool(_arg_arr_data[2],2);
			_data_bit._btn_cir = F_Check_turn_bit_bool(_arg_arr_data[2],1);
			_data_bit._btn_tri = F_Check_turn_bit_bool(_arg_arr_data[2],0);
		}
	};
	
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
			E_DIRECX _btn_cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY _btn_cross_y :2; //十字キー y軸 2,3bit
			
			BOOL _btn_x :1; //x 4bit
			BOOL _btn_a :1; //a 5bit
			BOOL _btn_y :1; //y 6bit
			BOOL _btn_b :1; //b 7bit
			
			//_mem_data_controler[2]
			BOOL _btn_right :1; //0bit
			BOOL _btn_left  :1; //1bit
			BOOL _btn_right_z :1; //2bit
			BOOL _btn_left_z  :1; //3bit
			
			BOOL _none_		:1; //4bit
			BOOL _btn_home	:1; //5bit
			BOOL _btn_start   :1; //6bit
			BOOL _btn_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[__CON_BYTE__];
		S_CONTR_Wii _data_bit;
		
		void Write (T_DATA_8 _arg_arr_data[__CON_BYTE_UART__])
		{
			_data_bit._btn_cross_x = F_Func_direc_x(F_Check_bit_bool(_arg_arr_data[1], 1), F_Check_bit_bool(_arg_arr_data[0], 5));
			_data_bit._btn_cross_y = F_Func_direc_y(F_Check_bit_bool(_arg_arr_data[0], 4), F_Check_bit_bool(_arg_arr_data[1], 0));
			
			_data_bit._stick_left_x = F_Func_direc_x(_arg_arr_data[3], 2);
			_data_bit._stick_left_y = F_Func_direc_y(_arg_arr_data[3], 4);
			
			_data_bit._stick_right_x = F_Func_direc_x(_arg_arr_data[2], 4);
			_data_bit._stick_right_y = F_Func_direc_y(_arg_arr_data[3], 0);
			
			_data_bit._btn_start  = F_Check_turn_bit_bool(_arg_arr_data[0], 3);
			_data_bit._btn_select = F_Check_turn_bit_bool(_arg_arr_data[0], 0);
			_data_bit._btn_home   = F_Check_turn_bit_bool(_arg_arr_data[0], 1);
			
			_data_bit._btn_right = F_Check_turn_bit_bool(_arg_arr_data[1], 5);
			_data_bit._btn_right_z = F_Check_turn_bit_bool(_arg_arr_data[1], 3);
			
			_data_bit._btn_left  = F_Check_turn_bit_bool(_arg_arr_data[1], 4);
			_data_bit._btn_left_z  = F_Check_turn_bit_bool(_arg_arr_data[1], 2);
			
			_data_bit._btn_y = F_Check_turn_bit_bool(_arg_arr_data[2], 3);
			_data_bit._btn_b = F_Check_turn_bit_bool(_arg_arr_data[2], 2);
			_data_bit._btn_a = F_Check_turn_bit_bool(_arg_arr_data[2], 1);
			_data_bit._btn_x = F_Check_turn_bit_bool(_arg_arr_data[2], 0);
		}
	};
	
	/**
	 * \brief 
	 * コントローラからのデータを受け取る。
	 * 
	 * \param _arg_uart_r   : データが送られてくるUART
	 * \param _arg_arr_data : データが格納される場所
	 */
	void In(C_UART_R  &_arg_uart_r  ,T_DATA_8 _arg_arr_data[__CON_BYTE_UART__] );
	
	/**
	 * \brief 
	 * コントローラからのデータを受け取る。
	 * 
	 * \param _arg_uart_r   : データが送られてくるUART*2
	 * \param _arg_arr_data : データが格納される場所
	 */
	void In(C_UART_R2 &_arg_uart_r2 ,T_DATA_8 _arg_arr_data[__CON_BYTE_UART__] );
};

/************************************************************************/
//protected

inline void
C_CONTR ::
In
(
	C_UART_R & _arg_uart_r,
	T_DATA_8 _arg_arr_data[__CON_BYTE_UART__]
)
{
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
		
		if (_flag == 0x0f) return (void)0; //全データ受信完了
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
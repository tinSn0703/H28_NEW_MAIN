
#pragma once

class C_CONTR
{
	protected:
	
	#define CON_BYTE_UART 4	//受信したコントローラのデータのバイト数
	#define CON_BYTE 3		//プログラム内で扱うコントローラのデータのバイト数
	
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
			E_DIRECX _cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY _cross_y :2; //十字キー y軸 2,3bit
			BOOL _nf_tri :1; //三角 4bit
			BOOL _nf_cir :1; //円   5bit
			BOOL _nf_squ :1; //四角 6bit
			BOOL _nf_cro :1; //罰印 7bit
			
			//_mem_data_controler[2]
			BOOL _nf_right_1 :1; //0bit
			BOOL _nf_left_1  :1; //1bit
			BOOL _nf_right_2 :1; //2bit
			BOOL _nf_left_2  :1; //3bit
			BOOL _nf_right_3 :1; //4bit
			BOOL _nf_left_3  :1; //5bit
			BOOL _nf_start   :1; //6bit
			BOOL _nf_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[CON_BYTE];
		S_CONTR_ps2 _data_bit;
		
		void Set_data (T_DATA_8 _arg_arr_contr_ps2_data[CON_BYTE_UART])
		{
			_data_bit._cross_x = SET_DIREC_X(CHECK_BIT_TF(_arg_arr_contr_ps2_data[1],1),CHECK_BIT_TF(_arg_arr_contr_ps2_data[0],5));
			_data_bit._cross_y = SET_DIREC_Y(CHECK_BIT_TF(_arg_arr_contr_ps2_data[1],0),CHECK_BIT_TF(_arg_arr_contr_ps2_data[0],4));
			
			_data_bit._stick_left_x = SET_DIREC_X(_arg_arr_contr_ps2_data[3],2);
			_data_bit._stick_left_y = SET_DIREC_Y(_arg_arr_contr_ps2_data[3],4);
			
			_data_bit._stick_right_x = SET_DIREC_X(_arg_arr_contr_ps2_data[2],4);
			_data_bit._stick_right_y = SET_DIREC_Y(_arg_arr_contr_ps2_data[3],0);
			
			_data_bit._nf_start   = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[0],3);
			_data_bit._nf_select  = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[0],0);
			
			_data_bit._nf_right_1 = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[1],5);
			_data_bit._nf_right_2 = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[1],3);
			_data_bit._nf_right_3 = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[0],2);
			
			_data_bit._nf_left_1  = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[1],4);
			_data_bit._nf_left_2  = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[1],2);
			_data_bit._nf_left_3  = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[0],1);
			
			_data_bit._nf_squ = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[2],3);
			_data_bit._nf_cro = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[2],2);
			_data_bit._nf_cir = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[2],1);
			_data_bit._nf_tri = CHECK_TURN_BIT_TF(_arg_arr_contr_ps2_data[2],0);
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
			E_DIRECX _cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY _cross_y :2; //十字キー y軸 2,3bit
			
			BOOL _nf_x :1; //x 4bit
			BOOL _nf_a :1; //a 5bit
			BOOL _nf_y :1; //y 6bit
			BOOL _nf_b :1; //b 7bit
			
			//_mem_data_controler[2]
			BOOL _nf_right :1; //0bit
			BOOL _nf_left  :1; //1bit
			BOOL _nf_z_right :1; //2bit
			BOOL _nf_z_left  :1; //3bit
			
			BOOL _none_		:1; //4bit
			BOOL _nf_home	:1; //5bit
			BOOL _nf_start   :1; //6bit
			BOOL _nf_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[CON_BYTE];
		S_CONTR_Wii _data_bit;
		
		void Set_data (T_DATA_8 _arg_arr_contr_wii_data[CON_BYTE_UART])
		{
			_data_bit._cross_x = SET_DIREC_X(CHECK_BIT_TF(_arg_arr_contr_wii_data[1],1),CHECK_BIT_TF(_arg_arr_contr_wii_data[0],5));
			_data_bit._cross_y = SET_DIREC_Y(CHECK_BIT_TF(_arg_arr_contr_wii_data[0],4),CHECK_BIT_TF(_arg_arr_contr_wii_data[1],0));
			
			_data_bit._stick_left_x = SET_DIREC_X(_arg_arr_contr_wii_data[3],2);
			_data_bit._stick_left_y = SET_TURN_DIREC_Y(_arg_arr_contr_wii_data[3],4);
			
			_data_bit._stick_right_x = SET_DIREC_X(_arg_arr_contr_wii_data[2],4);
			_data_bit._stick_right_y = SET_TURN_DIREC_Y(_arg_arr_contr_wii_data[3],0);
			
			_data_bit._nf_start  = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[0],3);
			_data_bit._nf_select = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[0],0);
			_data_bit._nf_home   = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[0],1);
			
			_data_bit._nf_right = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[1],5);
			_data_bit._nf_z_right = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[1],3);
			
			_data_bit._nf_left  = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[1],4);
			_data_bit._nf_z_left  = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[1],2);
			
			_data_bit._nf_y = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[2],3);
			_data_bit._nf_b = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[2],2);
			_data_bit._nf_a = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[2],1);
			_data_bit._nf_x = CHECK_TURN_BIT_TF(_arg_arr_contr_wii_data[2],0);
		}
	};
	
	void In(C_UART_R  & ,T_DATA_8 [CON_BYTE_UART] );
	void In(C_UART_R2 & ,T_DATA_8 [CON_BYTE_UART] );
};

inline void
C_CONTR::
In
(
	C_UART_R & _arg_contr_uart_r,
	T_DATA_8 _arg_contr_data[CON_BYTE_UART] 
)
{	
	_arg_contr_uart_r.Check();
	
	if (_arg_contr_uart_r == EU_ERROR) //受信失敗
	{
		_arg_contr_data[0] = 0x3f;
		_arg_contr_data[1] = 0x7f;
		_arg_contr_data[2] = 0x8f;
		_arg_contr_data[3] = 0xc0;
		
		return (void)0;
	}
	
	usint _flag = 0;
	
	for (usint i = 0; i < 15; i++) //さすがに無限ループ化するのはまずいので
	{
		T_DATA_8 _temp = 0;
		
		_arg_contr_uart_r >> _temp;
		
		if (_arg_contr_uart_r != EU_ERROR)
		{
			_arg_contr_data[(_temp & 0xc0) >> 6] = _temp;
			
			_flag |= (1 << ((_temp & 0xc0) >> 6));
		}
		
		if (_flag == 0x0f) //データを全て得るまで続く
		{
			break;
		}
	}
};

inline void
C_CONTR::
In
(
	C_UART_R2 & _arg_contr_uart_r2,
	T_DATA_8 _arg_contr_data[CON_BYTE_UART]
)
{
	_arg_contr_uart_r2.Set_bit9_0(FALES);
	_arg_contr_uart_r2.Set_bit9_1(FALES);
	
	_arg_contr_uart_r2.Check();
	
	if (_arg_contr_uart_r2 == EU_ERROR) //受信失敗
	{
		_arg_contr_data[0] = 0x3f;
		_arg_contr_data[1] = 0x7f;
		_arg_contr_data[2] = 0x8f;
		_arg_contr_data[3] = 0xc0;
		
		return (void)0;
	}
	
	usint _flag = 0;
	
	for (usint i = 0; i < 15; i++) //さすがに無限ループ化するのはまずいので
	{
		T_DATA_8 _temp = 0;
		
		_arg_contr_uart_r2 >> _temp;
		
		if (_arg_contr_uart_r2 != EU_ERROR)
		{
			_arg_contr_data[(_temp & 0xc0) >> 6] = _temp;
			
			_flag |= (1 << ((_temp & 0xc0) >> 6));
		}
		
		if (_flag == 0x0f) //データを全て得るまで続く
		{
			break;
		}
	}
};

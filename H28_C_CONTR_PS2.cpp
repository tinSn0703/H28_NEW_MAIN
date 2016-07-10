﻿
#ifndef _H28_C_CONTR_PS2_CPP_
#define _H28_C_CONTR_PS2_CPP_ 1

/*
PS2コントローラ用
*/

class C_CONTR_ps2
{
	private:
	
	#define CON_BYTE_UART 4	//受信したコントローラのデータのバイト数
	#define CON_BYTE 3			//プログラム内で扱うコントローラのデータのバイト数
	
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
			E_DIRECX stick_right_x :2; //右スティック x方向 0,1bit
			E_DIRECY stick_right_y :2; //右スティック y方向 2,3bit
			E_DIRECX stick_left_x :2; //左スティック x方向 4,5bit
			E_DIRECY stick_left_y :2; //左スティック y方向 6,7bit
			
			//_mem_data_controler[1]
			E_DIRECX cross_x :2; //十字キー x軸 0,1bit
			E_DIRECY cross_y :2; //十字キー y軸 2,3bit
			E_LOGIC nf_tri :1; //三角 4bit
			E_LOGIC nf_cir :1; //円   5bit
			E_LOGIC nf_squ :1; //四角 6bit
			E_LOGIC nf_cro :1; //罰印 7bit
			
			//_mem_data_controler[2]
			E_LOGIC nf_right_1 :1; //0bit
			E_LOGIC nf_left_1  :1; //1bit
			E_LOGIC nf_right_2 :1; //2bit
			E_LOGIC nf_left_2  :1; //3bit
			E_LOGIC nf_right_3 :1; //4bit
			E_LOGIC nf_left_3  :1; //5bit
			E_LOGIC nf_start   :1; //6bit
			E_LOGIC nf_select  :1; //7bit
		};
		
		uchar _arr_data_byte[CON_BYTE];
		S_CONTR_ps2 data_bit;
	};
	
	U_CONTR_ps2 _mem_contr_ps2_data;
	
	protected:
	void Set_data(T_DATA []);
	
	public:
	C_CONTR_ps2();
	
	E_DIRECX Ret_cross_x()	{	return _mem_contr_ps2_data.data_bit.cross_x;		}
	E_DIRECY Ret_cross_y()	{	return _mem_contr_ps2_data.data_bit.cross_y;		}
	E_DIRECX Ret_rsti_x()	{	return _mem_contr_ps2_data.data_bit.stick_right_x;	}
	E_DIRECX Ret_lsti_x()	{	return _mem_contr_ps2_data.data_bit.stick_left_x;	}
	E_DIRECY Ret_rsti_y()	{	return _mem_contr_ps2_data.data_bit.stick_right_y;	}
	E_DIRECY Ret_lsti_y()	{	return _mem_contr_ps2_data.data_bit.stick_left_y;	}
	E_LOGIC  Ret_select()	{	return _mem_contr_ps2_data.data_bit.nf_select;		}
	E_LOGIC  Ret_start()	{	return _mem_contr_ps2_data.data_bit.nf_start;		}
	E_LOGIC  Ret_tri()		{	return _mem_contr_ps2_data.data_bit.nf_tri;			}
	E_LOGIC  Ret_cir()		{	return _mem_contr_ps2_data.data_bit.nf_cir;			}
	E_LOGIC  Ret_squ()		{	return _mem_contr_ps2_data.data_bit.nf_squ;			}
	E_LOGIC  Ret_cro()		{	return _mem_contr_ps2_data.data_bit.nf_cro;			}
	E_LOGIC  Ret_r1()		{	return _mem_contr_ps2_data.data_bit.nf_right_1;		}
	E_LOGIC  Ret_r2()		{	return _mem_contr_ps2_data.data_bit.nf_right_2;		}
	E_LOGIC  Ret_r3()		{	return _mem_contr_ps2_data.data_bit.nf_right_3;		}
	E_LOGIC  Ret_l1()		{	return _mem_contr_ps2_data.data_bit.nf_left_1;		}
	E_LOGIC  Ret_l2()		{	return _mem_contr_ps2_data.data_bit.nf_left_2;		}
	E_LOGIC  Ret_l3()		{	return _mem_contr_ps2_data.data_bit.nf_left_3;		}
	
	uchar Ret_data(usint _arg_num_data)	{	return _mem_contr_ps2_data._arr_data_byte[_arg_num_data];	}
	
	void In(C_UART_R &);
	void In(C_UART_R2 &);
	void Reset();
};

//protected
inline void C_CONTR_ps2::Set_data(T_DATA _arg_contr_ps2_data[CON_BYTE_UART])
{	
	if (CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],5))		_mem_contr_ps2_data.data_bit.cross_x = ED_EAST;
	else if (CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],1))	_mem_contr_ps2_data.data_bit.cross_x = ED_WEST;
	else													_mem_contr_ps2_data.data_bit.cross_x = ED_XZERO;
	
	if (CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],0))		_mem_contr_ps2_data.data_bit.cross_y = ED_SOUTH;
	else if (CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],4))	_mem_contr_ps2_data.data_bit.cross_y = ED_NORTH;
	else													_mem_contr_ps2_data.data_bit.cross_y = ED_YZERO;
	
	if (CHECK_BIT_TF(_arg_contr_ps2_data[3],5))			_mem_contr_ps2_data.data_bit.stick_left_y = ED_SOUTH;
	else if (CHECK_BIT_TF(_arg_contr_ps2_data[3],4))	_mem_contr_ps2_data.data_bit.stick_left_y = ED_NORTH;
	else												_mem_contr_ps2_data.data_bit.stick_left_y = ED_YZERO;
	
	if (CHECK_BIT_TF(_arg_contr_ps2_data[3],3))			_mem_contr_ps2_data.data_bit.stick_left_x = ED_WEST;
	else if (CHECK_BIT_TF(_arg_contr_ps2_data[3],2))	_mem_contr_ps2_data.data_bit.stick_left_x = ED_EAST;
	else												_mem_contr_ps2_data.data_bit.stick_left_x = ED_XZERO;
	
	if (CHECK_BIT_TF(_arg_contr_ps2_data[3],1))			_mem_contr_ps2_data.data_bit.stick_right_y = ED_SOUTH;
	else if (CHECK_BIT_TF(_arg_contr_ps2_data[3],0))	_mem_contr_ps2_data.data_bit.stick_right_y = ED_NORTH;
	else												_mem_contr_ps2_data.data_bit.stick_right_y = ED_YZERO;
	
	if (CHECK_BIT_TF(_arg_contr_ps2_data[2],5))			_mem_contr_ps2_data.data_bit.stick_right_x = ED_WEST;
	else if (CHECK_BIT_TF(_arg_contr_ps2_data[2],4))	_mem_contr_ps2_data.data_bit.stick_right_x = ED_EAST;
	else												_mem_contr_ps2_data.data_bit.stick_right_x = ED_XZERO;
	
	_mem_contr_ps2_data.data_bit.nf_start   = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],3);
	_mem_contr_ps2_data.data_bit.nf_select  = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],0);
	
	_mem_contr_ps2_data.data_bit.nf_right_1 = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],5);
	_mem_contr_ps2_data.data_bit.nf_right_2 = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],3);
	_mem_contr_ps2_data.data_bit.nf_right_3 = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],2);
	
	_mem_contr_ps2_data.data_bit.nf_left_1  = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],4);
	_mem_contr_ps2_data.data_bit.nf_left_2  = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[1],2);
	_mem_contr_ps2_data.data_bit.nf_left_3  = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[0],1);
	
	_mem_contr_ps2_data.data_bit.nf_squ = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[2],3);
	_mem_contr_ps2_data.data_bit.nf_cro = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[2],2);
	_mem_contr_ps2_data.data_bit.nf_cir = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[2],1);
	_mem_contr_ps2_data.data_bit.nf_tri = CHECK_TURN_BIT_TF(_arg_contr_ps2_data[2],0);
}

//public
inline C_CONTR_ps2::C_CONTR_ps2()
{
	Reset();
}

void C_CONTR_ps2::In(C_UART_R &_arg_contr_ps2_uart_r)
{
	_arg_contr_ps2_uart_r.Set_bit9(FALES);
	
	_arg_contr_ps2_uart_r.Check();
	
	if (_arg_contr_ps2_uart_r.Ret_flag() == EU_ERROR)
	{
		Reset();
		return (void)0;
	}
	
	usint _flag = 0;
	
	usint i = 0;
	
	T_DATA _temp_data[CON_BYTE_UART] = {};
	
	while (_flag != 0x0f)
	{
		T_DATA _temp = _arg_contr_ps2_uart_r.In();
		
		if (_temp != IN_ERROR)
		{
			_temp_data[(_temp & 0xc0) >> 6] = _temp;
			
			_flag |= (1 << ((_temp & 0xc0) >> 6));
		}
		
		if (i == 15)	break;
		
		i++;
	}
	
	Set_data(_temp_data);
}

void C_CONTR_ps2::In(C_UART_R2 &_arg_contr_ps2_uart_r2)
{
	_arg_contr_ps2_uart_r2.Set_bit9_0(FALES);
	_arg_contr_ps2_uart_r2.Set_bit9_1(FALES);
	
	_arg_contr_ps2_uart_r2.Check();
	
	if (_arg_contr_ps2_uart_r2.Ret_flag() == EU_ERROR)
	{
		Reset();
		return (void)0;
	}
	
	usint _flag = 0;
	
	usint i = 0;
	
	T_DATA _temp_data[CON_BYTE_UART] = {};
	
	while (_flag != 0x0f)
	{
		T_DATA _temp = _arg_contr_ps2_uart_r2.In();
		
		if (_temp != IN_ERROR)
		{
			_temp_data[(_temp >> 6) & 0x03] = _temp;
			
			_flag |= (1 << ((_temp >> 6) & 0x03));
		}
		
		if (i == 15)	break;
		
		i++;
	}
	
	Set_data(_temp_data);
}

inline void C_CONTR_ps2::Reset()
{
	_mem_contr_ps2_data._arr_data_byte[0] = 0xff;
	_mem_contr_ps2_data._arr_data_byte[1] = 0x0f;
	_mem_contr_ps2_data._arr_data_byte[2] = 0x00;
}

#endif
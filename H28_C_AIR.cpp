
#ifndef _H28_C_AIR_CPP_
#define _H28_C_AIR_CPP_ 1

class C_AIR
{
	private:
	
	union U_AIR
	{	
		struct S_AIR
		{
			E_LOGIC _air0 :1;
			E_LOGIC _air1 :1;
			E_LOGIC _air2 :1;
			E_LOGIC _air3 :1;
			E_LOGIC _air4 :1;
			E_LOGIC _air5 :1;
			E_LOGIC _air6 :1;
			E_LOGIC _air7 :1;
		};
		
		T_DATA _data_byte :8;
		S_AIR _data_bit;
	};
	
	U_AIR _mem_air_data;
	E_LOGIC _mem_array_air_flag[8];
	
	public:
	C_AIR(T_DATA );
		
	void Set(T_DATA );
	void Set_num(T_NUM ,E_LOGIC );
	
	void Turn();
	void Turn_num(T_NUM );
	
	T_DATA Ret()						{	return _mem_air_data._data_byte;								}
	E_LOGIC Ret_num(T_NUM _arg_air_num)	{	return CHECK_BIT_TF(_mem_air_data._data_byte,_arg_air_num);	}
	
	void Set_0(E_LOGIC _arg_air_nf_0)	{	_mem_air_data._data_bit._air0 = _arg_air_nf_0;	}
	void Set_1(E_LOGIC _arg_air_nf_1)	{	_mem_air_data._data_bit._air1 = _arg_air_nf_1;	}
	void Set_2(E_LOGIC _arg_air_nf_2)	{	_mem_air_data._data_bit._air2 = _arg_air_nf_2;	}
	void Set_3(E_LOGIC _arg_air_nf_3)	{	_mem_air_data._data_bit._air3 = _arg_air_nf_3;	}
	void Set_4(E_LOGIC _arg_air_nf_4)	{	_mem_air_data._data_bit._air4 = _arg_air_nf_4;	}
	void Set_5(E_LOGIC _arg_air_nf_5)	{	_mem_air_data._data_bit._air5 = _arg_air_nf_5;	}
	void Set_6(E_LOGIC _arg_air_nf_6)	{	_mem_air_data._data_bit._air6 = _arg_air_nf_6;	}
	void Set_7(E_LOGIC _arg_air_nf_7)	{	_mem_air_data._data_bit._air7 = _arg_air_nf_7;	}

	void Turn_0()	{	_mem_air_data._data_bit._air0 = TURN_TF(_mem_air_data._data_bit._air0);	}
	void Turn_1()	{	_mem_air_data._data_bit._air1 = TURN_TF(_mem_air_data._data_bit._air1);	}
	void Turn_2()	{	_mem_air_data._data_bit._air2 = TURN_TF(_mem_air_data._data_bit._air2);	}
	void Turn_3()	{	_mem_air_data._data_bit._air3 = TURN_TF(_mem_air_data._data_bit._air3);	}
	void Turn_4()	{	_mem_air_data._data_bit._air4 = TURN_TF(_mem_air_data._data_bit._air4);	}
	void Turn_5()	{	_mem_air_data._data_bit._air5 = TURN_TF(_mem_air_data._data_bit._air5);	}
	void Turn_6()	{	_mem_air_data._data_bit._air6 = TURN_TF(_mem_air_data._data_bit._air6);	}
	void Turn_7()	{	_mem_air_data._data_bit._air7 = TURN_TF(_mem_air_data._data_bit._air7);	}
		
	E_LOGIC Ret_0()	{	return _mem_air_data._data_bit._air0;	}
	E_LOGIC Ret_1()	{	return _mem_air_data._data_bit._air1;	}
	E_LOGIC Ret_2()	{	return _mem_air_data._data_bit._air2;	}
	E_LOGIC Ret_3()	{	return _mem_air_data._data_bit._air3;	}
	E_LOGIC Ret_4()	{	return _mem_air_data._data_bit._air4;	}
	E_LOGIC Ret_5()	{	return _mem_air_data._data_bit._air5;	}
	E_LOGIC Ret_6()	{	return _mem_air_data._data_bit._air6;	}
	E_LOGIC Ret_7()	{	return _mem_air_data._data_bit._air7;	}

	void Do(T_NUM ,E_LOGIC );	
	void Do(T_NUM ,E_LOGIC ,E_LOGIC &);
	void Do(T_NUM ,T_NUM ,E_LOGIC ,E_LOGIC &);
	
	void Out(C_UART_T );
};

inline C_AIR::C_AIR(T_DATA _arg_air_data = 0x00)
{
	_mem_air_data._data_byte = _arg_air_data;
	
	for (usint i = 0; i < 8; i++)	_mem_array_air_flag[i] = TRUE;
}

inline void C_AIR::Set(T_DATA _arg_air_data)
{
	_mem_air_data._data_byte = _arg_air_data;
}

inline void C_AIR::Set_num(T_NUM _arg_air_num,E_LOGIC _arg_air_nf)
{
	switch (_arg_air_nf)
	{
		case TRUE:	_mem_air_data._data_byte |=  (1 << _arg_air_num);	break;
		case FALES:	_mem_air_data._data_byte &= ~(1 << _arg_air_num);	break;
	}
}

inline void C_AIR::Turn()
{
	_mem_air_data._data_byte = ~(_mem_air_data._data_byte);
}

inline void C_AIR::Turn_num(T_NUM  _arg_air_num)
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


inline void C_AIR::Do(T_NUM _arg_air_num, E_LOGIC _arg_air_nf)
//3port or 2port
{
	if (_arg_air_nf == TRUE)
	{
		if (_mem_array_air_flag[_arg_air_num] == TRUE)
		{
			Turn_num(_arg_air_num);
		}
		
		_mem_array_air_flag[_arg_air_num] = FALES;
	}
	else
	{
		_mem_array_air_flag[_arg_air_num] = TRUE;
	}
}

inline void C_AIR::Do(T_NUM _arg_air_num, E_LOGIC _arg_air_nf, E_LOGIC &_arg_nf_timer)
//3port or 2port
{
	if (_arg_air_nf == TRUE)
	{
		if ((_mem_array_air_flag[_arg_air_num] & _arg_nf_timer) == TRUE)
		{
			Turn_num(_arg_air_num);
		}
		
		_mem_array_air_flag[_arg_air_num] = FALES;
	}
	else
	{
		_mem_array_air_flag[_arg_air_num] = TRUE;
	}
}

inline void C_AIR::Do(T_NUM _arg_air_num_0, T_NUM _arg_air_num_1, E_LOGIC _arg_air_flag ,E_LOGIC &_arg_nf_timer)
//5port
{	
	if (_arg_air_flag)
	{
		if (_mem_array_air_flag[_arg_air_num_0] == FALES)	return (void)0;
		
		switch (_mem_array_air_flag[_arg_air_num_1])
		{
			case TRUE:
			{
				if (Ret_num(_arg_air_num_0))	_arg_nf_timer = FALES;
				
				Set_num(_arg_air_num_0,FALES);
				
				break;
			}
			case FALES:
			{
				if (Ret_num(_arg_air_num_1))	_arg_nf_timer = FALES;
				
				Set_num(_arg_air_num_1,FALES);
				
				break;
			}
		}
	}
	else
	{
		if (_mem_array_air_flag[_arg_air_num_0])
		{			
			if (Ret_num(_arg_air_num_0) | Ret_num(_arg_air_num_1) | TURN_TF(_arg_nf_timer))	return (void)0;
			
			switch (_mem_array_air_flag[_arg_air_num_1])
			{
				case TRUE:
				{
					Set_num(_arg_air_num_1,TRUE);
					
					_mem_array_air_flag[_arg_air_num_0] = FALES;
					_mem_array_air_flag[_arg_air_num_1] = TURN_TF(_mem_array_air_flag[_arg_air_num_1]);
					
					break;
				}
				case FALES:
				{
					Set_num(_arg_air_num_0,TRUE);
					
					_mem_array_air_flag[_arg_air_num_0] = FALES;
					_mem_array_air_flag[_arg_air_num_1] = TURN_TF(_mem_array_air_flag[_arg_air_num_1]);
					
					break;
				}
			}
		}
		else
		{
			_mem_array_air_flag[_arg_air_num_0] = TRUE;
		}
	}
}

void C_AIR::Out(C_UART_T _arg_air_uart_t)
{
	_arg_air_uart_t.Set_bit9(FALES);
	
	_arg_air_uart_t << _mem_air_data._data_byte;
}

#endif
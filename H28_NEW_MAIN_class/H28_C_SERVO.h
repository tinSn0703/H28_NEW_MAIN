
#pragma once

class C_SERVO
{
private:
	
	union U_SERVO
	{
		struct S_SERVO
		{
			T_DATA_8 _angle :5;
			T_DATA_8 _num :3;
		};
		
		S_SERVO _bit;
		T_DATA_8 _byte :8;
	};
	
	U_SERVO _mem_servo_data;
	
public:
	
	C_SERVO()	{}
		
	C_SERVO(T_DATA_8 _arg_num);
	
	void Set(T_DATA_8 _arg_angle);
	
	T_DATA_8 Ret();
	
	T_DATA_8 Ret_angle();
	
	T_DATA_8 Ret_num();
	
	void Out(C_UART_T &_arg_uart_t);
};

#include "H28_C_SERVO.cpp"


#pragma once

/*************************************************************************

SERVO回路に接続するモータ操作用のクラス

1オブジェクトでサーボモータ1つまで

新旧両方を操作可能にします。(2016 12 / 18現在は新回路のみ)

新回路はサーボモータを8個動かすことが可能
旧回路はサーボモータを2個動かすことが可能

*************************************************************************/


class C_SERVO
{
private:
	
	union U_SERVO
	{
		struct S_SERVO_old
		{
			T_DATA_8 _angle :7;
			T_DATA_8 _num	:1;	
		};
		
		struct S_SERVO_new
		{
			T_DATA_8 _angle :5;
			T_DATA_8 _num	:3;
		};
		
		S_SERVO_old _bit_old;
		S_SERVO_new _bit_new;
		T_DATA_8 _byte :8;
	};
	
	U_SERVO _mem_servo_data;
	
public:
	
	C_SERVO()	{}
		
	C_SERVO (T_DATA_8 _arg_num, T_DATA_8 _arg_angle);
	
	void Set (T_DATA_8 _arg_angle);
	
	void Out (C_UART_T &_arg_uart_t);
	
	T_DATA_8 Ret ()	{	return _mem_servo_data._byte;	}

	T_DATA_8 Ret_num ()	{	return _mem_servo_data._bit_new._num;	}

	T_DATA_8 Ret_angle ()	{	return _mem_servo_data._bit_new._angle;	}
};

/************************************************************************/
//public

inline
C_SERVO ::
C_SERVO 
(
	const T_DATA_8 _arg_num, 
	const T_DATA_8 _arg_angle = 0
)
{
	_mem_servo_data._bit_new._num = _arg_num;
	_mem_servo_data._bit_new._angle = _arg_angle;
}

inline void
C_SERVO ::
Set (const T_DATA_8 _arg_angle)
{
	_mem_servo_data._bit_new._angle = _arg_angle;
}

inline void
C_SERVO ::
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_off();
	
	_arg_uart_t.Out(_mem_servo_data._byte);
}

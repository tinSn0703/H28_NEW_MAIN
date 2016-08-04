
#pragma once

/*
H28 05 04 現在のMDのデータをまとめた構造体
PWM 0x1f 段階 , 段々制御有
ver 0.0.0 H28 05 04
ver 1.0.0 H28 05 24 共用体と構造体を活用してみました
*/

class C_MD_MAIN
{
	private:
	
	union U_MD_0
	{
		struct S_MD_0 //順番変えるな
		{
			E_SIG _md_0_sig_mode	:2;
			BOOL _md_0_nf_steps	:1;
			T_NUM _md_0_without		:2;
			T_NUM _md_0_num_data	:1;
			T_NUM _md_0_num_md		:2;
			T_NUM _md_0_num_mdc		:1; 
			
		};
		
		S_MD_0 _md_0_data_bit;
		T_DATA _md_0_data :9;
	};
	
	union U_MD_1
	{
		struct S_MD_1 //順番変えるな
		{
			T_PWM _md_1_pwm_value	:5;
			T_NUM _md_1_num_data	:1;
			T_NUM _md_1_num_md		:2;
			T_NUM _md_1_num_mdc		:1;
		};
		
		S_MD_1 _md_1_data_bit;
		T_DATA _md_1_data :9;
	};
	
	U_MD_0 _mem_md_main_data_0;
	U_MD_1 _mem_md_main_data_1;
	
	sint _mem_md_main_pwm_revis :6;
	
	BOOL _mem_md_main_nf_turn :1;
	
	#define MD_DATA_NUM_0 0
	#define MD_DATA_NUM_1 1
	
	public:

	C_MD_MAIN()	{}
	C_MD_MAIN(T_NUM ,T_NUM ,BOOL ,sint);
	
	void Chan_md(T_NUM );
	
	void Out(C_UART_T &);
	
	//データセット
	void Set_turn(BOOL );
	void Set_data(E_SIG ,T_PWM ,BOOL);
	void Set_pwm(T_PWM );
	void Set_sig(E_SIG );
	void Set_steps(BOOL );
	void Set_pwm_revis(sint );
	
	//データ表示
	T_DATA Ret_data_0()	{	return _mem_md_main_data_0._md_0_data;	}
	T_DATA Ret_data_1()	{	return _mem_md_main_data_1._md_1_data;	}
	T_NUM Ret_num_mdc()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_mdc;	}
	T_NUM Ret_num_md()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_md;		}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0._md_0_data_bit._md_0_sig_mode;	}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1._md_1_data_bit._md_1_pwm_value;	}
	BOOL Ret_steps()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_nf_steps;	}
	
	//Lcd表示
	void Lcd_sig_num(T_ADRS );
	void Lcd_sig_str(T_ADRS );	
	void Lcd_pwm(T_ADRS ,E_DECIMAL );
	void Lcd_data_2(T_ADRS ,T_NUM );
	void Lcd_data_16(T_ADRS ,T_NUM );
	void Lcd_md_num(T_ADRS );
};

inline 
C_MD_MAIN::
C_MD_MAIN
(
	T_NUM _arg_md_main_num_mdc, 
	T_NUM _arg_md_main_num_md ,
	BOOL _arg_md_main_nf_turn = FALSE ,
	sint _arg_md_main_pwm_revis = 0
)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_num_mdc = _arg_md_main_num_mdc;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_mdc = _arg_md_main_num_mdc;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_num_md = _arg_md_main_num_md;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_md = _arg_md_main_num_md;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_num_data = MD_DATA_NUM_0;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_data = MD_DATA_NUM_1;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_without = 0;
	
	_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode = ES_STOP;
	
	_mem_md_main_pwm_revis = _arg_md_main_pwm_revis;
	
	_mem_md_main_nf_turn = _arg_md_main_nf_turn;
}

inline void 
C_MD_MAIN::
Chan_md (T_NUM  _arg_md_main_num_md)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_num_md = _arg_md_main_num_md;
	_mem_md_main_data_1._md_1_data_bit._md_1_num_md = _arg_md_main_num_md;
}

inline void 
C_MD_MAIN::
Set_turn (BOOL _arg_md_main_nf_turn)
{
	_mem_md_main_nf_turn = _arg_md_main_nf_turn;
}

inline void 
C_MD_MAIN::
Set_pwm (T_PWM _arg_md_main_pwm_value)
{
	if (_arg_md_main_pwm_value != 0)
	{
		_arg_md_main_pwm_value += _mem_md_main_pwm_revis;
	}
	
	_mem_md_main_data_1._md_1_data_bit._md_1_pwm_value = _arg_md_main_pwm_value;
}

inline void 
C_MD_MAIN::
Set_sig (E_SIG _arg_md_main_sig_mode)
{
	if (CHECK_MOVE(_arg_md_main_sig_mode) == FALSE)
	{
		_mem_md_main_data_1._md_1_data_bit._md_1_pwm_value = 0;
	}
	
	if (_mem_md_main_nf_turn)
	{
		_arg_md_main_sig_mode = TURN_SIG_ROTATE(_arg_md_main_sig_mode);
	}
	
	
	_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode = _arg_md_main_sig_mode;
}

inline void 
C_MD_MAIN::
Set_steps (BOOL _arg_md_main_nf_steps = TRUE)
{
	_mem_md_main_data_0._md_0_data_bit._md_0_nf_steps = _arg_md_main_nf_steps;
}

inline void 
C_MD_MAIN::
Set_pwm_revis (sint _arg_md_main_pwm_revis)
/*
補正PWMの設定
-31 ~ +31の範囲にしてね
*/
{
	_mem_md_main_pwm_revis = _arg_md_main_pwm_revis;
}

inline void 
C_MD_MAIN::
Set_data
(
	E_SIG _arg_md_main_sig_mode, 
	T_PWM _arg_md_main_pwm_value = 0, 
	BOOL _arg_md_main_nf_steps = TRUE
)
{
	Set_pwm(_arg_md_main_pwm_value);
	Set_sig(_arg_md_main_sig_mode);
	Set_steps(_arg_md_main_nf_steps);
}

void 
C_MD_MAIN::
Out (C_UART_T &_arg_md_main_uart_t)
{
	_arg_md_main_uart_t.Set_bit9(TRUE);
	
	_arg_md_main_uart_t << _mem_md_main_data_0._md_0_data;
	_arg_md_main_uart_t << _mem_md_main_data_1._md_1_data;
	
	_delay_us(250);
}

void 
C_MD_MAIN::
Lcd_sig_num (T_ADRS _arg_md_main_adrs)
//1桁
//	0 FREE
//	1 FALSE
//	2 TRUE
//	3 STOP
{
	Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode,1,ED_10);
}

void 
C_MD_MAIN::
Lcd_sig_str (T_ADRS _arg_md_main_adrs)
//2桁
{
	switch (_mem_md_main_data_0._md_0_data_bit._md_0_sig_mode)
	{
		case ES_TRUE:	Lcd_put_str(_arg_md_main_adrs,"TR");	break;
		case ES_FALSE:	Lcd_put_str(_arg_md_main_adrs,"FA");	break;
		case ES_STOP:	Lcd_put_str(_arg_md_main_adrs,"ST");	break;
		case ES_FREE:	Lcd_put_str(_arg_md_main_adrs,"FR");	break;
	}
}

void 
C_MD_MAIN::
Lcd_pwm
(
	T_ADRS _arg_md_main_adrs,
	E_DECIMAL _arg_md_main_decimal
)
/*
設定されたPWMをLCDに表示する
2桁

	_arg_md_main_adrs : 表示するLCDの場所
	_arg_md_main_decimal : 表示する進数。ED_10、ED_16だけにしてね
*/
{
	if ((_arg_md_main_decimal != ED_10) && (_arg_md_main_decimal != ED_16))
	{
		Lcd_put_str(_arg_md_main_adrs,"ERROR");
		return (void)0;
	}
	
	Lcd_put_num(_arg_md_main_adrs, _mem_md_main_data_1._md_1_data_bit._md_1_pwm_value, 2, _arg_md_main_decimal);
}

void 
C_MD_MAIN::
Lcd_data_2
(
	T_ADRS _arg_md_main_adrs,
	T_NUM _arg_md_main_num_data
)
//9桁
{
	switch (_arg_md_main_num_data)
	{
		case 0:		
		{
			Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_0._md_0_data,9,ED_02);
			break;
		}
		case 1:
		{
			Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_1._md_1_data,9,ED_02);
			break;
		}
		default:
		{
			Lcd_put_str(_arg_md_main_adrs,"ERROR");
			break;
		}
	}
}

void 
C_MD_MAIN::
Lcd_data_16
(
	T_ADRS _arg_md_main_adrs,
	T_NUM _arg_md_main_num_data
)
//3桁
{
	switch (_arg_md_main_num_data)
	{
		case 0:
		{
			Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_0._md_0_data,3,ED_16);
			break;
		}
		case 1:
		{
			Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_1._md_1_data,3,ED_16);
			break;
		}
		default:
		{
			Lcd_put_str(_arg_md_main_adrs,"ERROR");
			break;
		}
	}
}

void 
C_MD_MAIN::
Lcd_md_num (T_ADRS _arg_md_main_adrs)
//1桁
{
	Lcd_put_num(_arg_md_main_adrs,_mem_md_main_data_0._md_0_data_bit._md_0_num_md,1,ED_10);
}
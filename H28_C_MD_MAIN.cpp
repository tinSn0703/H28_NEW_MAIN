
#ifndef _H28_C_MD_MAIN_CPP_
#define _H28_C_MD_MAIN_CPP_ 1

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
		struct S_MD_0
		{
			E_SIG md_0_sig_mode	  :2;
			E_LOGIC md_0_nf_steps :1;
			T_NUM md_0_without	  :2;
			T_NUM md_0_num_data	  :1;
			T_NUM md_0_num_md	  :2;
			T_NUM md_0_num_mdc	  :1;
			
		};
		
		S_MD_0 md_0_data_bit;
		T_DATA md_0_data :9;
	};
	
	union U_MD_1
	{
		struct S_MD_1
		{
			T_PWM md_1_pwm_value :5;
			T_NUM md_1_num_data	 :1;
			T_NUM md_1_num_md	 :2;
			T_NUM md_1_num_mdc	 :1;
		};
		
		S_MD_1 md_1_data_bit;
		T_DATA md_1_data :9;
	};
	
	U_MD_0 _mem_md_main_data_0;
	U_MD_1 _mem_md_main_data_1;
	
	sint _mem_md_main_pwm_revis :6;
	
	E_LOGIC _mem_md_main_nf_turn :1;
	
	#define MD_DATA_NUM_0 0
	#define MD_DATA_NUM_1 1
	
	public:

	C_MD_MAIN()	{}
	C_MD_MAIN(T_NUM ,T_NUM ,E_LOGIC ,sint);
	
	void Chan_md(T_NUM );
	
	void Out(C_UART_T &);
	
	void Set_turn(E_LOGIC );
	void Set_data(E_SIG ,T_PWM ,E_LOGIC);
	void Set_pwm(T_PWM );
	void Set_sig(E_SIG );
	void Set_steps(E_LOGIC );
	void Set_pwm_revis(sint );
	
	T_DATA Ret_data_0()	{	return _mem_md_main_data_0.md_0_data;	}
	T_DATA Ret_data_1()	{	return _mem_md_main_data_1.md_1_data;	}
	
	T_NUM Ret_num_mdc()	{	return _mem_md_main_data_0.md_0_data_bit.md_0_num_mdc;	}
	T_NUM Ret_num_md()	{	return _mem_md_main_data_0.md_0_data_bit.md_0_num_md;	}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0.md_0_data_bit.md_0_sig_mode;	}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1.md_1_data_bit.md_1_pwm_value;}
	E_LOGIC Ret_steps()	{	return _mem_md_main_data_0.md_0_data_bit.md_0_nf_steps;	}
};

inline C_MD_MAIN::C_MD_MAIN(T_NUM _arg_md_main_num_mdc, T_NUM _arg_md_main_num_md ,E_LOGIC _arg_md_main_nf_turn = FALES ,sint _arg_md_main_pwm_revis = 0)
{
	_mem_md_main_data_0.md_0_data_bit.md_0_num_mdc = _arg_md_main_num_mdc;
	_mem_md_main_data_1.md_1_data_bit.md_1_num_mdc = _arg_md_main_num_mdc;
	
	_mem_md_main_data_0.md_0_data_bit.md_0_num_md = _arg_md_main_num_md;
	_mem_md_main_data_1.md_1_data_bit.md_1_num_md = _arg_md_main_num_md;
	
	_mem_md_main_data_0.md_0_data_bit.md_0_num_data = MD_DATA_NUM_0;
	_mem_md_main_data_1.md_1_data_bit.md_1_num_data = MD_DATA_NUM_1;
	
	_mem_md_main_data_0.md_0_data_bit.md_0_without = 0;
	
	_mem_md_main_data_0.md_0_data_bit.md_0_sig_mode = ES_STOP;
	
	_mem_md_main_pwm_revis = _arg_md_main_pwm_revis;
	
	_mem_md_main_nf_turn = _arg_md_main_nf_turn;
}

inline void C_MD_MAIN::Chan_md(T_NUM  _arg_md_main_num_md)
{
	_mem_md_main_data_0.md_0_data_bit.md_0_num_md = _arg_md_main_num_md;
	_mem_md_main_data_1.md_1_data_bit.md_1_num_md = _arg_md_main_num_md;
}

inline void C_MD_MAIN::Set_turn(E_LOGIC _arg_md_main_nf_turn)
{
	_mem_md_main_nf_turn = _arg_md_main_nf_turn;
}

inline void C_MD_MAIN::Set_pwm(T_PWM _arg_md_main_pwm_value)
{
	_mem_md_main_data_1.md_1_data_bit.md_1_pwm_value = _arg_md_main_pwm_value;
}

inline void C_MD_MAIN::Set_sig(E_SIG _arg_md_main_sig_mode)
{
	if (CHECK_MOVE(_arg_md_main_sig_mode) == FALES)	_mem_md_main_data_1.md_1_data_bit.md_1_pwm_value = 0;
	
	_mem_md_main_data_0.md_0_data_bit.md_0_sig_mode = _arg_md_main_sig_mode;
}

inline void C_MD_MAIN::Set_steps(E_LOGIC _arg_md_main_nf_steps = TRUE)
{
	_mem_md_main_data_0.md_0_data_bit.md_0_nf_steps = _arg_md_main_nf_steps;
}

inline void C_MD_MAIN::Set_pwm_revis(sint _arg_md_main_pwm_revis)
{
	_mem_md_main_pwm_revis = _arg_md_main_pwm_revis;
}

inline void C_MD_MAIN::Set_data(E_SIG _arg_md_main_sig_mode, T_PWM _arg_md_main_pwm_value = 0, E_LOGIC _arg_md_main_nf_steps = TRUE)
{
	Set_pwm(_arg_md_main_pwm_value);
	Set_sig(_arg_md_main_sig_mode);
	Set_steps(_arg_md_main_nf_steps);
}

void C_MD_MAIN::Out(C_UART_T &_arg_md_main_uart_t)
{
	if (_mem_md_main_data_1.md_1_data_bit.md_1_pwm_value != 0) _mem_md_main_data_1.md_1_data_bit.md_1_pwm_value += _mem_md_main_pwm_revis;
	
	if (_mem_md_main_nf_turn == TRUE)	_mem_md_main_data_0.md_0_data_bit.md_0_sig_mode = TURN_SIG_ROTATE(_mem_md_main_data_0.md_0_data_bit.md_0_sig_mode);
	
	_arg_md_main_uart_t.Set_bit9(TRUE);
	
	_arg_md_main_uart_t.Out(_mem_md_main_data_0.md_0_data);
	_arg_md_main_uart_t.Out(_mem_md_main_data_1.md_1_data);
	
	_delay_us(250);
}

#endif

#pragma once

class C_MD_MAIN
{
private:
	
	union U_MD_0
	{
		struct S_MD_0 //順番変えるな
		{
			E_SIG _md_0_sig_mode	:2;
			BOOL  _md_0_nf_steps	:1;
			usint _md_0_without		:2;
			usint _md_0_num_data	:1;
			usint _md_0_num_md		:2;
			usint _md_0_num_mdc		:1;
			
		};
		
		S_MD_0 _md_0_data_bit;
		T_DATA _md_0_data :9;
	};
	
	union U_MD_1
	{
		struct S_MD_1 //順番変えるな
		{
			T_PWM _md_1_pwm_value	:5;
			usint _md_1_num_data	:1;
			usint _md_1_num_md		:2;
			usint _md_1_num_mdc		:1;
		};
		
		S_MD_1 _md_1_data_bit;
		T_DATA _md_1_data :9;
	};
	
	U_MD_0 _mem_md_main_data_0;
	U_MD_1 _mem_md_main_data_1;
	
	sint _mem_md_main_pwm_revis :6;
	
	BOOL _mem_md_main_nf_sig_turn :1;
	
#	define MD_DATA_NUM_0 0
#	define MD_DATA_NUM_1 1
	
public:

	C_MD_MAIN()	{}
	C_MD_MAIN(usint ,usint ,BOOL ,sint);
	
	void Chan_md(usint );
	
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
	usint Ret_num_mdc()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_mdc;	}
	usint Ret_num_md()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_md;		}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0._md_0_data_bit._md_0_sig_mode;	}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1._md_1_data_bit._md_1_pwm_value;	}
	BOOL Ret_steps()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_nf_steps;	}
	
	//Lcd表示
	void Lcd_sig_num(T_ADRS );
	void Lcd_sig_str(T_ADRS );
	void Lcd_pwm(T_ADRS ,E_DECIMAL );
	void Lcd_data_2(T_ADRS ,usint );
	void Lcd_data_16(T_ADRS ,usint );
	void Lcd_md_num(T_ADRS );
};

#include "H28_C_MD_MAIN.cpp"
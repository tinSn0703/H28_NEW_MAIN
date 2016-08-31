
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
	
	BOOL _mem_md_main_nf_sig_reverse :1;
	
#	define MD_DATA_NUM_0 0
#	define MD_DATA_NUM_1 1
	
public:

	/**
	 * \brief 空のコンストラクタ。
	 */
	C_MD_MAIN()	{}
	
	/**
	 * \brief コンストラクタ。設定は以下の通り
	 * 
	 * \param _arg_num_mdc : MDCの番号(0~1)
	 * \param _arg_num_md  : MDの番号(0~3)
	 * \param _arg_nf_sig_turn : 正逆反転の使用について
	 * \param _arg_pwm_revis : 補正PWMの設定
	 */
	C_MD_MAIN(usint _arg_num_mdc, usint _arg_num_md, BOOL _arg_nf_sig_turn, sint _arg_pwm_revis);
	
	/**
	 * \brief 使うMDの番号を変える
	 * 
	 * \param _arg_num_md : MDの番号(0~3)
	 */
	void Chan_md(usint _arg_num_md);
	
	/**
	 * \brief 反転の設定を入れ替える
	 */
	void Chan_reverse();
	
	/**
	 * \brief MDCへデータを送信する
	 * 
	 * \param _arg_uart_t : 送信に使うUART
	 */
	void Out(C_UART_T &_arg_uart_t);
	
	//データセット
	
	/**
	 * \brief 動作の設定
	 * 
	 * \param _arg_sig_mode  : 動き
	 * \param _arg_pwm_value : PWM
	 * \param _arg_nf_steps  : 段々の使用について	
	 */
	void Set_data(E_SIG _arg_sig_mode, T_PWM _arg_pwm_value, BOOL _arg_nf_steps);
	
	/**
	 * \brief PWMの設定。Set_dataを使うのを推奨
	 * 
	 * \param _arg_pwm_value : PWM
	 */
	void Set_pwm(T_PWM _arg_pwm_value);
	
	/**
	 * \brief 補正PWMの設定。PWMの設定の前に行うこと
	 * 
	 * \param _arg_pwm_revis : 補正PWM。-31~+30の範囲で設定してね
	 */
	void Set_pwm_revis(sint _arg_pwm_revis);
	
	/**
	 * \brief 動作の設定
	 * 
	 * \param _arg_sig_mode : 動作
	 */
	void Set_sig(E_SIG _arg_sig_mode);
	
	/**
	 * \brief 正逆反転の設定。SIGの設定の前に行うこと
	 * 
	 * \param _arg_sig_turn 
	 *		TURE  -> 反転
	 *		FALSE -> そのまま
	 */
	void Set_turn(BOOL _arg_sig_turn);
	
	/**
	 * \brief 段々の設定
	 * 
	 * \param _arg_nf_steps : ONOFF
	 */
	void Set_steps(BOOL _arg_nf_steps);
	
	//データ表示
	T_DATA Ret_data_0()	{	return _mem_md_main_data_0._md_0_data;	}
	T_DATA Ret_data_1()	{	return _mem_md_main_data_1._md_1_data;	}
	usint Ret_num_mdc()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_mdc;	}
	usint Ret_num_md()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_num_md;		}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0._md_0_data_bit._md_0_sig_mode;	}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1._md_1_data_bit._md_1_pwm_value;	}
	BOOL Ret_steps()	{	return _mem_md_main_data_0._md_0_data_bit._md_0_nf_steps;	}
	BOOL Ret_turn()		{	return _mem_md_main_nf_sig_reverse;	}
	
	//Lcd表示
	
	/**
	 * \brief 
	 * SIGをLCDに数値で表示する. 10進数 1桁
	 *		0 -> ES_FREE
	 *		1 -> ES_FALSE
	 *		2 -> ES_TRUE
	 *		3 -> ES_STOP
	 * 
	 * \param _arg_adrs : 表示する場所
	 */
	void Lcd_sig_num(T_ADRS _arg_adrs);
	
	/**
	 * \brief 
	 * SIGをLCDに文字で表示する。2文字
	 *	ES_FREE  -> FR
	 *	ES_FALSE -> FA
	 *	ES_TRUE  -> TR
	 *	ES_STOP  -> ST
	 *
	 * \param _arg_adrs : 表示する場所
	 */
	void Lcd_sig_str(T_ADRS _arg_adrs);
	
	/**
	 * \brief PWMをLCDに表示する。2桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_decimal : 表示する進数。10か16にしてね
	 */
	void Lcd_pwm(T_ADRS _arg_adrs,E_DECIMAL _arg_decimal);
	
	/**
	 * \brief 全体のデータを表示する。2進数 9桁
	 *
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_num_data : 表示するデータの番号
	 */
	void Lcd_data_2(T_ADRS _arg_adrs,usint _arg_num_data);
	
	/**
	 * \brief 全体のデータを表示する。16進数 3桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_num_data : 表示するデータの番号
	 */
	void Lcd_data_16(T_ADRS _arg_adrs,usint _arg_num_data);
	
	/**
	 * \brief MDの番号をLCDに表示する。10進数 1桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 */
	void Lcd_md_num(T_ADRS _arg_adrs);
};

#include "H28_C_MD_MAIN.cpp"
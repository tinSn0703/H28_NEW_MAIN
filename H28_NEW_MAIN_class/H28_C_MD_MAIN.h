
#pragma once

/*
H28 05 04 現在のMDのデータをまとめた構造体
PWM 0x1f 段階 , 段々制御有
ver 0.0.0 H28 05 04
ver 1.0.0 H28 05 24 共用体と構造体を活用してみました
*/

/*************************************************************************

MD操作用のクラス

新型のMD限定

1オブジェクトにつきMD1つ操作可能

*************************************************************************/

class C_MD_MAIN
{
	
private:
	
	union U_MD_0
	{
		struct S_MD_0 //順番変えるな
		{
			E_SIG _sig		:2;
			BOOL  _nf_step	:1;
			usint _without	:2;
			usint _num_data	:1;
			usint _num_md	:2;
			usint _num_mdc	:1;
			
		};
		
		S_MD_0 _data_divi  ;
		T_DATA _data_all :9;
	};

	union U_MD_1
	{
		struct S_MD_1 //順番変えるな
		{
			T_PWM _pwm		:5;
			usint _num_data	:1;
			usint _num_md	:2;
			usint _num_mdc	:1;
		};
		
		S_MD_1 _data_divi  ;
		T_DATA _data_all :9;
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
	C_MD_MAIN (usint _arg_num_mdc, usint _arg_num_md, BOOL _arg_nf_sig_turn, sint _arg_pwm_revis);
	
	/**
	 * \brief 使うMDの番号を変える
	 * 
	 * \param _arg_num_md : MDの番号(0~3)
	 */
	void Reset_num_md (usint _arg_num_md);
	
	/**
	 * \brief 正逆反転の設定。SIGの設定の前に行うこと
	 * 
	 * \param _arg_sig_turn 
	 *		TURE  -> 反転
	 *		FALSE -> そのまま
	 */
	void Reset_sig_reverse (BOOL _arg_sig_turn);
	
	/**
	 * \brief 反転の設定を入れ替える
	 */
	void Turn_sig_reverse();
	
	/**
	 * \brief 動作の設定
	 * 
	 * \param _arg_sig_mode  : 動き
	 * \param _arg_pwm_value : PWM
	 * \param _arg_nf_steps  : 段々の使用について	
	 */
	void Write_data(E_SIG _arg_sig_mode, T_PWM _arg_pwm_value, BOOL _arg_nf_steps);
	
	/**
	 * \brief PWMの設定。Write_dataを使うのを推奨
	 * 
	 * \param _arg_pwm_value : PWM
	 */
	void Write_pwm(T_PWM _arg_pwm_value);
	
	/**
	 * \brief 補正PWMの設定。PWMの設定の前に行うこと
	 * 
	 * \param _arg_pwm_revis : 補正PWM。-31~+30の範囲で設定してね
	 */
	void Write_pwm_revis(sint _arg_pwm_revis);
	
	/**
	 * \brief 動作の設定
	 * 
	 * \param _arg_sig_mode : 動作
	 */
	void Write_sig(E_SIG _arg_sig_mode);
	
	/**
	 * \brief 段々の設定
	 * 
	 * \param _arg_nf_steps : ONOFF
	 */
	void Write_steps(BOOL _arg_nf_steps);
	
	/**
	 * \brief	モーターを回転させる設定を行う。両方FALSEの場合は、ES_STOP。
	 *
	 * \param _arg_motor_set_true	: ES_TRUEにする
	 * \param _arg_motor_set_false	: ES_FALSEにする
	 * \param _arg_pwm				: PWM
	 */
	void Do (BOOL _arg_motor_set_true, BOOL _arg_motor_set_false, T_PWM _arg_pwm);
	
	/**
	 * \brief	モーターを回転させる設定を行う。
	 *
	 * \param _arg_motor_set	: ED_EASTのときES_TRUE,ED_WESTのときES_FALSE,ED_XZEROのときES_STOP
	 * \param _arg_pwm			: PWM
	 */
	void Do (E_DIRECX _arg_motor_set, T_PWM _arg_pwm);
	
	/**
	 * \brief	モーターを回転させる設定を行う。
	 * 
	 * \param _arg_motor_set	: ED_NORTHのときES_TRUE,ED_SOUTHのときES_FALSE,ED_YZEROのときES_STOP
	 * \param _arg_pwm			: PWM
	 */
	void Do (E_DIRECY _arg_motor_set, T_PWM _arg_pwm);
	
	/**
	 * \brief MDCへデータを送信する
	 * 
	 * \param _arg_uart_t : 送信に使うUART
	 */
	void Out (C_UART_T &_arg_uart_t);
	
	/**
	 * \brinf	MDCへデータを送信する。送信と値の設定が同時に行える(値の設定の方が先)
	 *
	 * \param _arg_uart_t	: 送信に使うUART
	 * \param _arg_sig		: モータの動作
	 * \param _arg_pwm		: PWM
	 * \param _arg_nf_step	: 段々
	 */
	void Out (C_UART_T &_arg_uart_t, E_SIG _arg_sig, T_PWM _arg_pwm, BOOL _arg_nf_step);
	
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
	void Lcd_sig_num (T_ADRS _arg_adrs);
	
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
	void Lcd_sig_str (T_ADRS _arg_adrs);
	
	/**
	 * \brief PWMをLCDに表示する。2桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_decimal : 表示する進数。10か16にしてね
	 */
	void Lcd_pwm (T_ADRS _arg_adrs,E_DECIMAL _arg_decimal);
	
	/**
	 * \brief 全体のデータを表示する。2進数 9桁
	 *
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_num_data : 表示するデータの番号
	 */
	void Lcd_data_2 (T_ADRS _arg_adrs, usint _arg_num_data);
	
	/**
	 * \brief 全体のデータを表示する。16進数 3桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 * \param _arg_num_data : 表示するデータの番号
	 */
	void Lcd_data_16 (T_ADRS _arg_adrs, usint _arg_num_data);
	
	/**
	 * \brief MDの番号をLCDに表示する。10進数 1桁
	 * 
	 * \param _arg_adrs : 表示する場所
	 */
	void Lcd_md_num (T_ADRS _arg_adrs);
	
	T_DATA Ret_data_0()	{	return _mem_md_main_data_0._data_all;			}
	T_DATA Ret_data_1()	{	return _mem_md_main_data_1._data_all;			}
	usint Ret_num_mdc()	{	return _mem_md_main_data_0._data_divi._num_mdc;	}
	usint Ret_num_md()	{	return _mem_md_main_data_0._data_divi._num_md;	}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0._data_divi._sig;		}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1._data_divi._pwm;		}
	BOOL Ret_steps()	{	return _mem_md_main_data_0._data_divi._nf_step;	}
	BOOL Ret_reverse()	{	return _mem_md_main_nf_sig_reverse;				}
};

/************************************************************************/
//public

inline
C_MD_MAIN ::
C_MD_MAIN
(
	const usint _arg_num_mdc,
	const usint _arg_num_md ,
	const BOOL	_arg_nf_sig_turn = FALSE ,
	const sint	_arg_pwm_revis = 0
)
{
	_mem_md_main_data_0._data_divi._num_mdc = _arg_num_mdc;
	_mem_md_main_data_1._data_divi._num_mdc = _arg_num_mdc;
	
	_mem_md_main_data_0._data_divi._num_md = _arg_num_md;
	_mem_md_main_data_1._data_divi._num_md = _arg_num_md;
	
	_mem_md_main_data_0._data_divi._num_data = MD_DATA_NUM_0;
	_mem_md_main_data_1._data_divi._num_data = MD_DATA_NUM_1;
	
	_mem_md_main_data_0._data_divi._without = 0;
	
	_mem_md_main_data_0._data_divi._sig = ES_STOP;
	
	_mem_md_main_pwm_revis = _arg_pwm_revis;
	
	_mem_md_main_nf_sig_reverse = _arg_nf_sig_turn;
}

inline void
C_MD_MAIN ::
Reset_num_md (const usint  _arg_num_md)
{
	_mem_md_main_data_0._data_divi._num_md = _arg_num_md;
	_mem_md_main_data_1._data_divi._num_md = _arg_num_md;
}

inline void
C_MD_MAIN ::
Turn_sig_reverse ()
{
	_mem_md_main_nf_sig_reverse = F_Turn_bool(_mem_md_main_nf_sig_reverse);
}

inline void
C_MD_MAIN ::
Reset_sig_reverse (const BOOL _arg_nf_sig_reverse)
{
	_mem_md_main_nf_sig_reverse = _arg_nf_sig_reverse;
}

inline void
C_MD_MAIN ::
Write_pwm (T_PWM _arg_pwm_value)
{
	if (_arg_pwm_value != 0)	_arg_pwm_value += _mem_md_main_pwm_revis;
	
	if (_arg_pwm_value > 31)	_arg_pwm_value = 31;
	
	_mem_md_main_data_1._data_divi._pwm = _arg_pwm_value;
}

inline void
C_MD_MAIN ::
Write_sig (const E_SIG _arg_sig_mode)
{
	if (F_Check_pwm(_arg_sig_mode) == FALSE)	_mem_md_main_data_1._data_divi._pwm = 0;
	
	_mem_md_main_data_0._data_divi._sig = (_mem_md_main_nf_sig_reverse ? F_Turn_sig_rotate(_arg_sig_mode) : _arg_sig_mode);
}

inline void
C_MD_MAIN ::
Write_steps (const BOOL _arg_nf_steps = TRUE)
{
	_mem_md_main_data_0._data_divi._nf_step = _arg_nf_steps;
}

inline void
C_MD_MAIN ::
Write_pwm_revis (const sint _arg_pwm_revis)
{
	if ((-31 <= _arg_pwm_revis) && (_arg_pwm_revis <= 30) )
	{
		_mem_md_main_pwm_revis = _arg_pwm_revis;
	}
}

inline void
C_MD_MAIN ::
Write_data
(
	const E_SIG _arg_sig_mode,
	const T_PWM _arg_pwm_value = 0,
	const BOOL	_arg_nf_steps = TRUE
)
{
	Write_pwm(_arg_pwm_value);
	Write_sig(_arg_sig_mode);
	Write_steps(_arg_nf_steps);
}

inline void
C_MD_MAIN ::
Do
(
	const BOOL	_arg_motor_set_true,
	const BOOL	_arg_motor_set_false,
	const T_PWM _arg_pwm
)
{
	E_SIG _temp_sig = ES_STOP;
	
	if (_arg_motor_set_false)	_temp_sig = ES_FALSE;
	if (_arg_motor_set_true)	_temp_sig = ES_TRUE;
	
	
	Write_data(_temp_sig,_arg_pwm);
}

inline void
C_MD_MAIN ::
Do
(
	const E_DIRECX	_arg_motor_set,
	const T_PWM		_arg_pwm
)
{
	Write_data(F_Func_sig(_arg_motor_set), _arg_pwm);
}

inline void
C_MD_MAIN ::
Do
(
	const E_DIRECY	_arg_motor_set,
	const T_PWM		_arg_pwm
)
{
	Write_data(F_Func_sig(_arg_motor_set), _arg_pwm);
}

void
C_MD_MAIN ::
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_on();
	
	_arg_uart_t << _mem_md_main_data_0._data_all;
	_arg_uart_t << _mem_md_main_data_1._data_all;
	
	_delay_us(250);
}

void
C_MD_MAIN ::
Out
(
	C_UART_T	&_arg_uart_t,
	const E_SIG	 _arg_sig,
	const T_PWM  _arg_pwm,
	const BOOL	 _arg_nf_step
)
{
	Write_data(_arg_sig, _arg_pwm, _arg_nf_step);
	
	_arg_uart_t.Set_bit9_on();
	
	_arg_uart_t << _mem_md_main_data_0._data_all;
	_arg_uart_t << _mem_md_main_data_1._data_all;
	
	_delay_us(250);
}

void
C_MD_MAIN ::
Lcd_sig_num (const T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs,_mem_md_main_data_0._data_divi._sig,1,ED_10);
}

void
C_MD_MAIN ::
Lcd_sig_str (const T_ADRS _arg_adrs)
{
	switch (_mem_md_main_data_0._data_divi._sig)
	{
		case ES_TRUE:	Lcd_put_str(_arg_adrs,"TR");	break;
		case ES_FALSE:	Lcd_put_str(_arg_adrs,"FA");	break;
		case ES_STOP:	Lcd_put_str(_arg_adrs,"ST");	break;
		case ES_FREE:	Lcd_put_str(_arg_adrs,"FR");	break;
	}
}

void
C_MD_MAIN ::
Lcd_pwm
(
	const T_ADRS	_arg_adrs,
	const E_DECIMAL	_arg_decimal
)
{
	if ((_arg_decimal != ED_10) && (_arg_decimal != ED_16))
	{
		Lcd_put_str(_arg_adrs,"ERROR");
		return (void)0;
	}
	
	Lcd_put_num(_arg_adrs, _mem_md_main_data_1._data_divi._pwm, 2, _arg_decimal);
}

void
C_MD_MAIN ::
Lcd_data_2
(
	const T_ADRS	_arg_adrs,
	const usint		_arg_num_data
)
{
	switch (_arg_num_data)
	{
		case 0:		Lcd_put_num(_arg_adrs, _mem_md_main_data_0._data_all, 9, ED_02);	break;
		case 1:		Lcd_put_num(_arg_adrs, _mem_md_main_data_1._data_all, 9, ED_02);	break;
		default:	Lcd_put_str(_arg_adrs, "ERROR");									break;
	}
}

void
C_MD_MAIN ::
Lcd_data_16
(
	const T_ADRS	_arg_adrs,
	const usint		_arg_num_data
)
{
	switch (_arg_num_data)
	{
		case 0:		Lcd_put_num(_arg_adrs, _mem_md_main_data_0._data_all, 3, ED_16);	break;
		case 1:		Lcd_put_num(_arg_adrs, _mem_md_main_data_1._data_all, 3, ED_16);	break;
		default:	Lcd_put_str(_arg_adrs, "ERROR");									break;
	}
}

void
C_MD_MAIN ::
Lcd_md_num (const T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs, _mem_md_main_data_0._data_divi._num_md, 1, ED_10);
}
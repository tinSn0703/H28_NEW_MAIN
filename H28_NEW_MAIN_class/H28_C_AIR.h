
#pragma once

/**
 * 電磁弁回路を扱うためのクラス。使用可能なポート数は8
 */
class C_AIR
{
private:
	
	union U_AIR
	{
		struct S_AIR
		{
			BOOL _air0 :1;
			BOOL _air1 :1;
			BOOL _air2 :1;
			BOOL _air3 :1;
			BOOL _air4 :1;
			BOOL _air5 :1;
			BOOL _air6 :1;
			BOOL _air7 :1;
		};
		
		T_DATA_8 _data_byte :8;
		S_AIR _data_bit;
	};
	
	U_AIR _mem_air_data;
	BOOL _mem_array_air_flag[8];
	
public:
	
	/**
	 * \brief 
	 * コンストラクタ。
	 * 電磁弁回路へ送信するデータの初期設定を行うことができる
	 * 
	 * \param _arg_air_data : 初期設定。使う番号のbitに1を立ててね
	 */
	C_AIR(T_DATA_8 _arg_air_data);
	
	/**
	 * \brief 全ての電磁弁の設定をreturnする。
	 * 
	 * \return T_DATA_8 return.8bit
	 */
	T_DATA_8 Ret();
	
	/**
	 * \brief 指定された電磁弁の設定を返す
	 * 
	 * \param _arg_air_num : 電磁弁の指定
	 * 
	 * \return BOOL return
	 */
	BOOL Ret_num(T_NUM _arg_air_num);
	
	BOOL Ret_0()	{	return _mem_air_data._data_bit._air0;	}
	BOOL Ret_1()	{	return _mem_air_data._data_bit._air1;	}
	BOOL Ret_2()	{	return _mem_air_data._data_bit._air2;	}
	BOOL Ret_3()	{	return _mem_air_data._data_bit._air3;	}
	BOOL Ret_4()	{	return _mem_air_data._data_bit._air4;	}
	BOOL Ret_5()	{	return _mem_air_data._data_bit._air5;	}
	BOOL Ret_6()	{	return _mem_air_data._data_bit._air6;	}
	BOOL Ret_7()	{	return _mem_air_data._data_bit._air7;	}
	
	/**
	 * \brief 電磁弁全体のONOFFを設定する
	 * 
	 * \param _arg_air_data : 設定。使いたい番号のbitを1,0してください
	 */
	void Set(T_DATA_8 _arg_air_data);
	
	/**
	 * \brief 指定された電磁弁のONOFFの設定を行う
	 * 
	 * \param _arg_air_num : 設定する番号
	 * \param _arg_air_nf  : ONOFF
	 */
	void Set_num(T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	void Set_0(BOOL _arg_air_nf_0)	{	_mem_air_data._data_bit._air0 = _arg_air_nf_0;	}
	void Set_1(BOOL _arg_air_nf_1)	{	_mem_air_data._data_bit._air1 = _arg_air_nf_1;	}
	void Set_2(BOOL _arg_air_nf_2)	{	_mem_air_data._data_bit._air2 = _arg_air_nf_2;	}
	void Set_3(BOOL _arg_air_nf_3)	{	_mem_air_data._data_bit._air3 = _arg_air_nf_3;	}
	void Set_4(BOOL _arg_air_nf_4)	{	_mem_air_data._data_bit._air4 = _arg_air_nf_4;	}
	void Set_5(BOOL _arg_air_nf_5)	{	_mem_air_data._data_bit._air5 = _arg_air_nf_5;	}
	void Set_6(BOOL _arg_air_nf_6)	{	_mem_air_data._data_bit._air6 = _arg_air_nf_6;	}
	void Set_7(BOOL _arg_air_nf_7)	{	_mem_air_data._data_bit._air7 = _arg_air_nf_7;	}
	
	/**
	 * \brief 電磁弁の設定を反転させる
	 */
	void Turn();
	
	/**
	 * \brief 指定された電磁弁の設定を反転させる 
	 *
	 * \param _arg_air_num : 電磁弁の指定
	 */
	void Turn_num(T_NUM _arg_air_num);

	void Turn_0()	{	_mem_air_data._data_bit._air0 = TURN_TF(_mem_air_data._data_bit._air0);	}
	void Turn_1()	{	_mem_air_data._data_bit._air1 = TURN_TF(_mem_air_data._data_bit._air1);	}
	void Turn_2()	{	_mem_air_data._data_bit._air2 = TURN_TF(_mem_air_data._data_bit._air2);	}
	void Turn_3()	{	_mem_air_data._data_bit._air3 = TURN_TF(_mem_air_data._data_bit._air3);	}
	void Turn_4()	{	_mem_air_data._data_bit._air4 = TURN_TF(_mem_air_data._data_bit._air4);	}
	void Turn_5()	{	_mem_air_data._data_bit._air5 = TURN_TF(_mem_air_data._data_bit._air5);	}
	void Turn_6()	{	_mem_air_data._data_bit._air6 = TURN_TF(_mem_air_data._data_bit._air6);	}
	void Turn_7()	{	_mem_air_data._data_bit._air7 = TURN_TF(_mem_air_data._data_bit._air7);	}

	/**
	 * \brief 
	 * 単動電磁弁の実行。
	 * _arg_air_nfがTRUEになると、一度FALSEにしてからじゃないと動作しません
	 *
	 * \param _arg_air_num : 番号
	 * \param _arg_air_nf  : ONOFF
	 */
	void Do(T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	/**
	 * \brief 
	 * 単動電磁弁の実行。
	 * タイマ付き
	 * _arg_air_nfがTRUEになると、一度FALSEにしてからじゃないと動作しません
	 * あとカウント完了するまで
	 *
	 * \param _arg_air_num  : 番号
	 * \param _arg_air_nf   : ONOFF
	 * \param _arg_nf_timer : TIMERのフラグ。カウント完了したら外部でTRUEにしといてください。
	 */
	void Do(T_NUM _arg_air_num, BOOL _arg_air_nf, BOOL & _arg_nf_timer);
	
	
	/**
	 * \brief 
	 * 双動電磁弁の実行。
	 * PORTが2つ必要なので、その2つを指定しておいてください。
	 * TIMERの時間はとりあえず100msぐらい確保しといてください
	 * 最初に自動的に_arg_air_num_1側がONになります
	 * 
	 * \param _arg_air_num_0 : 動かすPORTその0
	 * \param _arg_air_num_1 : 動かすPORTその1
	 * \param _arg_air_nf    : ONOFF
	 * \param _arg_nf_timer  : TIMERのフラグ。カウント完了したらTRUEにしといてくさい
	 */
	void Do(T_NUM _arg_air_num_0, T_NUM _arg_air_num_1, BOOL _arg_air_nf, BOOL &_arg_nf_timer);
	
	/**
	 * \brief 電磁弁回路へデータを送信する。
	 * 
	 * \param _arg_uart_t : 使うUART
	 */
	void Out(C_UART_T &_arg_uart_t);
	
	/**
	 * \brief 電磁弁の設定を2進数8桁でLCDに表示する。
	 * 
	 * \param _arg_adrs : 表示する場所。
	 */
	void Lcd_2 (T_ADRS _arg_adrs);
	
	/**
	 * \brief 電磁弁の設定を16進数2桁でLCDに表示する。
	 * 
	 * \param _arg_adrs : 表示する場所
	 */
	void Lcd_16(T_ADRS _arg_adrs);
	
	/**
	 * \brief 指定された電磁弁の設定を1桁でLCDに表示する。
	 * 
	 * \param _arg_adrs    : 表示する場所
	 * \param _arg_air_num : 表示する電磁弁
	 */
	void Lcd_num(T_ADRS _arg_adrs, T_NUM _arg_air_num);
};

#include "H28_C_AIR.cpp"

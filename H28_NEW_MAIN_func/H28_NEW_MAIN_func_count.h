
#pragma once

/************************************************************************/
/*	宣言																*/
/************************************************************************/

/**
 * \brief 
 *	C_COUNTを動かす。
 *	_arg_set_highか_arg_set_lowが一度FALESにならないと動かない仕組み
 * 
 * \param _arg_set_high : カウントアップ
 * \param _arg_set_low  : カウントダウン
 * \param _arg_count	: カウンタ。変えられるやつ
 */
inline void 
F_Do_count(const BOOL  _arg_set_high, const BOOL  _arg_set_low, C_COUNT_u1 &_arg_count);

inline void F_Start_count (const BOOL _arg_nf_start, BOOL &_arg_flag_nf_start, C_COUNT_u1 &_arg_count);

/**
 * \brief 
 *	カウンタを利用して_arg_nfのTFを反転させる関数
 *	カウンタはループにしとかないでください
 *	カウントの++は別のところでやってください。
 *	こいつはあくまでカウント完了していたらの関数です
 *	カウントを開始すると、カウンタのフラグがTRUEになり、完了するとFALSEになります。
 * 
 * \param _arg_nf_count	: カウントの開始
 * \param _arg_nf		: カウントが完了しているとこいつのTFが反転する
 * \param _arg_count	: カウンタ
 */
inline void F_Nf_count (const BOOL _arg_nf_count, BOOL &_arg_nf, C_COUNT_u1 &_arg_count);

/**
 * \brief
 *	カウンタを利用して_arg_nfのTFを反転させる関数
 *	カウンタはループにしとかないでください
 *	カウントの++は別のところでやってください。
 *	カウンタのフラグが立っていて、_arg_compとカウンタが等しいときに、_arg_nfが変化します
 *	変化するとカウンタの値が++されます。
 *
 * \param _arg_comp	 : 比較する値
 * \param _arg_nf	 : 動かされるやつ
 * \param _arg_flag	 : フラグ。外部で変えないでね
 * \param _arg_count : カウンタ
 */
inline void F_Nf_count (const uchar _arg_comp, BOOL &_arg_nf, BOOL &_arg_flag, C_COUNT_u1 &_arg_count);

/************************************************************************/
/*	実装																*/
/************************************************************************/

inline void 
F_Do_count
(
	const BOOL  _arg_set_high, 
	const BOOL  _arg_set_low, 
	C_COUNT_u1 &_arg_count)
{
	if (_arg_set_high | _arg_set_low)
	{
		if (_arg_set_high & _arg_count.Ret_flag())		_arg_count ++;
		else if (_arg_set_low & _arg_count.Ret_flag())	_arg_count --;
		
		_arg_count.Flag_down();
	}
	else
	{
		_arg_count.Flag_up();
	}
};

inline void 
F_Start_count 
(
	const BOOL	 _arg_nf_start, 
	BOOL		&_arg_flag_nf_start, 
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_nf_start & _arg_flag_nf_start & ~_arg_count.Ret_flag())
	{
		_arg_count.Min();
		_arg_count.Flag_up();
	}
	
	_arg_flag_nf_start = ~_arg_nf_start;
}

inline void 
F_Nf_count 
(
	const BOOL	 _arg_nf_count, 
	BOOL		&_arg_nf, 
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_nf_count)
	{
		if (_arg_nf & ~_arg_count.Ret_flag())
		{
			_arg_count.Min();
			_arg_count.Flag_up();
		}
	}
	
	if (_arg_count.Comp_max() & _arg_count.Ret_flag())
	{
		_arg_count.Flag_down();
		
		_arg_nf = ~_arg_nf;
	}
	
	_arg_nf = ~_arg_nf_count;
}

inline void 
F_Nf_count 
(
	const uchar  _arg_comp, 
	BOOL		&_arg_nf, 
	BOOL		&_arg_flag, 
	C_COUNT_u1	&_arg_count
)
{
	if (_arg_count.Comp(_arg_comp) & _arg_count.Ret_flag())
	{
		_arg_nf = ~_arg_nf;
		
		_arg_count ++;
	}
}

/************************************************************************/


#pragma once

/*************************************************************************

�d���ى�H���������߂̃N���X�B

�ʉ�H�^�ƃ��C����H�g���^�̗������g�p�\�B
�ʉ�H�ɍ��킹�Ă���̂ŁA1�I�u�W�F�N�g�œ�������\���m�C�h��8�܂�

*************************************************************************/

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
		
		T_DATA_8 _byte :8;
		S_AIR _bit;
	};
	
	U_AIR _mem_air_data;
	BOOL _mem_array_air_flag[8];
	
public:
	
	/**
	 * \brief 
	 * �R���X�g���N�^�B
	 * �d���ى�H�֑��M����f�[�^�̏����ݒ���s�����Ƃ��ł���
	 * 
	 * \param _arg_air_data : �����ݒ�B�g���ԍ���bit��1�𗧂ĂĂ�
	 */
	C_AIR (T_DATA_8 _arg_air_data);
	
	/**
	 * \brief �S�Ă̓d���ق̐ݒ��return����B
	 * 
	 * \return T_DATA_8 return.8bit
	 */
	T_DATA_8 Ret ();
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ��Ԃ�
	 * 
	 * \param _arg_air_num : �d���ق̎w��
	 */
	BOOL Ret_num (T_NUM _arg_air_num);
	
	BOOL Ret_0 ()	{	return _mem_air_data._bit._air0;	}
	BOOL Ret_1 ()	{	return _mem_air_data._bit._air1;	}
	BOOL Ret_2 ()	{	return _mem_air_data._bit._air2;	}
	BOOL Ret_3 ()	{	return _mem_air_data._bit._air3;	}
	BOOL Ret_4 ()	{	return _mem_air_data._bit._air4;	}
	BOOL Ret_5 ()	{	return _mem_air_data._bit._air5;	}
	BOOL Ret_6 ()	{	return _mem_air_data._bit._air6;	}
	BOOL Ret_7 ()	{	return _mem_air_data._bit._air7;	}
	
	/**
	 * \brief �d���ّS�̂�ONOFF��ݒ肷��
	 * 
	 * \param _arg_air_data : �ݒ�B�g�������ԍ���bit��1,0���Ă�������
	 */
	void Write_all (T_DATA_8 _arg_air_data);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق�ONOFF�̐ݒ���s��
	 * 
	 * \param _arg_air_num : �ݒ肷��ԍ�
	 * \param _arg_air_nf  : ONOFF
	 */
	void Write_num (T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	/**
	 * \brief 
	 * �_�u���^�̓d���ٗp�̐ݒ�
	 * �@_arg_air_num_one��PORT��ON�̏ꍇ�A_arg_air_num_do��PORT���ݒ�
	 * �ł��Ȃ��Ȃ��Ă���B
	 * 
	 * \param _arg_air_num_one	: �����Е���PORT
	 * \param _arg_air_num_do	: �ݒ肷��PORT
	 * \param _arg_air_nf		: ONOFF
	 */
	void Write_double (T_NUM _arg_air_num_one, T_NUM _arg_air_num_do, BOOL _arg_air_nf);
	
	void Write_0 (const BOOL _arg_air_nf_0)	{	_mem_air_data._bit._air0 = _arg_air_nf_0;	}
	void Write_1 (const BOOL _arg_air_nf_1)	{	_mem_air_data._bit._air1 = _arg_air_nf_1;	}
	void Write_2 (const BOOL _arg_air_nf_2)	{	_mem_air_data._bit._air2 = _arg_air_nf_2;	}
	void Write_3 (const BOOL _arg_air_nf_3)	{	_mem_air_data._bit._air3 = _arg_air_nf_3;	}
	void Write_4 (const BOOL _arg_air_nf_4)	{	_mem_air_data._bit._air4 = _arg_air_nf_4;	}
	void Write_5 (const BOOL _arg_air_nf_5)	{	_mem_air_data._bit._air5 = _arg_air_nf_5;	}
	void Write_6 (const BOOL _arg_air_nf_6)	{	_mem_air_data._bit._air6 = _arg_air_nf_6;	}
	void Write_7 (const BOOL _arg_air_nf_7)	{	_mem_air_data._bit._air7 = _arg_air_nf_7;	}
	
	/**
	 * \brief �d���ق̐ݒ�𔽓]������
	 */
	void Turn ();
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ�𔽓]������ 
	 *
	 * \param _arg_air_num : �d���ق̎w��
	 */
	void Turn_num(T_NUM _arg_air_num);

	void Turn_0 ()	{	_mem_air_data._bit._air0 = F_Turn_bool(_mem_air_data._bit._air0);	}
	void Turn_1 ()	{	_mem_air_data._bit._air1 = F_Turn_bool(_mem_air_data._bit._air1);	}
	void Turn_2 ()	{	_mem_air_data._bit._air2 = F_Turn_bool(_mem_air_data._bit._air2);	}
	void Turn_3 ()	{	_mem_air_data._bit._air3 = F_Turn_bool(_mem_air_data._bit._air3);	}
	void Turn_4 ()	{	_mem_air_data._bit._air4 = F_Turn_bool(_mem_air_data._bit._air4);	}
	void Turn_5 ()	{	_mem_air_data._bit._air5 = F_Turn_bool(_mem_air_data._bit._air5);	}
	void Turn_6 ()	{	_mem_air_data._bit._air6 = F_Turn_bool(_mem_air_data._bit._air6);	}
	void Turn_7 ()	{	_mem_air_data._bit._air7 = F_Turn_bool(_mem_air_data._bit._air7);	}

	/**
	 * \brief 
	 * ���X�g�^�̓d���ق̎��s�B
	 * _arg_air_nf��TRUE�ɂȂ�ƁA��xFALSE�ɂ��Ă��炶��Ȃ��Ɠ��삵�܂���
	 *
	 * \param _arg_air_num : �ԍ�
	 * \param _arg_air_nf  : ONOFF
	 */
	void Do (T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	/**
	 * \brief 
	 * ���X�g�^�̓d���ق̎��s�B
	 * �^�C�}�t��
	 * _arg_air_nf��TRUE�ɂȂ�ƁA��xFALSE�ɂ��Ă��炶��Ȃ��Ɠ��삵�܂���
	 * ���ƃJ�E���g��������܂�
	 *
	 * \param _arg_air_num  : �ԍ�
	 * \param _arg_air_nf   : ONOFF
	 * \param _arg_nf_timer : TIMER�̃t���O�B�J�E���g����������O����TRUE�ɂ��Ƃ��Ă��������B
	 */
	void Do (T_NUM _arg_air_num, BOOL _arg_air_nf, BOOL & _arg_nf_timer);
	
	/**
	 * \brief 
	 * �_�u���^�̓d���ق̎��s�B
	 * ON�ɂȂ��Ă���̂����ւ���
	 * PORT��2�K�v�Ȃ̂ŁA����2���w�肵�Ă����Ă��������B
	 * TIMER�̎��Ԃ͂Ƃ肠����100ms���炢�m�ۂ��Ƃ��Ă�������
	 * �ŏ��Ɏ����I��_arg_air_num_1����ON�ɂȂ�܂�
	 * 
	 * \param _arg_air_num_ri : ������PORT����0
	 * \param _arg_air_num_le : ������PORT����1
	 * \param _arg_air_nf    : ONOFF
	 * \param _arg_nf_timer  : TIMER�̃t���O�B�J�E���g����������TRUE�ɂ��Ƃ��Ă�����
	 */
	void Do_double (T_NUM _arg_air_num_ri, T_NUM _arg_air_num_le, BOOL _arg_air_nf, BOOL &_arg_nf_timer);
	
	/**
	 * \brief 
	 * �_�u���^�̓d���ق̎��s�B
	 * �Е��̃\���m�C�h�𓮂�����
	 * �����Е��̃\���m�C�h��ON�̏ꍇ�ɂ͓��������Ƃ��ł��Ȃ�
	 * 
	 * \param _arg_air_num_one	: �����Е�
	 * \param _arg_air_num_do	: �������ق�
	 * \param _arg_air_nf		: ONOFF
	 */
	void Do_double (T_NUM _arg_air_num_one, T_NUM _arg_air_num_do, BOOL _arg_air_nf);
	
	/**
	 * \brief 
	 * �_�u���^�̓d���ق̎��s�B
	 * �\���m�C�h���ʂɓ�������B
	 * ����ON�͖����Ȃ̂ŁB�������炸�B
	 * 
	 * \param _arg_air_num_ri : ������PORT����0
	 * \param _arg_air_nf_ri  : ONOFF����0
	 * \param _arg_air_num_le : ������PORT����1
	 * \param _arg_air_nf_le  : ONOFF����1
	 */
	void Do_double (T_NUM _arg_air_num_ri, BOOL _arg_air_nf_ri, T_NUM _arg_air_num_le, BOOL _arg_air_nf_le);
	
	/**
	 * \brief �d���ى�H�փf�[�^�𑗐M����B
	 * 
	 * \param _arg_uart_t : �g��UART
	 */
	void Out (C_UART_T &_arg_uart_t);
	
	/**
	 * \brief 
	 * �d���ى�H�̃f�[�^��IO���W�X�^����o�͂���B
	 * �g���d���ى�H�� 
	 *
	 * \param _arg_io_out : �o�͂���IO���W�X�^
	 */
	void Out (C_IO_OUT &_arg_io_out);
	
	/**
	 * \brief 
	 * �w�肳�ꂽ�d���ق݂̂��o�͂���B
	 * �o�͂����ꏊ�͓d���ق̔ԍ��Ƃ��Ȃ�IO�s��
	 * 
	 * \param _arg_io_out  : �o�͂���IO���W�X�^
	 * \param _arg_air_num : �o�͂���d����
	 */
	void Out (C_IO_OUT &_arg_io_out, usint _arg_air_num);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق��w�肳�ꂽIO�s���ɏo�͂��� 
	 * 
	 * \param _arg_io_out  : �o�͂���IO���W�X�^
	 * \param _arg_air_num : �o�͂���d����
	 * \param _arg_io_num  : �o�͂���s��
	 */
	void Out (C_IO_OUT &_arg_io_out, usint _arg_air_num, usint _arg_io_num);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق�IO�s������o�͂���
	 * 
	 * \param _arg_io_out  : �o�͂���IO�s��
	 * \param _arg_air_num : �o�͂���d����
	 */
	void Out (C_IO_OUT_pin &_arg_io_out, usint _arg_air_num);
	
	/**
	 * \brief �d���ق̐ݒ��2�i��8����LCD�ɕ\������B
	 * 
	 * \param _arg_adrs : �\������ꏊ�B
	 */
	void Lcd_2 (T_ADRS _arg_adrs);
	
	/**
	 * \brief �d���ق̐ݒ��16�i��2����LCD�ɕ\������B
	 * 
	 * \param _arg_adrs : �\������ꏊ
	 */
	void Lcd_16 (T_ADRS _arg_adrs);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ��1����LCD�ɕ\������B
	 * 
	 * \param _arg_adrs    : �\������ꏊ
	 * \param _arg_air_num : �\������d����
	 */
	void Lcd_num (T_ADRS _arg_adrs, T_NUM _arg_air_num);
};

inline
C_AIR ::
C_AIR (const T_DATA_8 _arg_air_data = 0x00)
{
	_mem_air_data._byte = _arg_air_data;
	
	for (usint i = 0; i < 8; i++)	_mem_array_air_flag[i] = TRUE;
}

inline T_DATA_8
C_AIR ::
Ret ()
{
	return _mem_air_data._byte;
}

inline BOOL
C_AIR ::
Ret_num (const T_NUM _arg_air_num)
{
	return F_Check_bit_bool(_mem_air_data._byte, _arg_air_num);
}

inline void
C_AIR ::
Write_all (const T_DATA_8 _arg_air_data)
{
	_mem_air_data._byte = _arg_air_data;
}

inline void
C_AIR ::
Write_num
(
	const T_NUM _arg_air_num,
	const BOOL	_arg_air_nf
)
{
	switch (_arg_air_nf)
	{
		case TRUE:	_mem_air_data._byte |=  (1 << _arg_air_num);	break;
		case FALSE:	_mem_air_data._byte &= ~(1 << _arg_air_num);	break;
	}
}

inline void
C_AIR ::
Write_double
(
	const T_NUM _arg_air_num_one,
	const T_NUM _arg_air_num_do,
	const BOOL	_arg_air_nf
)
{
	if (Ret_num(_arg_air_num_one) & _arg_air_nf)	return (void)0;
	//one��ON���Ado��ON�ɂ��悤�Ƃ��Ă����ꍇ
	
	Write_num(_arg_air_num_do, _arg_air_nf);
}

inline void
C_AIR ::
Turn ()
{
	_mem_air_data._byte = ~(_mem_air_data._byte);
}

inline void
C_AIR ::
Turn_num (const T_NUM _arg_air_num)
{
	Write_num(_arg_air_num, ~Ret_num(_arg_air_num));
}

inline void
C_AIR ::
Do
(
	const T_NUM _arg_air_num,
	const BOOL	_arg_air_nf
)
{
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num])	Turn_num(_arg_air_num);
	
	_mem_array_air_flag[_arg_air_num] = ~_arg_air_nf;
}

inline void
C_AIR ::
Do
(
	const T_NUM  _arg_air_num,
	const BOOL	 _arg_air_nf,
	BOOL		&_arg_nf_timer
)
{
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num] & _arg_nf_timer)	Turn_num(_arg_air_num);
	
	_mem_array_air_flag[_arg_air_num] = ~_arg_air_nf;
}

inline void
C_AIR ::
Do_double
(
	const T_NUM  _arg_air_num_ri,
	const T_NUM  _arg_air_num_le,
	const BOOL	 _arg_air_nf ,
	BOOL		&_arg_nf_timer
)
{
	//_mem_array_air_flag[_arg_air_num_ri] : _arg_air_nf�̃t���O�Ƃ��Ďg�p
	//_mem_array_air_flag[_arg_air_num_le] : ON�ɂ���PORT�̑I��p�Ƃ��Ďg�p�B
	//										 TRUE  -> _arg_air_num_le
	//										 FALSE -> _arg_air_num_ri
	
	if (_arg_air_nf & _mem_array_air_flag[_arg_air_num_ri])
	{
		switch (_mem_array_air_flag[_arg_air_num_le]) //�\���m�C�h��OFF��
		{
			case TRUE:	Write_num(_arg_air_num_ri,FALSE);	break;
			case FALSE:	Write_num(_arg_air_num_le,FALSE);	break;
		}
		
		_arg_nf_timer = FALSE;
	}
	
	_mem_array_air_flag[_arg_air_num_ri] = ~_arg_air_nf;
	
	if ((Ret_num(_arg_air_num_ri) | Ret_num(_arg_air_num_le) | ~_arg_nf_timer) == FALSE)
	//_arg_air_nf��TRUE�ɂȂ���FALSE�ɂȂ��Ă���A��莞�Ԍo�ߌ�ɏ�������܂��B
	{
		switch (_mem_array_air_flag[_arg_air_num_le]) //�\���m�C�h��ON��
		{
			case TRUE:	Write_num(_arg_air_num_le,TRUE);	break;
			case FALSE:	Write_num(_arg_air_num_ri,TRUE);	break;
		}
		
		_mem_array_air_flag[_arg_air_num_le] = ~_mem_array_air_flag[_arg_air_num_le];
	}
	
	if (Ret_num(_arg_air_num_ri) & Ret_num(_arg_air_num_le))	//������ON�ɂȂ��Ă��Ȃ����̃`�F�b�N
	{
		Write_num(_arg_air_num_ri, FALSE);
		Write_num(_arg_air_num_le, FALSE);
	}
}

void
C_AIR ::
Do_double
(
	const T_NUM _arg_air_num_one,
	const T_NUM _arg_air_num_do,
	const BOOL _arg_air_nf
)
{
	if ((Ret_num(_arg_air_num_one) & _arg_air_nf) == FALSE)	Do(_arg_air_num_do, _arg_air_nf);
	
	if (Ret_num(_arg_air_num_one) & Ret_num(_arg_air_num_do))	//������ON�ɂȂ��Ă��Ȃ����̃`�F�b�N
	{
		Write_num(_arg_air_num_one, FALSE);
		Write_num(_arg_air_num_do,  FALSE);
	}
}

void
C_AIR ::
Do_double
(
	const T_NUM		_arg_air_num_ri,
	const BOOL		_arg_air_nf_ri,
	const  T_NUM	_arg_air_num_le,
	const BOOL		_arg_air_nf_le
)
{
	if ((Ret_num(_arg_air_num_le) & _arg_air_nf_ri) == FALSE)	Do (_arg_air_num_ri, _arg_air_nf_ri);
	if ((Ret_num(_arg_air_num_le) & _arg_air_nf_ri) == FALSE)	Do (_arg_air_num_ri, _arg_air_nf_ri);
	
	if (Ret_num(_arg_air_num_ri) & Ret_num(_arg_air_num_le))	//������ON�ɂȂ��Ă��Ȃ����̃`�F�b�N
	{
		Write_num(_arg_air_num_ri, FALSE);
		Write_num(_arg_air_num_le, FALSE);
	}
}

void
C_AIR ::
Out (C_UART_T &_arg_uart_t)
{
	_arg_uart_t.Set_bit9_off();
	
	_arg_uart_t << _mem_air_data._byte;
}

void
C_AIR ::
Out (C_IO_OUT &_arg_io_out)
{
	_arg_io_out.Out(Ret());
}

void
C_AIR ::
Out
(
	C_IO_OUT	&_arg_io_out,
	const usint  _arg_air_num
)
{
	_arg_io_out.Out_num(_arg_air_num, Ret_num(_arg_air_num));
}

void
C_AIR ::
Out
(
	C_IO_OUT	&_arg_io_out,
	const usint	 _arg_air_num,
	const usint  _arg_io_num
)
{
	_arg_io_out.Out_num(_arg_io_num, Ret_num(_arg_air_num));
}

void
C_AIR ::
Out
(
	C_IO_OUT_pin	&_arg_io_out,
	const usint		 _arg_air_num
)
{
	_arg_io_out.Out(Ret_num(_arg_air_num));
}

inline void
C_AIR ::
Lcd_2 (const T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs, _mem_air_data._byte, 8, ED_02);
}

inline void
C_AIR ::
Lcd_16 (const T_ADRS _arg_adrs)
{
	Lcd_put_num(_arg_adrs, _mem_air_data._byte, 2, ED_16);
}

inline void
C_AIR ::
Lcd_num
(
	const T_ADRS	_arg_adrs,
	const T_NUM		_arg_air_num
)
{
	Lcd_put_num(_arg_adrs, Ret_num(_arg_air_num), 1, ED_02);
}

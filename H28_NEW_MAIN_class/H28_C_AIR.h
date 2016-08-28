
#pragma once

/**
 * �d���ى�H���������߂̃N���X�B�g�p�\�ȃ|�[�g����8
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
	C_AIR(T_DATA_8 _arg_air_data);
	
	/**
	 * \brief �S�Ă̓d���ق̐ݒ��return����B
	 * 
	 * \return T_DATA_8 return.8bit
	 */
	T_DATA_8 Ret();
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ��Ԃ�
	 * 
	 * \param _arg_air_num : �d���ق̎w��
	 * 
	 * \return BOOL return
	 */
	BOOL Ret_num(T_NUM _arg_air_num);
	
	BOOL Ret_0()	{	return _mem_air_data._bit._air0;	}
	BOOL Ret_1()	{	return _mem_air_data._bit._air1;	}
	BOOL Ret_2()	{	return _mem_air_data._bit._air2;	}
	BOOL Ret_3()	{	return _mem_air_data._bit._air3;	}
	BOOL Ret_4()	{	return _mem_air_data._bit._air4;	}
	BOOL Ret_5()	{	return _mem_air_data._bit._air5;	}
	BOOL Ret_6()	{	return _mem_air_data._bit._air6;	}
	BOOL Ret_7()	{	return _mem_air_data._bit._air7;	}
	
	/**
	 * \brief �d���ّS�̂�ONOFF��ݒ肷��
	 * 
	 * \param _arg_air_data : �ݒ�B�g�������ԍ���bit��1,0���Ă�������
	 */
	void Set(T_DATA_8 _arg_air_data);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق�ONOFF�̐ݒ���s��
	 * 
	 * \param _arg_air_num : �ݒ肷��ԍ�
	 * \param _arg_air_nf  : ONOFF
	 */
	void Set_num(T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	void Set_0(BOOL _arg_air_nf_0)	{	_mem_air_data._bit._air0 = _arg_air_nf_0;	}
	void Set_1(BOOL _arg_air_nf_1)	{	_mem_air_data._bit._air1 = _arg_air_nf_1;	}
	void Set_2(BOOL _arg_air_nf_2)	{	_mem_air_data._bit._air2 = _arg_air_nf_2;	}
	void Set_3(BOOL _arg_air_nf_3)	{	_mem_air_data._bit._air3 = _arg_air_nf_3;	}
	void Set_4(BOOL _arg_air_nf_4)	{	_mem_air_data._bit._air4 = _arg_air_nf_4;	}
	void Set_5(BOOL _arg_air_nf_5)	{	_mem_air_data._bit._air5 = _arg_air_nf_5;	}
	void Set_6(BOOL _arg_air_nf_6)	{	_mem_air_data._bit._air6 = _arg_air_nf_6;	}
	void Set_7(BOOL _arg_air_nf_7)	{	_mem_air_data._bit._air7 = _arg_air_nf_7;	}
	
	/**
	 * \brief �d���ق̐ݒ�𔽓]������
	 */
	void Turn();
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ�𔽓]������ 
	 *
	 * \param _arg_air_num : �d���ق̎w��
	 */
	void Turn_num(T_NUM _arg_air_num);

	void Turn_0()	{	_mem_air_data._bit._air0 = TURN_TF(_mem_air_data._bit._air0);	}
	void Turn_1()	{	_mem_air_data._bit._air1 = TURN_TF(_mem_air_data._bit._air1);	}
	void Turn_2()	{	_mem_air_data._bit._air2 = TURN_TF(_mem_air_data._bit._air2);	}
	void Turn_3()	{	_mem_air_data._bit._air3 = TURN_TF(_mem_air_data._bit._air3);	}
	void Turn_4()	{	_mem_air_data._bit._air4 = TURN_TF(_mem_air_data._bit._air4);	}
	void Turn_5()	{	_mem_air_data._bit._air5 = TURN_TF(_mem_air_data._bit._air5);	}
	void Turn_6()	{	_mem_air_data._bit._air6 = TURN_TF(_mem_air_data._bit._air6);	}
	void Turn_7()	{	_mem_air_data._bit._air7 = TURN_TF(_mem_air_data._bit._air7);	}

	/**
	 * \brief 
	 * ���X�g�^�̓d���ق̎��s�B�T�C�N�����b
	 * _arg_air_nf��TRUE�ɂȂ�ƁA��xFALSE�ɂ��Ă��炶��Ȃ��Ɠ��삵�܂���
	 *
	 * \param _arg_air_num : �ԍ�
	 * \param _arg_air_nf  : ONOFF
	 */
	void Do(T_NUM _arg_air_num, BOOL _arg_air_nf);
	
	/**
	 * \brief 
	 * ���X�g�^�̓d���ق̎��s�B�W���[�J�@�[
	 * �^�C�}�t��
	 * _arg_air_nf��TRUE�ɂȂ�ƁA��xFALSE�ɂ��Ă��炶��Ȃ��Ɠ��삵�܂���
	 * ���ƃJ�E���g��������܂�
	 *
	 * \param _arg_air_num  : �ԍ�
	 * \param _arg_air_nf   : ONOFF
	 * \param _arg_nf_timer : TIMER�̃t���O�B�J�E���g����������O����TRUE�ɂ��Ƃ��Ă��������B
	 */
	void Do(T_NUM _arg_air_num, BOOL _arg_air_nf, BOOL & _arg_nf_timer);
	
	/**
	 * \brief 
	 * �_�u���^�̓d���ق̎��s�B2��1�̓d���ق��B
	 * PORT��2�K�v�Ȃ̂ŁA����2���w�肵�Ă����Ă��������B
	 * TIMER�̎��Ԃ͂Ƃ肠����100ms���炢�m�ۂ��Ƃ��Ă�������
	 * �ŏ��Ɏ����I��_arg_air_num_1����ON�ɂȂ�܂�
	 * 
	 * \param _arg_air_num_0 : ������PORT����0
	 * \param _arg_air_num_1 : ������PORT����1
	 * \param _arg_air_nf    : ONOFF
	 * \param _arg_nf_timer  : TIMER�̃t���O�B�J�E���g����������TRUE�ɂ��Ƃ��Ă�����
	 */
	void Do(T_NUM _arg_air_num_0, T_NUM _arg_air_num_1, BOOL _arg_air_nf, BOOL &_arg_nf_timer);
	
	/**
	 * \brief �d���ى�H�փf�[�^�𑗐M����B
	 * 
	 * \param _arg_uart_t : �g��UART
	 */
	void Out(C_UART_T &_arg_uart_t);
	
	/**
	 * \brief 
	 * �d���ى�H�̃f�[�^��IO���W�X�^����o�͂���B
	 * �g���d���ى�H�� 
	 *
	 * \param _arg_io_out : �o�͂���IO���W�X�^
	 */
	void Out(C_IO_OUT &_arg_io_out);
	
	/**
	 * \brief 
	 * �w�肳�ꂽ�d���ق݂̂��o�͂���B
	 * �o�͂����ꏊ�͓d���ق̔ԍ��Ƃ��Ȃ�IO�s��
	 * 
	 * \param _arg_io_out  : �o�͂���IO���W�X�^
	 * \param _arg_air_num : �o�͂���d����
	 */
	void Out(C_IO_OUT &_arg_io_out, usint _arg_air_num);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق��w�肳�ꂽIO�s���ɏo�͂��� 
	 * 
	 * \param _arg_io_out  : �o�͂���IO���W�X�^
	 * \param _arg_air_num : �o�͂���d����
	 * \param _arg_io_num  : �o�͂���s��
	 */
	void Out(C_IO_OUT &_arg_io_out, usint _arg_air_num, usint _arg_io_num);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق�IO�s������o�͂���
	 * 
	 * \param _arg_io_out  : �o�͂���IO�s��
	 * \param _arg_air_num : �o�͂���d����
	 */
	void Out(C_IO_OUT_pin &_arg_io_out, usint _arg_air_num);
	
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
	void Lcd_16(T_ADRS _arg_adrs);
	
	/**
	 * \brief �w�肳�ꂽ�d���ق̐ݒ��1����LCD�ɕ\������B
	 * 
	 * \param _arg_adrs    : �\������ꏊ
	 * \param _arg_air_num : �\������d����
	 */
	void Lcd_num(T_ADRS _arg_adrs, T_NUM _arg_air_num);
};

#include "H28_C_AIR.cpp"
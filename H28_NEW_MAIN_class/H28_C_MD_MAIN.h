
#pragma once

union U_MD
{
	struct S_MD
	{
		T_DATA _data_md		:5;
		usint  _num_data	:1;
		usint  _num_md		:2;
		usint  _num_mdc		:1;
	};
	
	struct S_MD_0 //���ԕς����
	{
		E_SIG _sig		:2;
		BOOL  _nf_step	:1;
		usint _without	:2;
		usint _num_data	:1;
		usint _num_md	:2;
		usint _num_mdc	:1;
		
	};
	
	struct S_MD_1 //���ԕς����
	{
		T_PWM _pwm		:5;
		usint _num_data	:1;
		usint _num_md	:2;
		usint _num_mdc	:1;
	};
	
	S_MD	_data_divi_both	  ;
	S_MD_0	_data_divi_0	  ;
	S_MD_1	_data_divi_1	  ;
	T_DATA	_data_all		:9;
};

class C_MD_MAIN
{
private:
	
	union U_MD_0
	{
		struct S_MD_0 //���ԕς����
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
		struct S_MD_1 //���ԕς����
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
	 * \brief ��̃R���X�g���N�^�B
	 */
	C_MD_MAIN()	{}
	
	/**
	 * \brief �R���X�g���N�^�B�ݒ�͈ȉ��̒ʂ�
	 * 
	 * \param _arg_num_mdc : MDC�̔ԍ�(0~1)
	 * \param _arg_num_md  : MD�̔ԍ�(0~3)
	 * \param _arg_nf_sig_turn : ���t���]�̎g�p�ɂ���
	 * \param _arg_pwm_revis : �␳PWM�̐ݒ�
	 */
	C_MD_MAIN(usint _arg_num_mdc, usint _arg_num_md, BOOL _arg_nf_sig_turn, sint _arg_pwm_revis);
	
	/**
	 * \brief �g��MD�̔ԍ���ς���
	 * 
	 * \param _arg_num_md : MD�̔ԍ�(0~3)
	 */
	void Reset_num_md(usint _arg_num_md);
	
	/**
	 * \brief ���t���]�̐ݒ�BSIG�̐ݒ�̑O�ɍs������
	 * 
	 * \param _arg_sig_turn 
	 *		TURE  -> ���]
	 *		FALSE -> ���̂܂�
	 */
	void Reset_sig_reverse(BOOL _arg_sig_turn);
	
	/**
	 * \brief ���]�̐ݒ�����ւ���
	 */
	void Turn_sig_reverse();
	
	/**
	 * \brief ����̐ݒ�
	 * 
	 * \param _arg_sig_mode  : ����
	 * \param _arg_pwm_value : PWM
	 * \param _arg_nf_steps  : �i�X�̎g�p�ɂ���	
	 */
	void Write_data(E_SIG _arg_sig_mode, T_PWM _arg_pwm_value, BOOL _arg_nf_steps);
	
	/**
	 * \brief PWM�̐ݒ�BWrite_data���g���̂𐄏�
	 * 
	 * \param _arg_pwm_value : PWM
	 */
	void Write_pwm(T_PWM _arg_pwm_value);
	
	/**
	 * \brief �␳PWM�̐ݒ�BPWM�̐ݒ�̑O�ɍs������
	 * 
	 * \param _arg_pwm_revis : �␳PWM�B-31~+30�͈̔͂Őݒ肵�Ă�
	 */
	void Write_pwm_revis(sint _arg_pwm_revis);
	
	/**
	 * \brief ����̐ݒ�
	 * 
	 * \param _arg_sig_mode : ����
	 */
	void Write_sig(E_SIG _arg_sig_mode);
	
	/**
	 * \brief �i�X�̐ݒ�
	 * 
	 * \param _arg_nf_steps : ONOFF
	 */
	void Write_steps(BOOL _arg_nf_steps);
	
	T_DATA Ret_data_0()	{	return _mem_md_main_data_0._data_all;			}
	T_DATA Ret_data_1()	{	return _mem_md_main_data_1._data_all;			}
	usint Ret_num_mdc()	{	return _mem_md_main_data_0._data_divi._num_mdc;	}
	usint Ret_num_md()	{	return _mem_md_main_data_0._data_divi._num_md;	}
	E_SIG Ret_sig()		{	return _mem_md_main_data_0._data_divi._sig;		}
	T_PWM Ret_pwm()		{	return _mem_md_main_data_1._data_divi._pwm;		}
	BOOL Ret_steps()	{	return _mem_md_main_data_0._data_divi._nf_step;	}
	BOOL Ret_reverse()	{	return _mem_md_main_nf_sig_reverse;				}
	
	void Do(const BOOL , const BOOL , const T_PWM );
	
	void Do(const E_DIRECX , const T_PWM );
	
	void Do(const E_DIRECY , const T_PWM );
	
	/**
	 * \brief MDC�փf�[�^�𑗐M����
	 * 
	 * \param _arg_uart_t : ���M�Ɏg��UART
	 */
	void Out(C_UART_T &_arg_uart_t);
	
	//Lcd�\��
	
	/**
	 * \brief 
	 * SIG��LCD�ɐ��l�ŕ\������. 10�i�� 1��
	 *		0 -> ES_FREE
	 *		1 -> ES_FALSE
	 *		2 -> ES_TRUE
	 *		3 -> ES_STOP
	 * 
	 * \param _arg_adrs : �\������ꏊ
	 */
	void Lcd_sig_num(T_ADRS _arg_adrs);
	
	/**
	 * \brief 
	 * SIG��LCD�ɕ����ŕ\������B2����
	 *	ES_FREE  -> FR
	 *	ES_FALSE -> FA
	 *	ES_TRUE  -> TR
	 *	ES_STOP  -> ST
	 *
	 * \param _arg_adrs : �\������ꏊ
	 */
	void Lcd_sig_str(T_ADRS _arg_adrs);
	
	/**
	 * \brief PWM��LCD�ɕ\������B2��
	 * 
	 * \param _arg_adrs : �\������ꏊ
	 * \param _arg_decimal : �\������i���B10��16�ɂ��Ă�
	 */
	void Lcd_pwm(T_ADRS _arg_adrs,E_DECIMAL _arg_decimal);
	
	/**
	 * \brief �S�̂̃f�[�^��\������B2�i�� 9��
	 *
	 * \param _arg_adrs : �\������ꏊ
	 * \param _arg_num_data : �\������f�[�^�̔ԍ�
	 */
	void Lcd_data_2(T_ADRS _arg_adrs,usint _arg_num_data);
	
	/**
	 * \brief �S�̂̃f�[�^��\������B16�i�� 3��
	 * 
	 * \param _arg_adrs : �\������ꏊ
	 * \param _arg_num_data : �\������f�[�^�̔ԍ�
	 */
	void Lcd_data_16(T_ADRS _arg_adrs,usint _arg_num_data);
	
	/**
	 * \brief MD�̔ԍ���LCD�ɕ\������B10�i�� 1��
	 * 
	 * \param _arg_adrs : �\������ꏊ
	 */
	void Lcd_md_num(T_ADRS _arg_adrs);
};

#include "H28_C_MD_MAIN.cpp"
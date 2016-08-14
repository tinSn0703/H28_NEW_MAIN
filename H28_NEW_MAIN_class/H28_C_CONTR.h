
#pragma once

/**
 * �R���g���[���̃f�[�^���󂯎�邽�߂̃N���X�B
 * ���Ɠ����ɂ̓f�[�^�ێ��̂��߂̋��p�̂�����܂��B
 * ������Ӗ����ǂ�قǂ��邩�͂킩��܂���
 */
class C_CONTR
{
protected:
	
#	define __CON_BYTE_UART__ 4	//��M�����R���g���[���̃f�[�^�̃o�C�g��
#	define __CON_BYTE__ 3		//�v���O�������ň����R���g���[���̃f�[�^�̃o�C�g��
	
	union U_CONTR_ps2
	{
		struct S_CONTR_ps2
		{
			//PS2 controler data
			//byte0 5bit east, 4bit north, 3bit start, 2bit R3, 1bit L3, 0bit select
			//byte1 5bit R1, 4bit L1, 3bit R2, 2bit L2, 1bit west, 0bit south
			//byte2 5bit R_west, 4bit R_east, 3bit ��(squ), 2bit �~(cro), 1bit ��(cir), 0bit ��(tri)
			//byte3 5bit L_south, 4bit L_north, 3bit L_west, 2bit L_east, 1bit R_south, 0bit R_north
			
			//_mem_data_controler[0]
			E_DIRECX _stick_right_x :2; //�E�X�e�B�b�N x���� 0,1bit
			E_DIRECY _stick_right_y :2; //�E�X�e�B�b�N y���� 2,3bit
			E_DIRECX _stick_left_x :2; //���X�e�B�b�N x���� 4,5bit
			E_DIRECY _stick_left_y :2; //���X�e�B�b�N y���� 6,7bit
			
			//_mem_data_controler[1]
			E_DIRECX _cross_x :2; //�\���L�[ x�� 0,1bit
			E_DIRECY _cross_y :2; //�\���L�[ y�� 2,3bit
			BOOL _nf_tri :1; //�O�p 4bit
			BOOL _nf_cir :1; //�~   5bit
			BOOL _nf_squ :1; //�l�p 6bit
			BOOL _nf_cro :1; //���� 7bit
			
			//_mem_data_controler[2]
			BOOL _nf_right_1 :1; //0bit
			BOOL _nf_left_1  :1; //1bit
			BOOL _nf_right_2 :1; //2bit
			BOOL _nf_left_2  :1; //3bit
			BOOL _nf_right_3 :1; //4bit
			BOOL _nf_left_3  :1; //5bit
			BOOL _nf_start   :1; //6bit
			BOOL _nf_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[__CON_BYTE__];
		S_CONTR_ps2 _data_bit;
		
		void Set_data (T_DATA_8 _arg_arr_data[__CON_BYTE_UART__])
		{
			_data_bit._cross_x = SET_DIREC_X(CHECK_BIT_TF(_arg_arr_data[1],1),CHECK_BIT_TF(_arg_arr_data[0],5));
			_data_bit._cross_y = SET_DIREC_Y(CHECK_BIT_TF(_arg_arr_data[0],4),CHECK_BIT_TF(_arg_arr_data[1],0));
			
			_data_bit._stick_left_x = SET_DIREC_X(_arg_arr_data[3],2);
			_data_bit._stick_left_y = SET_TURN_DIREC_Y(_arg_arr_data[3],4);
			
			_data_bit._stick_right_x = SET_DIREC_X(_arg_arr_data[2],4);
			_data_bit._stick_right_y = SET_TURN_DIREC_Y(_arg_arr_data[3],0);
			
			_data_bit._nf_start   = CHECK_TURN_BIT_TF(_arg_arr_data[0],3);
			_data_bit._nf_select  = CHECK_TURN_BIT_TF(_arg_arr_data[0],0);
			
			_data_bit._nf_right_1 = CHECK_TURN_BIT_TF(_arg_arr_data[1],5);
			_data_bit._nf_right_2 = CHECK_TURN_BIT_TF(_arg_arr_data[1],3);
			_data_bit._nf_right_3 = CHECK_TURN_BIT_TF(_arg_arr_data[0],2);
			
			_data_bit._nf_left_1  = CHECK_TURN_BIT_TF(_arg_arr_data[1],4);
			_data_bit._nf_left_2  = CHECK_TURN_BIT_TF(_arg_arr_data[1],2);
			_data_bit._nf_left_3  = CHECK_TURN_BIT_TF(_arg_arr_data[0],1);
			
			_data_bit._nf_squ = CHECK_TURN_BIT_TF(_arg_arr_data[2],3);
			_data_bit._nf_cro = CHECK_TURN_BIT_TF(_arg_arr_data[2],2);
			_data_bit._nf_cir = CHECK_TURN_BIT_TF(_arg_arr_data[2],1);
			_data_bit._nf_tri = CHECK_TURN_BIT_TF(_arg_arr_data[2],0);
		}
	};
	
	union U_CONTR_Wii
	{
		struct S_CONTR_Wii
		{
			//Wii controler data
			//byte0 5bit east, 4bit north, 3bit start, 2bit NO, 1bit home, 0bit select
			//byte1 5bit R, 4bit L, 3bit ZR, 2bit ZL, 1bit west, 0bit south
			//byte2 5bit R_west, 4bit R_east, 3bit y, 2bit b, 1bit a, 0bit x
			//byte3 5bit L_south, 4bit L_north, 3bit L_west, 2bit L_east, 1bit R_south, 0bit R_north
			
			//_mem_data_controler[0]
			E_DIRECX _stick_right_x :2; //�E�X�e�B�b�N x���� 0,1bit
			E_DIRECY _stick_right_y :2; //�E�X�e�B�b�N y���� 2,3bit
			
			E_DIRECX _stick_left_x :2; //���X�e�B�b�N x���� 4,5bit
			E_DIRECY _stick_left_y :2; //���X�e�B�b�N y���� 6,7bit
			
			//_mem_data_controler[1]
			E_DIRECX _cross_x :2; //�\���L�[ x�� 0,1bit
			E_DIRECY _cross_y :2; //�\���L�[ y�� 2,3bit
			
			BOOL _nf_x :1; //x 4bit
			BOOL _nf_a :1; //a 5bit
			BOOL _nf_y :1; //y 6bit
			BOOL _nf_b :1; //b 7bit
			
			//_mem_data_controler[2]
			BOOL _nf_right :1; //0bit
			BOOL _nf_left  :1; //1bit
			BOOL _nf_z_right :1; //2bit
			BOOL _nf_z_left  :1; //3bit
			
			BOOL _none_		:1; //4bit
			BOOL _nf_home	:1; //5bit
			BOOL _nf_start   :1; //6bit
			BOOL _nf_select  :1; //7bit
		};
		
		T_DATA_8 _arr_data_byte[__CON_BYTE__];
		S_CONTR_Wii _data_bit;
		
		void Set_data (T_DATA_8 _arg_arr_data[__CON_BYTE_UART__])
		{
			_data_bit._cross_x = SET_DIREC_X(CHECK_BIT_TF(_arg_arr_data[1],1),CHECK_BIT_TF(_arg_arr_data[0],5));
			_data_bit._cross_y = SET_DIREC_Y(CHECK_BIT_TF(_arg_arr_data[0],4),CHECK_BIT_TF(_arg_arr_data[1],0));
			
			_data_bit._stick_left_x = SET_DIREC_X(_arg_arr_data[3],2);
			_data_bit._stick_left_y = SET_DIREC_Y(_arg_arr_data[3],4);
			
			_data_bit._stick_right_x = SET_DIREC_X(_arg_arr_data[2],4);
			_data_bit._stick_right_y = SET_DIREC_Y(_arg_arr_data[3],0);
			
			_data_bit._nf_start  = CHECK_TURN_BIT_TF(_arg_arr_data[0],3);
			_data_bit._nf_select = CHECK_TURN_BIT_TF(_arg_arr_data[0],0);
			_data_bit._nf_home   = CHECK_TURN_BIT_TF(_arg_arr_data[0],1);
			
			_data_bit._nf_right = CHECK_TURN_BIT_TF(_arg_arr_data[1],5);
			_data_bit._nf_z_right = CHECK_TURN_BIT_TF(_arg_arr_data[1],3);
			
			_data_bit._nf_left  = CHECK_TURN_BIT_TF(_arg_arr_data[1],4);
			_data_bit._nf_z_left  = CHECK_TURN_BIT_TF(_arg_arr_data[1],2);
			
			_data_bit._nf_y = CHECK_TURN_BIT_TF(_arg_arr_data[2],3);
			_data_bit._nf_b = CHECK_TURN_BIT_TF(_arg_arr_data[2],2);
			_data_bit._nf_a = CHECK_TURN_BIT_TF(_arg_arr_data[2],1);
			_data_bit._nf_x = CHECK_TURN_BIT_TF(_arg_arr_data[2],0);
		}
	};
	
	/**
	 * \brief 
	 * �R���g���[������̃f�[�^���󂯎��B
	 * 
	 * \param _arg_uart_r   : �f�[�^�������Ă���UART
	 * \param _arg_arr_data : �f�[�^���i�[�����ꏊ
	 */
	void In(C_UART_R  &_arg_uart_r  ,T_DATA_8 _arg_arr_data[__CON_BYTE_UART__] );
	
	/**
	 * \brief 
	 * �R���g���[������̃f�[�^���󂯎��B
	 * 
	 * \param _arg_uart_r   : �f�[�^�������Ă���UART*2
	 * \param _arg_arr_data : �f�[�^���i�[�����ꏊ
	 */
	void In(C_UART_R2 &_arg_uart_r2 ,T_DATA_8 _arg_arr_data[__CON_BYTE_UART__] );
};

#include "H28_C_CONTR.cpp"
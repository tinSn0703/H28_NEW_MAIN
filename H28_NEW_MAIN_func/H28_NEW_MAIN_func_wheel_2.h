
#pragma once

/************************************************************************/
/*	�錾																*/
/************************************************************************/

/**
 * \brief : 2�ւ������֐��B
 * 
 * \param _arg_motor : �v�f��2�̔z��ɂ��Ƃ��Ă�
 * \param _arg_direc_move : �i�ޕ���
 * \param _arg_pwm : PWM
 */
inline void F_Do_wheel_2(C_MD_MAIN _arg_motor[2], E_DIRECY _arg_direc_move, T_PWM _arg_pwm);

/**
 * \brief ��ւ̐M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_turn_0 : _arg_motor[0]����]������
 * \param _arg_turn_1 : _arg_motor[1]����]������
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 * \param _arg_sig_base : ���񎞂̐��t�]�̐ݒ�
 */
inline void F_Do_wheel_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_sig_base, BOOL _arg_nf_turn);

/**
 * \brief ��ւ̐M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_direc_x : ���񂷂�����̑I���B
 *		EAST -> [0]��
 *		WEST -> [1]��
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 * \param _arg_sig_base : ���񎞂̐��t�]�̐ݒ�
 */
inline void F_Do_wheel_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn, BOOL _arg_sig_base);

/**
 * \brief ��ւ̒��M�n����B
 * 
 * \param _arg_motor : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_turn_0 : _arg_motor[0]����]������
 * \param _arg_turn_1 : _arg_motor[1]����]������
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 */
inline void F_Do_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], BOOL _arg_turn_0, BOOL _arg_turn_1, T_PWM _arg_pwm, BOOL _arg_nf_turn);

/**
 * \brief ��ւ̒��M�n����B
 * 
 * \param _arg_motor   : ���񂳂��郂�[�^�B�v�f����2
 * \param _arg_direc_x : ���񂷂�����̑I���B
 *		EAST -> [0]��
 *		WEST -> [1]��
 * \param _arg_pwm : �ݒ肷��PWM
 * \param _arg_nf_turn : ����̔��]
 */
inline void F_Do_wheel_p_turn_2(C_MD_MAIN _arg_motor[2], E_DIRECX _arg_direc_x, T_PWM _arg_pwm, BOOL _arg_nf_turn);

/************************************************************************/
/*	����																*/
/************************************************************************/

inline void
F_Do_wheel_2
(
	C_MD_MAIN	_arg_motor[2],
	E_DIRECY	_arg_direc_move,
	T_PWM		_arg_pwm
)
{
	_arg_motor[0].Write_data(F_Func_sig(_arg_direc_move),_arg_pwm);
	_arg_motor[1].Write_data(F_Func_sig(_arg_direc_move),_arg_pwm);
}

inline void
F_Do_wheel_turn_2
(
	C_MD_MAIN	_arg_motor[2],
	BOOL		_arg_turn_0,
	BOOL		_arg_turn_1,
	T_PWM		_arg_pwm,
	BOOL		_arg_nf_turn = FALSE,
	BOOL		_arg_sig_base = TRUE
)
{
	E_SIG _sig = F_Func_sig(_arg_sig_base);
	
	BOOL _turn_0 = FALSE;
	BOOL _turn_1 = FALSE;
	
	switch (_arg_nf_turn)
	{
		case TRUE:
		{
			_turn_0 = _arg_turn_1;
			_turn_1 = _arg_turn_0;
			
			break;
		}
		case FALSE:
		{
			_turn_0 = _arg_turn_0;
			_turn_1 = _arg_turn_1;
			
			break;
		}
	}
	
	if (_turn_0)
	{
		_arg_motor[0].Write_data(  _sig,_arg_pwm);
		_arg_motor[1].Write_data(ES_STOP,_arg_pwm);
	}
	
	if (_turn_1)
	{
		_arg_motor[0].Write_data(ES_STOP,_arg_pwm);
		_arg_motor[1].Write_data(   _sig,_arg_pwm);
	}
}

inline void
F_Do_wheel_turn_2
(
	C_MD_MAIN	_arg_motor[2],
	E_DIRECX	_arg_direc_x,
	T_PWM		_arg_pwm,
	BOOL		_arg_nf_turn,
	BOOL		_arg_sig_base = TRUE
)
{
	E_SIG _sig = F_Func_sig(_arg_sig_base);
	E_DIRECX _direc = _arg_direc_x;
	
	if (_arg_nf_turn)
	{
		_sig = F_Turn_sig_rotate(_sig);
		
		_direc = F_Turn_direc_x(_direc);
	}
	
	switch (_direc)
	{
		case ED_EAST:
		{
			_arg_motor[0].Write_data(  _sig,_arg_pwm);
			_arg_motor[1].Write_data(ES_STOP,_arg_pwm);
			
			break;
		}
		case ED_WEST:
		{
			_arg_motor[0].Write_data(ES_STOP,_arg_pwm);
			_arg_motor[1].Write_data(   _sig,_arg_pwm);
			
			break;
		}
		case ED_XZERO:
		{
			_arg_motor[0].Write_data(ES_STOP,0);
			_arg_motor[1].Write_data(ES_STOP,0);
			
			break;
		}
	}
}

inline void
F_Do_wheel_p_turn_2
(
	C_MD_MAIN	_arg_motor[2],
	BOOL		_arg_turn_0,
	BOOL		_arg_turn_1,
	T_PWM		_arg_pwm,
	BOOL		_arg_nf_turn = FALSE
)
{
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	BOOL _turn_0 = FALSE;
	BOOL _turn_1 = FALSE;
	
	switch (_arg_nf_turn)
	{
		case TRUE:
		{
			_turn_0 = _arg_turn_1;
			_turn_1 = _arg_turn_0;
			
			break;
		}
		case FALSE:
		{
			_turn_0 = _arg_turn_0;
			_turn_1 = _arg_turn_1;
			
			break;
		}
	}
	
	if (_turn_0)
	{
		_sig_0 = ES_TRUE;
		_sig_1 = ES_FALSE;
	}
	
	if (_turn_1)
	{
		_sig_0 = ES_FALSE;
		_sig_1 = ES_TRUE;
	}
	
	_arg_motor[0].Write_data(_sig_0,_arg_pwm);
	_arg_motor[1].Write_data(_sig_1,_arg_pwm);
}

inline void
F_Do_wheel_p_turn_2
(
	C_MD_MAIN	_arg_motor[2],
	E_DIRECX	_arg_direc_x,
	T_PWM		_arg_pwm
)
{
	E_SIG _sig_0 = ES_STOP;
	E_SIG _sig_1 = ES_STOP;
	
	switch (_arg_direc_x)
	{
		case ED_EAST:
		{
			_sig_0 = ES_TRUE;
			_sig_1 = ES_FALSE;
			
			break;
		}
		case ED_WEST:
		{
			_sig_0 = ES_FALSE;
			_sig_1 = ES_TRUE;
			
			break;
		}
		case ED_XZERO:	break;
	}
	
	_arg_motor[0].Write_data(_sig_0,_arg_pwm);
	_arg_motor[1].Write_data(_sig_1,_arg_pwm);
}

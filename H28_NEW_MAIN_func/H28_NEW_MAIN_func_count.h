
#pragma once

/************************************************************************/
/*	�錾																*/
/************************************************************************/

/**
 * \brief 
 *	C_COUNT�𓮂����B
 *	_arg_set_high��_arg_set_low����xFALES�ɂȂ�Ȃ��Ɠ����Ȃ��d�g��
 * 
 * \param _arg_set_high : �J�E���g�A�b�v
 * \param _arg_set_low  : �J�E���g�_�E��
 * \param _arg_count	: �J�E���^�B�ς�������
 */
inline void 
F_Do_count(const BOOL  _arg_set_high, const BOOL  _arg_set_low, C_COUNT_u1 &_arg_count);

inline void F_Start_count (const BOOL _arg_nf_start, BOOL &_arg_flag_nf_start, C_COUNT_u1 &_arg_count);

/**
 * \brief 
 *	�J�E���^�𗘗p����_arg_nf��TF�𔽓]������֐�
 *	�J�E���^�̓��[�v�ɂ��Ƃ��Ȃ��ł�������
 *	�J�E���g��++�͕ʂ̂Ƃ���ł���Ă��������B
 *	�����͂����܂ŃJ�E���g�������Ă�����̊֐��ł�
 *	�J�E���g���J�n����ƁA�J�E���^�̃t���O��TRUE�ɂȂ�A���������FALSE�ɂȂ�܂��B
 * 
 * \param _arg_nf_count	: �J�E���g�̊J�n
 * \param _arg_nf		: �J�E���g���������Ă���Ƃ�����TF�����]����
 * \param _arg_count	: �J�E���^
 */
inline void F_Nf_count (const BOOL _arg_nf_count, BOOL &_arg_nf, C_COUNT_u1 &_arg_count);

/**
 * \brief
 *	�J�E���^�𗘗p����_arg_nf��TF�𔽓]������֐�
 *	�J�E���^�̓��[�v�ɂ��Ƃ��Ȃ��ł�������
 *	�J�E���g��++�͕ʂ̂Ƃ���ł���Ă��������B
 *	�J�E���^�̃t���O�������Ă��āA_arg_comp�ƃJ�E���^���������Ƃ��ɁA_arg_nf���ω����܂�
 *	�ω�����ƃJ�E���^�̒l��++����܂��B
 *
 * \param _arg_comp	 : ��r����l
 * \param _arg_nf	 : �����������
 * \param _arg_flag	 : �t���O�B�O���ŕς��Ȃ��ł�
 * \param _arg_count : �J�E���^
 */
inline void F_Nf_count (const uchar _arg_comp, BOOL &_arg_nf, BOOL &_arg_flag, C_COUNT_u1 &_arg_count);

/************************************************************************/
/*	����																*/
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


#ifndef _H28_NEW_MAIN__H_
#define _H28_NEW_MAIN__H_ 1

#include <H28_AVR/H28_AVR.h>
#include <FallMoon/akilcd_nm.h>
/* CONTROLER ************************************************************/
#define NOREA 1
#define SOUWE 2
#define ZERO  3

/*CONTROLER : cross rsti lsti*/
enum E_DIRECX
//XŽ²•ûŒü 2bit
{
	ED_EAST  = NOREA, /*‰E*/
	ED_WEST  = SOUWE, /*¶*/
	ED_XZERO = ZERO, /*–³*/
};

inline E_DIRECX SET_DIREC_X(T_DATA _arg_direc_x_data,T_NUM _arg_direc_x_bit)
{
	return (E_DIRECX)((0b100111 >> (((_arg_direc_x_data >> _arg_direc_x_bit) & 3) * 2)) & 3);
}

inline E_DIRECX SET_DIREC_X(E_LOGIC _arg_direc_x_east,E_LOGIC _arg_direc_x_west)
{
	usint _direc_num = (((_arg_direc_x_east << 1) | (_arg_direc_x_west << 0)) * 2);
	
	return (E_DIRECX)((0b100111 >> _direc_num) & 3);
}

inline E_DIRECX TURN_DIREC_X(E_DIRECX _arg_direc_x )
//“Œ¼”½“]
{
	return (E_DIRECX)((0b11011000 >> (((usint)_arg_direc_x) * 2)) & 3);
}

enum E_DIRECY
//YŽ²•ûŒü 2bit
{
	ED_NORTH = NOREA, /*ã*/
	ED_SOUTH = SOUWE, /*‰º*/
	ED_YZERO = ZERO, /*–³*/
};

inline E_DIRECY SET_DIREC_Y(T_DATA _arg_direc_y_data,T_NUM _arg_direc_y_bit)
{
	return (E_DIRECY)((0b100111 >> (((_arg_direc_y_data >> _arg_direc_y_bit) & 3) * 2)) & 3);
}

inline E_DIRECY SET_DIREC_Y(E_LOGIC _arg_direc_y_north,E_LOGIC _arg_direc_y_south)
{
	usint _direc_num = (((_arg_direc_y_north << 1) | (_arg_direc_y_south << 0)) * 2);
	
	return (E_DIRECY)((0b100111 >> _direc_num) & 3);
}

inline E_DIRECY TURN_DIREC_Y(E_DIRECY _arg_direc_y )
//“Œ¼”½“]
{
	return (E_DIRECY)((0b11011000 >> (((usint)_arg_direc_y) * 2)) & 3);
}

/************************************************************************/

/* MD *******************************************************************/
typedef unsigned char T_PWM;

enum E_SIG
//SIG_MODE 2bit
{
	ES_FREE  = 0,
	ES_FALES = 1,
	ES_TRUE  = 2,
	ES_STOP  = 3,
};

inline E_SIG SET_SIG(E_LOGIC _arg_set)
{
	return (E_SIG)(0b01 << _arg_set);
}

inline E_SIG SET_SIG(E_DIRECY _arg_set_direc_y)
{
	return (E_SIG)TURN_DIREC_Y(_arg_set_direc_y);
}

inline E_SIG SET_SIG(E_DIRECX _arg_set_direc_x)
{
	return (E_SIG)TURN_DIREC_X(_arg_set_direc_x);
}

inline E_SIG SET_SIG(E_DIRECY _arg_set_direc_y, E_DIRECX _arg_set_direc_x)	
{
	return (E_SIG)((usint)_arg_set_direc_y & (usint)_arg_set_direc_x);
}

inline E_SIG TURN_SIG_ROTATE(E_SIG _arg_turn_sig)
//³‹t”½“]
{
	return (E_SIG)(0b11011000 >> ((usint)_arg_turn_sig * 2));
}

inline E_SIG TURN_SIG_FIX(E_SIG _arg_turn_sig)
//ƒtƒŠ[AƒuƒŒ[ƒL”½“]
{
	return (E_SIG)(0b00100111 >> ((usint)_arg_turn_sig * 2));
}

inline E_LOGIC CHECK_MOVE(E_SIG _arg_check_sig_mode)
{
	return(E_LOGIC)(0b0110 >> _arg_check_sig_mode);
}

/************************************************************************/

/* AIR ******************************************************************/
#define AIR_NUM 8

/************************************************************************/

#include "H28_NEW_MAIN/H28_NEW_MAIN_class.h"
#include "H28_NEW_MAIN/H28_NEW_MAIN_func.cpp"

#endif /*_H28_MAIN_FUNK_H_*/

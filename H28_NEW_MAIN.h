
#pragma once

//#define USED_H28_AM_640

#include <H28_AVR/H28_AVR.h>
#include <FallMoon/akilcd_nm.h>
#include <H28_OTHERS/H28_C_COUNT.h>

/* CONTROLER ************************************************************/
#define __NOREA__ 0b01
#define __SOUWE__ 0b10
#define __ZERO__  0b11

/**
 * X軸方向 2bit
 */
enum E_DIRECX
{
	ED_EAST  = __NOREA__, //右
	ED_WEST  = __SOUWE__, //左
	ED_XZERO = __ZERO__,  //無
};

/**
 * Y軸方向 2bit
 */
enum E_DIRECY
{
	ED_NORTH = __NOREA__, //上
	ED_SOUTH = __SOUWE__, //下
	ED_YZERO = __ZERO__,  //無
};

/************************************************************************/

/* MD *******************************************************************/
typedef unsigned char T_PWM;
typedef C_COUNT <T_PWM> C_COUNT_PWM;

#ifndef PWM_NOR
#	define PWM_NOR 0x0a
#endif

/**
 * MOTOR_MODE 2bit
 */
enum E_SIG
{
	ES_FREE  = 0,
	ES_FALSE = 1,
	ES_TRUE  = 2,
	ES_STOP  = 3,
};

/************************************************************************/

/* AIR ******************************************************************/

#define AIR_NUM 8

/************************************************************************/

#include "H28_NEW_MAIN_func_direc.h"
#include "H28_NEW_MAIN_func_E_SIG.h"

#include "H28_NEW_MAIN_class/H28_NEW_MAIN_class.h"
#include "H28_NEW_MAIN_func/H28_NEW_MAIN_func.h"


#pragma once

/**
 * \brief 
 * MDCのSIGのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 */
void F_Lcd_mdc_sig(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0);

/**
 * \brief 
 * MDCのSIGのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 */
void F_Lcd_mdc_sig(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1);

/**
 * \brief 
 * MDCのSIGのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 * \param _arg_md_2		: MDのデータ
 */
void F_Lcd_mdc_sig(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1, C_MD_MAIN &_arg_md_2);

/**
 * \brief 
 * MDCのSIGのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 * \param _arg_md_2		: MDのデータ
 * \param _arg_md_3		: MDのデータ
 */
void F_Lcd_mdc_sig(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1, C_MD_MAIN &_arg_md_2, C_MD_MAIN &_arg_md_3);

/**
 * \brief 
 * MDCのPWMのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 */
void F_Lcd_mdc_pwm(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0);

/**
 * \brief 
 * MDCのPWMのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 */
void F_Lcd_mdc_pwm(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1);

/**
 * \brief 
 * MDCのPWMのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 * \param _arg_md_2		: MDのデータ
 */
void F_Lcd_mdc_pwm(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1, C_MD_MAIN &_arg_md_2);

/**
 * \brief 
 * MDCのPWMのデータをLCDに表示する。
 * 実際のMDの順番に合わせて引数に入れてください。
 * MDは実際とあうように設定してください
 *
 * \param _arg_num_mdc	: MDCの番号
 * \param _arg_md_0		: MDのデータ
 * \param _arg_md_1		: MDのデータ
 * \param _arg_md_2		: MDのデータ
 * \param _arg_md_3		: MDのデータ
 */
void F_Lcd_mdc_pwm(usint _arg_num_mdc, C_MD_MAIN &_arg_md_0, C_MD_MAIN &_arg_md_1, C_MD_MAIN &_arg_md_2, C_MD_MAIN &_arg_md_3);

/**
 * \brief 
 * AITのデータをLCDに表示する。
 * 2進数8桁
 * 
 * \param _arg_num_air	: AIRの番号
 * \param _arg_air		: 表示するAIR
 */
void F_Lcd_air(usint _arg_num_air, C_AIR &_arg_air);

#include "H28_NEW_MAIN_func_lcd.cpp"
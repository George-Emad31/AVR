/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 29-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_int.h		             */
/*****************************************/


#ifndef _EXTI_INT_H_
#define _EXTI_INT_H_

void EXTI0_voidInit(void);
void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);
void EXTI0_voidClearFlag(void);
void EXTI0_Set_CallBack( void (*fun_ptr) (void));

void EXTI1_voidInit(void);
void EXTI1_voidEnable(void);
void EXTI1_voidDisable(void);
void EXTI1_voidClearFlag(void);
void EXTI1_Set_CallBack( void (*fun_ptr) (void));

void EXTI2_voidInit(void);
void EXTI2_voidEnable(void);
void EXTI2_voidDisable(void);
void EXTI2_voidClearFlag(void);
void EXTI2_Set_CallBack( void (*fun_ptr) (void));

#endif
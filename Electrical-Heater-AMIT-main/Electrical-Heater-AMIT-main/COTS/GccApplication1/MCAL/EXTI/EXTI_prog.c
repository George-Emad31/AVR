/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 29-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_prog.c	             */
/*****************************************/
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"
#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../GIE/GIE_int.h"
void (*EXTI_0_CallBack) (void) ;

void EXTI0_voidInit(void)
{
	#if EXTI0_u8_ISC == EXTI0_u8_LOW_LEVEL
	CLEAR_BIT(MCUCR,0);
	CLEAR_BIT(MCUCR,1);
	#elif EXTI0_u8_ISC == EXTI0_u8_RISING
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);	
	#elif EXTI0_u8_ISC == EXTI0_u8_FALLING
	CLEAR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);	
	#elif EXTI0_u8_ISC == EXTI0_u8_ANY_CHANGE
	SET_BIT(MCUCR,0);
	CLEAR_BIT(MCUCR,1);	
	#endif
	
	EXTI0_voidDisable();
	GIE_voidDisable();
	EXTI0_voidClearFlag();
}
void EXTI0_voidEnable(void)
{
	SET_BIT(GICR , 6);
}
void EXTI0_voidDisable(void)
{
	CLEAR_BIT(GICR , 6);
}
void EXTI0_voidClearFlag(void)
{
	SET_BIT(GIFR , 6);
}
void EXTI0_Set_CallBack(void (*fun_ptr) (void)){
    EXTI_0_CallBack = fun_ptr;
}
void __vector_1(void) __attribute__((signal , used));
void __vector_1(void)
{
	EXTI_0_CallBack();
}




void (*EXTI_1_CallBack) (void) ;

void EXTI1_voidInit(void)
{
	#if EXTI1_u8_ISC == EXTI1_u8_LOW_LEVEL
	CLEAR_BIT(MCUCR,2);
	CLEAR_BIT(MCUCR,3);
	#elif EXTI0_u8_ISC == EXTI0_u8_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);	
	#elif EXTI0_u8_ISC == EXTI0_u8_FALLING
	CLEAR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);	
	#elif EXTI0_u8_ISC == EXTI0_u8_ANY_CHANGE
	SET_BIT(MCUCR,2);
	CLEAR_BIT(MCUCR,3);	
	#endif
	
	EXTI1_voidDisable();
	GIE_voidDisable();
	EXTI1_voidClearFlag();
}
void EXTI1_voidEnable(void)
{
	SET_BIT(GICR , 7);
}
void EXTI1_voidDisable(void)
{
	CLEAR_BIT(GICR , 7);
}
void EXTI1_voidClearFlag(void)
{
	SET_BIT(GIFR , 7);
}
void EXTI1_Set_CallBack(void (*fun_ptr) (void)){
    EXTI_1_CallBack = fun_ptr;
}
void __vector_2(void) __attribute__((signal , used));
void __vector_2(void)
{
	EXTI_1_CallBack();
}




void (*EXTI_2_CallBack) (void) ;

void EXTI2_voidInit(void)
{
	#if EXTI0_u8_ISC == EXTI0_u8_RISING
	SET_BIT(MCUCSR,6);	
	#elif EXTI0_u8_ISC == EXTI0_u8_FALLING
	CLEAR_BIT(MCUCSR,6);	
	#endif
	
	EXTI2_voidDisable();
	GIE_voidDisable();
	EXTI2_voidClearFlag();
}
void EXTI2_voidEnable(void)
{
	SET_BIT(GICR , 5);
}
void EXTI2_voidDisable(void)
{
	CLEAR_BIT(GICR , 5);
}
void EXTI2_voidClearFlag(void)
{
	SET_BIT(GIFR , 5);
}
void EXTI2_Set_CallBack(void (*fun_ptr) (void)){
    EXTI_2_CallBack = fun_ptr;
}
void __vector_3(void) __attribute__((signal , used));
void __vector_3(void)
{
	EXTI_2_CallBack();
}
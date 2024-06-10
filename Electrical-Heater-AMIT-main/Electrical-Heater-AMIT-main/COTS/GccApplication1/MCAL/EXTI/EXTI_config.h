/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 29-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : EXTI_config.h		         */
/*****************************************/
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_


/*
options:

	EXTI0_u8_RISING
	
	EXTI0_u8_FALLING
	
	EXTI0_u8_ANY_CHANGE
	
	EXTI0_u8_LOW_LEVEL
*/

#define EXTI0_u8_ISC   EXTI0_u8_RISING


/*
options:

	EXTI1_u8_RISING
	
	EXTI1_u8_FALLING
	
	EXTI1_u8_ANY_CHANGE
	
	EXTI1_u8_LOW_LEVEL
*/

#define EXTI1_u8_ISC   EXTI1_u8_RISING


/*
options:

	EXTI2_u8_RISING
	
	EXTI2_u8_FALLING
	
*/

#define EXTI2_u8_ISC   EXTI2_u8_RISING

#endif
	

/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 28-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : GIE_prog.c	                 */
/*****************************************/

#include "GIE_private.h"

void GIE_voidEnable(void)
{
	SREG |= (1<<7);
}
void GIE_voidDisable(void)
{
	SREG &=~ (1<<7);
}
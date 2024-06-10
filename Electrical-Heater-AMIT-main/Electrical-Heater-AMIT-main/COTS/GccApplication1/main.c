/*
 * GccApplication1.c
 *
 * Created: 30/12/2022 06:29:35
 * Author : George Emad
 */ 

#define  F_CPU 1000000UL
#include <stdlib.h>
#include <util/delay.h>
#include "Services/STD_types.h"
#include "Services/BIT_MATH.h"
#include "DIO.H"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/TIMER0/TIMER0_int.h"
#include "MCAL/GIE/GIE_int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/EEPROM/EEPROM_int.h"

 
unsigned char flag1='0',flag2='0',EXTI01_flag = '0',EXTI2_flag = '1';
unsigned short int ADC_val,i=0,j=0,K=0,l=0;
float currenttemperature=0.0,desiredtemperature=60.0;
char desiredtemperature_AsChar[1];
//temperature setting mode in case of increasing temperature
void EXTI0_ISR (void)
{
	Lable0:
	/*
	when pressing the up temperature button for the first time EXTI01_flag == '0' so that it will not increase the
	 desiredtemperature by 5 in the first time and display the desiredtemperature on 7_segment using switching technique 
	 and blinking every 500ms for 5 seconds if the user press the up temperature button again within the 5 seconds the
	 EXTI01_flag will became '1' and flag1 will became '1' and desiredtemperature will be increased by 5 and be displayed
	 on the 7 segments for another 5 second
	*/ 
	if(desiredtemperature<75.0 && EXTI01_flag == '1')
	{
		desiredtemperature += 5.0;
	}
	//every change in desiredtemperature update it in EEPROM
	itoa((int)desiredtemperature,desiredtemperature_AsChar,10); 
	EEPROM_write(0,desiredtemperature_AsChar[0]);
	EEPROM_write(1,desiredtemperature_AsChar[1]);
	flag1='1';
	EEPROM_write(2,flag1);
	flag1 = EEPROM_read(2);
	flag2 = EEPROM_read(3);
	EXTI01_flag = '1';//change EXTI01_flag to '1' to increase the desiredtemperature if the up button pressed again within 5 seconds
	while(PIND & (1<<2));//stop when the button is still pressed 
	//display the desiredtemperature on 7_segment for 5 seconds and blinking every 500ms using switching technique 
	for(j=0;j<=4;j++)
	{
			for(K=0;K<=24;K++)
			{
				//if the up temp button pressed again during displaying the desiredtemperature go to Lable0 and increase the desiredtemperature
				if(PIND & (1<<2))
				{
					goto Lable0;
				}
				PORTD &=~ (1<<0);
				PORTD |= (1<<1);
				PORTC = desiredtemperature_AsChar[0]-'0';
				_delay_ms(10);
				PORTC = desiredtemperature_AsChar[1]-'0';
				PORTD &=~ (1<<1);
				PORTD &=~ (1<<0);
				_delay_ms(10);
			}
			for(K=0;K<=24;K++)
			{	
				//if the up temp button pressed again during displaying the desiredtemperature go to Lable0 and increase the desiredtemperature
				if(PIND & (1<<2))
				{
				 goto Lable0;
				}
				PORTD |= (1<<0);
				PORTD |= (1<<1);
				PORTC = desiredtemperature_AsChar[0]-'0';
				_delay_ms(10);
				PORTC = desiredtemperature_AsChar[1]-'0';
				PORTD |= (1<<1);
				PORTD |= (1<<0);
				_delay_ms(10);
			}
	}
	EXTI01_flag = '0';
}

//temperature setting mode in case of decreasing temperature
void EXTI1_ISR (void)
{
	Lable1:
	/*
	when pressing the down temperature button for the first time EXTI01_flag == '0' so that it will not decrease the
	desiredtemperature by 5 in the first time and display the desiredtemperature on 7_segment using switching technique 
	and blinking every 500ms for 5 seconds if the user press the down temperature button again within the 5 seconds the
    EXTI01_flag will became '1' and flag1 will became '1' and desiredtemperature will be decreased by 5 and be displayed
	on the 7 segments for another 5 seconds
	*/ 
	if(desiredtemperature>35.0 && EXTI01_flag == '1')
	{
		desiredtemperature -= 5.0;
	}
	//every change in desiredtemperature update it in EEPROM
	itoa((int)desiredtemperature,desiredtemperature_AsChar,10); //function used to convert int data type to array of characters
	EEPROM_write(0,desiredtemperature_AsChar[0]);
	EEPROM_write(1,desiredtemperature_AsChar[1]);
	flag1='1';
	EEPROM_write(20,flag1);
	flag1 = EEPROM_read(2);
	flag2 = EEPROM_read(3);
	EXTI01_flag = '1';//change EXTI01_flag to '1' to increase the desiredtemperature if the up button pressed again within 5 seconds
	while(PIND & (1<<3));//stop when the button is still pressed
	//display the desiredtemperature on 7_segment for 5 seconds and blinking every 500ms using switching technique
	for(j=0;j<=4;j++)
	{
		for(K=0;K<=24;K++)
		{
			//if the down temp button pressed again during displaying the desiredtemperature go to Lable1 and decrease the desiredtemperature
			if(PIND & (1<<3))
			{
				goto Lable1;
			}
			PORTD &=~ (1<<0);
			PORTD |= (1<<1);
			PORTC = desiredtemperature_AsChar[0]-'0';
			_delay_ms(10);
			PORTC = desiredtemperature_AsChar[1]-'0';
			PORTD &=~ (1<<1);
			PORTD &=~ (1<<0);
			_delay_ms(10);
		}
		for(K=0;K<=24;K++)
		{
			//if the down temp button pressed again during displaying the desiredtemperature go to Lable1 and decrease the desiredtemperature
			if(PIND & (1<<3))
			{
				goto Lable1;
			}
			PORTD |= (1<<0);
			PORTD |= (1<<1);
			PORTC = desiredtemperature_AsChar[0]-'0';
			_delay_ms(10);
			PORTC = desiredtemperature_AsChar[1]-'0';
			PORTD |= (1<<1);
			PORTD |= (1<<0);
			_delay_ms(10);
		}
	}
	EXTI01_flag = '0';
}


void EXTI2_ISR (void)
{
	//case circuit is on and i want to make it off
	if(EXTI2_flag == '1')
	{
		while(PINB & (1<<2));
		EXTI0_voidDisable();
		EXTI1_voidDisable();
		TIMER0_OV_disable();
		//this flag be using inside the super loop to determine the status of the system on(1) or off(0)
		EXTI2_flag = '0';
	}
	//case circuit is off and i want to make it on
	else
	{
		while(PINB & (1<<2));
		EXTI0_voidEnable();
		EXTI1_voidEnable();
		TIMER0_OV_enable();
		////this flag be using inside the super loop to determine the status of the system on(1) or off(0)
		EXTI2_flag = '1';
	}
}


/*timer0 0v ISR happen every 10ms and read temperature sensor value every 100ms by ADC
and increasing a global variable l by 1 every 10ms this variable is used 
to blink 7_segments in temperature setting mode up or down*/
void T0_ISR (void)
{
	i++;
	l++;
	TIMER0_SetTimerCounter(246);
	if(i==10)
	{
		ADC_val = ADC_read('0');
		currenttemperature = (((float)ADC_val * 5.0)/1023.0)/0.01;
		i=0;
	}
}


int main(void)
{
	DDRB &=~ (1<<2);
	DDRC=0b00001111;
	DDRD=0b01110011;
	char currenttemperature_ToChar[1];
	ADC_init();
	TIMER0_SetOV_CallBack(T0_ISR);
	TIMER0_init();
	TIMER0_SetTimerCounter(246);
	TIMER0_OV_enable();
	EXTI0_Set_CallBack(EXTI0_ISR);
	EXTI0_voidInit();
	EXTI0_voidEnable();
	EXTI1_Set_CallBack(EXTI1_ISR);
	EXTI1_voidInit();
	EXTI1_voidEnable();
	EXTI2_Set_CallBack(EXTI2_ISR);
	EXTI2_voidInit();
	EXTI2_voidEnable();
	GIE_voidEnable();
	_delay_ms(150);
	
	/*when the program run for the first time (currenttemperature<36) store the default desiredtemperature (60) in EEPROM*/
	if((int)currenttemperature<36)
	{
		itoa((int)desiredtemperature,desiredtemperature_AsChar,10); //function used to convert int data type to array of characters
		EEPROM_write(0,desiredtemperature_AsChar[0]);
		EEPROM_write(1,desiredtemperature_AsChar[1]);
	}
	
	/*the next 3 lines to restore the last desiredtemperature from EEPROM in case of microcontroller lost power for any reason*/
	desiredtemperature_AsChar[0] = EEPROM_read(0);
	desiredtemperature_AsChar[1] = EEPROM_read(1);
	desiredtemperature=atof(desiredtemperature_AsChar);
	
	while (1)
	{	
		/*when pressing system on/off button which connected on EXTI2 it toggle a flag called EXTI2_flag which it's initial 
		value is 1 that flag determine if the system is on (EXTI2_flag = 1) or system is off (EXTI2_flag = 0)*/	
		if(EXTI2_flag == '0')
		{
			PORTD |=  (1<<0); //turn off first 7_segments
			PORTD |=  (1<<1); //turn off second 7_segments
			PORTD &=~ (1<<4); //turn off led
			PORTD &=~ (1<<5); //turn off heater
			PORTD &=~ (1<<6); //turn off cooler
		}
		//do else when (EXTI2_flag = 1)
		else
		{
			if((int)currenttemperature>35)
			{
				flag1 = EEPROM_read(2);
				flag2 = EEPROM_read(3);
			}
			if(flag1=='1')
			{
				//case if current < desired
				if(((int)currenttemperature<(int)desiredtemperature)&&flag2=='0')
				{
					if(l>=99)
					{
						PORTD ^=  (1<<4);
						l=0;
					}
					PORTD |=  (1<<5);
					PORTD &=~ (1<<6);
				}
				else if(((int)currenttemperature>(int)desiredtemperature)&&flag2=='0')
				{
					PORTD |=  (1<<4);
					PORTD &=~ (1<<5);
					PORTD |=  (1<<6);
				}
				else
				{
					flag2='1';
					EEPROM_write(3,flag2);
					PORTD &=~  (1<<4);
					PORTD &=~  (1<<5);
					PORTD &=~ (1<<6);
					if((int)currenttemperature <= (int)(desiredtemperature - 5.0))
					{
						flag2='0';
						EEPROM_write(3,flag2);
					}
					else if((int)currenttemperature > (int)desiredtemperature)
					{
						flag2='0';
						EEPROM_write(3,flag2);
					}
				}
			}
			/*function used to convert int data type to array of characters ex if the currenttemperature = 35 the function put
			 '3' in currenttemperature_ToChar[0] and '5' in currenttemperature_ToChar[1]*/
			itoa((int)currenttemperature,currenttemperature_ToChar,10); 
			/*display currenttemperatur on 7_segments using switching technique */
			PORTD &=~ (1<<0);
			PORTD |= (1<<1);
			PORTC = currenttemperature_ToChar[0]-'0';
			_delay_ms(10);
			PORTC = currenttemperature_ToChar[1]-'0';
			PORTD &=~ (1<<1);
			PORTD &=~ (1<<0);
			_delay_ms(10);
		}	
	}
}

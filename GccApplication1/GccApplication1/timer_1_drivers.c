/*
 * timer_1__drivers.c
 *
 * Created: 10/17/2022 2:22:47 PM
 *  Author: mostafa_hamedo
 */ 
#include "std_macros.h"
#include <avr/io.h>

void timer_1_pwm_fast(void)
{
	

// SET_pin_direction of OC1A & OC1B

SET_BIT(DDRD,4);    // SET OC1B
SET_BIT(DDRD,5);	// SET OC1A

// Select clock timer 
 
 SET_BIT(TCCR1B,CS10);
 SET_BIT(TCCR1B,CS12);
 
 //select wave form 
 
 SET_BIT(TCCR1A,COM1A0);	//SET OC1A at bottom
 SET_BIT(TCCR1A,COM1A1);	//set OC1A clear at compare match
 
 SET_BIT(TCCR1A,COM1B0);	//SET OC1B at bottom
 SET_BIT(TCCR1A,COM1B1);	//set OC1B clear at compare match
 
 
//select pwm_fast mode
 SET_BIT(TCCR1A,WGM10);
 SET_BIT(TCCR1A,WGM11);
 SET_BIT(TCCR1B,WGM12);
 SET_BIT(TCCR1B,WGM13);
 
 //preload the OC1A & OC1B VALUE 
 
 
 OCR1A=250;
 //OCR1B=500;
 
} 

void servo_angle(unsigned short angle)
{
	
	// SET_pin_direction of OC1A 
	SET_BIT(DDRD,5);	// SET OC1A

	// Select clock timer
	SET_BIT(TCCR1B,CS11);   // prescaler factor 8 , timer clock will be (1Mhz)
	
	//select wave form
	SET_BIT(TCCR1A,COM1A1);	// (non_inverting mode)
	
	//select pwm_fast mode
	
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);	// fast pwm mode (ICR1)
	SET_BIT(TCCR1B,WGM13);	// TOP =ICR1
	
	//preload the ICR1 & OCR1A VALUE
	
	ICR1=20000;							 //		0.5
	OCR1A=1000+(angle*0.005555555)*1000; //    -----=0.005555555 for one degree
										 //		90
	/*
	duty cycle =20 mile_second	
	0 degree------------------>1 mile_second 
	90 degree ---------------->1.5 mile_second
	180 degree --------------->2 mile_second
	*/
	
}
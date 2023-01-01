/*
 * GccApplication1.c
 *
 * Created: 10/19/2022 7:36:24 AM
 *  Author: mostafa_hamedo
 */ 


#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "timer_1_drivers.h"
int main(void)
{
	unsigned short count ;
    while(1)
    {
		servo_angle(0);		// 0 degree
		_delay_ms(1000);
		servo_angle(30);	// 30 degree
		_delay_ms(1000);
        servo_angle(60);	// 60 degree
        _delay_ms(1000);
		servo_angle(90);	// 90 degree
		_delay_ms(1000);
		servo_angle(120);	// 120 degree
		_delay_ms(1000);
		servo_angle(150);	// 150 degree
		_delay_ms(1000);
		servo_angle(180);	// 180 degree
		_delay_ms(1000);
		servo_angle(0);		//0 degree
		_delay_ms(2000);
		
		for (count=0;count<=180;count++)
		{
			servo_angle(count);           // 0 : 180 degree
			_delay_ms(100);
		}
		
		for (count=180;count>0;count--)
		{
			servo_angle(count);			// 180 : 0 degree
			_delay_ms(100);
		}
		
		
    }
}
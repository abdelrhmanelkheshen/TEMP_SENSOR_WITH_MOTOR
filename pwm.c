/*
 * pwm.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */

#include "pwm.h"
#include <avr/io.h>
#include "gpio.h"

void PWM_TIMER0_START(uint8 duty_cycle)
{
	TCNT0=0;
	TCCR0 = (1<<CS01) | (1<<WGM00) | (1<<WGM01) | (1<<COM01);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
	if(duty_cycle==0){
		OCR0=0;
	}
	else if(duty_cycle==25){
		OCR0=64;
	}
	else if(duty_cycle==50){
		OCR0=128;
	}
	else if(duty_cycle==75){
		OCR0=192;
	}else if(duty_cycle==100){
		OCR0=255;

	}
	else{

	}

}

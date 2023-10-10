/*
 * dcmotor.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */
#include "dcmotor.h"
#include "gpio.h"
#include <avr/io.h>
#include "pwm.h"

void DMotor_Init(void)
{
	GPIO_setupPinDirection(ENABLE_1_PORT_ID, ENABLE_1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE_2_PORT_ID, ENABLE_2_PIN_ID,PIN_OUTPUT);
    GPIO_writePin(ENABLE_2_PORT_ID, ENABLE_2_PIN_ID, LOGIC_LOW);
    GPIO_writePin(ENABLE_1_PORT_ID, ENABLE_1_PIN_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PORTB = (PORTB & 0xFC) | (state);
	PWM_TIMER0_START(speed);
}


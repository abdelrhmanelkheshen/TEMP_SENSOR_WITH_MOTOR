/*
 * dcmotor.h
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "standard_types_defined.h"

#define MAX_MOTOR_SPEED 100
#define MIN_MOTOR_SPEED 0

#define ENABLE_1_PORT_ID PORTB_ID
#define ENABLE_2_PORT_ID PORTB_ID

#define ENABLE_1_PIN_ID PIN0_ID
#define ENABLE_2_PIN_ID PIN1_ID

typedef enum
{
	stop,cw,ccw
}DcMotor_State;



void DMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* DCMOTOR_H_ */

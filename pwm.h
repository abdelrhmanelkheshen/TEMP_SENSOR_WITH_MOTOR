/*
 * pwm.h
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */

#ifndef PWM_H_
#define PWM_H_
#include "standard_types_defined.h"

#define MAX_PWM_SIGNAL 255


void PWM_TIMER0_START(uint8 duty_cycle);

#endif /* PWM_H_ */

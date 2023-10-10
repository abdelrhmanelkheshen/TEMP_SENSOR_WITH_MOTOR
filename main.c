/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */
#include "dcmotor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include"adc.h"

void fan(uint8 *x);


int main(void) {
	ADC_config configuration = { INTERNAL_VREF2, FCPU_8 };

	LCD_init();
	DMotor_Init();
	ADC_init(&configuration);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp is ");
	for (;;)
	{
		uint8 temp = LM35_getTemperature();
		fan(&temp);
	}
}
void fan(uint8 *x)
{

	if (*x < 10) {
		LCD_moveCursor(1, 8);
		LCD_intgerToString(*x);
		LCD_displayString("  ");
	}
	else if (*x < 100) {
		LCD_moveCursor(1, 8);
		LCD_intgerToString(*x);
		LCD_displayString(" ");

	}
	else
	{
		LCD_moveCursor(1, 8);
		LCD_intgerToString(*x);
	}
	if (*x>30)
	{
		LCD_moveCursor(0, 7);
		LCD_displayString("on ");
	}
	else
	{
		LCD_moveCursor(0, 7);
		LCD_displayString("off");
	}
	if (*x < 30) {
		DcMotor_Rotate(stop, 0);
	} else if ((*x >= 30) && (*x < 60)) {
		DcMotor_Rotate(cw, 25);
	} else if ((*x >= 60) && (*x < 90)) {
		DcMotor_Rotate(cw, 50);
	} else if ((*x >= 90) && (*x < 120)) {
		DcMotor_Rotate(cw, 75);
	} else {
		DcMotor_Rotate(cw, 100);
	}
}

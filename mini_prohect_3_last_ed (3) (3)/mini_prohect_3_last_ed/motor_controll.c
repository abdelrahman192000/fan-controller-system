/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "timer_pwm.h"
#include <util/delay.h>

int main(void)
{
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_ConfigType adc_Config = {INTERNAL,_8};
	ADC_init(&adc_Config);  /* initialize ADC driver */
	DcMotor_Init();
	DcMotor_Rotate(STATE_OFF,0);

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");


	while(1)
	{

		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		if (temp<30)
		{

			DcMotor_Rotate(STATE_ON,0);
		}
		else if (temp>=30 && temp<60)
		{

			DcMotor_Rotate(STATE_ON,25);
		}
		else if (temp>=60 && temp<90)

		{

			DcMotor_Rotate(STATE_ON,50);
		}
		else if (temp>=90 && temp<120)

		{

			DcMotor_Rotate(STATE_ON,75);
		}
		else if (temp>=120)
		{

			DcMotor_Rotate(STATE_ON,100);
		}

		LCD_moveCursor(0,7);

		if(temp >= 100)
		{
			LCD_intgerToString(temp);

			if (temp<30)
			{
				LCD_moveCursor(1,0);
				LCD_displayString(" state off");

			}
			else
			{
				LCD_moveCursor(1,0);
				LCD_displayString(" state on");
			}
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			if (temp<30)
			{
				LCD_moveCursor(1,0);
				LCD_displayString(" state off");
			}
			else
			{
				LCD_moveCursor(1,0);
				LCD_displayString(" state on");
			}

			LCD_displayCharacter(' ');
		}
	}
}

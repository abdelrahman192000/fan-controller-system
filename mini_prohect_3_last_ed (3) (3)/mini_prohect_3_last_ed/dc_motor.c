/*
 * dc_motor.c
 *
 *  Created on: Oct 7, 2022
 *      Author: abdelrahman
 */
#include "dc_motor.h"
#include "gpio.h"
#include "timer_pwm.h"
#include <stdio.h>

void DcMotor_Init (void) // fun to set motor direction and start up setting
{

	//set direction of pins
	GPIO_setupPinDirection(DC_IN_1_PIN_PORT,DC_IN_1_PIN_PIN,PIN_OUTPUT); //set in1 ass out
	GPIO_setupPinDirection(DC_IN_2_PIN_PORT,DC_IN_2_PIN_PIN,PIN_OUTPUT); //set in2 ass out
	GPIO_setupPinDirection(DC_SPEED_CONTROLL_PORT,DC_SPEED_CONTROLL_PIN,PIN_OUTPUT); //set oc0 ass out

	//set start value off
	GPIO_writePin(DC_IN_1_PIN_PORT,DC_IN_1_PIN_PIN,LOGIC_LOW); //set in1 off
	GPIO_writePin(DC_IN_2_PIN_PORT,DC_IN_2_PIN_PIN,LOGIC_LOW); //set in2 off
	GPIO_writePin(DC_SPEED_CONTROLL_PORT,DC_SPEED_CONTROLL_PIN,LOGIC_LOW); //set oc0 off

}
void DcMotor_Rotate (DcMotor_State state,uint8 speed) //fun to take state of motor with its speed

{
	uint8 percintage_speed =(((float)speed/100)*255);



	if (state == STATE_ON)
	{

#if (DC_DIRECTION==1) // set dc direction as clock wise

		GPIO_writePin(DC_IN_1_PIN_PORT,DC_IN_1_PIN_PIN,LOGIC_LOW); //set in1 off
		GPIO_writePin(DC_IN_2_PIN_PORT,DC_IN_2_PIN_PIN,LOGIC_HIGH); //set in2 on
		PWM_Timer0_Start(percintage_speed);// fun to take value of speed to generate (PWM SIGNAL)

#elif (DC_DIRECTION==0)

		GPIO_writePin(DC_IN_1_PIN_PORT,DC_IN_1_PIN_PIN,LOGIC_HIGH); //set in1 on
		GPIO_writePin(DC_IN_2_PIN_PORT,DC_IN_2_PIN_PIN,LOGIC_LOW); //set in2 off
		PWM_Timer0_Start(percintage_speed);

#endif

	}

}

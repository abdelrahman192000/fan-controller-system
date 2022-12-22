/*
 * dc_motor.h
 *
 *  Created on: Oct 7, 2022
 *      Author: abdelrahman
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "gpio.h"




/*******definitions*******/

typedef enum  DcMotor_State
{
	  STATE_OFF,
	  STATE_ON





} DcMotor_State;



#define DC_IN_1_PIN_PORT PORTB_ID
#define DC_IN_1_PIN_PIN  PIN0_ID

#define DC_IN_2_PIN_PORT PORTB_ID
#define DC_IN_2_PIN_PIN  PIN1_ID

#define DC_SPEED_CONTROLL_PORT PORTB_ID
#define DC_SPEED_CONTROLL_PIN  PIN3_ID



#define DC_DIRECTION 1 //clock wise
//clock wise -> value = 1
//clock wise -> value = 0










/***********function definitions************/
void DcMotor_Init (void);// fun to set motor direction and start up setting

void DcMotor_Rotate (DcMotor_State state,uint8 speed);//fun to take state of motor with its speed




#endif /* DC_MOTOR_H_ */

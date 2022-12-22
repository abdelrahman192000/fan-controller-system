/*
 * timer_pwm.h
 *
 *  Created on: Oct 7, 2022
 *      Author: abdelrahman
 */

#ifndef TIMER_PWM_H_
#define TIMER_PWM_H_

#include "std_types.h"



/***** definitions *********/
// make up setting of duty cycle
#define FULL_DUTY_CYCLE          255   // 100%
#define THREE_QUARTER_DUTY_CYCLE 192   // 75%
#define HALF_DUTY_CYCLE          128   // 50%
#define QUARTER_DUTY_CYCLE       64    // 25%
#define DUTY_CYCLE_ZERO          0     //0%




// make up connection of PWM pin and target

#define PWM_PORT_ID   PORTB_ID
#define PWM_PIN_ID    PIN3_ID



/*************functions definitions***************/

void PWM_Timer0_Start (uint8 duty_cycle) ;




#endif /* TIMER_PWM_H_ */

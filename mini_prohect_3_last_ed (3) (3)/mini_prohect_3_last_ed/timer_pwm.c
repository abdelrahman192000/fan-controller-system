/*
 * timer_pwm.c
 *
 *  Created on: Oct 7, 2022
 *      Author: abdelrahman
 */
#include "timer_pwm.h"
#include <avr/io.h>
#include "gpio.h"

void PWM_Timer0_Start (uint8 duty_cycle)

{

	TCNT0 = 0;
	OCR0 = duty_cycle;
	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,PIN_OUTPUT); //set directio of oc0 output
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	/*
	     * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
    */

}





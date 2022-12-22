 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

/*
 * enum to define the Prescaler for ADC
 */
typedef enum
{
	_2 = 1, _4, _8, _16, _32, _64, _128
}ADC_Prescaler;

/*
 * Structure containing reference voltage & Prescaler for ADC
 */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */

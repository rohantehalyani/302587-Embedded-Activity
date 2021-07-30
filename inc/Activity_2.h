/**
 * @file Heater_Controller.c
 * @author Abhay Sahu
 * @brief Reading Temperature sensor
 * @version 0.1
 * @date 2021-07-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY_2_h__
#define __ACTIVITY_2_h__
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initializing ADC
 * 
 */
void ADCInit(void);

/**
 * @brief Read the Temperature sensor output using ADC
 * 
 * @return uint16_t temperature sensor output
 */

uint16_t readADC(uint8_t);

#endif
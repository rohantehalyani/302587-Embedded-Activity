/**
 * @file Activity_3.h
 * @author Abhay Sahu
 * @brief Modulate PWM output based on Temp. sensor
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY_3_H__
#define __ACTIVITY_3_H__
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize Timer for PWM operation
 * 
 */
void PWMInit(void);

/**
 * @brief Modulate PWM output duty cycle based on Temperature Sensor value
 * 
 * @param data Temperature Sensor value
 */
void PWMOutput(uint16_t);

/**
 * @brief Turn OFF Output of PWM when Heater is off
 * 
 */
void PWMHeaterOFF(void);

#endif
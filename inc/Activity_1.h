/**
 * @file Activity_1.h
 * @author Abhay Sahu
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY_1_H__
#define __ACTIVITY_1_H__

#include <avr/io.h>
#include <util/delay.h>

#define CHECK_SEAT (!(PIND&(1<<PD0))) /**< Check Seat*/
#define Check_HEATER_ONOFF (!(PIND&(1<<PD1))) /**<Check Heater Button is ON or Off*/

#define LED_PORT (PORTB) /**<LED port B*/
#define LED_PIN (PB0) /**<LED pin no.*/

/**
 * @brief Initialazation of GPIO pins
 * 
 */
void gpioInit(void);

/**
 * @brief Check AND condition of check seat and check heater button
 * 
 * @return on off status of heater
 */
uint8_t heaterStatus(void);

#endif

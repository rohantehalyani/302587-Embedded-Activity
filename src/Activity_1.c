/**
 * @file Activity_1.c
 * @author Rohan Tehalyani
 * @brief If Occupancy status is true (ON) AND if heater status is true (ON) then: Turn ON Heater
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "Activity_1.h"

/**
 * @brief aquiring status by initializing gpio pins
 * 
 */
void gpioInit(void){
    DDRB |= (1<<PB0); // set PB0=1 (output)

    DDRD &= ~(1<<PD0); // clear PD0=0 (input for seat occupancy)
    PORTD |= (1<<PD0); // set PD0=1

    DDRD &= ~(1<<PD1); // clear PD1=0 (input for heater)
    PORTD |= (1<<PD1); // set PD1=1
}

/**
* @brief If seat occupancy is ON AND heater is ON -> Heater and LED ON
 * 
 * @return unit8_t ON or OFF the heater
 */ 
uint8_t heaterStatus(void){
    if((CHECK_SEAT)&&(Check_HEATER_ONOFF)){
        LED_PORT |= (1<<LED_PIN); // LED ON
        _delay_ms(200);
        return 1;
    }
    else{
        LED_PORT &= ~(1<<LED_PIN); //LED OFF
        _delay_ms(200);
        return 0;
    }
}


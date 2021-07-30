/**
 * @file Activity_3.c
 * @author Abhay Sahu
 * @brief Modulate PWM output based on Temp. sensor
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "Activity_3.h"

/**
 * @brief Initialize Timer for PWM operation
 * 
 */
void PWMInit(void){
    TCCR1A |= (1<<COM1A1)|(1<<WGM11)|(1<<WGM10); // set to non inverting mode and set to 10 bit Fast PWM mode
    TCCR1B |= (1<<WGM12); //set to 10 bit Fast PWM mode
    TCCR1B |= (1<<CS11)|(1<<CS10);//64 prescaler
    DDRB |= (1<<PB1); // Set B1 as output to view PWM output
}

/**
 * @brief Modulate PWM output duty cycle based on Temperature Sensor value
 * 
 * @param data Temperature Sensor value
 */
void PWMOutput(uint16_t data){
    //use ADC output data to define PWM duty cycle
    if (data>=0 && data<=200){
        OCR1A = 204; //20% duty cycle
        _delay_ms(200);
    }
    else if (data>=201 && data<=500){
        OCR1A = 409; //40% duty cycle
        _delay_ms(200);
    }
    else if (data>=501 && data<=700){
        OCR1A = 716; //70% duty cycle
        _delay_ms(200);
    }
    else if (data>=701 && data<=1024){
        OCR1A = 972; //95% duty cycle
        _delay_ms(200);
    }
}

/**
 * @brief Turn OFF Output of PWM when Heater is off
 * 
 */
void PWMHeaterOFF(void){
    OCR1A = 0; //0% duty cycle
     _delay_ms(200);
}
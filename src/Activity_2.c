/**
 * @file Activity_2.c
 * @author Rohan Tehalyani
 * @brief Reading Temperature sensor
 * @version 0.1
 * @date 2021-07-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __AVR_ATmega328__
    #define __AVR_ATmega328__
#endif

#include "Activity_2.h"

/**
 * @brief Initialize ADC
 * 
 */
void ADCInit(void){
    ADMUX |= (1<<REFS0); //ARef=AVcc
    ADCSRA |= (1<<ADEN)|(7<<ADPS0);//enable ADC and set prescalar to 128
}

/**
 * @brief Read the Temperature Sensor (Potentiometer) value via ADC
 * 
 * @param ch The to which the ADC is connected
 * @return uint16_t Temperature Sensor (Potentiometer) value
 */
uint16_t readADC(uint8_t ch){

    //Select ADC Channel ch must be 0-7

    ADMUX&=0xf8; //clearing MUX2,1,0 bits and considering the rest as such
    ch=ch&0b00000111;

    ADMUX|=ch;
    ADCSRA|=(1<<ADSC); //Start Single conversion

    //Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    
    ADCSRA|=(1<<ADIF); //Clear ADIF by writing one to it

    return(ADC);
}

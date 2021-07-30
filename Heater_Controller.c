/**
 * @file Heater_Controller.c
 * @author Abhay Sahu
 * @brief Seat Heateing Status
 * @version 0.1
 * @date 2021-07-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "Activity_1.h"
#include "Activity_2.h"
#include "Activity_3.h"

int main(void){

    gpioInit(); //Initialize GPIO
    ADCInit(); //Initialize ADC
    PWMInit(); //Initialize PWM

    while(1){
        uint8_t status = 0; // To store heater status
        uint16_t sensorOut = 0; // To store temp sensor output

        status = heaterStatus(); // Get heater status

        if(status==1){
            sensorOut = readADC(0); // Read temp sensor
            _delay_ms(200); // Delay after reading sensor output 
            PWMOutput(sensorOut); // Modulate PWM according to sensor output
        }
        else{
            PWMHeaterOFF(); // OFF heater id heaterStatus condition not satisfied
        }
    }
    return 0;
}
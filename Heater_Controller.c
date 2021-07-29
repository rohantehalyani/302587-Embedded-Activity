/**
 * @file Heater_Controller.c
 * @author Rohan Tehalyani
 * @brief Seat Heating
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Activity_1.h"
#include "Activity_2.h"

int main(void){

    gpioInit();

    while(1){
        uint8_t status = 0;
        uint16_t sensorOut = 0;

        status = heaterStatus();

        if(status==1){
            sensorOut = readADC(0);
            _delay_ms(200);
        }
    }
    return 0;
}
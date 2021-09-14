/**
 * Author: Ahmed Alaa
 * main.c
 */

#define F_CPU 16000000UL

#include "tm4c123gh6pm/stdtypes.h"
#include "tm4c123gh6pm/gpio_reg.h"
#include "tm4c123gh6pm/gpio.h"
#include "tm4c123gh6pm/util.h"

int main(void)
{
    /* Setup Configurations */
    GPIO_SetPinDirection(PORTF, PF4, INPUT); // Switch 1: Pin 4 on Port F in Input Pin
    GPIO_SetPinDirection(PORTF, PF0, INPUT); // Switch 2: Pin 0 on Port F in Input Pin

    activate_pull_up(PORTF, PF4); // Activate the pull up resistance on PF4 (Switch 1)
    activate_pull_up(PORTF, PF0); // Activate the pull up resistance on PF4 (Switch 2)

    GPIO_SetPinDirection(PORTF, PF1, OUTPUT); // RED LED: Pin 1 on Port F in Output Pin
    GPIO_SetPinDirection(PORTF, PF2, OUTPUT); // BLUE LED: Pin 2 on Port F in Output Pin
    GPIO_SetPinDirection(PORTF, PF3, OUTPUT); // GREEN LED: Pin 3 on Port F in Output Pin

    GPIO_SetPinValue(PORTF, PF1, LOW); // Turn off Red LED
    GPIO_SetPinValue(PORTF, PF2, LOW); // Turn off Blue LED
    GPIO_SetPinValue(PORTF, PF3, LOW); // Turn off Green LED
    /* Super Loop */
    while(1)
    {
        if (!GPIO_GetPinValue(PORTF, PF4) && !GPIO_GetPinValue(PORTF, PF0)) // If Switch 1 and Switch 2 are pressed on the same time
        {
            _delay_ms(30); // 30 ms delay to overcome the de-baunce problem

            if (!GPIO_GetPinValue(PORTF, PF4) && !GPIO_GetPinValue(PORTF, PF0))
            {
                GPIO_SetPinValue(PORTF, PF1, HIGH); // Turn on Red LED
                GPIO_SetPinValue(PORTF, PF2, LOW); // Turn off Blue LED
                GPIO_SetPinValue(PORTF, PF3, LOW); // Turn off Green LED

                _delay_ms(100); // 100 ms delay to make the LEDs light visible
            }
        }

        else if (!GPIO_GetPinValue(PORTF, PF0)) // If Switch 2 is pressed
        {
            _delay_ms(30); // 30 ms delay to overcome the de-baunce problem

            if (!GPIO_GetPinValue(PORTF, PF0))
            {
                GPIO_SetPinValue(PORTF, PF1, LOW); // Turn off Red LED
                GPIO_SetPinValue(PORTF, PF2, HIGH); // Turn on Blue LED
                GPIO_SetPinValue(PORTF, PF3, LOW); // Turn off Green LED

                _delay_ms(100); // 100 ms delay to make the LEDs light visible
            }
        }

        else if (!GPIO_GetPinValue(PORTF, PF4)) // If Switch 1 is pressed
        {
            _delay_ms(30); // 30 ms delay to overcome the de-baunce problem

            if (!GPIO_GetPinValue(PORTF, PF4))
            {
                GPIO_SetPinValue(PORTF, PF1, LOW); // Turn off Red LED
                GPIO_SetPinValue(PORTF, PF2, LOW); // Turn off Blue LED
                GPIO_SetPinValue(PORTF, PF3, HIGH); // Turn on Green LED

                _delay_ms(100); // 100 ms delay to make the LEDs light visible
            }
        }
    }
}

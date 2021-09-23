/*
 * vtasks.c
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */
#define FOREVER 1
#define NULL (void*)0
#include "vtasks.h"
#include "new_types.h"
#include "flags.h"

/* FreeRTOS APIs */
#include "rtoslib/FreeRTOS.h"
#include "rtoslib/task.h"

extern TaskHandle_t action_handler;
char response;

extern void test(void);

void comm_task(void* pvParameters)
{
    while(FOREVER)
    {
        do{
            if(FAIL_RESPONSE == 0)
                send_str("Please, Enter R, B, or G character:\n\r");
            else
                send_str("Error! Please, Enter R, B, or G character:\n\r");

            response = receive_char();


            FAIL_RESPONSE = 1;
        } while((response != 'R') && (response != 'r')\
                && (response != 'B') && (response != 'b')\
                && (response != 'G') && (response != 'g'));

        FAIL_RESPONSE = 0;
        vTaskDelay(100);
    }
}


void action_task(void* pvParameters)
{
    while (FOREVER)
    {
        switch (response)
        {
        case 'r':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
            break;
        case 'R':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
            break;
        case 'b':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x04);
            break;
        case 'B':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x04);
            break;
        case 'g':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x08);
            break;
        case 'G':
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x08);
            break;
        }
    }
}

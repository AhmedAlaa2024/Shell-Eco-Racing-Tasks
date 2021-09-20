/*
 * vtasks.c
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */
#include "vtasks.h"
#include "new_types.h"
#include "flags.h"

/* FreeRTOS APIs */
#include "rtoslib/FreeRTOS.h"
#include "rtoslib/task.h"

extern TaskHandle_t action_handler1;
extern TaskHandle_t action_handler2;
extern TaskHandle_t action_handler3;

extern void test(void);

void comm_task(void* pvParameters)
{
    char response;
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

    if ((response == 'r') || (response == 'R'))
    {
        vTaskResume(action_handler1);
        vTaskSuspend(action_handler2);
        vTaskSuspend(action_handler3);
    } else if ((response == 'b') || (response == 'B'))
    {
        vTaskSuspend(action_handler1);
        vTaskResume(action_handler2);
        vTaskSuspend(action_handler3);
    } else if ((response == 'b') || (response == 'B'))
    {
        vTaskSuspend(action_handler1);
        vTaskSuspend(action_handler2);
        vTaskResume(action_handler3);
    }
}


void action_task1(void* pvParameters)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
}


void action_task2(void* pvParameters)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x0);
}


void action_task3(void* pvParameters)
{
   GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x08);
}


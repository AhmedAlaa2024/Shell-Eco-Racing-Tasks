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

void comm_task1(void* pvParameters)
{
    send_str((char*)pvParameters);
}


void comm_task2(void* pvParameters)
{
    char** local_response = &(((COMM_BACKAGE*)pvParameters)->response);
    do{
        if(FAIL_RESPONSE == 1)
            send_str(((COMM_BACKAGE*)pvParameters)->message);
        **local_response = receive_char();
        FAIL_RESPONSE = 1;
    } while((**local_response != 'R') && (**local_response != 'r')\
            && (**local_response != 'B') && (**local_response != 'b')\
            && (**local_response != 'G') && (**local_response != 'g'));

    FAIL_RESPONSE = 0;
    if ((**local_response == 'r') || (**local_response == 'R'))
    {
        vTaskResume(action_handler1);
        vTaskSuspend(action_handler2);
        vTaskSuspend(action_handler3);
    } else if ((**local_response == 'b') || (**local_response == 'B'))
    {
        vTaskSuspend(action_handler1);
        vTaskResume(action_handler2);
        vTaskSuspend(action_handler3);
    } else if ((**local_response == 'b') || (**local_response == 'B'))
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
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x04);
}


void action_task3(void* pvParameters)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x08);
}


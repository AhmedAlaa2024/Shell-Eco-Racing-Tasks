/*
 * vtasks.c
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */
#include "vtasks.h"
#include "new_types.h"
#include "flags.h"

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
    } while((**local_response != 'R') && (**local_response != 'r')\
            && (**local_response != 'B') && (**local_response != 'b')\
            && (**local_response != 'G') && (**local_response != 'g'));

    FAIL_RESPONSE = 0;
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


/*
 * vtasks.c
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */
#define FOREVER 1
#define NULL (void*)0
#include "vtasks.h"
#include "Types.h"

/* FreeRTOS APIs */
#include "FreeRTOS.h"
#include "task.h"
#include "shared_resources.h"



void vTask1_Comm(void* pvParameter)
{
    xQueue1_colors = xQueueCreate(2, sizeof(uint8_t));
    xQueue2_colors_names = xQueueCreate(2, sizeof(char*));

    uint8_t i = 0, led_color = RED, flag_low = 1; // Working on falling edge
    char* current_color = "RED";
    volatile uint32_t data;
    while(1)
    {
        data = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);

        if ((data == 0) && (flag_low == 1))
        {
            led_color = colors[i];
            current_color = color_names[i];
            ++i;

            xQueueSend(xQueue1_colors, (void*)&led_color, (TickType_t)1000);
            xQueueSend(xQueue2_colors_names, (void*)&current_color, (TickType_t)1000);

            i = i % 7;
        }
        flag_low = data;
        vTaskDelay(100);
    }
}


void vTask2_action(void* pvParameter)
{
    uint8_t led_color = RED;
    char* current_color = "RED";
    while(1)
    {
        xQueueReceive(xQueue1_colors, &(led_color), (TickType_t)0);
        if (xQueueReceive(xQueue2_colors_names, &(current_color), (TickType_t)0))
        {
            send_str(current_color);
            send_newline();
        }
        GPIOPinWrite(GPIO_PORTF_BASE, led_color, led_color);
        vTaskDelay(50);
        GPIOPinWrite(GPIO_PORTF_BASE, led_color, 0x00);
        vTaskDelay(50);
    }
}

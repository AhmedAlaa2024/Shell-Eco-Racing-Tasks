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


void Add_Hydrogen(void* pvParameter)
{
    uint8_t flag_low = 1;
    uint32_t data;
    Hydrogen = 0;
    while (FOREVER)
    {
        xSemaphoreTake(Mutex1, (TickType_t)1000);
        data = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
        if ((data == 0) && (flag_low == 1))
        {
            Hydrogen++;

            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x02);

            send_str("Hydrogen: ");
            send_int(Hydrogen);
            send_newline();
        }
        xSemaphoreGive(Mutex1);
        vTaskDelay(1000);
    }
}


void Add_Oxygen(void* pvParameter)
{
    uint8_t flag_low = 1;
    uint32_t data;
    Oxygen = 0;
    while (FOREVER)
    {
        xSemaphoreTake(Mutex1, (TickType_t)1000);
        data = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);
        if ((data == 0) && (flag_low == 1))
        {
                Oxygen++;

                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x04);

                send_str("Oxygen: ");
                send_int(Oxygen);
                send_newline();
        }
        xSemaphoreGive(Mutex1);
        vTaskDelay(1000);
    }
}


void Create_Water(void *pvParameters)
{
    Mutex1 = xSemaphoreCreateMutex();
    uint8_t flag_low = 1;
    uint32_t data;
    Water = 0;
    while (FOREVER)
    {
        xSemaphoreTake(Mutex1, (TickType_t)1000);
        data = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
        if ((data == 0) && (flag_low == 0x11))
        {
            if ((Hydrogen >= 2) && (Oxygen >= 1))
            {
                Hydrogen -= 2;
                Oxygen--;
                Water++;

                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x08);

                send_str("Water: ");
                send_int(Water);
                send_newline();
            }
            else
            {
                send_str("Error: There are not enough Hydrogen or Oxygen.");
                send_newline();

                send_str("Water: ");
                send_int(Water);
                send_newline();
            }
        }
        xSemaphoreGive(Mutex1);
        vTaskDelay(1000);
    }
}

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
#include "stdint.h"
#include "Types.h"

/* FreeRTOS APIs */
#include "FreeRTOS.h"
#include "task.h"


extern uint8_t speed;
extern uint8_t data;

void statistics_task(void* pvParameters)
{
    send_str("statistics_task is running");

    // GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
    TaskHandle_t state1 = ((Handles *)pvParameters)->handle1;
    TaskHandle_t state2 = ((Handles *)pvParameters)->handle2;

    TaskStatus_t status1, status2, *pxTaskStatusArray;

    volatile UBaseType_t number_of_tasks, i;
    uint32_t ulTotalRunTime;

    number_of_tasks = uxTaskGetNumberOfTasks();
    pxTaskStatusArray = pvPortMalloc(number_of_tasks * sizeof(TaskStatus_t));

    uxTaskGetSystemState(pxTaskStatusArray, number_of_tasks, &ulTotalRunTime);

    send_str("Number of Tasks = ");
    send_int(number_of_tasks);
    make_newline();

    send_str("#######################################################################################");
    make_newline();

    for(i = 0; i < number_of_tasks; i++)
    {
        send_str("Task ");
        send_int(i);
        send_str(": ");

        send_str((char*)(pxTaskStatusArray[i].pcTaskName));

        make_newline();
    }

    send_str("#######################################################################################");
    make_newline();

    while(1)
    {
        vTaskGetInfo(state1, &status1, pdTRUE, eInvalid);
        vTaskGetInfo(state2, &status2, pdTRUE, eInvalid);

        send_str("Task Name: ");
        send_str((char*)(status1.pcTaskName));
        make_newline();

        send_str("Current State: ");
        if (status1.eCurrentState == eRunning)
            send_str("Running");
        else if (status1.eCurrentState == eReady)
            send_str("Ready");
        else
            send_str("Blocked");
        make_newline();
        make_newline();

        send_str("Task Name: ");
        send_str((char*)(status2.pcTaskName));
        make_newline();

        send_str("Current State: ");
        if (status2.eCurrentState == eRunning)
            send_str("Running");
        else if (status2.eCurrentState == eReady)
            send_str("Ready");
        else
            send_str("Blocked");
        make_newline();
        make_newline();

        send_str("------------------------------");
        make_newline();

        vTaskDelay(1000);
    }
}


void Button_task(void* pvParameters) // Active Low Configurations
{
    // GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
    send_str("Button_task is running");
    uint8_t flag_low = 1;
    while(1)
    {
        data = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
        if((data == 0) && (flag_low == 1)) // Detect Falling edge, the button is pressed!
        {
            speed += 2;
            speed = (speed > 10)? 1 : speed;
        }
        flag_low = data;
        vTaskDelay(25); // The button_task has higher priority than led_task, so I need to delay the button_task to give opportunity for led_task to run
    }
}


void Led_task(void* pvParameters)
{
    // GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
    send_str("Led_task is running");
    uint8_t state = 0;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    while(1)
    {
        vTaskDelayUntil(&xLastWakeTime, 100*speed);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, state);
        state ^= 0xFF;
    }
}

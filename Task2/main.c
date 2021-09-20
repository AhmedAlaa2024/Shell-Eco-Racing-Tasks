

/**
 * main.c
 */
#define FOREVER 1
#define NULL (void*)0

/* C Standared Libraries */
#include <stdbool.h>
#include <stdint.h>

/* FreeRTOS APIs */
#include "rtoslib/FreeRTOS.h"
#include "rtoslib/task.h"

/* User Defined Functions */
#include "GPIO.h"
#include "UART.h"
#include "vtasks.h"
#include "new_types.h"

/* Directive Definitions */
#define COMM_STACK 200
#define ACTION_STACK 200

/* Global Variables */
// char** request_messages = {"Please, Enter R, B, or G character:\n\r", "Error! Please, Enter R, B, or G character:\n\r"};

/* FreeRTOS Handlers */
TaskHandle_t comm_handler;
TaskHandle_t action_handler1, action_handler2, action_handler3;

/* Function used to test if some code is running */
void test(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
    SysCtlDelay(16000000u / 3u);
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x00);
    SysCtlDelay(16000000u / 3u);
}

int main(void)
{
    /* Setup Configurations */
    PLL_Set80();
    UART0_INIT();
    GPIOF_INIT();

    /* RTOS Configurations */

    xTaskCreate(comm_task, "UART0-COM3", COMM_STACK, NULL, 2, &comm_handler);

    xTaskCreate(action_task1, "RED_LED_TURN_ON", ACTION_STACK, NULL, 1, &action_handler1);
    xTaskCreate(action_task2, "BLUE_LED_TURN_ON", ACTION_STACK, NULL, 1, &action_handler2);
    xTaskCreate(action_task3, "GREEN_LED_TURN_ON", ACTION_STACK, NULL, 1, &action_handler3);

    vTaskStartScheduler();
    /* Super Loop */
    while(FOREVER);
}

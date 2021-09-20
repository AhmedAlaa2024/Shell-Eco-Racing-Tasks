

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
#define FIRST_STACK 50
#define SECOND_STACK 50

/* Global Variables */
extern char response;
COMM_BACKAGE comm_task1_backage = {"Please, Enter R, B, or G character:\n\r"};
COMM_BACKAGE comm_task2_backage = {"Error! Please, Enter R, B, or G character:\n\r"};

/* FreeRTOS Handlers */
TaskHandle_t comm_handler1, comm_handler2;
TaskHandle_t action_handler1, action_handler2, action_handler3;

/* Function used to test if some code is running */
/*
void test(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
    SysCtlDelay(16000000u / 3u);
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x00);
    SysCtlDelay(16000000u / 3u);
}
*/

int main(void)
{
    /* Setup Configurations */
    UART0_INIT();
    GPIOF_INIT();

    /* RTOS Configurations */

    xTaskCreate(comm_task1, "UART0-COM3_Transmitting", FIRST_STACK, (void*)&comm_task1_backage, 2, &comm_handler1);
    xTaskCreate(comm_task2, "UART0-COM3_Receiving", FIRST_STACK, (void*)&comm_task2_backage, 2, &comm_handler2);

    xTaskCreate(action_task1, "RED_LED_TURN_ON", SECOND_STACK, NULL, 1, &action_handler1);
    xTaskCreate(action_task2, "BLUE_LED_TURN_ON", SECOND_STACK, NULL, 1, &action_handler2);
    xTaskCreate(action_task3, "GREEN_LED_TURN_ON", SECOND_STACK, NULL, 1, &action_handler3);

    vTaskStartScheduler();
    /* Super Loop */
    while(FOREVER);
}

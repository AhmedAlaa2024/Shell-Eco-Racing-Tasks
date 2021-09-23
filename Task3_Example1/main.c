#include "FreeRTOS.h"
#include "task.h"
#include "stdint.h"
#include "UART.h"
#include "GPIO.h"
#include "vtasks.h"
#include "Types.h"

#define STACK_SIZE 200

Handles handles;

uint8_t speed = 1;
volatile uint8_t data = 0;

int main(void)
{
    /* Configurations */
    UART0_INIT();
    GPIOF_INIT();

    // Set PF1 as Output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    // Set PF0 as Input
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);

    TaskHandle_t handler1, handler2, handler3;
    xTaskCreate(Led_task, "LED", STACK_SIZE, NULL, 1, &handler1);
    xTaskCreate(Button_task, "BUTTON", STACK_SIZE, NULL, 2, &handler2);
    handles.handle1 = handler1;
    handles.handle2 = handler2;
    xTaskCreate(statistics_task, "STATISTICS", STACK_SIZE, (void*)(&handles), 3, &handler3);

    vTaskStartScheduler();
    return 0;
}




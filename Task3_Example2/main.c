#include "FreeRTOS.h"
#include "task.h"
#include "stdint.h"
#include "GPIO.h"
#include "UART.h"
#include "vtasks.h"
#include "Types.h"

#define STACK_SIZE 128

int main(void)
{
    /* Configurations */
    UART0_INIT();
    GPIOF_INIT();

    // Set PF1 as Output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, 0xFE);
    // Set PF0 as Input
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);

    TaskHandle_t handler1, handler2;
    xTaskCreate(vTask2_action, "ACTION", STACK_SIZE, NULL, 1, &handler1);
    xTaskCreate(vTask1_Comm, "COMMUNICATION", STACK_SIZE, NULL, 2, &handler2);

    vTaskStartScheduler();
}

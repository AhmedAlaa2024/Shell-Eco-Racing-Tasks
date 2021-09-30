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
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    // Set PF0 as Input
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);

    TaskHandle_t handler1, handler2, handler3;
    xTaskCreate(Add_Hydrogen, "Hydrogen", STACK_SIZE, NULL, 1, &handler1);
    xTaskCreate(Add_Oxygen, "Oxygen", STACK_SIZE, NULL, 1, &handler2);
    xTaskCreate(Create_Water, "Water", STACK_SIZE, NULL, 2, &handler3);

    vTaskStartScheduler();
}

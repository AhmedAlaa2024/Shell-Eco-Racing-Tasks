

/**
 * main.c
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"


void test(void)
{
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
    SysCtlDelay(16000000u / 3u);
    GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x00);
    SysCtlDelay(16000000u / 3u);
}

void UART0_INIT(void);
void send_str(char str[]);
char receive_char(void);

extern void UART0_Handler(void);

void GPIOF_INIT(void);

uint8_t received_flag = 0;
uint8_t request_flag = 0;

char request[] = "Please, Enter R, B, or G character:\n\r";
char request_error_handling[] = "Error 404: Not Found!\nPlease, Enter R, B, or G character only:\n";

char response = 0;

int main(void)
{
    /* Setup Configurations */
    UART0_INIT();
    GPIOF_INIT();

    /* Super Loop */
    while(1)
    {
        do{
            send_str(request);
            response = receive_char();
           } while((response != 'R') && (response != 'r') && (response != 'B') && (response != 'b') && (response != 'G') && (response != 'g'));

        if ((response == 'R') || (response == 'r'))
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x02);
        else if ((response == 'B') || (response == 'b'))
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x04);
        else if ((response == 'g') || (response == 'b'))
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x08);
        else
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3) , 0x00);
    }
}

void UART0_INIT(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable UART0 module
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Wait for UART0 module to be ready
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));

    UARTEnable(UART0_BASE);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    /*
     * Initialize the UART:
     * 1. Pass the base address
     * 2. Pass the source clock to feed the UART0 Module
     * 3. Set the baud rate = 9600
     * 4. Number of data bits = sizeof(char) = 1 byte = 8 bits
     * 5. Turn off the parity bit
     * 6. Set the number of the stop bits
     * 7. Set the stick mode
     */
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    UARTIntEnable(UART0_BASE, UART_INT_RX);
    // Enable the interrupt for UART 0.
    IntEnable(INT_UART0);

    // Register the interrupt handler function for UART 0.
    UARTIntRegister(UART0_BASE, UART0_Handler);
}


void UART0_Handler(void)
{
    UARTIntClear(UART0_BASE, UART_INT_RX);
    response = receive_char();
    test();
    if ((response != 'R') && (response != 'r') && (response != 'B') && (response != 'b') && (response != 'G') && (response != 'g'))
        send_str(request_error_handling);
    else
        send_str(request);
}


void send_str(char str[])
{
    int i = 0;
    for(i = 0; str[i] != '\0'; i++)
        UARTCharPut(UART0_BASE, str[i]);
}
char receive_char(void)
{
    char response;
    // Polling until the character is available
    response = UARTCharGet(UART0_BASE);

    // Send the entered Character
    UARTCharPut(UART0_BASE, response);

    // Send Carriage Return Character
    UARTCharPut(UART0_BASE, '\n');

    // Send Line Feed Character
    UARTCharPut(UART0_BASE, '\r');

    return response;
}


void GPIOF_INIT(void)
{
    // Enable the GPIOF Peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Wait for GPIOF module to be ready
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    // Set PF1, PF2, PF3 as Output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
}

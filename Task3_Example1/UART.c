/*
 * init.h
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */

#include "UART.h"
#include "GPIO.h"

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
}


void send_str(char str[])
{
    int i = 0;
    for(i = 0; str[i] != '\0'; i++)
        UARTCharPut(UART0_BASE, str[i]);
}


void send_int(uint8_t number)
{
    UARTCharPut(UART0_BASE, (char)number);
}


void make_newline(void)
{
    // Send Carriage Return Character
    UARTCharPut(UART0_BASE, '\n');

    // Send Line Feed Character
    UARTCharPut(UART0_BASE, '\r');
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

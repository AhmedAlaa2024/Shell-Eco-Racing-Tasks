/*
 * GPIO.c
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */

#include "GPIO.h"

void GPIOF_INIT(void)
{
    // Enable the GPIOF Peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Wait for GPIOF module to be ready
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
}

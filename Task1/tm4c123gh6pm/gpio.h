/*
 * gpio.h
 *
 *  Created on: Sep 12, 2021
 *      Author: AhmedAlaa
 */

#ifndef TM4C123GH6PM_GPIO_H_
#define TM4C123GH6PM_GPIO_H_


// IO Pins
void GPIO_SetPinDirection (uint8 PORTX, uint8 PINX, uint8 DIR);
void GPIO_SetPinValue (uint8 PORTX, uint8 PINX, uint8 VAL);
uint8 GPIO_GetPinValue (uint8 PORTX, uint8 PINX);
void activate_pull_up (uint8 PORTX, uint8 PINX);

// IO Ports
void Enable_Port(uint8 PORTX);
void Disable_Port(uint8 PORTX);
void GPIO_SetPortDirection (uint8 PORTX, uint8 DIR);
void GPIO_SetPortValue (uint8 PORTX, uint8 VAL);


#endif /* TM4C123GH6PM_GPIO_H_ */

/*
 * vtasks.h
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */

#ifndef VTASKS_H_
#define VTASKS_H_

#include "UART.h"
#include "GPIO.h"

/* C Standared Libraries */
#include <stdbool.h>
#include <stdint.h>

/* User Defined Functions */
void Add_Hydrogen(void* pvParameter);
void Add_Oxygen(void* pvParameter);
void Create_Water(void* pvParameter);

#endif /* VTASKS_H_ */

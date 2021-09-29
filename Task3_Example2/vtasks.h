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
void vTask1_Comm(void* pvParameter);
void vTask2_action(void* pvParameter);

#endif /* VTASKS_H_ */

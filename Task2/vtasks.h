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

extern uint8_t FAIL_RESPONSE;

void comm_task1(void* pvParameters);
void comm_task2(void* pvParameters);
void action_task1(void* pvParameters);
void action_task2(void* pvParameters);
void action_task3(void* pvParameters);


#endif /* VTASKS_H_ */

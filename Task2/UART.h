/*
 * init.h
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

/* C Standared Libraries */
#include <stdbool.h>
#include <stdint.h>

/* TivaWare APIs */
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"

void UART0_INIT(void);
void send_str(char str[]);
char receive_char(void);

extern void UART0_Handler(void);

#endif /* UART_H_ */

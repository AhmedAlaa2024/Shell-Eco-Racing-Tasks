/*
 * GPIO.h
 *
 *  Created on: Sep 20, 2021
 *      Author: ahmed
 */

#ifndef GPIO_H_
#define GPIO_H_

/* C Standared Libraries */
#include <stdbool.h>
#include <stdint.h>

/* TivaWare APIs */
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

void GPIOF_INIT(void);

#endif /* GPIO_H_ */

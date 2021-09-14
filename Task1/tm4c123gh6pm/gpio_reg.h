/*
 * gpio_reg.h
 *
 *  Created on: Sep 12, 2021
 *      Author: AhmedAlaa
 */

#ifndef TM4C123GH6PM_GPIO_REG_H_
#define TM4C123GH6PM_GPIO_REG_H_

#include "stdtypes.h"

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/*
  Register Map from Data Sheet

  GPIO Port A (APB): 0x4000.4000
  GPIO Port A (AHB): 0x4005.8000
  GPIO Port B (APB): 0x4000.5000
  GPIO Port B (AHB): 0x4005.9000
  GPIO Port C (APB): 0x4000.6000
  GPIO Port C (AHB): 0x4005.A000
  GPIO Port D (APB): 0x4000.7000
  GPIO Port D (AHB): 0x4005.B000
  GPIO Port E (APB): 0x4002.4000
  GPIO Port E (AHB): 0x4005.C000
  GPIO Port F (APB): 0x4002.5000
  GPIO Port F (AHB): 0x4005.D000
*/

/* General Registers */
#define RCGCGPIO *((volatile uint32*)0x400FE608)

/* Registers Abbreviations
 *
 * GPIO      = General Purpose Input Output -> Get or Set data form or to pins
 * GPIODIR   = GPIO Direction -> Determine the direction of the port's pins
 * GPIOLOCK  = GPIO Lock -> Enables write access to the GPIOCR register
 * GPIOCR    = GPIO Commit -> Enable some locked registers
 * GPIOAFSEL = GPIO Alternative Functions Select -> Select the alternative functions of the GPIO like UART
 * GPIOPCTL  = GPIO Port Control -> Determine the GPIO Alternative Function Mode
 * GPIOAMSEL = GPIO Analog Mode Select -> Select the analog mode of GPIO
 * GPIOPUR   = GPIO Pull Up Resistance -> Activate the Pull up resistance mode
 * GPIODEN   = GPIO Digital Enable -> Enable the digital signal to pass
 *
 */

/* PORT A (APB) */
#define PORTA 0
#define GPIOA_DATA *((volatile uint32*)0x40004000)
#define GPIOA_DIR *((volatile uint32*)0x40004400)
#define GPIOA_LOCK *((volatile uint32*)0x40004520)
#define GPIOA_CR *((volatile uint32*)0x40004524)
#define GPIOA_AFSEL *((volatile uint32*)0x40004420) // GPIOAFSEL = GPIO Alternative Functions Select
#define GPIOA_PCTL *((volatile uint32*)0x4000452C)
#define GPIOA_AMSEL *((volatile uint32*)0x40004528)
#define GPIOA_PUR *((volatile uint32*)0x40004510)
#define GPIOA_DEN *((volatile uint32*)0x4000451C)

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

/* PORT B (APB) */
#define PORTB 1
#define GPIOB_DATA *((volatile uint32*)0x40005000)
#define GPIOB_DIR *((volatile uint32*)0x40005400)
#define GPIOB_LOCK *((volatile uint32*)0x40005520)
#define GPIOB_CR *((volatile uint32*)0x40005524)
#define GPIOB_AFSEL *((volatile uint32*)0x40005420)
#define GPIOB_PCTL *((volatile uint32*)0x4000552C)
#define GPIOB_AMSEL *((volatile uint32*)0x40005528)
#define GPIOB_PUR *((volatile uint32*)0x40005510)
#define GPIOB_DEN *((volatile uint32*)0x4000551C)

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

/* PORT C (APB) */
#define PORTC 2
#define GPIOC_DATA *((volatile uint32*)0x40006000)
#define GPIOC_DIR *((volatile uint32*)0x40006400)
#define GPIOC_LOCK *((volatile uint32*)0x40006520)
#define GPIOC_CR *((volatile uint32*)0x40006524)
#define GPIOC_AFSEL *((volatile uint32*)0x40006420)
#define GPIOC_PCTL *((volatile uint32*)0x4000652C)
#define GPIOC_AMSEL *((volatile uint32*)0x40006528)
#define GPIOC_PUR *((volatile uint32*)0x40006510)
#define GPIOC_DEN *((volatile uint32*)0x4000651C)

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

/* PORT D (APB) */
#define PORTD 3
#define GPIOD_DATA *((volatile uint32*)0x40007000)
#define GPIOD_DIR *((volatile uint32*)0x40007400)
#define GPIOD_LOCK *((volatile uint32*)0x40007520)
#define GPIOD_CR *((volatile uint32*)0x40007524)
#define GPIOD_AFSEL *((volatile uint32*)0x40007420)
#define GPIOD_PCTL *((volatile uint32*)0x4000752C)
#define GPIOD_AMSEL *((volatile uint32*)0x40007528)
#define GPIOD_PUR *((volatile uint32*)0x40007510)
#define GPIOD_DEN *((volatile uint32*)0x4000751C)

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

/* PORT E (APB) */
#define PORTE 4
#define GPIOE_DATA *((volatile uint32*)0x40024000)
#define GPIOE_DIR *((volatile uint32*)0x40024400)
#define GPIOE_LOCK *((volatile uint32*)0x40024520)
#define GPIOE_CR *((volatile uint32*)0x40024524)
#define GPIOE_AFSEL *((volatile uint32*)0x40024420)
#define GPIOE_PCTL *((volatile uint32*)0x4002452C)
#define GPIOE_AMSEL *((volatile uint32*)0x40024528)
#define GPIOE_PUR *((volatile uint32*)0x40024510)
#define GPIOE_DEN *((volatile uint32*)0x4002451C)

#define PE0 0
#define PE1 1
#define PE2 2
#define PE3 3
#define PE4 4
#define PE5 5

/* PORT F (APB) */
#define PORTF 5
#define GPIOF_DATA *((volatile uint32*)0x400253FC)
#define GPIOF_DIR *((volatile uint32*)0x40025400)
#define GPIOF_LOCK *((volatile uint32*)0x40025520)
#define GPIOF_CR *((volatile uint32*)0x40025524)
#define GPIOF_AFSEL *((volatile uint32*)0x40025420)
#define GPIOF_PCTL *((volatile uint32*)0x4002552C)
#define GPIOF_AMSEL *((volatile uint32*)0x40025528)
#define GPIOF_PUR *((volatile uint32*)0x40025510)
#define GPIOF_DEN *((volatile uint32*)0x4002551C)

#define PF0 0
#define PF1 1
#define PF2 2
#define PF3 3
#define PF4 4


#endif /* TM4C123GH6PM_GPIO_REG_H_ */

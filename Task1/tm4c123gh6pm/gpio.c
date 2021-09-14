/*
 * gpioinit.h
 *
 *  Created on: Sep 7, 2021
 *  Author: AhmedAlaa
 *  Description: This file contains all GPIO functions definitions
 */

#include "bitmath.h"
#include "stdtypes.h"
#include "gpio_reg.h"
#include "gpio.h"

// IO Pins
void GPIO_SetPinDirection (uint8 PORTX, uint8 PINX, uint8 DIR)
{
    Enable_Port(PORTX);
    if (DIR == OUTPUT)
    {
        switch (PORTX)
        {
            case PORTA: SET_BIT(GPIOA_DIR, PINX); break;
            case PORTB: SET_BIT(GPIOB_DIR, PINX); break;
            case PORTC: SET_BIT(GPIOC_DIR, PINX); break;
            case PORTD: SET_BIT(GPIOD_DIR, PINX); break;
            case PORTE: SET_BIT(GPIOE_DIR, PINX); break;
            case PORTF: SET_BIT(GPIOF_DIR, PINX); break;
        }
    }

    else if (DIR == INPUT)
    {
        switch (PORTX)
        {
            case PORTA: CLR_BIT(GPIOA_DIR, PINX); break;
            case PORTB: CLR_BIT(GPIOB_DIR, PINX); break;
            case PORTC: CLR_BIT(GPIOC_DIR, PINX); break;
            case PORTD: CLR_BIT(GPIOD_DIR, PINX); break;
            case PORTE: CLR_BIT(GPIOE_DIR, PINX); break;
            case PORTF: CLR_BIT(GPIOF_DIR, PINX); break;
        }
    }
}


void GPIO_SetPinValue (uint8 PORTX, uint8 PINX, uint8 VAL)
{
    if (VAL == HIGH)
     {
         switch (PORTX)
         {
             case PORTA: SET_BIT(GPIOA_DATA, PINX); break;
             case PORTB: SET_BIT(GPIOB_DATA, PINX); break;
             case PORTC: SET_BIT(GPIOC_DATA, PINX); break;
             case PORTD: SET_BIT(GPIOD_DATA, PINX); break;
             case PORTE: SET_BIT(GPIOE_DATA, PINX); break;
             case PORTF: SET_BIT(GPIOF_DATA, PINX); break;
         }
     }

     else if (VAL == LOW)
     {
         switch (PORTX)
         {
             case PORTA: CLR_BIT(GPIOA_DATA, PINX); break;
             case PORTB: CLR_BIT(GPIOB_DATA, PINX); break;
             case PORTC: CLR_BIT(GPIOC_DATA, PINX); break;
             case PORTD: CLR_BIT(GPIOD_DATA, PINX); break;
             case PORTE: CLR_BIT(GPIOE_DATA, PINX); break;
             case PORTF: CLR_BIT(GPIOF_DATA, PINX); break;
         }
     }
}


uint8 GPIO_GetPinValue (uint8 PORTX, uint8 PINX)
{
    uint8 VAL;

    switch (PORTX)
    {
        case PORTA: VAL= GET_BIT(GPIOA_DATA, PINX); break;
        case PORTB: VAL= GET_BIT(GPIOB_DATA, PINX); break;
        case PORTC: VAL= GET_BIT(GPIOC_DATA, PINX); break;
        case PORTD: VAL= GET_BIT(GPIOD_DATA, PINX); break;
        case PORTE: VAL= GET_BIT(GPIOE_DATA, PINX); break;
        case PORTF: VAL= GET_BIT(GPIOF_DATA, PINX); break;
        default: VAL = 0xFF; break; // Indication that there is an error in data
    }

    return VAL;
}


void activate_pull_up (uint8 PORTX, uint8 PINX)
{
    switch (PORTX)
    {
    case PORTA: SET_BIT(GPIOA_PUR, PINX); break;
    case PORTB: SET_BIT(GPIOB_PUR, PINX); break;
    case PORTC: SET_BIT(GPIOC_PUR, PINX); break;
    case PORTD: SET_BIT(GPIOD_PUR, PINX); break;
    case PORTE: SET_BIT(GPIOE_PUR, PINX); break;
    case PORTF: SET_BIT(GPIOF_PUR, PINX); break;
    }
}


// IO Ports
void Enable_Port(uint8 PORTX)
{
    switch(PORTX)
    {
        case PORTA:
            SET_BIT(RCGCGPIO, PORTA);
            GPIOA_LOCK = 0x40025000; // To unlock GPIOA_CR register
            GPIOA_CR |= 0x0000001F; // Allow change of some needed registers for Port A
            GPIOA_AFSEL = 0x00000000; // Select the function as Digital GPIO
            GPIOA_PCTL = 0x00000000; // Select the function as GPIO
            GPIOA_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOA_DEN = 0x000000FF; // Enable the digital signal to pass
            break;
        case PORTB:
            SET_BIT(RCGCGPIO, PORTB);
            GPIOB_LOCK = 0x40025000; // To unlock GPIOB_CR register
            GPIOB_CR |= 0x0000001F; // Allow change of some needed registers for Port B
            GPIOB_AFSEL = 0x00000000; // Select the function as Digital GPIO
            GPIOB_PCTL = 0x00000000; // Select the function as GPIO
            GPIOB_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOB_DEN = 0x000000FF; // Enable the digital signal to pass
            break;
        case PORTC:
            SET_BIT(RCGCGPIO, PORTC);
            GPIOC_LOCK = 0x40025000; // To unlock GPIOC_CR register
            GPIOC_CR |= 0x0000001F; // Allow change of some needed registers for Port C
            GPIOC_AFSEL = 0x00000000; // Select the function as Digital GPIO
            GPIOC_PCTL = 0x00000000; // Select the function as GPIO
            GPIOC_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOC_DEN = 0x000000FF; // Enable the digital signal to pass
            break;
        case PORTD:
            SET_BIT(RCGCGPIO, PORTD);
            GPIOD_LOCK = 0x40025000; // To unlock GPIOD_CR register
            GPIOD_CR |= 0x0000001F; // Allow change of some needed registers for Port D
            GPIOD_AFSEL = 0x00000000; // Disable Alternative Functions
            GPIOD_PCTL = 0x00000000; // Select the function as Digital GPIO
            GPIOD_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOD_DEN = 0x000000FF; // Enable the digital signal to pass
            break;
        case PORTE:
            SET_BIT(RCGCGPIO, PORTE);
            GPIOE_LOCK = 0x40025000; // To unlock GPIOE_CR register
            GPIOE_CR |= 0x0000001F; // Allow change of some needed registers for Port E
            GPIOE_AFSEL = 0x00000000; // Disable Alternative Functions
            GPIOE_PCTL = 0x00000000; // Select the function as Digital GPIO
            GPIOE_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOE_DEN = 0x0000003F; // Enable the digital signal to pass
            break;
        case PORTF:
            SET_BIT(RCGCGPIO, PORTF);
            GPIOF_LOCK = 0x40025000; // To unlock GPIOF_CR register
            GPIOF_CR |= 0x0000001F; // Allow change of some needed registers for Port F
            GPIOF_AFSEL = 0x00000000; // Disable Alternative Functions
            GPIOF_PCTL = 0x00000000; // Select the function as Digital GPIO
            GPIOF_AMSEL = 0x00000000; // Disable the Analog mode of GPIO
            GPIOF_DEN = 0x0000001F; // Enable the digital signal to pass
            break;
    }

    uint8 delay = RCGCGPIO;
}


void Disable_Port(uint8 PORTX)
{
    switch(PORTX)
    {
    case PORTA:
        GPIOA_LOCK = 0x00000001; // To lock GPIOA_CR register
        CLR_BIT(RCGCGPIO, PORTA);
        break;
    case PORTB:
        GPIOB_LOCK = 0x00000001; // To lock GPIOB_CR register
        CLR_BIT(RCGCGPIO, PORTB);
        break;
    case PORTC:
        GPIOC_LOCK = 0x00000001; // To lock GPIOC_CR register
        CLR_BIT(RCGCGPIO, PORTC);
        break;
    case PORTD:
        GPIOD_LOCK = 0x00000001; // To lock GPIOD_CR register
        CLR_BIT(RCGCGPIO, PORTD);
        break;
    case PORTE:
        GPIOE_LOCK = 0x00000001; // To lock GPIOE_CR register
        CLR_BIT(RCGCGPIO, PORTE);
        break;
    case PORTF:
        GPIOF_LOCK = 0x00000001; // To lock GPIOF_CR register
        CLR_BIT(RCGCGPIO, PORTF);
        break;
    }

    uint8 delay = RCGCGPIO;
}


void GPIO_SetPortDirection (uint8 PORTX, uint8 DIR)
{
    switch(PORTX)
    {
        case PORTA: GPIOA_DIR = DIR; break;
        case PORTB: GPIOB_DIR = DIR; break;
        case PORTC: GPIOC_DIR = DIR; break;
        case PORTD: GPIOD_DIR = DIR; break;
        case PORTE: GPIOE_DIR = DIR; break;
        case PORTF: GPIOF_DIR = DIR; break;
    }
}


void GPIO_SetPortValue (uint8 PORTX, uint8 VAL)
{
    switch(PORTX)
    {
        case PORTA: GPIOA_DATA = VAL; break;
        case PORTB: GPIOB_DATA = VAL; break;
        case PORTC: GPIOC_DATA = VAL; break;
        case PORTD: GPIOD_DATA = VAL; break;
        case PORTE: GPIOE_DATA = VAL; break;
        case PORTF: GPIOF_DATA = VAL; break;
    }
}

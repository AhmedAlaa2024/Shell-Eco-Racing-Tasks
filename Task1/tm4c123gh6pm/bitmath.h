/*
 * bitmath.h
 *
 *  Created on: Sep 7, 2021
 *  Author: AhmedAlaa
 *  Description: This files contains the 4 main operations on registers
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(REG,BITNO) (REG) |=  (1 << (BITNO))
#define CLR_BIT(REG,BITNO) (REG) &= ~(1 << (BITNO))
#define TOG_BIT(REG,BITNO) (REG) ^=  (1 << (BITNO))
#define GET_BIT(REG,BITNO) (((REG) >> (BITNO)) & 0x01)


#endif /* BITMATH_H_ */

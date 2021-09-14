/*
 * util.h
 *
*  Created on: Sep 7, 2021
 *  Author: AhmedAlaa
 *  Description: This files contains some utilities
 */

#include "util.h"

void _delay_ms(uint32 time)
{
    uint32 periodic_time = (uint32)((1 / F_CPU) * 1000000000); // The time of one clock by nanosecond
    uint32 num_of_clocks = (uint32)(time * 1000000 / periodic_time);
    for(;num_of_clocks > 0; num_of_clocks--);
}



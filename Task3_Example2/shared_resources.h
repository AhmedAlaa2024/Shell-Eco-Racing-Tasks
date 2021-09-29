#ifndef SHARED_RESOURCES_H_
#define SHARED_RESOURCES_H_

#include "FreeRTOS.h"
#include "queue.h"

#define RED  0x02
#define BLUE 0x04
#define GREEN 0x08
#define YELLOW 0x0A
#define CYAN 0x0C
#define WHITE 0x0E
#define PINK 0x06


extern QueueHandle_t xQueue1_colors;
extern QueueHandle_t xQueue2_colors_names;
extern uint8_t colors[7];
extern char *color_names[7];


#endif /* SHARED_RESOURCES_H_ */

#include "shared_resources.h"
#include "stdint.h"

/* Global Queues */
QueueHandle_t xQueue1_colors;
QueueHandle_t xQueue2_colors_names;


/* Colors */
uint8_t colors[7] = {RED, BLUE, GREEN, YELLOW, CYAN, WHITE, PINK};
char *color_names[7] = {"RED", "BLUE", "GREEN", "YELLOW", "CYAN", "WHITE", "PINK"};

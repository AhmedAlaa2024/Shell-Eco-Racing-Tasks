#include "shared_resources.h"
#include "stdint.h"

/* Global Queues */
QueueHandle_t xQueue1_colors;
QueueHandle_t xQueue2_colors_names;


/* Global Semaphore */
SemaphoreHandle_t semaphore1;


/* Colors */
uint8_t colors[8] = {NONE, RED, BLUE, GREEN, YELLOW, CYAN, WHITE, PINK};
char *color_names[8] = {"NONE", "RED", "BLUE", "GREEN", "YELLOW", "CYAN", "WHITE", "PINK"};

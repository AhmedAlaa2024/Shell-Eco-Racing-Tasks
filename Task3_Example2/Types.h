#ifndef TYPES_H
#define TYPES_H

#include "FreeRTOS.h"
#include "task.h"

typedef unsigned char uint8;
typedef unsigned long int uint32;
typedef unsigned long int* puint32;
typedef long int int32;

typedef struct {
    TaskHandle_t handle1;
    TaskHandle_t handle2;
} Handles;

#endif

#ifndef SHARED_RESOURCES_H_
#define SHARED_RESOURCES_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"

extern uint32_t Oxygen, Hydrogen, Water;

extern SemaphoreHandle_t Mutex1;

#endif /* SHARED_RESOURCES_H_ */

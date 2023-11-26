/*
 * tasks.h
 *
 *  Created on: Nov 26, 2023
 *      Author: nikola
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "cmsis_os2.h"
#include "cmsis_os.h"
#include "semphr.h"
#include "stm32f4xx_hal.h"
#include "logging.h"
#include "temp_hum_click20.h"


#define LOGGING_QUEUE_SIZE     16


void tasksInit(void);
void TempHumMeasurements(void *argument);
void loggingHandle(void *argument);
void ProcessingButtons(void *argument);
osSemaphoreId_t getButtonSemaphore(void);


#endif /* INC_TASKS_H_ */

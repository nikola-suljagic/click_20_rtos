/*
 * tasks.c
 *
 *  Created on: Nov 26, 2023
 *      Author: nikola
 */

#include "tasks.h"


/* Definitions for Measurements */
osThreadId_t MeasurementsHandle;
const osThreadAttr_t Measurements_attributes = { .name = "Measurements",
		.stack_size = 512 * 4, .priority = (osPriority_t) osPriorityNormal, };
/* Definitions for Buttons */
osThreadId_t ButtonsHandle;
const osThreadAttr_t Buttons_attributes = { .name = "Buttons", .stack_size = 128
		* 4, .priority = (osPriority_t) osPriorityLow, };

osThreadId_t LoggingHandle;
const osThreadAttr_t Logging_attributes = { .name = "loggingHandle",
		.stack_size = 1024 * 4, .priority = (osPriority_t) osPriorityLow, };

osMessageQueueId_t loggingQueue;
const osMessageQueueAttr_t loggingQueue_attributes = { .name = "loggingQueue" };

/* Definitions for buttonSemaphore */
osSemaphoreId_t buttonSemaphoreHandle;
const osSemaphoreAttr_t buttonSemaphore_attributes =
		{ .name = "buttonSemaphore" };


osSemaphoreId_t getButtonSemaphore(void) {
	return buttonSemaphoreHandle;
}


void tasksInit(void) {
	MeasurementsHandle = osThreadNew(TempHumMeasurements, NULL,
			&Measurements_attributes);
	ButtonsHandle = osThreadNew(ProcessingButtons, NULL, &Buttons_attributes);
	LoggingHandle = osThreadNew(loggingHandle, NULL, &Logging_attributes);
	loggingQueue = osMessageQueueNew(LOGGING_QUEUE_SIZE, sizeof(Event_t),
			&loggingQueue_attributes);
	buttonSemaphoreHandle = osSemaphoreNew(10, 1, &buttonSemaphore_attributes);
}


/**
 * @brief  Function implementing the Measurements thread.
 * @param  argument: Not used
 * @retval None
 */
void TempHumMeasurements(void *argument) {
	static float temperature, humidity;
	/* Infinite loop */
	for (;;) {
		tempHumClick20GetMeasurements(&temperature, &humidity);
		logEvent(createEvent(TempMeasurements, &temperature));
		logEvent(createEvent(HumMeasurements, &humidity));
		osDelay(4000);
	}
}

/**
 * @brief Function implementing the loggingHandle thread.
 * @param argument: Not used
 * @retval None
 */
void loggingHandle(void *argument) {
	Event_t event;
	uint8_t prio = 1;
	/* Infinite loop */
	for (;;) {
		if (osMessageQueueGet(loggingQueue, &event, &prio, 100000) == osOK) {
			handleEvent(event);
		}
	}
}

/**
 * @brief Function implementing the Buttons thread.
 * @param argument: Not used
 * @retval None
 */
void ProcessingButtons(void *argument) {
	xSemaphoreTake(buttonSemaphoreHandle, 0xFFFF);
	for (;;) {
		xSemaphoreTakeRecursive(buttonSemaphoreHandle, portMAX_DELAY);
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) {
			int32_t value = 1;
			logEvent(createEvent(UserButton1Pressed, &value));
		}
	}
}

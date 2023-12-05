/*
 * logging.c
 *
 *  Created on: Nov 25, 2023
 *      Author: nikola
 */

#include "logging.h"
#include <stdio.h>

/* Definitions for myQueue01 */
extern osMessageQueueId_t loggingQueue;

void logEvent(Event_t event) {
	osMessageQueuePut(loggingQueue, &event, 1, 100);
}

Event_t createEvent(EventType_t type, void *value) {
	Event_t event;

	event.type = type;
	if ((type == HumMeasurements) || (type == TempMeasurements)) {
		event.value.floatVal = *((float*) value);
	} else {
		event.value.intVal = *((int32_t*) value);
	}

	return event;
}

void handleEvent(Event_t event) {
	if (event.type == TempMeasurements) {
		printf("{'name': 'Temperature', 'value': %f}\n\r", event.value.floatVal);
	} else if (event.type == HumMeasurements) {
		printf("{'name': 'Humidity', 'value': %f}\n\r", event.value.floatVal);
	} else if (event.type == UserButton1Pressed) {
		printf("{'name': 'Button1', 'value': %ld}\n\r", event.value.intVal);
	} else {
		printf("{'name': 'Button2', 'value': %ld}\n\r", event.value.intVal);
	}
}

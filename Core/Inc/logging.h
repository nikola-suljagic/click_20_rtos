/*
 * logging.h
 *
 *  Created on: Nov 25, 2023
 *      Author: nikola
 */

#ifndef INC_LOGGING_H_
#define INC_LOGGING_H_

#include "cmsis_os.h"


typedef union EventValue {
	float floatVal;
	int32_t intVal;
} EventValue_t;


typedef enum EventType {
	UserButton1Pressed,
	UserButton2Pressed,
	TempMeasurements,
	HumMeasurements
} EventType_t;


typedef struct Event {
	EventType_t type;
	EventValue_t value;
} Event_t;


osMessageQueueId_t getLoggingQueue(void);
void logEvent(Event_t event);
Event_t createMeasurementEvent(EventType_t type, void *value);
void handleEvent(Event_t event);

#endif /* INC_LOGGING_H_ */

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
	UserButton1Pressed, UserButton2Pressed, TempMeasurements, HumMeasurements
} EventType_t;

typedef struct Event {
	EventType_t type;
	EventValue_t value;
} Event_t;


/// Log specified event
/// \param[in]     event          event that will be logged via serial  line..
/// \return void
void logEvent(Event_t event);

/// Create measurement type of event
/// \param[in]     type          event that will be logged via serial  line..
/// \param[in]     value         pointer to event value.
/// \return return created event
Event_t createEvent(EventType_t type, void *value);

/// Handle event and send event in json format via serial line
/// \param[in]     event          logging event
/// \return void
void handleEvent(Event_t event);

#endif /* INC_LOGGING_H_ */

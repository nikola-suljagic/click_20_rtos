/*
 * cc2d23_pins.h
 *
 *  Created on: Nov 19, 2023
 *      Author: nikola
 */

#ifndef BSP_INC_TEMP_HUM_CLICK20_PINS_H_
#define BSP_INC_TEMP_HUM_CLICK20_PINS_H_

#include "stm32f4xx_hal.h"

#define ENABLE_PIN GPIO_PIN_4
#define ENABLE_PORT GPIOA

#define DATA_READY_PIN GPIO_PIN_3
#define DATA_READY_PORT GPIOD

void setEnablePin(uint8_t level);
uint8_t dataReady(void);

#endif /* BSP_INC_TEMP_HUM_CLICK20_PINS_H_ */

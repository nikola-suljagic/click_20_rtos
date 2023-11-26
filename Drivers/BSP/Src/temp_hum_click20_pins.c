/*
 * cc2d23_pins.c
 *
 *  Created on: Nov 19, 2023
 *      Author: nikola
 */
#include "temp_hum_click20_pins.h"
#include "stm32f4xx_hal.h"

void setEnablePin(uint8_t level) {
	GPIO_PinState pinState = GPIO_PIN_RESET;
	if (level == 1) {
		pinState = GPIO_PIN_SET;
	}

	HAL_GPIO_WritePin(ENABLE_PORT, ENABLE_PIN, pinState);
}

uint8_t dataReady(void) {
	if (HAL_GPIO_ReadPin(DATA_READY_PORT, DATA_READY_PIN) == GPIO_PIN_SET) {
		return 1;
	} else {
		return 0;
	}
}

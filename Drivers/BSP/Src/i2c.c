/*
 * i2c.c
 *
 *  Created on: Nov 17, 2023
 *      Author: nikola
 */

#include "i2c.h"


extern I2C_HandleTypeDef hi2c1;

int i2cWrite(uint8_t i2cAddr, uint8_t *buff, uint8_t len) {
	if (HAL_I2C_Master_Transmit(&hi2c1, i2cAddr << 1, buff, len, HAL_MAX_DELAY) != HAL_OK) {
		return -1;
	}

	return 0;
}

int i2cRead(uint8_t i2cAddr, uint8_t *buff, uint8_t len) {
	if (HAL_I2C_Master_Receive(&hi2c1, i2cAddr << 1, buff, len, HAL_MAX_DELAY) != HAL_OK) {
		return -1;
	}

	return 0;
}

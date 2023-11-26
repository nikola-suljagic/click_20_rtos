/*
 * i2c.h
 *
 *  Created on: Nov 17, 2023
 *      Author: nikola
 */

#ifndef BSP_INC_I2C_H_
#define BSP_INC_I2C_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

int i2cWrite(uint8_t i2cAddr, uint8_t *buff, uint8_t len);
int i2cRead(uint8_t i2cAddr, uint8_t *buff, uint8_t len);

#endif /* BSP_INC_I2C_H_ */

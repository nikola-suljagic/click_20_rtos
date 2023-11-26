/*
 * cc2d23.h
 *
 *  Created on: Nov 16, 2023
 *      Author: nikola
 */

#ifndef BSP_INC_TEMP_HUM_CLICK20_H_
#define BSP_INC_TEMP_HUM_CLICK20_H_

#include "stdint.h"

#define TEMP_MULTIPLIER  165.0
#define TEMP_OFFSET  40.0
#define TEMP_SCLE 0x4000

#define HUM_SCALE  0x4000
#define HUM_MULTIPLIER   100.0
#define HUM_OFFSET      40.0

#define TEMP_HUM_CLICK20_ADDRESS_DEFAULT 0x28

typedef int (*i2c_func_t)(uint8_t, uint8_t*, uint8_t);
typedef void (*set_enebale_pin_t)(uint8_t level);
typedef uint8_t (*data_ready_t)(void);
typedef void (*delay_t)(uint32_t delay);

typedef enum TempHumClick20OperationMode {
	CMD_MODE, NORMAL_MODE
} TempHumClick20OperationMode_t;

typedef enum TempHumClick20Status {
	TempHumClick20Success, TempHumClick20Error
} TempHumClick20Status_t;

TempHumClick20Status_t tempHumClick20Init(TempHumClick20OperationMode_t opMode,
		i2c_func_t i2cWrite, i2c_func_t i2cRead, set_enebale_pin_t enable_pin,
		data_ready_t data_ready, delay_t delay);
void tempHumClick20Reset();
TempHumClick20Status_t tempHumClick20GetMeasurements(float *temperature, float *humidity);

#endif /* BSP_INC_TEMP_HUM_CLICK20_H_ */

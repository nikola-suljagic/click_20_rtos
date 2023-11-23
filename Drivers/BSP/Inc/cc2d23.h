/*
 * cc2d23.h
 *
 *  Created on: Nov 16, 2023
 *      Author: nikola
 */

#ifndef BSP_INC_CC2D23_H_
#define BSP_INC_CC2D23_H_

#include "stdint.h"


#define TEMP_MULTIPLIER  165.0
#define TEMP_OFFSET  40.0
#define TEMP_SCLE 0x4000

#define HUM_SCALE  0x4000
#define HUM_MULTIPLIER   100.0
#define HUM_OFFSET      40.0

#define CC2D23_ADDRESS_DEFAULT 0x28

typedef int (*i2c_func_t)(uint8_t, uint8_t*, uint8_t);
typedef void (*set_enebale_pin_t)(uint8_t level);
typedef uint8_t (*data_ready_t)(void);
typedef void (*delay_t)(uint32_t delay);

typedef enum CC2D23OperationMode {
	CMD_MODE,
	NORMAL_MODE
} CC2D23OperationMode_t;


typedef enum CC2D23Status {
	CC2D23Success,
	CC2D23Error
} CC2D23Status_t;

CC2D23Status_t cc2d23Init(CC2D23OperationMode_t opMode, i2c_func_t i2cWrite, i2c_func_t i2cRead,
		                  set_enebale_pin_t enable_pin, data_ready_t data_ready, delay_t delay);
void cc2d23Reset();
CC2D23Status_t cc2d23GetMeasurements(float *temperature, float *humidity);

#endif /* BSP_INC_CC2D23_H_ */

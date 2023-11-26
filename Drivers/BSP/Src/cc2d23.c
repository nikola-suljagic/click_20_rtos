/*
 * cc2d23.c
 *
 *  Created on: Nov 16, 2023
 *      Author: nikola
 */
#include "cc2d23.h"

int (*I2CWriteCallback)(uint8_t i2cAddr, uint8_t *buffer, uint8_t len);
int (*I2CReadCallback)(uint8_t i2cAddr, uint8_t *buffer, uint8_t len);
void (*EnablePinCallback)(uint8_t level);
uint8_t (*DataReadyPinLevelCallback)(void);
void (*DelayCallback)(uint32_t delay);

CC2D23Status_t cc2d23Init(CC2D23OperationMode_t opMode, i2c_func_t i2cWrite,
		i2c_func_t i2cRead, set_enebale_pin_t enablePin, data_ready_t dataReady,
		delay_t delay) {

	I2CWriteCallback = i2cWrite;
	I2CReadCallback = i2cRead;
	EnablePinCallback = enablePin;
	DataReadyPinLevelCallback = dataReady;
	DelayCallback = delay;

	cc2d23Reset();

	return CC2D23Success;
}

void cc2d23Reset() {
	EnablePinCallback(0);
	DelayCallback(100);
	EnablePinCallback(1);
	DelayCallback(1);
}

CC2D23Status_t cc2d23GetMeasurements(float *temperature, float *humidity) {
	uint8_t data[4];
	while (DataReadyPinLevelCallback() == 0)
		;

	if (I2CReadCallback(CC2D23_ADDRESS_DEFAULT, data, 4) != 0) {
		return CC2D23Error;
	}

	*temperature =
			((float) (((uint16_t) data[2] << 6) | ((data[3] >> 2) & 0x3F)) /
			TEMP_SCLE) * TEMP_MULTIPLIER - TEMP_OFFSET;

	*humidity = ((float) (((uint16_t) data[0] << 8) | data[1]) /
	HUM_SCALE) * HUM_MULTIPLIER;

	return CC2D23Success;

}


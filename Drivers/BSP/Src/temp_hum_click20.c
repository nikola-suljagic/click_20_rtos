/*
 * cc2d23.c
 *
 *  Created on: Nov 16, 2023
 *      Author: nikola
 */
#include <temp_hum_click20.h>

int (*I2CWriteCallback)(uint8_t i2cAddr, uint8_t *buffer, uint8_t len);
int (*I2CReadCallback)(uint8_t i2cAddr, uint8_t *buffer, uint8_t len);
void (*EnablePinCallback)(uint8_t level);
uint8_t (*DataReadyPinLevelCallback)(void);
void (*DelayCallback)(uint32_t delay);

TempHumClick20Status_t tempHumClick20Init(TempHumClick20OperationMode_t opMode, i2c_func_t i2cWrite,
		i2c_func_t i2cRead, set_enebale_pin_t enablePin, data_ready_t dataReady,
		delay_t delay) {

	I2CWriteCallback = i2cWrite;
	I2CReadCallback = i2cRead;
	EnablePinCallback = enablePin;
	DataReadyPinLevelCallback = dataReady;
	DelayCallback = delay;

	tempHumClick20Reset();

	return TempHumClick20Success;
}

void tempHumClick20Reset() {
	EnablePinCallback(0);
	DelayCallback(100);
	EnablePinCallback(1);
	DelayCallback(1);
}

TempHumClick20Status_t tempHumClick20GetMeasurements(float *temperature, float *humidity) {
	uint8_t data[4];
	while (DataReadyPinLevelCallback() == 0)
		;

	if (I2CReadCallback(TEMP_HUM_CLICK20_ADDRESS_DEFAULT, data, 4) != 0) {
		return TempHumClick20Error;
	}

	*temperature =
			((float) (((uint16_t) data[2] << 6) | ((data[3] >> 2) & 0x3F)) /
			TEMP_SCLE) * TEMP_MULTIPLIER - TEMP_OFFSET;

	*humidity = ((float) (((uint16_t) data[0] << 8) | data[1]) /
	HUM_SCALE) * HUM_MULTIPLIER;

	return TempHumClick20Success;

}


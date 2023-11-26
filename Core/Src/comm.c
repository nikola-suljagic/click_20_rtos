/*
 * comm.c
 *
 *  Created on: Nov 26, 2023
 *      Author: nikola
 */
#include "comm.h"


I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart6;


/**
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void I2C1_Init(void) {
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 400000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief USART6 Initialization Function
 * @param None
 * @retval None
 */
static void USART6_UART_Init(void) {
	huart6.Instance = USART6;
	huart6.Init.BaudRate = 921600;
	huart6.Init.WordLength = UART_WORDLENGTH_8B;
	huart6.Init.StopBits = UART_STOPBITS_1;
	huart6.Init.Parity = UART_PARITY_NONE;
	huart6.Init.Mode = UART_MODE_TX_RX;
	huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart6.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart6) != HAL_OK) {
		Error_Handler();
	}

}

/**
 * @brief Initialization communication peripherals
 * @param None
 * @retval None
 */
void commInit(void) {
	I2C1_Init();
	USART6_UART_Init();
}


/**
 * @brief Override _write weak function in order to enable pritf via UART
 * @param None
 * @retval None
 */
int _write(int file, char *ptr, int len) {
	HAL_UART_Transmit(&huart6, (uint8_t*) ptr, len, HAL_MAX_DELAY);
	return len;
}


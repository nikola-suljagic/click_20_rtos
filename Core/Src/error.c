/*
 * error.c
 *
 *  Created on: Nov 26, 2023
 *      Author: nikola
 */
#include "error.h"

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
}

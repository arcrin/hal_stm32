/*
 * main.c
 *
 *  Created on: May 12, 2022
 *      Author: wbai
 */


#include "stm32f4xx_hal.h"

void SystemClockConfig(void);
void UART2_Init();
void Error_handler();

UART_HandleTypeDef huart2;

int main(void) {
	HAL_Init();
	SystemClockConfig();
	UART2_Init();
	return 0;
}


void SystemClockConfig(void){

}


void UART2_Init(){
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&huart2) != HAL_OK){
		//There is a problem
		Error_handler();
	}
}


void Error_handler(){
	while(1){
		//have a LED blinking
	}
}

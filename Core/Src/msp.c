/*
 * msp.c
 *
 *  Created on: May 12, 2022
 *      Author: wbai
 */

#include "stm32f4xx_hal.h"


void HAL_MspInit(void)
{
// Here we will do low level processor specific initializations
	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exception of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; //USGFAULT, BUSFAULT, MEMFAULT system exceptions

	//3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	//here we are  going to do the low level initialization of the USART2 peripheral

	//1. enable the clock for the USART2 peripheral
	//2. pin muxing configurations
	//3. enable the IRQ and set up the priority (NVIC settings)
}

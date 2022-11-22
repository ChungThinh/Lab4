/*
 * function.c
 *
 *  Created on: Nov 22, 2022
 *      Author: Chung Thinh
 */

#include "function.h"


void Init()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_PURPLE_GPIO_Port, LED_PURPLE_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_ORANGE_GPIO_Port, LED_ORANGE_Pin, SET);
	HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, SET);
}
void task05()
{
	HAL_GPIO_TogglePin(LED_PURPLE_GPIO_Port, LED_PURPLE_Pin);
}

void task1()
{
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

void task15()
{
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}

void task2()
{
	HAL_GPIO_TogglePin(LED_ORANGE_GPIO_Port, LED_ORANGE_Pin);
}

void task25()
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}


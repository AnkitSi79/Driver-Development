/*
 * 05button_interrupt.c
 *
 *  Created on: Jun 19, 2024
 *      Author: Ankit
 */

#include <string.h>
#include "stm32f407xx.h"

void delay(void)
{
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

int main(void)
{

	GPIO_Handle_t GpioLed, GPIOBtn;

	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GPIOBtn,0,sizeof(GpioLed));

	// led gpio configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed);


	// btn gpio configuration
	GPIOBtn.pGPIOx = GPIOD;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GPIOBtn);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);

	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI4,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI4,ENABLE);

    while(1);

}


void EXTI4_IRQHandler(void)
{
   /// delay();           //200ms .  button de-bouncing
	GPIO_IRQHandling(GPIO_PIN_NO_4); //clear the pending event from exti line
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
}

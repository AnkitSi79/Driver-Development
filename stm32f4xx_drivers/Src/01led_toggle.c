/*
 * 01led_toggle.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Ankit
 */

#include "stm32f407xx.h"

void delay(void)
{
	for (uint32_t i=0; i<500000; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	/* in open daran config, toggling will not work as thepin will be ground of floting
	 * to fix the issue GPIO_PinPuPdControl to "GPIO_PIN_PU", if using external pull up then use "GPIO_NO_PUPD"
	 * if the intensity is low then use extenal pull up with less resitance value */
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}
	return 0;
}

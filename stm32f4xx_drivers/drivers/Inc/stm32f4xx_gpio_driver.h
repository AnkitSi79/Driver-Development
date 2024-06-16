/*
 * stm32f4xx_gpio_driver.h
 *
 *  Created on: Jun 14, 2024
 *      Author: greycell
 */

#ifndef INC_STM32F4XX_GPIO_DRIVER_H_
#define INC_STM32F4XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig;


/*
 * This is a handle structure for a GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;   // this holds the base address of the gpio port to which pin belongs
	GPIO_PinConfig_t GPIO_PinConfig;  // this holds gpio pin configuration
}GPIO_Handle_t;


/*******************************
 * APIs supported by this driver
 ******************************/

/*
 * Init and Deinit
 */
void GPIO_Init(void);
void GPIO_DeInit(void);

/*
 * Peripheral clock setup
 */
void GPIO_PeripheralControl(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputtPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);

/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);

#endif /* INC_STM32F4XX_GPIO_DRIVER_H_ */

/*
 * stm32f407xx.h
 *
 *  Created on: Jun 13, 2024
 *      Author: greycell
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __vo volatile


/*
 * base address of flash and SRAM memories
 */

#define FLASH_BASEADDR        (uint32_t) 0x08000000       /* RM0090 datasheet */
#define SRAM1_BASEADDR        0x20000000U
#define SRAM2_BASEADDR        0x2001C000U		/* 112kB from sram1*/
#define ROM_BASEADDR          0x1FFF0000U        /* System memory*/
#define SRAM_BASEADDR         SRAM1_BASEADDR    /* SRAM1 can be defined as SRAM*/


/*
 * AHBx and APBx bus peripheral base memories
 */

#define PERIPH_BASE           0x40000000U
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       0x40010000U
#define AHB1PERIPH_BASE       0x40020000U
#define AHB2PERIPH_BASE       0x50000000U


/*
 * Base address of peripheral which are on AHB1 Bus
 */
#define GPIOA_BASEADDR         (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR         (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR         (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR         (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR         (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR         (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR         (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR         (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR         (AHB1PERIPH_BASE + 0x2000)


/*
 * Base address of peripheral which are on APB1 Bus
 */
#define SPI2_BASEADDR          (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR          (APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR        (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR        (APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR         (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR         (APB1PERIPH_BASE + 0x5000)

#define I2C1_BASEADDR          (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR          (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR          (APB1PERIPH_BASE + 0x5C00)


/*
 * Base address of peripheral which are on APB2 Bus
 */
#define USART1_BASEADDR        (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR        (APB2PERIPH_BASE + 0x1400)
#define SPI1_BASEADDR          (APB2PERIPH_BASE + 0x3000)
#define SYSCFG_BASEADDR        (APB2PERIPH_BASE + 0x3800)
#define EXT1_BASEADDR          (APB2PERIPH_BASE + 0x3C00)



/**Peripheral register defination structure**/
/*
 * Note : Registers of peripheral are specific to MCU
 */

typedef struct
{
__vo uint32_t MODER;      /* GPIO port mode register      Address offset: 0x00*/
__vo uint32_t OTYPER;     /* GPIO port output type register      Address offset: 0x04*/
__vo uint32_t OSPEEDR;    /* GPIO port output speed register      Address offset: 0x08*/
__vo uint32_t PUPDR;      /* GPIO port pull-up/pull-down register      Address offset: 0x0C*/
__vo uint32_t IDR;        /* GPIO port input data register      Address offset: 0x10*/
__vo uint32_t ODR;        /* GPIO port output data register      Address offset: 0x14*/
__vo uint32_t BSRR;       /* GPIO port bit set/reset register      Address offset: 0x18*/
__vo uint32_t LCKR;       /* GPIO port configuration lock register      Address offset: 0x1C*/
__vo uint32_t AFR[2];     /* AFR[0] : GPIO alternate function low register        AFR[1] : GPIO alternate function high register*/
}GPIO_RegDef_t;


/*
 * Peripheral definations (peripheral base address typedef to xxx_RegDef_t)
 */
//GPIO_RegDef_t *pGPIOA = ((GPIO_RegDef_t*) GPIOA_BASEADDR);
#define GPIOA  ( (GPIO_RegDef_t*) GPIOA_BASEADDR )
#define GPIOB  ( (GPIO_RegDef_t*) GPIOB_BASEADDR )
#define GPIOC  ( (GPIO_RegDef_t*) GPIOC_BASEADDR )
#define GPIOD  ( (GPIO_RegDef_t*) GPIOD_BASEADDR )
#define GPIOE  ( (GPIO_RegDef_t*) GPIOE_BASEADDR )
#define GPIOF  ( (GPIO_RegDef_t*) GPIOF_BASEADDR )
#define GPIOG  ( (GPIO_RegDef_t*) GPIOG_BASEADDR )
#define GPIOH  ( (GPIO_RegDef_t*) GPIOH_BASEADDR )
#define GPIOI  ( (GPIO_RegDef_t*) GPIOI_BASEADDR )


#endif /* INC_STM32F407XX_H_ */

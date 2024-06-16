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
#define RCC_BASEADDR           (AHB1PERIPH_BASE + 0x3800)

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
 * Peripheral definations register for RCC
 */
typedef struct
{
__vo uint32_t CR;              		/*RCC clock control register     0x00 */
__vo uint32_t PLLCFGR;         		/*RCC PLL configuration register   0x04*/
__vo uint32_t CFGR;            		/*RCC clock configuration register 0x08*/
__vo uint32_t CIR;             		/*RCC clock interrupt register    0x0C*/
__vo uint32_t AHB1RSTR;        		/*RCC AHB1 peripheral reset register   0x10*/
__vo uint32_t AHB2RSTR;        		/*RCC AHB2 peripheral reset register   0x14*/
__vo uint32_t AHB3RSTR;        		/*RCC AHB3 peripheral reset register   0x18*/
uint32_t      RESERVED0;            /*0x1C*/
__vo uint32_t APB1RSTR;        		/*RCC APB1 peripheral reset register   0x20*/
__vo uint32_t APB2RSTR;        		/*RCC APB2 peripheral reset register   0x24*/
uint32_t      RESERVED1[2];         /*0x28   0x2C*/
__vo uint32_t AHB1ENR;        		/* RCC AHB1 peripheral clock register    0x30 */
__vo uint32_t AHB2ENR;         		/*RCC AHB2 peripheral clock enable register 0x34*/
__vo uint32_t AHB3ENR;         		/*RCC AHB3 peripheral clock enable register 0x38*/
uint32_t      RESERVED2;            /*0x3C*/
__vo uint32_t APB1ENR;         		/*RCC APB1 peripheral clock enable register 0x40*/
__vo uint32_t APB2ENR;         		/*RCC APB2 peripheral clock enable register 0x44*/
uint32_t      RESERVED3[2];         /*0x48 0x4C*/
__vo uint32_t AHB1LPENR;     		/*RCC AHB1 peripheral clock enable in low power mode register 0x50*/
__vo uint32_t AHB2LPENR;      		/*RCC AHB2 peripheral clock enable in low power mode register 0x54*/
__vo uint32_t AHB3LPENR;      		/*RCC AHB3 peripheral clock enable in low power mode register 0x58*/
uint32_t      RESERVED4;           	/*0x5C*/
__vo uint32_t APB1LPENR;      		/*RCC APB1 peripheral clock enable in low power mode register  0x60*/
__vo uint32_t APB2LPENR;      		/*RCC APB2 peripheral clock enabled in low power mode register  0x64*/
uint32_t      RESERVED5[2];         /*0x68 0x6C*/
__vo uint32_t BDCR;                 /*RCC Backup domain control register  0x70*/
__vo uint32_t CSR;                  /*RCC clock control & status register  0x74*/
uint32_t      RESERVED6[2];         /*0x78 0x7C*/
__vo uint32_t SSCGR;  				/*RCC spread spectrum clock generation register 0x80*/
__vo uint32_t PLLI2SCFGR;     		/*RCC PLLI2S configuration register   0x84*/
__vo uint32_t PLLSAICFGR;     		/*RCC PLL configuration register   0x88*/
__vo uint32_t DCKCFGR;     			/*RCC Dedicated Clock Configuration Register  0x8c*/
}RCC_RegDef_t;



/*
 * Peripheral definations (peripheral base address typedef to xxx_RegDef_t)
 */
//GPIO_RegDef_t *pGPIOA = ((GPIO_RegDef_t*) GPIOA_BASEADDR);
#define GPIOA  ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB  ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC  ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD  ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE  ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF  ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG  ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH  ((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI  ((GPIO_RegDef_t*) GPIOI_BASEADDR)

#define RCC    ((RCC_RegDef_t*) RCC_BASEADDR)


/*
 * Clock Enable macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1 << 0))   // enable the 0Th bit for gpioa
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()   (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()   (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()   (RCC->AHB1ENR |= (1 << 8))


/*
 * Clock Enable macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()   (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()   (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()   (RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()   (RCC->APB2ENR |= (1 << 12))


/*
 * Clock Enable macros for USARTx peripherals
 */
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1 << 4))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1 << 5))


/*
 * Clock Enable macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()   (RCC->APB2ENR |= (1 << 14))



/*
 * Clock DISABLE macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 0))   // DISABLE the 0Th bit for GPIOA
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 8))


/*
 * Clock DISABLE macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()   (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock DISABLE macros for I2Cx peripherals
 */
#define SPI1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 12))


/*
 * Clock DISABLE macros for USARTx peripherals
 */
#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 4))
#define USART6_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 5))


/*
 * Clock DISABLE macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 14))



#endif /* INC_STM32F407XX_H_ */
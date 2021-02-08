#include "stm32f1xx_hal_uart.h"


#ifndef STM32F1XX_HAL_UART__CFG_H__
#define STM32F1XX_HAL_UART__CFG_H__


// Function prototype
void UART_Init(void);
void USART1_IRQHandler(void);


// Defines UART port for communication 
extern UART_InitTypeDef UART1;   

#endif

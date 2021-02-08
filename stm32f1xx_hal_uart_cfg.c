#include "stm32f1xx_hal_uart_cfg.h"     /*hal_uart header*/

// Initialing UART structure
UART_InitTypeDef UART1 = {0};  


//Function definition
void UART_Init(){

	// Populate UART_InitTypeDef struct
	UART1.UartNumber = UART_1;
	UART1.Mode = UART_MODE_FULL_DUPLEX;
	UART1.BaudRate = 0x271	;  //115000 bps
	UART1.InterruptEnable = UART_INTERRUPT_ON;    //For Non blocking UART
	HAL_UART_Init(&UART1);
	
}



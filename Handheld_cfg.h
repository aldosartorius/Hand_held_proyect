
#ifndef HANDHELD_CFG_H__
#define HANDHELD_CFG_H__

#include "stdint.h"
#include "hal_lcd.h"                    // LCD Samsumg driver
#include "stm32f1xx_hal_tim_cfg.h"
#include "stm32f1xx_hal_uart_cfg.h"
#include "string.h"                     //memcpy


extern uint8_t iMotorNumber;
extern uint16_t iButtonDebouncingTime;
extern char lcdRow1[16];
extern char lcdRow2[16];
extern char uartTxChar;

//extern char lolo[45];

__PACKED_STRUCT StructData{
	float q1;    // Specifies articular position for motor 1
	float q2;     // Specifies articular position for motor 2
	float q3;     // Specifies articular position for motor 3
	float q4;     // Specifies articular position for motor 4
	float q5;     // Specifies articular position for motor 5
};

extern struct StructData EncodersReceivedData;



//Functions prototype
void Init_Handheld(void);
void UART_Tx_Struct(UART_InitTypeDef *, struct StructData *, int);


#endif

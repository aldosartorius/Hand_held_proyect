
#ifndef HANDHELD_CFG_H__
#define HANDHELD_CFG_H__

#include "stdint.h"
#include "hal_lcd.h"                    // LCD Samsumg driver
#include "stm32f1xx_hal_tim_cfg.h"

//Functions prototype
void Init_Handheld(void);


extern uint8_t iMotorNumber;
extern uint16_t iButtonDebouncingTime;
extern char lcdRow1[16];
extern char lcdRow2[16];
extern char uartString[3];


typedef struct{
	float q1;    // Specifies articular position for motor 1
	float q2;     // Specifies articular position for motor 2
	float q3;     // Specifies articular position for motor 3
	float q4;     // Specifies articular position for motor 4
	float q5;     // Specifies articular position for motor 5
}RobotArticularPositionTypeDef;

#endif

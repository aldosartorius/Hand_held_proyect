#include "stm32f1xx_hal_gpio.h"


#ifndef STM32F1XX_HAL_GPIO__CFG_H__
#define STM32F1XX_HAL_GPIO__CFG_H__

//Functions prototype
void GPIO_Init(void);

//define states por buttons
extern GPIO_PinState RESET_BUTTON_STATE;
extern GPIO_PinState OPEN_CLOSE_BUTTON_STATE;
extern GPIO_PinState CLOSE_POSITION_SEND_BUTTON_STATE;
extern GPIO_PinState SAVE_POSITION_BUTTON_STATE;

extern GPIO_PinState JOSTICK_RIGHT_BUTTON_STATE;
extern GPIO_PinState JOSTICK_LEFT_BUTTON_STATE;
extern GPIO_PinState JOSTICK_DOWN_BUTTON_STATE;
extern GPIO_PinState JOSTICK_UP_BUTTON_STATE;

//define leds variables
extern GPIO_Pin_TypeDef sSTATE_LED;                   //State led
extern GPIO_Pin_TypeDef sRESET_LED;                   //Reset led
extern GPIO_Pin_TypeDef sOPEN_CLOSE_LED;              //O/C Loop led
extern GPIO_Pin_TypeDef sSAVE_POSITION_LED;           //Save position led

//Define buttons variables
extern GPIO_Pin_TypeDef sRESET_BUTTON;                //Reset button
extern GPIO_Pin_TypeDef sOPEN_CLOSE_BUTTON;           //O/C Loop button
extern GPIO_Pin_TypeDef sCLOSE_POSITION_SEND_BUTTON;  //Close position send button
extern GPIO_Pin_TypeDef sSAVE_POSITION_BUTTON;        //Save position button

//Define joystick variables
extern GPIO_Pin_TypeDef sJOSTICK_RIGHT_BUTTON;        //Joystick right button
extern GPIO_Pin_TypeDef sJOSTICK_LEFT_BUTTON;         //Joystick left button
extern GPIO_Pin_TypeDef sJOSTICK_DOWN_BUTTON;         //Joystick down button
extern GPIO_Pin_TypeDef sJOSTICK_UP_BUTTON;           //Joystick up button

//Define Pins for LCD registers
extern GPIO_Pin_TypeDef sRS;      //RS (Register select)
extern GPIO_Pin_TypeDef sRW;      //RW (Read/Write Register)*always connect
extern GPIO_Pin_TypeDef sE;       //E  (Enable)

//Define Pins for LCD data
extern GPIO_Pin_TypeDef sD0;      //Data 0
extern GPIO_Pin_TypeDef sD1;      //Data 1
extern GPIO_Pin_TypeDef sD2;      //Data 2
extern GPIO_Pin_TypeDef sD3;      //Data 3

//Unused pins

extern GPIO_Pin_TypeDef sPB12;
extern GPIO_Pin_TypeDef sPA8;
extern GPIO_Pin_TypeDef sPA9;
extern GPIO_Pin_TypeDef sPA10;
extern GPIO_Pin_TypeDef sPA11;
extern GPIO_Pin_TypeDef sPA12;
extern GPIO_Pin_TypeDef sPA15;

extern GPIO_Pin_TypeDef sPB9;
extern GPIO_Pin_TypeDef sPC15;
extern GPIO_Pin_TypeDef sPC14;
extern GPIO_Pin_TypeDef sPC13;

#endif

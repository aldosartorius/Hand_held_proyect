#include "stm32f1xx_hal_exti.h"


#ifndef STM32F1XX_HAL_EXTI__CFG_H__
#define STM32F1XX_HAL_EXTI__CFG_H__


//Function prototype
void EXTI_Init(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);

//  Defines external interruts for joystick and buttons 
extern EXTI_ConfigTypeDef sEXTI_PA0;  //Interrupt for jostick up
extern EXTI_ConfigTypeDef sEXTI_PA1;  //Interrupt for jostick down
extern EXTI_ConfigTypeDef sEXTI_PA2;  //Interrupt for jostick left
extern EXTI_ConfigTypeDef sEXTI_PA3;  //Interrupt for jostick right

extern EXTI_ConfigTypeDef sEXTI_PA4;  //Interrupt for save position button
extern EXTI_ConfigTypeDef sEXTI_PA5;  //Interrupt for close position send buttom
extern EXTI_ConfigTypeDef sEXTI_PA6;  //Interrupt for O/C loop button
extern EXTI_ConfigTypeDef sEXTI_PA7;  //Interrupt for reset button

#endif

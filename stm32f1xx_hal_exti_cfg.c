#include "stm32f1xx_hal_exti_cfg.h"     /*hal_exti header*/
#include "stm32f1xx_hal_gpio_cfg.h"     /*hal_gpio header*/
#include "stm32f1xx_hal_tim_cfg.h"      /*hal_tim header*/
#include "hal_lcd.h".h"      /*hal_tim header*/

#include <stdio.h>    //for sprintf function

int iMotorNumber = (uint8_t)1;
//cRow1[16] = " ";
//cRow2[16] = " ";

// Initialing EXTI structures
EXTI_ConfigTypeDef sEXTI_PA0 = {0};  //Interrupt for jostick up
EXTI_ConfigTypeDef sEXTI_PA1 = {0};  //Interrupt for jostick down
EXTI_ConfigTypeDef sEXTI_PA2 = {0};  //Interrupt for jostick left
EXTI_ConfigTypeDef sEXTI_PA3 = {0};  //Interrupt for jostick right

EXTI_ConfigTypeDef sEXTI_PA4 = {0};  //Interrupt for save position button
EXTI_ConfigTypeDef sEXTI_PA5 = {0};  //Interrupt for close position send buttom
EXTI_ConfigTypeDef sEXTI_PA6 = {0};  //Interrupt for O/C loop button
EXTI_ConfigTypeDef sEXTI_PA7 = {0};  //Interrupt for reset button

//Function definition
void EXTI_Init(){

	// Populate structure for Interrupt (Jostick up)
	sEXTI_PA0.GPIOSel = EXTI_GPIOA;
	sEXTI_PA0.Line = EXTI_LINE_0;
	sEXTI_PA0.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA0);
	
	// Populate structure for Interrupt (Jostick down)
	sEXTI_PA1.GPIOSel = EXTI_GPIOA;
	sEXTI_PA1.Line = EXTI_LINE_1;
	sEXTI_PA1.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA1);

	// Populate structure for Interrupt (Jostick left)
	sEXTI_PA2.GPIOSel = EXTI_GPIOA;
	sEXTI_PA2.Line = EXTI_LINE_2;
	sEXTI_PA2.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA2);

	// Populate structure for Interrupt (Jostick rigth)
	sEXTI_PA3.GPIOSel = EXTI_GPIOA;
	sEXTI_PA3.Line = EXTI_LINE_3;
	sEXTI_PA3.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA3);

	// Populate structure for Interrupt (Save position button)
	sEXTI_PA4.GPIOSel = EXTI_GPIOA;
	sEXTI_PA4.Line = EXTI_LINE_4;
	sEXTI_PA4.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA4);

	// Populate structure for Interrupt (Close position send button)
	sEXTI_PA5.GPIOSel = EXTI_GPIOA;
	sEXTI_PA5.Line = EXTI_LINE_5;
	sEXTI_PA5.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA5);

	// Populate structure for Interrupt (O/C loop button)
	sEXTI_PA6.GPIOSel = EXTI_GPIOA;
	sEXTI_PA6.Line = EXTI_LINE_6;
	sEXTI_PA6.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA6);

	// Populate structure for Interrupt (Reset button)
	sEXTI_PA7.GPIOSel = EXTI_GPIOA;
	sEXTI_PA7.Line = EXTI_LINE_7;
	sEXTI_PA7.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA7);

}

// Interrupt Handler (Jostick up)
void EXTI0_IRQHandler(void){
	

	//Button debouncing
	HAL_TIM_msDelay(&sTIMER1,200);
	iMotorNumber++;	
	HAL_Lcd_Clear();
	sprintf(cRow1,"Motor M%d", iMotorNumber);
	HAL_Lcd_Print_String(cRow1);
	HAL_EXTI_ClearPending(&sEXTI_PA0);

}

// Interrupt Handler (Jostick down)
void EXTI1_IRQHandler(void){
	
	//Button debouncing
	HAL_TIM_msDelay(&sTIMER1,200);
	iMotorNumber--;	
	HAL_Lcd_Clear();
	sprintf(cRow1,"Motor M%d", iMotorNumber);
	HAL_Lcd_Print_String(cRow1);
	//HAL_Lcd_Clear();
					 

	HAL_EXTI_ClearPending(&sEXTI_PA1);

}

// Interrupt Handler (Jostick left)
void EXTI2_IRQHandler(void){
	
	HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);
	HAL_EXTI_ClearPending(&sEXTI_PA2);

}

// Interrupt Handler (Jostick rigth)
void EXTI3_IRQHandler(void){
	
	HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);
	HAL_EXTI_ClearPending(&sEXTI_PA3);

}

// Interrupt Handler (Save position button)
void EXTI4_IRQHandler(void){
	
	HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
	HAL_EXTI_ClearPending(&sEXTI_PA4);
}

// Interrupt Handler for close position send button, O/C, loop button, reset button
void EXTI9_5_IRQHandler(void){
	

	//If EXTI Line 5 is detected
	if(EXTI->PR & 0x20){
		
		HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
		HAL_EXTI_ClearPending(&sEXTI_PA5);
	}
	
	//If EXTI Line 6 is detected
	if(EXTI->PR & 0x40){
			
		HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);
		HAL_EXTI_ClearPending(&sEXTI_PA6);
	}
	
  //If EXTI Line 7 is detected
	if(EXTI->PR & 0x80){
		
		HAL_GPIO_Pin_Toggle(&sRESET_LED);
		HAL_EXTI_ClearPending(&sEXTI_PA7);
	}
}
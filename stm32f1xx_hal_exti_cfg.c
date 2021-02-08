#include "stm32f1xx_hal_exti_cfg.h"     /*hal_exti header*/
#include "stm32f1xx_hal_gpio_cfg.h"     /*hal_gpio header*/


// Initialing EXTI structures
EXTI_ConfigTypeDef sEXTI_PA0 = {0};  //Interrupt for jostick up
EXTI_ConfigTypeDef sEXTI_PA1 = {0};  //Interrupt for jostick down
EXTI_ConfigTypeDef sEXTI_PA2 = {0};  //Interrupt for jostick left
EXTI_ConfigTypeDef sEXTI_PA8 = {0};  //Interrupt for jostick right

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
	sEXTI_PA8.GPIOSel = EXTI_GPIOA;
	sEXTI_PA8.Line = EXTI_LINE_8;//3
	sEXTI_PA8.Trigger = EXTI_TRIGGER_RISING;
	HAL_EXTI_Init(&sEXTI_PA8);

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
	sEXTI_PA6.Trigger = EXTI_TRIGGER_RISING_FALLING;
	HAL_EXTI_Init(&sEXTI_PA6);

	// Populate structure for Interrupt (Reset button)
	sEXTI_PA7.GPIOSel = EXTI_GPIOA;
	sEXTI_PA7.Line = EXTI_LINE_7;
	sEXTI_PA7.Trigger = EXTI_TRIGGER_RISING_FALLING;
	HAL_EXTI_Init(&sEXTI_PA7);

}

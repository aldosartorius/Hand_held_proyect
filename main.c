/****************************************************************************
* @Title                 :   Hand held project for Robot Armdroid by LabVolt 
* @Filename              :   Hand held 
* @Author                :   Aldo R. Sartorius Castellanos
* Origin Date            :   01/01/2021
* @Version               :   1.1.0
* Compiler               :   Keil
* Target                 :   STM32F103C8T6 Microcontroller
* Notes                  :   None
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author          Description 
*  01/01/21   1.0.0   Aldo Sartorius   add stm32f1xx_hal_gpio_cfg.h for configure I/O
*  01/01/21   1.0.0   Aldo Sartorius   add stm32f1xx_hal_gpio_cfg.c for configure I/O
*  03/01/21   1.0.0   Aldo Sartorius   add stm32f1xx_hal_tim_cfg.h for configure timer delay
*  03/01/21   1.0.0   Aldo Sartorius   add stm32f1xx_hal_tim_cfg.c for configure timer delay
*  15/01/21   1.0.0   Aldo Sartorius   add hal_lcd.h for configure LCD functionallity
*  15/01/21   1.0.0   Aldo Sartorius   add hal_lcd.c for configure LCD functionallity
*  03/02/21   1.1.0   Aldo Sartorius   add external interrupt functionality EXTI for buttons
* 
*
*****************************************************************************/
/** @file main.c
 *  @brief Hand held project for Robot Armdroid by LabVolt.
 * 
 *  This is program is used for control hand held. It move robot manipulator
 *  Armdroid by Labvolt using STM32F103C8T6 microcontroller
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"                  // Device header

// For configuration modules
                             
#include "stm32f1xx_hal_gpio_cfg.h"
#include "stm32f1xx_hal_tim_cfg.h"
#include "stm32f1xx_hal_exti_cfg.h"
#include "hal_lcd.h"


#include <stdio.h>    //for sprintf function
//#include <stdlib.h>   //for rand function


static int iMotorNumber;
static  char cRow1[16];
static char cRow2[16];
static uint16_t iButtonDebouncingTime = 150;

void Init_Handheld(void);




int main(void){

	//double random_number;
	//int max_theta1 = 360;

	__disable_irq();
	GPIO_Init();
	TIM_Delay_Init();
	
	HAL_Lcd_Init();
	HAL_Lcd_Clear();	
	
	Init_Handheld();
	EXTI_Init();

	__enable_irq();
	
	//Set off all indicator leds
	HAL_GPIO_Pin_Write(&sSTATE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sOPEN_CLOSE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);

//UNUSED PINS TO 0

HAL_GPIO_Pin_Write(&sPB12, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA8, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA9, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA10, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA11, GPIO_PIN_RESET);

HAL_GPIO_Pin_Write(&sPA12, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA15, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPB9, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC15, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC14, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC13, GPIO_PIN_SET);

iMotorNumber = 0;
     
	while(1){
	
	}

 return 0;
}

void Init_Handheld(void){
		
		HAL_Lcd_Cmd(0x2);  //Display return home
	
		HAL_Lcd_Print_String("Handheld v1.0.0");	
	  HAL_Lcd_Set_Cursor(2,0);
		HAL_Lcd_Print_String("Robot Armdroid");
	  HAL_TIM_msDelay(&sTIMER1,500);
	
}

// Interrupt Handler (Jostick up)
void EXTI0_IRQHandler(void){
	
	// Verify that the interrupt and the input are present (avoiding false trigers
	if((EXTI->PR & 0x1) & (GPIOA->IDR & 0x1) ){
					
		//Button debouncing
		HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
		
		//Verify max motor number
		if(iMotorNumber == 5){
				iMotorNumber = 1;
		}
		else{
				iMotorNumber++;
		}
		HAL_Lcd_Clear();
		sprintf(cRow1,"Motor M%d", iMotorNumber);
		HAL_Lcd_Print_String(cRow1);
	}
	HAL_EXTI_ClearPending(&sEXTI_PA0);
}

// Interrupt Handler (Jostick down)
void EXTI1_IRQHandler(void){
	
	// Verify that the interrupt and the input are present (avoiding false trigers
	if((EXTI->PR & 0x2) & (GPIOA->IDR & 0x2)){
				
		//Button debouncing
		HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);	
		
		//Verify min motor number
		if(iMotorNumber <= 1){
				iMotorNumber = 5;
		}
		else{
				iMotorNumber--;
		}
		HAL_Lcd_Clear();
		sprintf(cRow1,"Motor M%d", iMotorNumber);
		HAL_Lcd_Print_String(cRow1);	
	}
	HAL_EXTI_ClearPending(&sEXTI_PA1);
}

// Interrupt Handler (Jostick left)
void EXTI2_IRQHandler(void){
	
	
	if((EXTI->PR & 0x4) & (GPIOA->IDR & 0x4)){
				
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sRESET_LED);
	
	}
	HAL_EXTI_ClearPending(&sEXTI_PA2);
}

// Interrupt Handler (Jostick rigth)
void EXTI3_IRQHandler(void){
	
	
	if((EXTI->PR & 0x8) & (GPIOA->IDR & 0x8)){
		
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);		
	}
	HAL_EXTI_ClearPending(&sEXTI_PA3);
}

// Interrupt Handler (Save position button)
void EXTI4_IRQHandler(void){
	
	if((EXTI->PR & 0x10) & (GPIOA->IDR & 0x10)){
		
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
	}
	HAL_EXTI_ClearPending(&sEXTI_PA4);
}

// Interrupt Handler for close position send button, O/C, loop button, reset button
void EXTI9_5_IRQHandler(void){
	

	//If EXTI Line 5 is detected
	if((EXTI->PR & 0x20) & (GPIOA->IDR & 0x20)){
		
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
			HAL_EXTI_ClearPending(&sEXTI_PA5);
	}
	
	//If EXTI Line 6 is detected
	if((EXTI->PR & 0x40) & (GPIOA->IDR & 0x40)){
			
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);
			HAL_EXTI_ClearPending(&sEXTI_PA6);
	}
	
  //If EXTI Line 7 is detected 
  if((EXTI->PR & 0x80) & (GPIOA->IDR & 0x80)){
			
		//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);	
		if (HAL_GPIO_Pin_Read(&sRESET_BUTTON) & GPIO_PIN_SET){	
		
			HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_SET);
			HAL_EXTI_ClearPending(&sEXTI_PA7);
		}
		if (HAL_GPIO_Pin_Read(&sRESET_BUTTON) == GPIO_PIN_RESET ){	
		
			HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_RESET);
			HAL_EXTI_ClearPending(&sEXTI_PA7);
		}
		
	}
	
}


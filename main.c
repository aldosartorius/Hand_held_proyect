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
*  04/02/21   1.1.0   Aldo Sartorius   modify external interrupt handlers to avoid false trigers 
*  08/02/21   1.1.0   Aldo Sartorius   Change PA3 pint for PA8 pin to read Jostick rigth button (PA3 change this state suddently)
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
#include "hal_lcd.h"                    // LCD Samsumg driver
#include <stdio.h>                      //sprintf function

// For configuration modules
#include "stm32f1xx_hal_gpio_cfg.h"
#include "stm32f1xx_hal_tim_cfg.h"
#include "stm32f1xx_hal_exti_cfg.h"
#include "stm32f1xx_hal_uart_cfg.h"
#include "Handheld_cfg.h"


int main(void){

	__disable_irq();
	
	// Init Ports, timers, LCD, EXTI, UART
	GPIO_Init();
	TIM_Delay_Init();
	HAL_Lcd_Init();
	EXTI_Init();
	UART_Init();
	
	//Init Handheld 
	HAL_Lcd_Clear();	
	
	Init_Handheld();
	
	//Set off all indicator leds
	HAL_GPIO_Pin_Write(&sSTATE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sOPEN_CLOSE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);
	

	__enable_irq();
	
	

//Set Unused pins to 0

HAL_GPIO_Pin_Write(&sPB12, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA11, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA12, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPA15, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPB9, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC15, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC14, GPIO_PIN_RESET);
HAL_GPIO_Pin_Write(&sPC13, GPIO_PIN_SET);


	while(1){
		
	}

 return 0;
}



// Interrupt Handler (Jostick up)
void EXTI0_IRQHandler(void){
	
	// Verify that the interrupt and the input are present (avoiding false trigers
	if((EXTI->PR & 0x1) && (GPIOA->IDR & 0x1) ){
					
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
		sprintf(lcdRow1,"Motor M%d", iMotorNumber);
		HAL_Lcd_Print_String(lcdRow1);
	}
	HAL_EXTI_ClearPending(&sEXTI_PA0);
}

// Interrupt Handler (Jostick down)
void EXTI1_IRQHandler(void){
	
	// Verify that the interrupt and the input are present (avoiding false trigers
	if((EXTI->PR & 0x2) && (GPIOA->IDR & 0x2)){
				
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
		sprintf(lcdRow1,"Motor M%d", iMotorNumber);
		HAL_Lcd_Print_String(lcdRow1);	
	}
	HAL_EXTI_ClearPending(&sEXTI_PA1);
}

// Interrupt Handler (Jostick left)
void EXTI2_IRQHandler(void){
	
	
	if((EXTI->PR & 0x4) && (GPIOA->IDR & 0x4)){
				
		//Button debouncing
		HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
		HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_SET);
		sprintf(uartString,"-%d", iMotorNumber);
		HAL_UART_Tx_String(&UART1, uartString);
	}
	HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);
	HAL_EXTI_ClearPending(&sEXTI_PA2);
}

// Interrupt Handler (Save position button)
void EXTI4_IRQHandler(void){
	
	if((EXTI->PR & 0x10) && (GPIOA->IDR & 0x10)){
		
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
	}
	HAL_EXTI_ClearPending(&sEXTI_PA4);
}

// Interrupt Handler for close position send button, O/C, loop button, reset button
void EXTI9_5_IRQHandler(void){
	
	//If EXTI Line 5 is detected
	if((EXTI->PR & 0x20) && (GPIOA->IDR & 0x20)){
		
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sSAVE_POSITION_LED);
			HAL_EXTI_ClearPending(&sEXTI_PA5);
	}
	
	//If EXTI Line 6 is detected
	if((EXTI->PR & 0x40) && (GPIOA->IDR & 0x40)){
			
			//Button debouncing
			HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
			HAL_GPIO_Pin_Toggle(&sOPEN_CLOSE_LED);
			HAL_EXTI_ClearPending(&sEXTI_PA6);
	}
	
  //If EXTI Line 7 is detected 
  if((EXTI->PR & 0x80) && (GPIOA->IDR & 0x80)){
			
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
	
	//If EXTI Line 8 is detected  (Jostick rigth)
  if((EXTI->PR & 0x100) && (GPIOA->IDR & 0x100)){
		
		HAL_TIM_msDelay(&sTIMER1,iButtonDebouncingTime);
		HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_SET);
		sprintf(uartString,"+%d", iMotorNumber);
		HAL_UART_Tx_String(&UART1, uartString);	

		HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);
		HAL_EXTI_ClearPending(&sEXTI_PA8);
	}			
}

// Interrupt Handler USART Rx
void USART1_IRQHandler(){
	//RECIBIR LOS DATOS Y ACTUALIZAR 



}

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
//#include "stm32f1xx_hal_gpio.h"  /* For this modules definitions */                                
#include "stm32f1xx_hal_gpio_cfg.h"

 //#include "stm32f1xx_hal_tim.h"  /* For this modules definitions */                                
#include "stm32f1xx_hal_tim_cfg.h"
#include "stm32f1xx_hal_exti_cfg.h"
#include "hal_lcd.h"


#include <stdio.h>    //for sprintf function
#include <stdlib.h>   //for rand function


void Init_Handheld(void);




int main(void){

	double random_number;
	int max_theta1 = 360;

	
	GPIO_Init();
	TIM_Delay_Init();
	
	HAL_Lcd_Init();
	HAL_Lcd_Clear();	
	
	Init_Handheld();
	EXTI_Init();

	
	
	//Set off all indicator leds
	HAL_GPIO_Pin_Write(&sSTATE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sOPEN_CLOSE_LED, GPIO_PIN_RESET);
	HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);


	
     
	while(1){
		
	/*
	
        random_number=rand()/3000000;
				char cRow1[16];
		    char cRow2[16];
				char s3[13];
        sprintf(s,"%0.2f", random_number);
		    sprintf(s2,"%d", max_theta1);
				
		
		    HAL_Lcd_Print_String(s3);
				HAL_Lcd_Set_Cursor(2,3);
				sprintf(s,"%0.2f", random_number);
				HAL_Lcd_Print_String(s);
				HAL_Lcd_Set_Cursor(2,9);
				HAL_Lcd_Print_String("/");  
				HAL_Lcd_Print_String(s2);
				HAL_Lcd_Set_Cursor(1,1);
		
		
	
				//Read buttons states
				RESET_BUTTON_STATE = HAL_GPIO_Pin_Read(&sRESET_BUTTON);
        OPEN_CLOSE_BUTTON_STATE = HAL_GPIO_Pin_Read(&sOPEN_CLOSE_BUTTON);
        CLOSE_POSITION_SEND_BUTTON_STATE = HAL_GPIO_Pin_Read(&sCLOSE_POSITION_SEND_BUTTON);
        SAVE_POSITION_BUTTON_STATE = HAL_GPIO_Pin_Read(&sSAVE_POSITION_BUTTON);

				//Read Joystick states
				JOSTICK_RIGHT_BUTTON_STATE = HAL_GPIO_Pin_Read(&sJOSTICK_RIGHT_BUTTON);
				JOSTICK_LEFT_BUTTON_STATE = HAL_GPIO_Pin_Read(&sJOSTICK_LEFT_BUTTON);
				JOSTICK_DOWN_BUTTON_STATE = HAL_GPIO_Pin_Read(&sJOSTICK_DOWN_BUTTON);
				JOSTICK_UP_BUTTON_STATE = HAL_GPIO_Pin_Read(&sJOSTICK_UP_BUTTON);
                
             
        if(RESET_BUTTON_STATE == GPIO_PIN_SET){
         
            HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_SET);
        
        }
        else{
              
            HAL_GPIO_Pin_Write(&sRESET_LED, GPIO_PIN_RESET);
        
        }
       
         
        
        if(OPEN_CLOSE_BUTTON_STATE ==  GPIO_PIN_SET){
        
            HAL_GPIO_Pin_Write(&sOPEN_CLOSE_LED, GPIO_PIN_SET);
        
       }
         else{
              
         HAL_GPIO_Pin_Write(&sOPEN_CLOSE_LED, GPIO_PIN_RESET);
        
        }
      
        
        if(CLOSE_POSITION_SEND_BUTTON_STATE ==  GPIO_PIN_SET | SAVE_POSITION_BUTTON_STATE ==  GPIO_PIN_SET){
        
            HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_SET);
        
        }
        else{
              
        HAL_GPIO_Pin_Write(&sSAVE_POSITION_LED, GPIO_PIN_RESET);
        
        }
				
				if(JOSTICK_UP_BUTTON_STATE ==  GPIO_PIN_SET){
					HAL_TIM_msDelay(&sTIMER1,200);
					motor_number++;	
					HAL_Lcd_Clear();
					HAL_Lcd_Print_String("Jaz te quiero");
					//sprintf(s3,"Jaz te quiero %d", motor_number);
				}
				if(JOSTICK_DOWN_BUTTON_STATE ==  GPIO_PIN_SET){
					HAL_TIM_msDelay(&sTIMER1,200);
					motor_number--;	
					//sprintf(s3,"Sarai te quiero M%d", motor_number);
					HAL_Lcd_Clear();
					HAL_Lcd_Print_String("Sarai te quiero");
				}
				
				if(JOSTICK_RIGHT_BUTTON_STATE ==  GPIO_PIN_SET){
					HAL_TIM_msDelay(&sTIMER1,200);
					motor_number--;	
					//sprintf(s3,"Sarai te quiero M%d", motor_number);
					HAL_Lcd_Clear();
					HAL_Lcd_Print_String("PAPA");
				}
			
				if(JOSTICK_LEFT_BUTTON_STATE ==  GPIO_PIN_SET){
					HAL_TIM_msDelay(&sTIMER1,200);
					motor_number--;	
					//sprintf(s3,"Sarai te quiero M%d", motor_number);
					HAL_Lcd_Clear();
					HAL_Lcd_Print_String("MAMA");
				}
       
*/
	}

 return 0;
}

void Init_Handheld(void){
		
		HAL_Lcd_Cmd(0x2);  //Display return home
	
		HAL_Lcd_Print_String("Handheld v1.0.0");	
	  HAL_Lcd_Set_Cursor(2,0);
		HAL_Lcd_Print_String("Robot Armdroid");
	  HAL_TIM_msDelay(&sTIMER1,2000);
	
}


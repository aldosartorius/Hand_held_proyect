#include "stm32f1xx_hal_tim_cfg.h"   

//Initialization of variable for TIM structure
TIM_Base_InitTypeDef sTIMER1 = {0}; //Delay  

void TIM_Delay_Init(){
        
    //*******************TIM 1 populate and Init for Delay (see excel calc)***********************
    //FOR DELAY TIMER MUST BE CONFIGURATED AT 1 ms
    sTIMER1.Timer = TIM_1;
    sTIMER1.Prescaler = (uint16_t)7199;
    sTIMER1.Period = (uint16_t)9;
    HAL_TIM_Init(&sTIMER1);        
} 

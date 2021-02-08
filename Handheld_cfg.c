#include "Handheld_cfg.h"


uint8_t iMotorNumber = 0;
uint16_t iButtonDebouncingTime = 200;

char lcdRow1[16] = "";
char lcdRow2[16] = "";
char uartString[3] = "";


void Init_Handheld(void){
		
	HAL_Lcd_Cmd(0x2);  //Display return home
	HAL_Lcd_Print_String("Handheld v1.0.0");	
	HAL_Lcd_Set_Cursor(2,0);
	HAL_Lcd_Print_String("Robot Armdroid");
	HAL_TIM_msDelay(&sTIMER1,500);	
}

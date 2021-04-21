#include "Handheld_cfg.h"



uint8_t iMotorNumber = 0;
uint16_t iButtonDebouncingTime = 200;

char lcdRow1[16] = "";
char lcdRow2[16] = "";
char uartTxChar = ' '; // Char send to microcontroller to move in open loop the robot manipulator

//struct StructData EncodersReceivedData = {10, 20, 30, 40, 50};


void Init_Handheld(void){
		
	HAL_Lcd_Cmd(0x2);  //Display return home
	HAL_Lcd_Print_String("Handheld v1.0.0");	
	HAL_Lcd_Set_Cursor(2,0);
	HAL_Lcd_Print_String("Robot Armdroid");
	HAL_TIM_msDelay(&sTIMER1,500);	
}

/*void UART_Tx_Struct(UART_InitTypeDef * ptrUART_Init_Struct, struct StructData * ptrStructData, int structure_bytes){
	
	uint8_t payload[sizeof(*ptrStructData)];
	memcpy(payload, ptrStructData, sizeof(*ptrStructData));
	
	for(int count=0; count < sizeof(*ptrStructData); count++){
	
		HAL_UART_Tx(ptrUART_Init_Struct, payload[count]);
	}
}
*/
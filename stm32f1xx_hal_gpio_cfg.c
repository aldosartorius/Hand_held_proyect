#include "stm32f1xx_hal_gpio_cfg.h"     /*hal_gpio header*/


//Initialize states por buttons
GPIO_PinState RESET_BUTTON_STATE = {0};
GPIO_PinState OPEN_CLOSE_BUTTON_STATE = {0};
GPIO_PinState CLOSE_POSITION_SEND_BUTTON_STATE = {0};
GPIO_PinState SAVE_POSITION_BUTTON_STATE = {0};

GPIO_PinState JOSTICK_RIGHT_BUTTON_STATE = {0};
GPIO_PinState JOSTICK_LEFT_BUTTON_STATE = {0};
GPIO_PinState JOSTICK_DOWN_BUTTON_STATE = {0};
GPIO_PinState JOSTICK_UP_BUTTON_STATE = {0};

//Initialize leds variables
GPIO_Pin_TypeDef sSTATE_LED = {0};                   //State led
GPIO_Pin_TypeDef sRESET_LED = {0};                   //Reset led
GPIO_Pin_TypeDef sOPEN_CLOSE_LED = {0};              //O/C Loop led
GPIO_Pin_TypeDef sSAVE_POSITION_LED = {0};           //Save position led

//Initialize variables
GPIO_Pin_TypeDef sRESET_BUTTON = {0};                //Reset button
GPIO_Pin_TypeDef sOPEN_CLOSE_BUTTON = {0};           //O/C Loop button
GPIO_Pin_TypeDef sCLOSE_POSITION_SEND_BUTTON = {0};  //Close position send button
GPIO_Pin_TypeDef sSAVE_POSITION_BUTTON = {0};        //Save position button

//Initialize joystick variables
GPIO_Pin_TypeDef sJOSTICK_RIGHT_BUTTON = {0};        //Joystick right button
GPIO_Pin_TypeDef sJOSTICK_LEFT_BUTTON = {0};         //Joystick left button
GPIO_Pin_TypeDef sJOSTICK_DOWN_BUTTON = {0};         //Joystick down button
GPIO_Pin_TypeDef sJOSTICK_UP_BUTTON = {0};           //Joystick  up button

//Initialize Pins for LCD registers
GPIO_Pin_TypeDef sRS = {0};      //RS (Register select)
GPIO_Pin_TypeDef sRW = {0};      //RW (Read/Write Register)*always connect
GPIO_Pin_TypeDef sE = {0};       //E  (Enable)

//Initialize Pins for LCD data
GPIO_Pin_TypeDef sD0 = {0};      //Data 0
GPIO_Pin_TypeDef sD1 = {0};      //Data 1
GPIO_Pin_TypeDef sD2 = {0};      //Data 2
GPIO_Pin_TypeDef sD3 = {0};      //Data 3

//Initialize Pins for USART
GPIO_Pin_TypeDef sUsart1Tx= {0}; //USART Tx
GPIO_Pin_TypeDef sUsart1Rx= {0}; //USART Rx

//Unused pins

GPIO_Pin_TypeDef sPB12= {0};
//GPIO_Pin_TypeDef sPA8= {0};
GPIO_Pin_TypeDef sPA11= {0};
GPIO_Pin_TypeDef sPA12= {0};
GPIO_Pin_TypeDef sPA15= {0};
GPIO_Pin_TypeDef sPB9= {0};
GPIO_Pin_TypeDef sPC15= {0};
GPIO_Pin_TypeDef sPC14= {0};
GPIO_Pin_TypeDef sPC13= {0};


void GPIO_Init(void){  

	//Populate GPIO structure for State led
	sSTATE_LED.Port = GPIO_PORT_B;
	sSTATE_LED.Pin  = GPIO_PIN_11;
	sSTATE_LED.Mode =  GPIO_MODE_OUTPUT_LOW;
	sSTATE_LED.Config =  GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sSTATE_LED);

	//Populate GPIO structure for Reset led
	sRESET_LED.Port = GPIO_PORT_B;
	sRESET_LED.Pin  = GPIO_PIN_10;
	sRESET_LED.Mode =  GPIO_MODE_OUTPUT_LOW;
	sRESET_LED.Config =  GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sRESET_LED);

	//Populate GPIO structure for O/C Loop led
	sOPEN_CLOSE_LED.Port = GPIO_PORT_B;
	sOPEN_CLOSE_LED.Pin  = GPIO_PIN_1;
	sOPEN_CLOSE_LED.Mode =  GPIO_MODE_OUTPUT_LOW;
	sOPEN_CLOSE_LED.Config =  GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sOPEN_CLOSE_LED);

	//Populate GPIO structure for save position led
	sSAVE_POSITION_LED.Port = GPIO_PORT_B;
	sSAVE_POSITION_LED.Pin  = GPIO_PIN_0;
	sSAVE_POSITION_LED.Mode =  GPIO_MODE_OUTPUT_LOW;
	sSAVE_POSITION_LED.Config =  GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sSAVE_POSITION_LED);

	//Populate GPIO structure for reset button
	sRESET_BUTTON.Port = GPIO_PORT_A;
	sRESET_BUTTON.Pin  = GPIO_PIN_7;
	sRESET_BUTTON.Mode =  GPIO_MODE_INPUT;
	sRESET_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sRESET_BUTTON);

	//Populate GPIO structure for open/close button
	sOPEN_CLOSE_BUTTON.Port = GPIO_PORT_A;
	sOPEN_CLOSE_BUTTON.Pin  = GPIO_PIN_6;
	sOPEN_CLOSE_BUTTON.Mode =  GPIO_MODE_INPUT;
	sOPEN_CLOSE_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sOPEN_CLOSE_BUTTON);

	//Populate GPIO structure for close position send button
	sCLOSE_POSITION_SEND_BUTTON.Port = GPIO_PORT_A;
	sCLOSE_POSITION_SEND_BUTTON.Pin  = GPIO_PIN_5;
	sCLOSE_POSITION_SEND_BUTTON.Mode =  GPIO_MODE_INPUT;
	sCLOSE_POSITION_SEND_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sCLOSE_POSITION_SEND_BUTTON);

	//Populate GPIO structure for save position button
	sSAVE_POSITION_BUTTON.Port = GPIO_PORT_A;
	sSAVE_POSITION_BUTTON.Pin  = GPIO_PIN_4;
	sSAVE_POSITION_BUTTON.Mode =  GPIO_MODE_INPUT;
	sSAVE_POSITION_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sSAVE_POSITION_BUTTON);


	//Populate GPIO structure for Joystick right button
	sJOSTICK_RIGHT_BUTTON.Port = GPIO_PORT_A;
	sJOSTICK_RIGHT_BUTTON.Pin  = GPIO_PIN_8;//PA3
	sJOSTICK_RIGHT_BUTTON.Mode =  GPIO_MODE_INPUT;
	sJOSTICK_RIGHT_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sJOSTICK_RIGHT_BUTTON);

	//Populate GPIO structure for Joystick left button
	sJOSTICK_LEFT_BUTTON.Port = GPIO_PORT_A;
	sJOSTICK_LEFT_BUTTON.Pin  = GPIO_PIN_2;
	sJOSTICK_LEFT_BUTTON.Mode =  GPIO_MODE_INPUT;
	sJOSTICK_LEFT_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sJOSTICK_LEFT_BUTTON);

	//Populate GPIO structure for Joystick down button
	sJOSTICK_DOWN_BUTTON.Port = GPIO_PORT_A;
	sJOSTICK_DOWN_BUTTON.Pin  = GPIO_PIN_1;
	sJOSTICK_DOWN_BUTTON.Mode =  GPIO_MODE_INPUT;
	sJOSTICK_DOWN_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sJOSTICK_DOWN_BUTTON);

	//Populate GPIO structure for Joystick up button
	sJOSTICK_UP_BUTTON.Port = GPIO_PORT_A;
	sJOSTICK_UP_BUTTON.Pin  = GPIO_PIN_0;
	sJOSTICK_UP_BUTTON.Mode =  GPIO_MODE_INPUT;
	sJOSTICK_UP_BUTTON.Config =  GPIO_CNF_INPUT_PP;
	HAL_GPIO_Pin_Init(&sJOSTICK_UP_BUTTON);

	//Populate GPIO structure for D0 LCD data pin
	sD0.Port = GPIO_PORT_B;
	sD0.Pin = GPIO_PIN_5;
	sD0.Mode = GPIO_MODE_OUTPUT_LOW;
	sD0.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sD0);

	//Populate GPIO structure for D1 LCD data pin
	sD1.Port = GPIO_PORT_B;
	sD1.Pin = GPIO_PIN_6;
	sD1.Mode = GPIO_MODE_OUTPUT_LOW;
	sD1.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sD1);

	//Populate GPIO structure for D2 LCD data pin
	sD2.Port = GPIO_PORT_B;
	sD2.Pin = GPIO_PIN_7;
	sD2.Mode = GPIO_MODE_OUTPUT_LOW;
	sD2.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sD2);

	//Populate GPIO structure for D3 LCD data pin
	sD3.Port = GPIO_PORT_B;
	sD3.Pin = GPIO_PIN_8;
	sD3.Mode = GPIO_MODE_OUTPUT_LOW;
	sD3.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sD3);

	//Populate GPIO structure for RS LCD pin
	sRS.Port = GPIO_PORT_B;
	sRS.Pin = GPIO_PIN_14;
	sRS.Mode = GPIO_MODE_OUTPUT_LOW;
	sRS.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sRS);

	//Populate GPIO structure for RW LCD pin
	sRW.Port = GPIO_PORT_B;
	sRW.Pin = GPIO_PIN_13;
	sRW.Mode = GPIO_MODE_OUTPUT_LOW;
	sRW.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sRW);

	//Populate GPIO structure for E LCD  pin
	sE.Port = GPIO_PORT_B;
	sE.Pin = GPIO_PIN_15;
	sE.Mode = GPIO_MODE_OUTPUT_LOW;
	sE.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sE);

	//Populate GPIO structure for USART Tx pin
	sUsart1Tx.Port = GPIO_PORT_A;
	sUsart1Tx.Pin = GPIO_PIN_9;
	sUsart1Tx.Mode = GPIO_MODE_OUTPUT_MEDIUM;
	sUsart1Tx.Config = GPIO_CNF_AF_PP;
	HAL_GPIO_Pin_Init(&sUsart1Tx);


	//Populate GPIO structure for USART Rx pin 
	sUsart1Rx.Port = GPIO_PORT_A;
	sUsart1Rx.Pin = GPIO_PIN_10;
	sUsart1Rx.Mode = GPIO_MODE_OUTPUT_MEDIUM;
	sUsart1Rx.Config = GPIO_CNF_AF_PP;
	HAL_GPIO_Pin_Init(&sUsart1Rx);
 
	
	//UNUSED PINS
	
	sPB12.Port = GPIO_PORT_B;
	sPB12.Pin = GPIO_PIN_12;
	sPB12.Mode = GPIO_MODE_OUTPUT_LOW;
	sPB12.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPB12);
/*
	sPA8.Port = GPIO_PORT_A;
	sPA8.Pin = GPIO_PIN_8;
	sPA8.Mode = GPIO_MODE_OUTPUT_LOW;
	sPA8.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPA8);
*/
	sPA11.Port = GPIO_PORT_A;
	sPA11.Pin = GPIO_PIN_11;
	sPA11.Mode = GPIO_MODE_OUTPUT_LOW;
	sPA11.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPA11);

	sPA12.Port = GPIO_PORT_A;
	sPA12.Pin = GPIO_PIN_12;
	sPA12.Mode = GPIO_MODE_OUTPUT_LOW;
	sPA12.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPA12);

	sPA15.Port = GPIO_PORT_A;
	sPA15.Pin = GPIO_PIN_15;
	sPA15.Mode = GPIO_MODE_OUTPUT_LOW;
	sPA15.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPA15);

	sPB9.Port = GPIO_PORT_B;
	sPB9.Pin = GPIO_PIN_9;
	sPB9.Mode = GPIO_MODE_OUTPUT_LOW;
	sPB9.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPB9);


	sPC15.Port = GPIO_PORT_C;
	sPC15.Pin = GPIO_PIN_15;
	sPC15.Mode = GPIO_MODE_OUTPUT_LOW;
	sPC15.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPC15);

	sPC14.Port = GPIO_PORT_C;
	sPC14.Pin = GPIO_PIN_14;
	sPC14.Mode = GPIO_MODE_OUTPUT_LOW;
	sPC14.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPC14);

	sPC13.Port = GPIO_PORT_C;
	sPC13.Pin = GPIO_PIN_13;
	sPC13.Mode = GPIO_MODE_OUTPUT_LOW;
	sPC13.Config = GPIO_CNF_OUTPUT_PP;
	HAL_GPIO_Pin_Init(&sPC13);

}

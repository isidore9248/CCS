#include "ti_msp_dl_config.h"                 // Device header
#include "main.h"

void Key_Init(void)
{
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (DL_GPIO_readPins(KEY_KEY2_PORT, KEY_KEY2_PIN)==0)
	{
		delay_ms(20);
		while (DL_GPIO_readPins(KEY_KEY2_PORT, KEY_KEY2_PIN)==0);
		delay_ms(20);
		KeyNum = 1;
	}
	if (DL_GPIO_readPins(KEY_KEY3_PORT, KEY_KEY3_PIN)==0)
	{
		delay_ms(20);
		while (DL_GPIO_readPins(KEY_KEY3_PORT, KEY_KEY3_PIN)==0);
		delay_ms(20);
		KeyNum = 2;
	}
	if (DL_GPIO_readPins(KEY_KEY4_PORT, KEY_KEY4_PIN)==0)
	{
		delay_ms(20);
		while (DL_GPIO_readPins(KEY_KEY4_PORT, KEY_KEY4_PIN)==0);
		delay_ms(20);
		KeyNum = 3;
	}
	if (DL_GPIO_readPins(KEY_KEY5_PORT, KEY_KEY5_PIN)==0)
	{
		delay_ms(20);
		while (DL_GPIO_readPins(KEY_KEY5_PORT, KEY_KEY5_PIN)==0);
		delay_ms(20);
		KeyNum = 4;
	}
	// if (DL_GPIO_readPins(KEY2_PORT, DL_GPIO_PIN_21))
	// {
	// 	delay_ms(20);
	// 	while (DL_GPIO_readPins(KEY2_PORT, DL_GPIO_PIN_21));
	// 	delay_ms(20);
	// 	KeyNum = 2;
	// }
//	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0)
//	{
//		Delay_ms(20);
//		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0);
//		Delay_ms(20);
//		KeyNum = 3;
//	}
//	
	return KeyNum;
}

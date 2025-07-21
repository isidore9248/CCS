#include "ti_msp_dl_config.h"
#include "oled_software_i2c.h"
#include "clock.h"
void Serial_JY61P_Zero_Yaw(void){
    DL_UART_Main_transmitDataBlocking(UART_1_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X69);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X88);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XB5);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X01);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X04);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X00);
	delay_ms(100);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0XAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X00);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0X00);
	
}
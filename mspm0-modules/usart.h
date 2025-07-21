#ifndef __NUART_H
#define __NUART_H
#include "ti_msp_dl_config.h"

void UART_Init(void);
void uart0_send_char(char ch);
void uart_send_char(UART_Regs *port,char ch);
void uart0_send_string(char* str);
void uart_send_string(UART_Regs *port,char* str);
void UART_SendBytes(UART_Regs *port,uint8_t *ubuf, uint32_t len);
void UART_SendByte(UART_Regs *port,uint8_t data);
void UART1_Init(void);
uint8_t ucTemp;
uint8_t data1;
uint8_t data2;
#endif
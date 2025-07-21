#include "usart.h"
#include "JY61.h"
uint8_t ucTemp;
uint8_t data1;
uint8_t data2;
// void UART_Init(void)
// {
//     NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);//ÇåÖÐ¶Ï¹ÒÆð
// 	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);//Ê¹ÄÜ´®¿ÚÖÐ¶Ï
// }
void UART1_Init(void)
{
  DL_UART_clearInterruptStatus(UART_1_INST, DL_UART_INTERRUPT_RX); // 清除中断标志
    NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);//ÇåÖÐ¶Ï¹ÒÆð
    NVIC_SetPriority(UART_1_INST_INT_IRQN, 3); // 设置中断优先级
	NVIC_EnableIRQ(UART_1_INST_INT_IRQN);//
  DL_UART_enableInterrupt(UART_1_INST, DL_UART_INTERRUPT_RX); // 使能UART接收中断
  Serial_JY61P_Zero_Yaw();//Enable the Received Interrupt
}
//串口发送单个字符 Send a single character through the serial port
// void uart0_send_char(char ch)
// {
//     //当串口0忙的时候等待，不忙的时候再发送传进来的字符
// 		// Wait when serial port 0 is busy, and send the incoming characters when it is not busy
//     while( DL_UART_isBusy(UART_0_INST) == true );
//     //发送单个字符 Send a single character
//     DL_UART_Main_transmitData(UART_0_INST, ch);
// }

void uart_send_char(UART_Regs *port,char ch)
   { while( DL_UART_isBusy(port) == true );
    //发送单个字符 Send a single character
    DL_UART_Main_transmitData(port, ch);

}
// //串口发送字符串 Send string via serial port
// void uart0_send_string(char* str)
// {
//     //当前字符串地址不在结尾 并且 字符串首地址不为空
// 		// The current string address is not at the end and the string first address is not empty
//     while(*str!=0&&str!=0)
//     {
//         //发送字符串首地址中的字符，并且在发送完成之后首地址自增
// 				// Send the characters in the first address of the string, and increment the first address after sending.
//         uart0_send_char(*str++);
//     }
// }
void uart_send_string(UART_Regs *port,char* str)
{
 while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
				// Send the characters in the first address of the string, and increment the first address after sending.
        uart_send_char(UART_1_INST,*str++);
    }
}

void UART_SendBytes(UART_Regs *port,uint8_t *ubuf, uint32_t len)
{
  while(len--)
  {
    DL_UART_Main_transmitDataBlocking(port, *ubuf);
    ubuf++;
  }
}

/***************************************
º¯ÊýÃû:	void UART_SendByte(uint32_t port,uint8_t data)
ËµÃ÷: ·¢ËÍ1¸ö×Ö½Ú³¤¶ÈµÄÊý¾Ý
Èë¿Ú:	uint32_t port-´®¿ÚºÅ
			uint8_t data-´ý·¢ÉúÊý¾Ý
³ö¿Ú:	ÎÞ
±¸×¢:	ÎÞ
×÷Õß:	ÎÞÃû´´ÐÂ
***************************************/
void UART_SendByte(UART_Regs *port,uint8_t data)
{
  DL_UART_Main_transmitDataBlocking(port, data);//DL_UART_Main_transmitData(UART_0_INST, *buf);
}

//  volatile unsigned char uart_data = 0;
// //串口的中断服务函数 Serial port interrupt service function
// void UART_0_INST_IRQHandler(void)
// {
//     //如果产生了串口中断 If a serial port interrupt occurs
//     switch( DL_UART_getPendingInterrupt(UART_0_INST) )
//     {
//         case DL_UART_IIDX_RX://如果是接收中断 If it is a receive interrupt
//             //接发送过来的数据保存在变量中 The data sent is saved in the variable
//             uart_data = DL_UART_Main_receiveData(UART_0_INST);
//             //将保存的数据再发送出去 Send the saved data again
//             uart0_send_char(uart_data);
//             break;

//         default://其他的串口中断 Other serial port interrupts
//             break;
//     }
// }
// void UART_1_INST_IRQHandler(void)
// {
//     //如果产生了串口中断 If a serial port interrupt occurs
//     switch( DL_UART_getPendingInterrupt(UART_1_INST) )
//     {
//         case DL_UART_IIDX_RX://如果是接收中断 If it is a receive interrupt
//             //接发送过来的数据保存在变量中 The data sent is saved in the variable
//             uart_data = DL_UART_Main_receiveData(UART_1_INST);
//             //将保存的数据再发送出去 Send the saved data again
//             uart_send_char(UART_1_INST,uart_data);
//             break;

//         default://其他的串口中断 Other serial port interrupts
//             break;
//     }
// }



   // if(newDataReady) {
        //     // 主循环中处理数据转换
        //     // int16_t yaw_raw = (YawH << 8) | YawL;
        //     // Yaw = (float)yaw_raw / 32768.0f * 180.0f;
            
        //     // if(Yaw > 180) Yaw -= 360;
            
        //     // 主循环中更新显示
        //     OLED_ShowSignedNum(4,1, (int)Yaw, 4);
            
        //     newDataReady = 0;  // 清除标志
        // }



/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "main.h"
#include "oled_software_i2c.h"
#include "stdio.h"
#include "ti_msp_dl_config.h"

void OLED_ShowInit();
void OLED_show();

uint8_t oled_buffer[32];

uint32_t encoding_count0 = 0, encoding_count1 = 0;

void NVIC_Init(void) {
  NVIC_ClearPendingIRQ(GPIO_Encoder_GPIOB_INT_IRQN);
  NVIC_EnableIRQ(GPIO_Encoder_GPIOB_INT_IRQN);
}

int main(void) {
  SYSCFG_DL_init();
  SysTick_Init();
  /* Don't remove this! */
  Interrupt_Init();
  NVIC_Init();
  //* 硬件外设初始化
  MPU6050_Init();
  OLED_Init();

  DL_TimerG_startCounter(Motor_INST);
  Motor1_On();
  Motor2_On();

  OLED_ShowInit();

  while (1) {
    // OLED_show();
    // delay_ms(5000);
    // OLED_ShowString(1, 6, (uint8_t *)"finished", 16);
    Motor1_Off();
    Motor2_Off();

    OLED_ShowCount();
    OLED_ShowNum(0, 2, encoding_count0, 5, 16);
    OLED_ShowNum(0, 4, encoding_count1, 5, 16);
  }
}

void GROUP1_IRQHandler(void) {
  uint32_t interruptStatus = DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1);

  switch (interruptStatus) {

  case DL_INTERRUPT_GROUP1_IIDX_GPIOA:
    // #if defined GPIO_MPU6050_INT_IIDX
    //     Read_Quad();
    //     break;
    // #endif
    if ((DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_Encoder_EncoderA_PIN) &
         GPIO_Encoder_EncoderA_PIN) != 0) {
      encoding_count0++;
    }
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Encoder_EncoderA_PIN);
    break;
  case DL_INTERRUPT_GROUP1_IIDX_GPIOB:

    if ((DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_Encoder_EncoderB_PIN) &
         GPIO_Encoder_EncoderB_PIN) != 0) {
      encoding_count1++;
    }
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Encoder_EncoderB_PIN);

    break;
  default:
    break;
  }
}

void OLED_ShowInit() {
  OLED_Clear();
  OLED_ShowString(0, 0, (uint8_t *)"OLEDInit", 16);
  // OLED_ShowString(0, 2, (uint8_t *)"MPU6050 Init", 16);
  // OLED_ShowString(0, 4, (uint8_t *)"Motor Init", 16);
}

void OLED_show() {
  OLED_ShowString(0, 7, (uint8_t *)"MPU6050 Demo", 8);

  OLED_ShowString(0, 0, (uint8_t *)"Pitch", 8);
  OLED_ShowString(0, 2, (uint8_t *)" Roll", 8);
  OLED_ShowString(0, 4, (uint8_t *)"  Yaw", 8);

  OLED_ShowString(16 * 6, 3, (uint8_t *)"Accel", 8);
  OLED_ShowString(17 * 6, 4, (uint8_t *)"Gyro", 8);

  sprintf((char *)oled_buffer, "%-6.1f", pitch);
  OLED_ShowString(5 * 8, 0, oled_buffer, 16);
  sprintf((char *)oled_buffer, "%-6.1f", roll);
  OLED_ShowString(5 * 8, 2, oled_buffer, 16);
  sprintf((char *)oled_buffer, "%-6.1f", yaw);
  OLED_ShowString(5 * 8, 4, oled_buffer, 16);

  sprintf((char *)oled_buffer, "%6d", accel[0]);
  OLED_ShowString(15 * 6, 0, oled_buffer, 8);
  sprintf((char *)oled_buffer, "%6d", accel[1]);
  OLED_ShowString(15 * 6, 1, oled_buffer, 8);
  sprintf((char *)oled_buffer, "%6d", accel[2]);
  OLED_ShowString(15 * 6, 2, oled_buffer, 8);

  sprintf((char *)oled_buffer, "%6d", gyro[0]);
  OLED_ShowString(15 * 6, 5, oled_buffer, 8);
  sprintf((char *)oled_buffer, "%6d", gyro[1]);
  OLED_ShowString(15 * 6, 6, oled_buffer, 8);
  sprintf((char *)oled_buffer, "%6d", gyro[2]);
  OLED_ShowString(15 * 6, 7, oled_buffer, 8);
}

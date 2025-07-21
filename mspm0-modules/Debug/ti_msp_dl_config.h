/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for Motor */
#define Motor_INST                                                         TIMG0
#define Motor_INST_IRQHandler                                   TIMG0_IRQHandler
#define Motor_INST_INT_IRQN                                     (TIMG0_INT_IRQn)
#define Motor_INST_CLK_FREQ                                               125000
/* GPIO defines for channel 0 */
#define GPIO_Motor_C0_PORT                                                 GPIOB
#define GPIO_Motor_C0_PIN                                         DL_GPIO_PIN_10
#define GPIO_Motor_C0_IOMUX                                      (IOMUX_PINCM27)
#define GPIO_Motor_C0_IOMUX_FUNC                     IOMUX_PINCM27_PF_TIMG0_CCP0
#define GPIO_Motor_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_Motor_C1_PORT                                                 GPIOB
#define GPIO_Motor_C1_PIN                                         DL_GPIO_PIN_11
#define GPIO_Motor_C1_IOMUX                                      (IOMUX_PINCM28)
#define GPIO_Motor_C1_IOMUX_FUNC                     IOMUX_PINCM28_PF_TIMG0_CCP1
#define GPIO_Motor_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_10ms */
#define TIMER_10ms_INST                                                  (TIMA0)
#define TIMER_10ms_INST_IRQHandler                              TIMA0_IRQHandler
#define TIMER_10ms_INST_INT_IRQN                                (TIMA0_INT_IRQn)
#define TIMER_10ms_INST_LOAD_VALUE                                        (390U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C0
#define I2C_MPU6050_INST_IRQHandler                              I2C0_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C0_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_0
#define GPIO_I2C_MPU6050_IOMUX_SDA                                (IOMUX_PINCM1)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                 IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_1
#define GPIO_I2C_MPU6050_IOMUX_SCL                                (IOMUX_PINCM2)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                 IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_FREQUENCY                                           40000000
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM20)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM19)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM20_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM19_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_1_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group GPIO_MPU6050222 */
#define GPIO_MPU6050222_PORT                                             (GPIOA)

/* Defines for PIN_MPU6050_INT: GPIOA.23 with pinCMx 53 on package pin 24 */
// groups represented: ["GPIO_Encoder","GPIO_MPU6050222"]
// pins affected: ["EncoderA","PIN_MPU6050_INT"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_MPU6050222_PIN_MPU6050_INT_IIDX                (DL_GPIO_IIDX_DIO23)
#define GPIO_MPU6050222_PIN_MPU6050_INT_PIN                     (DL_GPIO_PIN_23)
#define GPIO_MPU6050222_PIN_MPU6050_INT_IOMUX                    (IOMUX_PINCM53)
/* Port definition for Pin Group BUZZER */
#define BUZZER_PORT                                                      (GPIOB)

/* Defines for BUZZER1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define BUZZER_BUZZER1_PIN                                       (DL_GPIO_PIN_4)
#define BUZZER_BUZZER1_IOMUX                                     (IOMUX_PINCM17)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOB)

/* Defines for PIN_OLED_SCL: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_OLED_PIN_OLED_SCL_PIN                               (DL_GPIO_PIN_9)
#define GPIO_OLED_PIN_OLED_SCL_IOMUX                             (IOMUX_PINCM26)
/* Defines for PIN_OLED_SDA: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_OLED_PIN_OLED_SDA_PIN                               (DL_GPIO_PIN_8)
#define GPIO_OLED_PIN_OLED_SDA_IOMUX                             (IOMUX_PINCM25)
/* Port definition for Pin Group GPIO_Motor1 */
#define GPIO_Motor1_PORT                                                 (GPIOB)

/* Defines for PIN_AIN1: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_Motor1_PIN_AIN1_PIN                                 (DL_GPIO_PIN_6)
#define GPIO_Motor1_PIN_AIN1_IOMUX                               (IOMUX_PINCM23)
/* Defines for PIN_AIN2: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_Motor1_PIN_AIN2_PIN                                (DL_GPIO_PIN_26)
#define GPIO_Motor1_PIN_AIN2_IOMUX                               (IOMUX_PINCM57)
/* Port definition for Pin Group GPIO_Motor2 */
#define GPIO_Motor2_PORT                                                 (GPIOB)

/* Defines for PIN_BIN1: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_Motor2_PIN_BIN1_PIN                                (DL_GPIO_PIN_14)
#define GPIO_Motor2_PIN_BIN1_IOMUX                               (IOMUX_PINCM31)
/* Defines for PIN_BIN2: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_Motor2_PIN_BIN2_PIN                                (DL_GPIO_PIN_16)
#define GPIO_Motor2_PIN_BIN2_IOMUX                               (IOMUX_PINCM33)
/* Defines for EncoderA: GPIOA.2 with pinCMx 7 on package pin 42 */
#define GPIO_Encoder_EncoderA_PORT                                       (GPIOA)
#define GPIO_Encoder_EncoderA_IIDX                           (DL_GPIO_IIDX_DIO2)
#define GPIO_Encoder_EncoderA_PIN                                (DL_GPIO_PIN_2)
#define GPIO_Encoder_EncoderA_IOMUX                               (IOMUX_PINCM7)
/* Defines for EncoderB: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_Encoder_EncoderB_PORT                                       (GPIOB)
// pins affected by this interrupt request:["EncoderB"]
#define GPIO_Encoder_GPIOB_INT_IRQN                             (GPIOB_INT_IRQn)
#define GPIO_Encoder_GPIOB_INT_IIDX             (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_EncoderB_IIDX                          (DL_GPIO_IIDX_DIO27)
#define GPIO_Encoder_EncoderB_PIN                               (DL_GPIO_PIN_27)
#define GPIO_Encoder_EncoderB_IOMUX                              (IOMUX_PINCM58)
/* Defines for TRACK0: GPIOB.25 with pinCMx 56 on package pin 27 */
#define TRACK_TRACK0_PORT                                                (GPIOB)
#define TRACK_TRACK0_PIN                                        (DL_GPIO_PIN_25)
#define TRACK_TRACK0_IOMUX                                       (IOMUX_PINCM56)
/* Defines for TRACK1: GPIOA.24 with pinCMx 54 on package pin 25 */
#define TRACK_TRACK1_PORT                                                (GPIOA)
#define TRACK_TRACK1_PIN                                        (DL_GPIO_PIN_24)
#define TRACK_TRACK1_IOMUX                                       (IOMUX_PINCM54)
/* Defines for TRACK2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define TRACK_TRACK2_PORT                                                (GPIOB)
#define TRACK_TRACK2_PIN                                        (DL_GPIO_PIN_24)
#define TRACK_TRACK2_IOMUX                                       (IOMUX_PINCM52)
/* Defines for TRACK3: GPIOB.13 with pinCMx 30 on package pin 1 */
#define TRACK_TRACK3_PORT                                                (GPIOB)
#define TRACK_TRACK3_PIN                                        (DL_GPIO_PIN_13)
#define TRACK_TRACK3_IOMUX                                       (IOMUX_PINCM30)
/* Defines for TRACK4: GPIOB.20 with pinCMx 48 on package pin 19 */
#define TRACK_TRACK4_PORT                                                (GPIOB)
#define TRACK_TRACK4_PIN                                        (DL_GPIO_PIN_20)
#define TRACK_TRACK4_IOMUX                                       (IOMUX_PINCM48)
/* Defines for TRACK5: GPIOB.18 with pinCMx 44 on package pin 15 */
#define TRACK_TRACK5_PORT                                                (GPIOB)
#define TRACK_TRACK5_PIN                                        (DL_GPIO_PIN_18)
#define TRACK_TRACK5_IOMUX                                       (IOMUX_PINCM44)
/* Defines for TRACK6: GPIOB.19 with pinCMx 45 on package pin 16 */
#define TRACK_TRACK6_PORT                                                (GPIOB)
#define TRACK_TRACK6_PIN                                        (DL_GPIO_PIN_19)
#define TRACK_TRACK6_IOMUX                                       (IOMUX_PINCM45)
/* Defines for KEY1: GPIOA.18 with pinCMx 40 on package pin 11 */
#define KEY_KEY1_PORT                                                    (GPIOA)
#define KEY_KEY1_PIN                                            (DL_GPIO_PIN_18)
#define KEY_KEY1_IOMUX                                           (IOMUX_PINCM40)
/* Defines for KEY2: GPIOA.15 with pinCMx 37 on package pin 8 */
#define KEY_KEY2_PORT                                                    (GPIOA)
#define KEY_KEY2_PIN                                            (DL_GPIO_PIN_15)
#define KEY_KEY2_IOMUX                                           (IOMUX_PINCM37)
/* Defines for KEY3: GPIOB.0 with pinCMx 12 on package pin 47 */
#define KEY_KEY3_PORT                                                    (GPIOB)
#define KEY_KEY3_PIN                                             (DL_GPIO_PIN_0)
#define KEY_KEY3_IOMUX                                           (IOMUX_PINCM12)
/* Defines for KEY4: GPIOA.17 with pinCMx 39 on package pin 10 */
#define KEY_KEY4_PORT                                                    (GPIOA)
#define KEY_KEY4_PIN                                            (DL_GPIO_PIN_17)
#define KEY_KEY4_IOMUX                                           (IOMUX_PINCM39)
/* Defines for KEY5: GPIOB.1 with pinCMx 13 on package pin 48 */
#define KEY_KEY5_PORT                                                    (GPIOB)
#define KEY_KEY5_PIN                                             (DL_GPIO_PIN_1)
#define KEY_KEY5_IOMUX                                           (IOMUX_PINCM13)
/* Defines for LED1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED_LED1_PORT                                                    (GPIOB)
#define LED_LED1_PIN                                            (DL_GPIO_PIN_22)
#define LED_LED1_IOMUX                                           (IOMUX_PINCM50)
/* Defines for LED2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define LED_LED2_PORT                                                    (GPIOA)
#define LED_LED2_PIN                                            (DL_GPIO_PIN_12)
#define LED_LED2_IOMUX                                           (IOMUX_PINCM34)
/* Defines for LED3: GPIOA.16 with pinCMx 38 on package pin 9 */
#define LED_LED3_PORT                                                    (GPIOA)
#define LED_LED3_PIN                                            (DL_GPIO_PIN_16)
#define LED_LED3_IOMUX                                           (IOMUX_PINCM38)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_Motor_init(void);
void SYSCFG_DL_TIMER_10ms_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_1_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */

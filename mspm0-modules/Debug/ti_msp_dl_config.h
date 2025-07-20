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

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_Motor_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */

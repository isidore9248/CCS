#include "main.h"
#include "oled_software_i2c.h"
#include "stdio.h"
#include "ti_msp_dl_config.h"

void OLED_ShowInit();
void OLED_show();

uint8_t oled_buffer[32];

uint32_t encoding_count0 = 0, encoding_count1 = 0;

uint8_t RollL, RollH, PitchL, PitchH, YawL, YawH, VL, VH, SUM;
// 新增：用于中断和主程序同步的标志位
volatile uint8_t dataUpdated = 0; 
// 修正：用volatile修饰中断中修改的变量
volatile float Pitch, Roll, Yaw; 
#define WAIT_HEADER1 0
#define WAIT_HEADER2 1
#define RECEIVE_DATA 2
int regcountnow=0;
int regcountbefore=0;
uint8_t RxState = WAIT_HEADER1;
uint8_t receivedData[9];
uint8_t dataIndex = 0;
int jy61state=0;
volatile uint8_t newDataReady = 0;  // 新数据就绪标志
//陀螺仪0-360

uint8_t TRACK0;
uint8_t TRACK1;
uint8_t TRACK2;
uint8_t TRACK3;
uint8_t TRACK4;
uint8_t TRACK5;
uint8_t TRACK6;
// uint8_t TRACK7;

uint16_t times;
uint16_t lasttimes;
uint8_t shu;
 
void NVIC_Init(void) {
  NVIC_ClearPendingIRQ(GPIO_Encoder_GPIOB_INT_IRQN);
  NVIC_EnableIRQ(GPIO_Encoder_GPIOB_INT_IRQN);//group1 inint

  NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
	NVIC_EnableIRQ(UART_1_INST_INT_IRQN);//uart1 init

  NVIC_ClearPendingIRQ(TIMER_10ms_INST_INT_IRQN);//开启10ms中断
  NVIC_EnableIRQ(TIMER_10ms_INST_INT_IRQN);
  DL_TimerG_startCounter(TIMER_10ms_INST); //time init
    
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
  UART1_Init();

  DL_TimerG_startCounter(Motor_INST);
  Motor1_On();
  Motor2_On();

  OLED_ShowInit();

  LED1_OFF();
   LED2_OFF();
    LED3_OFF();
Buzzer_OFF();
  while (1) {
    // OLED_show();
    // delay_ms(5000);
    // OLED_ShowString(1, 6, (uint8_t *)"finished", 16);
    // Motor1_Off();
    // Motor2_Off();

    // OLED_ShowCount();
    // OLED_ShowNum(0, 2, encoding_count0, 5, 16);
    // OLED_ShowNum(0, 4, encoding_count1, 5, 16);
    OLED_ShowNum(2, 6, Yaw, 9, 16);
    // OLED_ShowNum(2, 6, yaw_raw, 9, 16);

    // Get_Infrared_State();
    // OLED_ShowNum(0, 2, TRACK1, 5, 16);
    // OLED_ShowNum(0, 4, TRACK0, 5, 16);
    switch (Key_GetNum())
    {
      case 1:
      LED1_ON();
      break;
      case 2:
      LED2_ON();
      break;
      case 3:
      LED3_ON();
      break;
      case 4:
      Buzzer_ON();
      break;
      default:  
              break;
    }

if(times - lasttimes >= 5) 
  {
    shu++;
    lasttimes = times;
    }
    OLED_ShowNum(0, 4, shu, 5, 16);

  }
}

void TIMER_50ms_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_10ms_INST))
     {
        case DL_TIMER_IIDX_ZERO:
        {
          times++;
        }
        break;
        default:
        break;
    }
}

void UART1_IRQHandler(void) {
    switch(DL_UART_getPendingInterrupt(UART_1_INST)) {
        case DL_UART_IIDX_RX: {
            uint8_t uartdata = DL_UART_Main_receiveData(UART_1_INST);
            
            switch(RxState) {
                case WAIT_HEADER1:
                    if(uartdata == 0x55) RxState = WAIT_HEADER2;
                    break;
                    
                case WAIT_HEADER2:
                    if(uartdata == 0x53) {
                        RxState = RECEIVE_DATA;
                        dataIndex = 0;
                    } else {
                        RxState = WAIT_HEADER1;
                    }
                    break;
                    
                case RECEIVE_DATA:
                    receivedData[dataIndex++] = uartdata;
                    if(dataIndex >= 9) {
                        // 仅保存原始数据
                        RollL = receivedData[0];
                        RollH = receivedData[1];
                        PitchL = receivedData[2];
                        PitchH = receivedData[3];
                        YawL = receivedData[4];
                        YawH = receivedData[5];
                        
                        int16_t yaw_raw = (YawH << 8 | YawL)/32768.0*180;//0-360
                        Yaw = (float)yaw_raw;//(float)yaw_raw / 32768.0f * 180.0f;
                        // if(Yaw>=180)  Yaw -= 360;
                        
                        //  if(Yaw > 180)  Yaw -= 360;
                        //  if(Yaw < -180) Yaw += 360;
                        // 设置数据就绪标志
                        newDataReady = 1;
                        
                        RxState = WAIT_HEADER1;
                    }
                    break;
            }
            break;
        }
        
        default:
            break;
    }
}
//以上为JY61初始化

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
  // OLED_ShowString(0, 0, (uint8_t *)"OLEDInit", 16);
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

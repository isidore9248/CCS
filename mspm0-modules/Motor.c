#include "Motor.h" // Include the Motor header
#include "ti_msp_dl_config.h"

void Motor1_On(void) {
  DL_GPIO_setPins(GPIO_Motor1_PORT, GPIO_Motor1_PIN_AIN1_PIN);
  DL_GPIO_clearPins(GPIO_Motor1_PORT, GPIO_Motor1_PIN_AIN2_PIN);
}

void Motor1_Off(void) {
  DL_GPIO_clearPins(GPIO_Motor1_PORT, GPIO_Motor1_PIN_AIN2_PIN);
  DL_GPIO_clearPins(GPIO_Motor1_PORT, GPIO_Motor1_PIN_AIN1_PIN);
}

void Motor1_setSpeed(uint32_t speed1) {
  DL_TimerG_setCaptureCompareValue(Motor_INST, speed1, DL_TIMER_CC_0_INDEX);
}

void Motor2_On(void) {
  DL_GPIO_setPins(GPIO_Motor2_PORT,
                  GPIO_Motor2_PIN_BIN2_PIN); // Assuming BIN1 for Motor2
  DL_GPIO_clearPins(GPIO_Motor2_PORT,
                    GPIO_Motor2_PIN_BIN1_PIN); // Assuming BIN2 for Motor2
}

void Motor2_Off(void) {
  DL_GPIO_clearPins(GPIO_Motor2_PORT,
                    GPIO_Motor2_PIN_BIN1_PIN); // Assuming BIN1 for Motor2
  DL_GPIO_clearPins(GPIO_Motor2_PORT,
                    GPIO_Motor2_PIN_BIN2_PIN); // Assuming BIN2 for Motor2
}

void Motor2_setSpeed(uint32_t speed2) {
  DL_TimerG_setCaptureCompareValue(Motor_INST, speed2, DL_TIMER_CC_1_INDEX);
}

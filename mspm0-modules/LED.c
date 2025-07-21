#include "ti_msp_dl_config.h"
#include "main.h"
void LED1_OFF()
{
    DL_GPIO_clearPins(LED_LED1_PORT,LED_LED1_PIN);
}
void LED2_OFF()
{
    DL_GPIO_setPins(LED_LED2_PORT,LED_LED2_PIN);
}
void LED3_OFF()
{
    DL_GPIO_setPins(LED_LED3_PORT,LED_LED3_PIN);
}



void LED1_ON()
{
    DL_GPIO_setPins(LED_LED1_PORT,LED_LED1_PIN);
}
void LED2_ON()
{
    DL_GPIO_clearPins(LED_LED2_PORT,LED_LED2_PIN);
}
void LED3_ON()
{
    DL_GPIO_clearPins(LED_LED3_PORT,LED_LED3_PIN);
}
void LED1_turn()
{
LED1_ON();
delay_ms(100);
LED1_OFF();
// DL_GPIO_togglePins(LED_LED1_PORT,LED_LED1_PIN);
}
void LED2_turn()
{
LED2_ON();
delay_ms(100);
LED2_OFF();
}
void LED3_turn()
{
LED3_ON();
delay_ms(100);
LED3_OFF();
}
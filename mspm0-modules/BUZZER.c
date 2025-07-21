#include "main.h"
void Buzzer_ON()
{
    DL_GPIO_setPins(BUZZER_PORT,BUZZER_BUZZER1_PIN);
}
void Buzzer_OFF()
{
    DL_GPIO_clearPins(BUZZER_PORT,BUZZER_BUZZER1_PIN);
}
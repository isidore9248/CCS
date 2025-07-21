#ifndef __TRACK_H
#define __TRACK_H
#include "main.h"

uint8_t Get_Infrared_State(void);

float Track_err(void);
int PID_out(float error,int Target);//poistion_pid:Èë¿Ú²ÎÊý£º1.Ñ­¼£Ä£¿é·µ»ØµÄÎó²î;2.Ä¿±êÎó²î£¬Ò²¾ÍÊÇ0£¬ÈÃÐ¡³µÔÚÏßµÄÖÐ¼ä
// void Final_Speed(int pid_out ,int base_speed);



#endif

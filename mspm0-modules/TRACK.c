#include "main.h"
#include "TRACK.h"

extern uint8_t TRACK0;
extern uint8_t TRACK1;
extern uint8_t TRACK2;
extern uint8_t TRACK3;
extern uint8_t TRACK4;
extern uint8_t TRACK5;
extern uint8_t TRACK6;
// extern uint8_t TRACK7;

	
uint8_t Get_Infrared_State(void)
{	 uint8_t state = 0;

    if(DL_GPIO_readPins(TRACK_TRACK0_PORT, TRACK_TRACK0_PIN)) {TRACK0 = 1;} else {TRACK0 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK1_PORT, TRACK_TRACK1_PIN)) {TRACK1 = 1;} else {TRACK1 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK2_PORT, TRACK_TRACK2_PIN)) {TRACK2 = 1;} else {TRACK2 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK3_PORT, TRACK_TRACK3_PIN)) {TRACK3 = 1;} else {TRACK3 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK4_PORT, TRACK_TRACK4_PIN)) {TRACK4 = 1;} else {TRACK4 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK5_PORT, TRACK_TRACK5_PIN)) {TRACK5 = 1;} else {TRACK5 = 0;}
    if(DL_GPIO_readPins(TRACK_TRACK6_PORT, TRACK_TRACK6_PIN)) {TRACK6 = 1;} else {TRACK6 = 0;}

    state=(uint8_t)(TRACK0|TRACK1|TRACK2|TRACK3|TRACK4|TRACK5|TRACK6);
    return state;
//    u8 state1=0; 
//    if(TRACK1==0||TRACK2==0||TRACK3==0||TRACK4==0||TRACK5==0||TRACK6==0||TRACK7==0)//4 5É¨Ãè
//    return state1;
}

float error;
//int PID_out;

#define Kp    4
#define Kd    3

float Track_err(void)
{
	uint8_t state =  Get_Infrared_State();
	//³µÔÚÏßµÄÓÒ±ßerrÎªÕýÖµ£¬×ó±ßÎª¸ºÊý
	switch(state)
	{  

		case 0:   //0000 0000   
		error= 0 ;	  break;
		case 16:   //0001 0000   
		error= 0 ;	  break;
		case 8:   //0000 1000   
		error= 0 ;	  break;	
		case 24:   //0001 1000   
		error= 0 ;	  break;		
		case 60:   //0011 1100   
		error= 0 ;	  break;		
		case 126:   //0111 1110   
		error= 0 ;	  break;
		
		case 48:   //0011 0000   //Ð¡³µÓÒÆ«£¬errÎªÕý
		error= 2.5  ;	  break;
		case 32:   //0010 0000   
		error= 3 ;	  break;
		case 64:   //0100 0000   
		error= 5 ;	  break;
		case 96:   //0110 0000   
		error= 4.5 ;	  break;
		case 128:   //1000 0000   
		error= 10 ;	  break;	
		case 192:   //1100 0000   
		error= 6.5 ;	  break;


		
		case 12:   //0000 1100   //Ð¡³µ×óÆ«£¬errÎª¸º
		error= -2.5 ;	  break;		
		case 4:   //0000 0100   
		error= -3 ;	  break;		
		case 2:   //0000 0010   
		error= -5 ;	  break;
		case 6:   //0000 0110   
		error= -4.5 ;	  break;
		case 1:   //0000 0001   
		error= -10 ;	  break;
		case 3:   //0000 0011   
		error= -6.5 ;	  break;
		
		
		default: 
		error=0;   break;
	}
	return error;
}






int PID_out(float error,int Target)//poistion_pid:Èë¿Ú²ÎÊý£º1.Ñ­¼£Ä£¿é·µ»ØµÄÎó²î;2.Ä¿±êÎó²î£¬Ò²¾ÍÊÇ0£¬ÈÃÐ¡³µÔÚÏßµÄÖÐ¼ä+Ki*add_err
{
    int err=error;
    int last_err;
	int out;
	int add_err;
	add_err+=err;
	out=Kp*err+Kd*(err-last_err);
	last_err=err;
	return out;
}

// void Final_Speed(int pid_out ,int base_speed)
// {

//   Set_Speed(base_speed-pid_out,base_speed+pid_out);

// }
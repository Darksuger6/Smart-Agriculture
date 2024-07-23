#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#include "oled.h"
#include "dht11.h"
#include "adc.h"
#include "relay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/03
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  
extern u8 Autoflag;
extern u8 Soilkey;
extern u8 Lightkey;

extern int Soilvalue;
extern int Lightvalue;

void TIM3_Int_Init(u16 arr,u16 psc); 
void TIM2_Int_Init(u16 arr,u16 psc); 
#endif

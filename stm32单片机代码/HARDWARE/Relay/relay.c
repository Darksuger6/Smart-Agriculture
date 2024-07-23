#include "stm32f10x.h"
#include "relay.h"
                             //�̵�����ʹ��io��
void Relay_init(void)
{ 
	 GPIO_InitTypeDef relay_init;
   //ʹ��GPIO��ʱ�� APB2   //rcc.h
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

   //ʹ��GPIO�ṹ��
	  
	   relay_init.GPIO_Mode   =GPIO_Mode_Out_PP;
	   relay_init.GPIO_Pin    =GPIO_Pin_13 | GPIO_Pin_14;  //PB13���� PB14��ˮ
	   relay_init.GPIO_Speed  =GPIO_Speed_10MHz;
	   GPIO_Init(GPIOC,&relay_init);
}

void SoilRelayOn(void)  
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);
}

void SoilRelayOff(void)  
{
	GPIO_SetBits(GPIOC,GPIO_Pin_14);
}

void LightRelayOn(void)  
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
}
void LightRelayOff(void)  
{
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
}

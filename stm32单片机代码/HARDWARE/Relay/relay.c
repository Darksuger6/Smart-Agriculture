#include "stm32f10x.h"
#include "relay.h"
                             //继电器的使能io口
void Relay_init(void)
{ 
	 GPIO_InitTypeDef relay_init;
   //使能GPIO的时钟 APB2   //rcc.h
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

   //使能GPIO结构体
	  
	   relay_init.GPIO_Mode   =GPIO_Mode_Out_PP;
	   relay_init.GPIO_Pin    =GPIO_Pin_13 | GPIO_Pin_14;  //PB13补光 PB14补水
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

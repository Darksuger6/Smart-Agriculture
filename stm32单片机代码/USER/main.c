#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "dht11.h"
#include "adc.h"
#include "oled.h"
#include "esp8266.h"
#include "onenet.h"
#include "timer.h"
#include "relay.h"

//int shidu;
//int guangzhao;
float temp_avrg=0;               
//u8 DHT11_Temp,DHT11_Hum;	

const char *topics[] = {"Agricultural"};

u8 Autokey = 0;
u8 Soilkey = 0;
u8 Lightkey = 0;


int Soilvalue = 5;
int Lightvalue = 60;

unsigned short timeCount = 0;	//发送间隔变量
	
unsigned char *dataPtr = NULL;

int main(void)
{	
	

	delay_init();
	Adc_Init();
	Relay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
	DHT11_Init();
	OLED_Init();
	OLED_Clear();
	TIM2_Int_Init(4999,7999);
	TIM3_Int_Init(2999,7999);
	Usart1_Init(115200);//Debug串口调试
	Usart2_Init(115200);//ESP8266串口通信
	UsartPrintf(USART_DEBUG, " Hardware init OK\r\n");

	
	ESP8266_Init();
	while(OneNet_DevLink())			//接入OneNET
	delay_ms(500);

	OneNet_Subscribe(topics, 1);
	
while(1)
		{   
			DHT11_Read_Data();
			Adc_Read_Data();
			
			if(Autokey == 0)
			{
				//UsartPrintf(USART_DEBUG ,"111111111\r\n");
				if(Lightkey == 0) LightRelayOff();
				if(Lightkey == 1) LightRelayOn();
				if(Soilkey == 0) SoilRelayOff();
				if(Soilkey == 1) SoilRelayOn();
			}
			if(Autokey == 1)	//×Ô¶¯¿ØÖÆÏÂ£¬µÍÓÚãÐÖµ×Ô¶¯²¹¹â²¹Ë®
			{
				if(Soilvalue >= adc_info.Soil)
				{
					Soilkey = 1;
					SoilRelayOn();//GPIO_ResetBits(GPIOC, GPIO_Pin_14);//
				}
				if(Soilvalue < adc_info.Soil)
				{
					Soilkey = 0;
					SoilRelayOff();//GPIO_SetBits(GPIOC, GPIO_Pin_14);//
				}					
				
				if(Lightvalue >= adc_info.Light)
				{
					Lightkey = 1;
					LightRelayOn();//GPIO_ResetBits(GPIOC, GPIO_Pin_13); //
				}
				if(Lightvalue < adc_info.Light)
				{
					Lightkey = 0;
					LightRelayOff();//GPIO_SetBits(GPIOC, GPIO_Pin_13);//
				}					
			}
			
			
			if(timeCount % 40 == 0) //1000 / 25 = 40,间隔一秒发送一次数据
			{
				
				UsartPrintf(USART_DEBUG ,"温度:%d  湿度:%d  土壤湿度:%d 光照强度:%d  \r\n",dht11_info.tempreture,dht11_info.humidity,adc_info.Soil,adc_info.Light);
				UsartPrintf(USART_DEBUG ,"土壤湿度阈值:%d  光照强度阈值:%d  补光:%d 补水:%d  \r\n",Soilvalue,Lightvalue,Lightkey,Soilkey);
				UsartPrintf(USART_DEBUG ,"自动控制:%d \r\n",Autokey);
			}
			
			
			if(++timeCount >= 40)		//发送间隔5s，5000ms / 25 = 200
			{
				UsartPrintf(USART_DEBUG, "OneNet_SendData\r\n");
				
				OneNet_SendData();
				
				timeCount = 0;
				ESP8266_Clear();
			}
			
			dataPtr = ESP8266_GetIPD(3); // 3*5 + 10ms
			if(dataPtr != NULL)
			OneNet_RevPro(dataPtr);
			delay_ms(10);				
			
	}
	
}

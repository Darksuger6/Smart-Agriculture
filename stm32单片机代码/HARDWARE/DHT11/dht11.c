#include "dht11.h"
#include "delay.h"

//u8 temp;
//u8 humi;
DHT11_INFO dht11_info;
//初始化DHT11
//返回：初始化的状态（应答信号）
u8 DHT11_Init()
{
	GPIO_InitTypeDef GPIO_InitStruce;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);		//利用引脚PB0
	
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruce.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruce);
 
	DHT11_Rst();
	return DHT11_Check();
}
 
//复位DHT11
void DHT11_Rst(void)	   
{                 
    DHT11_IO_OUT(); 	//SET OUTPUT
    DHT11_DQ_OUT=0; 	//拉低DQ
    delay_ms(20);    	//拉低至少18ms
    DHT11_DQ_OUT=1; 	//DQ=1 
    delay_us(30);     	//主机拉高20~40us
}
 
//等待DHT11的回应
//返回1:未检测到DHT11的存在
//返回0:存在
u8 DHT11_Check(void) 	   
{   
   u8 retry=0;
   DHT11_IO_IN();//SET INPUT	 
   while (DHT11_DQ_IN&&retry<100)//DHT11会拉低40~80us
   {
		retry++;   
		delay_us(1);
   };	 
   if(retry>=100)return 1;
   else retry=0;
   while (!DHT11_DQ_IN&&retry<100)//DHT11拉低后会再次拉高40~80us
   {
       retry++;  
	   delay_us(1);
   };
   if(retry>=100)return 1;	    
   return 0;
}
 
//从DHT11读取一个位   
//返回值：1/0
u8 DHT11_Read_Bit(void) 			 
{
      u8 retry=0;
      while(DHT11_DQ_IN&&retry<100)//等待变为低电平
      {
             retry++;   
             delay_us(1);
       }
      retry=0;
      while(!DHT11_DQ_IN&&retry<100)//等待变高电平
       {
              retry++;	
              delay_us(1);
         }
      delay_us(40);//等待40us
      if(DHT11_DQ_IN)
		  return 1;
      else 
		  return 0;		   
}
 
//从DHT11读取一个字节
//返回值：读到的数据
u8 DHT11_Read_Byte(void)    
{        
    u8 i,dat;
    dat=0;
   for (i=0;i<8;i++) 
  {
      dat<<=1; 
     dat|=DHT11_Read_Bit();
    }				    
    return dat;
}
 
//从DHT11读取一次数据
//temp:温度值(范围:0~50°)     humi:湿度值(范围:20%~90%)
//返回值：0,正常;1,读取失败
u8 DHT11_Read_Data(void)    
{        
    u8 buf[5];
    u8 i;
    DHT11_Rst();
    if(DHT11_Check()==0)
   {
          for(i=0;i<5;i++)//读取40位数据
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			dht11_info.humidity=buf[0];
			dht11_info.tempreture=buf[2];
		}
	}else return 1;
	return 0;	    
}
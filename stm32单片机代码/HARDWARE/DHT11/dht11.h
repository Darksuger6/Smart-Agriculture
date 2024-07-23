#ifndef __DHT11_H
#define __DHT11_H   
#include "sys.h"
 

#define DHT11_IO_IN()  {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=8<<0;}
#define DHT11_IO_OUT() {GPIOB->CRL&=0XFFFFFFF0;GPIOB->CRL|=3<<0;}
										   
#define	DHT11_DQ_OUT PBout(0) //????	PB0
#define	DHT11_DQ_IN  PBin(0)  //????	PB0 
 
//extern u8 temp;
//extern u8 humi;

typedef struct
{

	u8 tempreture;
	u8 humidity;

} DHT11_INFO;

extern DHT11_INFO dht11_info;

u8 DHT11_Init(void);
u8 DHT11_Read_Data(void);
u8 DHT11_Read_Byte(void);
u8 DHT11_Read_Bit(void);
void DHT11_Rst(void);
u8 DHT11_Check(void);
 
#endif
 
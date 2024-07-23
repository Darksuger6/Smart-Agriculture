#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"

typedef struct
{

	u8 Soil;
	u8 Light;

} ADC_INFO;
extern ADC_INFO adc_info;

//正点原子的adc采集代码
void Adc_Init(void);
u16  Get_Adc(u8 ch); 
u16 Get_Adc_Average(u8 ch,u8 times);
u8 Adc_Read_Data(void);
extern float temp_avrg;
//extern int shidu;
 
#endif 

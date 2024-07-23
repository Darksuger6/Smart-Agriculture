#include "stm32f10x.h"
//#define JDQ_BG PCout(13)	//远程控制补光

//#define JDQ_BS PCout(14)	//远程控制补水

//#define SoilRelay PCout(14)   //远程控制补光
//#define LightRelay PCout(13)	//远程控制补水

void Relay_init(void);

void SoilRelayOn(void);
void SoilRelayOff(void);
void LightRelayOn(void);
void LightRelayOff(void);
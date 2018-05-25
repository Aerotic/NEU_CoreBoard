#ifndef _USART2_H_
#define _USART2_H_

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include <stdio.h>
extern u8 USART_RX_TEST;
void USART2_Config(void);
void USART2_IRQHandler(void);
//void USART3_IRQHandler(void);  
#endif /*_Dbus_H*/

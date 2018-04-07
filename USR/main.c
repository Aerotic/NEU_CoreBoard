/*
*Author: NEU_Aeroman  东北大学陈刚团队 胡韬
*Date: 20180127
*Description: main() of this STM32F4 project
*/

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "usart2.h"

int main(void)
{	
	Usart2_Config();
//	Usart2_SendChar(0xff);
//	Usart2_SendChar(0xff);
//	Usart2_SendChar(0xff);
//	Usart2_SendChar(0xff);
//	Usart2_SendChar(0xff);
	printf("Successfully print string via serial");
	while(1){
	}
}

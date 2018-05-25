#include "usart2.h"
#if 1
#pragma import(__use_no_semihosting)                             
struct __FILE 
{ 
	int handle; 

}; 
FILE __stdout;       
    
int fputc(int ch, FILE *f)
{      
	while((USART2->SR&0X40)==0);  
    USART2->DR = (u8) ch;      
	return ch;
}
#endif 

u8 USART_RX_TEST;
void USART2_Config()
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
		
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2 ,GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3 ,GPIO_AF_USART3);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	USART_DeInit(USART2);
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART2,&USART_InitStructure);
  USART_Cmd(USART2,ENABLE);
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);  
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);		
		
}
void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET){
			USART_RX_TEST = USART_ReceiveData(USART2);
			printf("Received data is %c\n",USART_RX_TEST);		
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}
//				USART_RX_TEST = USART_GetITStatus(USART2, USART_IT_RXNE);//USART_ReceiveData(USART2);
//	USART_RX_TEST += 3;
}

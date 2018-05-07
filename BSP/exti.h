#ifndef _EXTI_H_
#define _EXTI_H_
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define EXTI_RCC		RCC_AHB1Periph_GPIOC
#define EXTI_PORT		GPIOC
#define	EXTI_PIN		GPIO_Pin_4
#define EXTI_PUPD 	GPIO_PuPd_UP
#define EXTI_TRIGG  EXTI_Trigger_Falling
#define EXTI_LINE 	EXTI_Line4
#define EXTI_CH			EXTI4_IRQn 

void Exti_Init(void);

void EXTI4_IRQHandler(void);
#endif /* _EXTI_H_ */
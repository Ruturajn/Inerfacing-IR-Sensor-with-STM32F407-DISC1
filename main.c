#include<stm32f4xx.h>
#define ARM_MATH_CM4

void GPIO_Init();
void EXTI0_Init();
void TIM3_ms_Delay(uint8_t delay);
void NVIC_Init();
void EXTI0_IRQHandler();

void GPIO_Init(){
	RCC->AHB1ENR |= 1;// Enable the GPIO port A clock
	GPIOA->MODER |= (1<<14); //Configuring PA7 as output, if external LED needs to be connected

	//Since we require PA0 to be input we do no make any changes to GPIOA->MODER
}

void TIM3_ms_Delay(uint8_t delay){
	RCC->APB1ENR |= (1<<1);
	TIM3->PSC = 16000-1;
	TIM3->ARR = (int)delay;
	TIM3->CNT = 0;
	TIM3->CR1 |= 1;
	while(!(TIM3->SR & 1)){}
	TIM2->SR &= ~(0x0001); //Reset the update interrupt flag
}

void EXTI0_Init(){
	EXTI->IMR |= 1;// Interrupt is not masked on EXTI line 0 (Enabled Interrupt)
	EXTI->FTSR |= 1;// Falling Edge trigger Enabled for the interrupt
}

void NVIC_Init(){
	NVIC->ISER[0] |= 1<<6;// Setting the EXTI0 interrupt
}

void EXTI0_IRQHandler( )
{
	GPIOA->ODR ^= (1<<7);
	EXTI->PR |= 1;

}

int main(){
	GPIO_Init();
	EXTI0_Init();
	NVIC_Init();
	while(1){}
}

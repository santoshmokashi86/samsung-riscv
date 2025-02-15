#include <ch32v00x.h>
#include <debug.h>


#define LED1_PORT GPIOD
#define LED1_PIN  GPIO_Pin_6
#define LED1_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void My_Delay_Ms(uint32_t n);

int main(void)
{
    SystemCoreClockUpdate();
    LED1_CLOCK_ENABLE;

    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = LED1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED1_PORT, &GPIO_InitStructure);

    while (1)
    {
        GPIO_SetBits(LED1_PORT, LED1_PIN);  // Turn ON
        My_Delay_Ms(100);  // 
        GPIO_ResetBits(LED1_PORT, LED1_PIN); // Turn OFF
        My_Delay_Ms(100);  // 
    }
}

// Simple delay function
void My_Delay_Ms(uint32_t n)
{
    for (volatile uint32_t i = 0; i < (n * 4000); i++);
}

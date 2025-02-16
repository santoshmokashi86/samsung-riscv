#include <stdint.h>
#include <ch32v00x.h>
#include <debug.h>

#define BLINKY_GPIO_PORT GPIO_PORTD
#define BLINKY_GPIO_PIN (1 << 6)
#define PIR_GPIO_PIN (1 << 2) // PIR sensor output connected to GPIO Pin 2

void Delay_Ms(uint32_t n);

int main(void)
{
    SystemInit();

    // Configure GPIO for LED output
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

    // Configure PIR sensor input pin
    GPIO_InitStructure.GPIO_Pin = PIR_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input mode with pull-up
    GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

    while (1)
    {
        // Read PIR sensor status
        uint8_t pirStatus = GPIO_ReadInputDataBit(BLINKY_GPIO_PORT, PIR_GPIO_PIN);

        // Control the LED based on PIR sensor output
        if (pirStatus)
        {
            GPIO_SetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN); // Turn on LED
        }
        else
        {
            GPIO_ResetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN); // Turn off LED
        }

        Delay_Ms(1000);
    }
}

void Delay_Ms(uint32_t n)
{
    for (volatile uint32_t i = 0; i < n * 1000; i++)
        ;
}

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
    while (1)
    {
    }
}

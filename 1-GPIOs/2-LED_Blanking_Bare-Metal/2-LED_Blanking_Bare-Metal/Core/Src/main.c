#include "stm32g474xx.h"

void delay(volatile uint32_t t)
{
    while(t--);
}

int main(void)
{
    /* Enable GPIOF clock */
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN;

    /* PF2 output */
    GPIOF->MODER &= ~(3U << (2 * 2));
    GPIOF->MODER |=  (1U << (2 * 2));

    /* Push-pull */
    GPIOF->OTYPER &= ~(1U << 2);

    /* LED OFF initially (PF2 = 1) */
    GPIOF->BSRR = ~(1U << 2);

    while (1)
    {
        /* LED ON (PF2 = 0) */
        GPIOF->BSRR = (1U << (2 + 16));
        delay(800000);

        /* LED OFF (PF2 = 1) */
        GPIOF->BSRR = (1U << 2);
        delay(800000);
    }
}

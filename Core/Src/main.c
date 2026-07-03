#include "stm32f1xx.h"
#include "lmb162a.h"
#include <stdint.h>
#include "main.h"

int main()
{
    enable_rcc_for_gpio();

    configure_onboard_led();

    lcd_init();

    char character = 0xA2;
    lcd_send_char(character);

    return 0;
}

void configure_onboard_led()
{
    GPIOC->CRH &= ~(0xFu << 20);
    GPIOC->CRH |= (0x2u << 20);

    GPIOC->BSRR = (1u << (13 + 16));
}

void enable_rcc_for_gpio()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}
#include "stm32f1xx.h"
#include "lmb162a_config.h"
#include <stdint.h>
#include "main.h"

int main()
{
    enable_rcc();

    configure_onboard_led();

    lcd_init();

    char character = 0b11000111;
    lcd_write_byte_to_db(character);

    return 0;
}

void configure_onboard_led()
{
    GPIOC->CRH &= ~(0xFu << 20);
    GPIOC->CRH |= (0x2u << 20);

    GPIOC->BSRR = (1u << (13 + 16));
}

void enable_rcc()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}
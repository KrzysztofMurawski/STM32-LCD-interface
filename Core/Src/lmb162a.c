
#include "lmb162a.h"



void time_delay(){
    for (int i = 0; i < 5000; i++){}
}

void lcd_init(){

    //Disable JTAG
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;

    // Set pins as output


    LCD_RS_PORT->LCD_RS_CR |= (0b0011u << ((LCD_RS_PIN & 7) * 4));
    LCD_RS_PORT->LCD_RS_CR &= ~(0b1100u << ((LCD_RS_PIN & 7) * 4));

    LCD_RW_PORT->LCD_RW_CR |= (0b0011u << ((LCD_RW_PIN & 7) * 4));
    LCD_RW_PORT->LCD_RW_CR &= ~(0b1100u << ((LCD_RW_PIN & 7) * 4));

    LCD_E_PORT->LCD_E_CR |=    (0b0011u << ((LCD_E_PIN & 7) * 4));
    LCD_E_PORT->LCD_E_CR &=    ~(0b1100u << ((LCD_E_PIN & 7) * 4));

    LCD_DB0_PORT->LCD_DB0_CR |= (0b0011u << ((LCD_DB0_PIN & 7) * 4));
    LCD_DB0_PORT->LCD_DB0_CR &= ~(0b1100u << ((LCD_DB0_PIN & 7) * 4));

    LCD_DB1_PORT->LCD_DB1_CR |= (0b0011u << ((LCD_DB1_PIN & 7) * 4));
    LCD_DB1_PORT->LCD_DB1_CR &= ~(0b1100u << ((LCD_DB1_PIN & 7) * 4));

    LCD_DB2_PORT->LCD_DB2_CR |= (0b0011u << ((LCD_DB2_PIN & 7) * 4));
    LCD_DB2_PORT->LCD_DB2_CR &= ~(0b1100u << ((LCD_DB2_PIN & 7) * 4));

    LCD_DB3_PORT->LCD_DB3_CR |= (0b0011u << ((LCD_DB3_PIN & 7) * 4));
    LCD_DB3_PORT->LCD_DB3_CR &= ~(0b1100u << ((LCD_DB3_PIN & 7) * 4));

    LCD_DB4_PORT->LCD_DB4_CR |= (0b0011u << ((LCD_DB4_PIN & 7) * 4));
    LCD_DB4_PORT->LCD_DB4_CR &= ~(0b1100u << ((LCD_DB4_PIN & 7) * 4));

    LCD_DB5_PORT->LCD_DB5_CR |= (0b0011u << ((LCD_DB5_PIN & 7) * 4));
    LCD_DB5_PORT->LCD_DB5_CR &= ~(0b1100u << ((LCD_DB5_PIN & 7) * 4));

    LCD_DB6_PORT->LCD_DB6_CR |= (0b0011u << ((LCD_DB6_PIN & 7) * 4));
    LCD_DB6_PORT->LCD_DB6_CR &= ~(0b1100u << ((LCD_DB6_PIN & 7) * 4));

    LCD_DB7_PORT->LCD_DB7_CR |= (0b0011u << ((LCD_DB7_PIN & 7) * 4));
    LCD_DB7_PORT->LCD_DB7_CR &= ~(0b1100u << ((LCD_DB7_PIN & 7) * 4));

    lcd_reset_pins();   

    time_delay();

    lcd_send_cmd(0x30);
    time_delay();

    lcd_send_cmd(0x30);
    time_delay();

    lcd_send_cmd(0x30);
    time_delay();

    lcd_send_cmd(0x38);

    lcd_send_cmd(0x08);

    lcd_send_cmd(0x01);
    time_delay();

    lcd_send_cmd(0x06);

    lcd_send_cmd(0x0C);
}

void lcd_reset_pins()
{
    LCD_RS_PORT->BSRR = 1u << (LCD_RS_PIN + 16);
    LCD_RW_PORT->BSRR = 1u << (LCD_RW_PIN + 16);
    LCD_E_PORT->BSRR = 1u << (LCD_E_PIN + 16);
    LCD_DB0_PORT->BSRR = 1u << (LCD_DB0_PIN + 16);
    LCD_DB1_PORT->BSRR = 1u << (LCD_DB1_PIN + 16);
    LCD_DB2_PORT->BSRR = 1u << (LCD_DB2_PIN + 16);
    LCD_DB3_PORT->BSRR = 1u << (LCD_DB3_PIN + 16);
    LCD_DB4_PORT->BSRR = 1u << (LCD_DB4_PIN + 16);
    LCD_DB5_PORT->BSRR = 1u << (LCD_DB5_PIN + 16);
    LCD_DB6_PORT->BSRR = 1u << (LCD_DB6_PIN + 16);
    LCD_DB7_PORT->BSRR = 1u << (LCD_DB7_PIN + 16);
}


void lcd_write_byte_to_db(char byte)
{
    uint8_t mask = 0b1;

    if (byte & mask)
        LCD_DB0_PORT->BSRR = (1 << LCD_DB0_PIN);
    else
        LCD_DB0_PORT->BSRR = (1 << (LCD_DB0_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB1_PORT->BSRR = (1 << LCD_DB1_PIN);
    else
        LCD_DB1_PORT->BSRR = (1 << (LCD_DB1_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB2_PORT->BSRR = (1 << LCD_DB2_PIN);
    else
        LCD_DB2_PORT->BSRR = (1 << (LCD_DB2_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB3_PORT->BSRR = (1 << LCD_DB3_PIN);
    else
        LCD_DB3_PORT->BSRR = (1 << (LCD_DB3_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB4_PORT->BSRR = (1 << LCD_DB4_PIN);
    else
        LCD_DB4_PORT->BSRR = (1 << (LCD_DB4_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB5_PORT->BSRR = (1 << LCD_DB5_PIN);
    else
        LCD_DB5_PORT->BSRR = (1 << (LCD_DB5_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB6_PORT->BSRR = (1 << LCD_DB6_PIN);
    else
        LCD_DB6_PORT->BSRR = (1 << (LCD_DB6_PIN + 16));

    mask <<= 1;

    if (byte & mask)
        LCD_DB7_PORT->BSRR = (1 << LCD_DB7_PIN);
    else
        LCD_DB7_PORT->BSRR = (1 << (LCD_DB7_PIN + 16));
}


void lcd_command_mode(){
    LCD_RS_PORT->BSRR = (1 << (LCD_RS_PIN + 16));
    LCD_RW_PORT->BSRR = (1 << (LCD_RW_PIN + 16));
}

void lcd_data_mode(){
    LCD_RS_PORT->BSRR = (1 << (LCD_RS_PIN));
    LCD_RW_PORT->BSRR = (1 << (LCD_RW_PIN + 16));

}

void lcd_flash_enable(){
    LCD_E_PORT->BSRR = (1 << LCD_E_PIN);
    time_delay();
    LCD_E_PORT->BSRR = (1 << (LCD_E_PIN + 16));
    time_delay();
}




void lcd_send_cmd(char byte){
    lcd_command_mode();
    lcd_write_byte_to_db(byte);
    time_delay();
    lcd_flash_enable();
    lcd_reset_pins();
}

void lcd_send_char(char character){
    lcd_data_mode();
    lcd_write_byte_to_db(character);
    time_delay();
    lcd_flash_enable();
    lcd_reset_pins();
}

void lcd_send_string(char *string){
    while(*string){
        lcd_send_char(*string++);
    }
}

void lcd_send_int(int number){
    int digits = 1;
    int k = number;
    while (k != 0){
        k /= 10;
        digits++;
    }
    char *char_num_to_send = malloc(digits);
    sprintf(char_num_to_send, "%d", number);

    lcd_send_string(char_num_to_send);
}
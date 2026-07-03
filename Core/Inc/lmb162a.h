#pragma once

#include "stm32f1xx.h"
#include "stm32f103xb.h"
#include <time.h>

#define LCD_RS_PORT     GPIOB
#define LCD_RW_PORT     GPIOB
#define LCD_E_PORT      GPIOB
#define LCD_DB0_PORT    GPIOB
#define LCD_DB1_PORT    GPIOA
#define LCD_DB2_PORT    GPIOA
#define LCD_DB3_PORT    GPIOA
#define LCD_DB4_PORT    GPIOA
#define LCD_DB5_PORT    GPIOA
#define LCD_DB6_PORT    GPIOA
#define LCD_DB7_PORT    GPIOB

#define LCD_RS_PIN  12 
#define LCD_RW_PIN  13
#define LCD_E_PIN   14
#define LCD_DB0_PIN 15 
#define LCD_DB1_PIN 8 
#define LCD_DB2_PIN 9 
#define LCD_DB3_PIN 10 
#define LCD_DB4_PIN 11 
#define LCD_DB5_PIN 12 
#define LCD_DB6_PIN 15
#define LCD_DB7_PIN 3 

#if LCD_RS_PIN > 7
#define LCD_RS_CR CRH
#else
#define LCD_RS_CR CRL
#endif

#if LCD_RW_PIN > 7
#define LCD_RW_CR CRH
#else
#define LCD_RW_CR CRL
#endif

#if LCD_E_PIN > 7
#define LCD_E_CR CRH
#else
#define LCD_E_CR CRL
#endif

#if LCD_DB0_PIN > 7
#define LCD_DB0_CR CRH
#else
#define LCD_DB0_CR CRL
#endif

#if LCD_DB1_PIN > 7
#define LCD_DB1_CR CRH
#else
#define LCD_DB1_CR CRL
#endif

#if LCD_DB2_PIN > 7
#define LCD_DB2_CR CRH
#else
#define LCD_DB2_CR CRL
#endif

#if LCD_DB3_PIN > 7
#define LCD_DB3_CR CRH
#else
#define LCD_DB3_CR CRL
#endif

#if LCD_DB4_PIN > 7
#define LCD_DB4_CR CRH
#else
#define LCD_DB4_CR CRL
#endif

#if LCD_DB5_PIN > 7
#define LCD_DB5_CR CRH
#else
#define LCD_DB5_CR CRL
#endif

#if LCD_DB6_PIN > 7
#define LCD_DB6_CR CRH
#else
#define LCD_DB6_CR CRL
#endif

#if LCD_DB7_PIN > 7
#define LCD_DB7_CR CRH
#else
#define LCD_DB7_CR CRL
#endif

void lcd_init();

void lcd_reset_pins();
void lcd_write_byte_to_db(char byte);
void lcd_send_cmd(char byte);
void lcd_send_char(char character);
void lcd_command_mode();
void lcd_data_mode();
void lcd_flash_enable();
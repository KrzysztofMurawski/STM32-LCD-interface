#include "stm32f1xx.h"

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


int main(){

    LCD_RS_PORT->LCD_RS_CR |=     (0b0011u << (LCD_RS_PIN * 4));
    LCD_RS_PORT->LCD_RS_CR &=    ~(0b1100u << (LCD_RS_PIN * 4));

    LCD_RW_PORT->LCD_RS_CR |=     (0b0011u << (LCD_RW_PIN * 4));
    LCD_RW_PORT->LCD_RS_CR &=    ~(0b1100u << (LCD_RW_PIN * 4));

    LCD_E_PORT->LCD_RS_CR |=       (0b0011u << (LCD_E_PIN * 4));
    LCD_E_PORT->LCD_RS_CR &=      ~(0b1100u << (LCD_E_PIN * 4));

    LCD_DB0_PORT->LCD_DB0_CR |=     (0b0011u << (LCD_DB0_PIN * 4));
    LCD_DB0_PORT->LCD_DB0_CR &=    ~(0b1100u << (LCD_DB0_PIN * 4));

    LCD_DB1_PORT->LCD_DB1_CR |=     (0b0011u << (LCD_DB1_PIN * 4));
    LCD_DB1_PORT->LCD_DB1_CR &=    ~(0b1100u << (LCD_DB1_PIN * 4));

    LCD_DB2_PORT->LCD_DB2_CR |=     (0b0011u << (LCD_DB2_PIN * 4));
    LCD_DB2_PORT->LCD_DB2_CR &=    ~(0b1100u << (LCD_DB2_PIN * 4));

    LCD_DB3_PORT->LCD_DB3_CR |=     (0b0011u << (LCD_DB3_PIN * 4));
    LCD_DB3_PORT->LCD_DB3_CR &=    ~(0b1100u << (LCD_DB3_PIN * 4));

    LCD_DB4_PORT->LCD_DB4_CR |=     (0b0011u << (LCD_DB4_PIN * 4));
    LCD_DB4_PORT->LCD_DB4_CR &=    ~(0b1100u << (LCD_DB4_PIN * 4));

    LCD_DB5_PORT->LCD_DB5_CR |=     (0b0011u << (LCD_DB5_PIN * 4));
    LCD_DB5_PORT->LCD_DB5_CR &=    ~(0b1100u << (LCD_DB5_PIN * 4));

    LCD_DB6_PORT->LCD_DB6_CR |=     (0b0011u << (LCD_DB6_PIN * 4));
    LCD_DB6_PORT->LCD_DB6_CR &=    ~(0b1100u << (LCD_DB6_PIN * 4));

    LCD_DB7_PORT->LCD_DB7_CR |=     (0b0011u << (LCD_DB7_PIN * 4));
    LCD_DB7_PORT->LCD_DB7_CR &=    ~(0b1100u << (LCD_DB7_PIN * 4));

    
    char character = 'A'; 
    


    while (1){




    }

    return 0;
}
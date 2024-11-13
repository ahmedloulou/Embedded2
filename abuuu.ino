#include <util/delay.h>
#include "Adc_pot.h"
#include "Lcd.h"
#include "Uart.h"
#include <stdlib.h>



int main(void) {
 
  unsigned short adc_reading;
  unsigned short upperlimit;
  unsigned short lowerlimit;
  unsigned char buffer[4];
  DDRD = DDRD & ~(1 << PD3);  
  PORTD = PORTD | (1 << PD3);
  DDRD = DDRD & ~(1 << PD0);  
  PORTD = PORTD | (1 << PD0);
  DDRB = DDRB & ~(1 << PB4);  
  PORTB = PORTB | (1 << PB4);
  DDRB = DDRB & ~(1 << PB5);  
  PORTB = PORTB | (1 << PB5);


  upperlimit = 700;
  lowerlimit = 400;
  Adc_Init(); 
  Uart_Init();
  LCD_Init();


  while (1) {
    _delay_ms(100);                    
    
    adc_reading = Adc_ReadChannel(1);
    itoa(adc_reading, buffer, 10);
    
    Uart_SendString(buffer, 4);
    Uart_SendChar('\n');
    
    LCD_Clear();
    LCD_String("ADC Value: ");
    LCD_String(buffer);
    LCD_Command(0xC0);
    itoa(upperlimit, buffer, 10);
    LCD_String("UL: ");
    LCD_String(buffer);
    LCD_String("  LL: ");
    itoa(lowerlimit, buffer, 10);
    LCD_String(buffer);

    if (((PIND >> 3) & 1) == 0) {
      upperlimit += 10 ;
      _delay_ms(100);
    } 
     if (((PIND >> 0) & 1) == 0) {
      upperlimit -= 10 ;
      _delay_ms(100);
    }  
         if (((PINB >> 4) & 1) == 0) {
      lowerlimit += 10 ;
      _delay_ms(100);
    } 
         if (((PINB >> 5) & 1) == 0) {
      lowerlimit -= 10 ;
      _delay_ms(100);
    } 


    

    if (adc_reading >= lowerlimit && adc_reading < upperlimit) {
      PORTD|= (1 << 2);           
    } else {
      PORTD &= ~(1 << 2);        
    }
  }

  return 0;
}



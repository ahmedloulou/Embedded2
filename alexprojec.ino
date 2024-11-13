#include <util/delay.h> // include the delay library.
#include "Adc_pot.h"    // include the header file for the analog digital converter.
#include "Lcd.h"        // include the header file for the lcd functions.
#include "Uart.h"
#include <stdlib.h>



int main(void) {
 
  unsigned short adcreading;
  unsigned short upperlimit;
  unsigned short lowerlimit;
  unsigned char buffer[4];
  DDRD &= ~(1 << PD3);  
  PORTD |= (1 << PD3);
  DDRD &= ~(1 << PD0);  
  PORTD |= (1 << PD0);
  DDRB &= ~(1 << PB4);  
  PORTB |= (1 << PB4);
  DDRB &= ~(1 << PB5);  
  PORTB |= (1 << PB5);


  upperlimit = 700;
  lowerlimit = 400;
  Adc_Init(); 
  Uart_Init();
  LCD_Init();


  while (1) {
    _delay_ms(100);                    
    
    adcreading = Adc_ReadChannel(1);
    itoa(adcreading, buffer, 10);
    
    Uart_SendString(buffer, 4);
    Uart_SendChar('\n');
    
    LCD_Clear();
    LCD_String("Sensor: ");
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


    

    if (adcreading >= lowerlimit && adcreading < upperlimit) {
      PORTD &= ~(1 << 2); 
      LCD_Command(0x8E);
      LCD_String("OK");          
    } 
    else {      
      PORTD|= (1 << 2);
      LCD_Command(0x8D);
      LCD_String("NOK");
   
    }
  }

  return 0;
}



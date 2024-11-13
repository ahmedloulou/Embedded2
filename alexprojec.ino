#include <util/delay.h> // include the delay library.
#include "Adc_pot.h"    // include the header file for the analog digital converter.
#include "Lcd.h"        // include the header file for the lcd functions.
#include "Uart.h"       // include the header file for the uart communication.
#include <stdlib.h>     // include the library for conversions to string and memory allocations.



int main(void) {        // Start of the main function of the code.
 
  unsigned short adcreading;    // defining adcreading as an unsigned short variable"holds only positive values and short because it holds short values maximum 165 bit"
  unsigned short upperlimit;    // defining upperlimit as an unsigned short variable"holds only positive values and short because it holds short values maximum 165 bit"
  unsigned short lowerlimit;    // defining lowerlimit as an unsigned short variable"holds only positive values and short because it holds short values maximum 165 bit"
  unsigned char buffer[4];      // define the buffer as unsigned to only hold positive elemnts and 4 as to make it hold 4 elemnts.
  DDRD &= ~(1 << PD3);          // define pin D3 as input for a push button
  PORTD |= (1 << PD3);          // activate the internal pull up resistor.
  DDRD &= ~(1 << PD0);          // define pin D3 as input for a push button
  PORTD |= (1 << PD0);          // activate the internal pull up resistor.
  DDRB &= ~(1 << PB4);          // define pin D3 as input for a push button
  PORTB |= (1 << PB4);          // activate the internal pull up resistor.
  DDRB &= ~(1 << PB5);          // define pin D3 as input for a push button.
  PORTB |= (1 << PB5);          // activate the internal pull up resistor.


  upperlimit = 700;       // set the initial value of the upperlimit to 700.
  lowerlimit = 400;       // set initial value for the lowerlimit to 400.
  Adc_Init();             // include analog digital converter initialization.
  Uart_Init();            // include uart communication initialization.
  LCD_Init();             // include Lcd initialization.


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



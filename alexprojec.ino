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


  while (1) {           // using an infinte loop to kepp the code always running 
    _delay_ms(100);     // adding a delay to let the code run smoothly and prevent loss of data              
    
    adcreading = Adc_ReadChannel(1); // assigning the value of the analog sensor to the variable adcreading using the function adc_ReadChannel()
    itoa(adcreading, buffer, 10);    // this function takes input adcreading and converts it to a string of base 10 then stores the value in the buffer
    
    Uart_SendString(buffer, 4);     // we send the value obtained from the function itoa() to the uart to displat it on the serial monitor for comaprisons with the lcd
    Uart_SendChar('\n');            // this indicates the end of the line and moves the cursor down to a new line.
    
    LCD_Clear();           // this function clears the display from any charcters that was on it.
    LCD_String("Sensor: ");  // lcd_strig sends the characters withinn the quotation to the lcd displaying it.
    LCD_String(buffer);    // displays the value stored in the buffer which is the analog sensor value
    LCD_Command(0xC0);     // this command shift down to the second row to write on it
    itoa(upperlimit, buffer, 10);  // this function takes input upperlimit and converts it to a string of base 10 then stores the value in the buffer
    LCD_String("UL: "); // displays the letters UL which refers to the Upperlimit
    LCD_String(buffer);// displays the value of the upper limit
    LCD_String("  LL: "); // displays the letters LL which refers to the lower limit
    itoa(lowerlimit, buffer, 10); // // ttakes input lowerlimit and converts it to a string of base 10 then stores the value in the buffer
    LCD_String(buffer); // displays the value in the buffer which is the low limit

    if (((PIND >> 3) & 1) == 0) {   // checks if the button in pin D3 is pressed or not
      upperlimit += 10 ;    // if button is pressed upper limit increases by 10
      _delay_ms(100);
    } 
    if (((PIND >> 0) & 1) == 0) {   // checks if the button in pin D0 is pressed or not
      upperlimit -= 10 ;            // if button is pressed upper limit decreases by 10
      _delay_ms(100);
    }  
    if (((PINB >> 4) & 1) == 0) {   // checks if the button in pin B4 is pressed or not
      lowerlimit += 10 ;            // if button is pressed lower limit increases by 10
      _delay_ms(100);
    } 
    if (((PINB >> 5) & 1) == 0) {   // checks if the button in pin B5 is pressed or not
      lowerlimit -= 10 ;            // if button is pressed lower limit decreases by 10
      _delay_ms(100);
    } 


    

    if (adcreading >= lowerlimit && adcreading < upperlimit) {       // checks if the value of the potentiometer is in the range or not"betwwen the upper and lower limit"
      PORTD &= ~(1 << 2);  // if sensor value inside the rage buzzer and led stays off.
      LCD_Command(0x8E);   // this command moves the cursor to a specific character in this case character 15
      LCD_String("OK");    // displays the letters OK on the far right of the lcd in the top row      
    } 
    else {                    // if sensor value outside the range it eneters the else
      PORTD|= (1 << 2);       // sets pin D2 to 1 turning on the led and buzzer
      LCD_Command(0x8D);      // moves the cursor to a specific character in this case character 14
      LCD_String("NOK");      // displays the letters NOK on the far right of the lcd in the top row
   
    }
  }

  return 0;
}



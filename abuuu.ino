#include <util/delay.h>
#include "Adc_pot.h"
#include "Lcd.h"
#include "Uart.h"
#include <stdlib.h>

int main(void) {
 
  unsigned short adc_reading;
  unsigned char buffer[4];
  

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
    

    if (adc_reading >= 400 && adc_reading < 700) {
      PORTD|= (1 << 2);     
    } else if (adc_reading >= 700 && adc_reading < 1000) {
      PORTD &= ~(1 << 2);       
    } else {
      PORTD &= ~(1 << 2);        
    }
  }

  return 0;
}




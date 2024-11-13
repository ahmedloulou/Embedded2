#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif
#include "Adc_pot.h"

void Adc_Init(void)  // defines the initialization of the adc
{

    ADMUX = (1<<REFS0);   // enables the pin by shifting 1.
 

    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned short Adc_ReadChannel(unsigned char ch)
{


  ch &= 0b00000111;  // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
 

  ADCSRA |= (1<<ADSC);

  while(ADCSRA & (1<<ADSC));
 
  return (ADC);

}

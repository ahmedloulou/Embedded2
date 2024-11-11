#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"
unsigned char size;

void leddred_init() {
    DDRB = DDRB | (1 << 0);  
    PORTB = PORTB & ~(1 << 0); 
    DDRD = DDRD & ~(1 << PD2);  
    PORTD = PORTD | (1 << PD2);  
    EICRA = EICRA | (1 << ISC01); 
    EIMSK = EIMSK | (1 << INT0);  
    sei(); 
}
void leddred_init();
   
int main(void) {
    leddred_init();
    Uart_Init();

    while (1) {

        unsigned char letter = Uart_ReadData();

        if (letter == '1') {

            PORTB = PORTB | (1 << 0);  

        } 
        else if (letter == '0') {

            PORTB = PORTB & ~(1 << 0); 
        }
    }

    return 0;
}


void PUSHbutton(void) {
    if (((PIND >> 2) & 1) == 0) {
        Uart_SendString("button is pressed\n\r", sizeof(size));
        _delay_ms(100);
    }
}



ISR(INT0_vect) {
    Uart_SendString("button is pressed\n\r", sizeof(size));
}




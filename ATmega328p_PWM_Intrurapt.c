/*
 Author : Kalana dhanajaya
 Date : 2018.04.25
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
double dutyCycle = 0;

int main(void)
{   
    DDRD = (1 << PORTD6);
     
    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TIMSK0 = (1 << TOIE0);
     
    OCR0A = (dutyCycle/100.0)*255.0;
     
    sei();
     
    TCCR0B = (1 << CS00) | (1 << CS01)|(0<<CS02);
    while(1)
    {
        _delay_ms(100);
        dutyCycle =50;
    }
}

ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutyCycle/100.0)*255;
}

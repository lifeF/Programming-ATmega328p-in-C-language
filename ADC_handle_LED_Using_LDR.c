/*
Kalana Dhananjaya Rathnayake
University of Peradeniya
*/

#include <avr/io.h>
#include <util/delay.h>

int main () {
  DDRC = (DDRC | (0 << 1)); 
  DDRD = (DDRD | (1 << PD4)); // set PD4 as output
  
  ADMUX = 0b01000001;
  ADCSRA = 0b11000111;

  while (1) {
    ADCSRA |= (1 << ADSC);
    while (!(ADCSRA & (1 << ADIF)));
    _delay_ms(30);
    
    if (ADCW < 300) {
      PORTD = (PORTD | (1 << PD4));
    }
    else {
       PORTD = (PORTD & ~(1 << PD4));
    }
  }
}

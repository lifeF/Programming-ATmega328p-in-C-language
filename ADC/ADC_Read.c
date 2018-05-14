
/*
Kalana Dhananjaya Rathnayake
Department of Computer Engineering
University of Peradeniya
*/

#include <avr/io.h>
#include <util/delay.h>

int main () {
  DDRC = (DDRC | (0 << 1)); /* configure pin 1 of PORTC for input*/
  DDRD = (DDRD | (1 << PD4)) | (DDRD | (1 << PD5)) | (DDRD | (1 << PD6));
  
  ADMUX = 0b01000001; // set input pin chanel and ADC ref voltage
  ADCSRA = 0b11000111; // enable ADC and set Prescaler 
  while (1) {
    ADCSRA |= (1 << ADSC);// start convention
    // When, convention complete ADIF set 0 to 1
    
    while (!(ADCSRA & (1 << ADIF)));  // wait for ADIF is set 
    _delay_ms(30);
    //ADC register hold A0 input value
    
    if (ADCW < 300) {
      PORTD = (PORTD | (1 << PD4));
      PORTD = (PORTD & ~(1 << PD5));
      PORTD = (PORTD & ~(1 << PD6));
    } else if ((ADCW >= 300) && (ADCW <= 1020)) {
      PORTD = (PORTD | (1 << PD4));
      PORTD = (PORTD | (1 << PD5));
      PORTD = (PORTD & ~(1 << PD6));
    } else {
      PORTD = (PORTD | (1 << PD4));
      PORTD = (PORTD | (1 << PD5));
      PORTD = (PORTD | (1 << PD6));
    }
   
  }
}

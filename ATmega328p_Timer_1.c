#include <avr/io.h>
#include <avr/interrupt.h>
int over_flower;


void timer_init() {
    TCCR1B =0x02;
    TCNT1 = 61536;
    over_flower=0;
    TIMSK1 |= (1 << TOIE1);
    sei();
}

ISR(TIMER1_OVF_vect){
    over_flower++;
    TCNT1 = 61536;
    if(over_flower==25){
        PORTB ^= (1 << 5);
        over_flower=0;
    }
}

int main(void) {    
    DDRB |= (1 << 5);// set port 5 as a output port
    timer_init();
    while(1) { }
    
    return 0;
    
}

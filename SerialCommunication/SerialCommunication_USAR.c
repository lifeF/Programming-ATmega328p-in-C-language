
/*
 Kalana dhananjaya Rathnayake
 date 2018 05 16
*/

#include <avr/io.h>
#include <util/delay.h>


void USART_Init(void )
{
    //enable transmit and reciveing
    UCSR0B |= (1<<TXEN0);
    UCSR0B |= (1<<RXEN0);
    
    /*   Setup parity bit and stop bit
         UPM - for USART Parity Mode
         USBS)- for Stop Bit Settings
         UCSZ - for USART Character Size
    */
    UCSR0C =(0<< UPM01) | (0<<UPM00) | (0<<USBS0) |(0<<UCSZ02) |(1<<UCSZ01) |(1<<UCSZ00) ;
    
    // write ubrr0l 103 to get 9600 bound rate
    UBRR0L =0x67;
}

//Send data function
void USART_TX (unsigned char ch){
    
    while(!(UCSR0A & (1<<UDRE0)));// waiting for UDRE0 bit is set
                                  // Wait for empty transmit buffer
    UDR0 =ch;// write data in UDR0 ( on buffer)
}

// Recieving Data
unsigned char USART_RX(void){
    
    while ((UCSR0A & (1<<RXC0))==0x00); //RXC0 flag bit of the UCSR0A register is monitored for a HIGH
    return (UDR0);// return character in UDR0 register
}


int main () {

   USART_Init();
   char name[ ] ="kalana dhananajaya";
   int i =0;
   while(1){
      char n = USART_RX();
      USART_TX(n);
      //i++;
   }

   

}


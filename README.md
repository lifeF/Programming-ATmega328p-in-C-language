# Programming-ATmega328p-in-C-language
Programming ATmega328p in C language

<b>Timers</b>

Many applications need to count occurrences of an event or generate time delays. So, there are counter registers in microcontrollers for this purpose. When we want to count events, we connect the external event source to the clock pin of the counter register. Then, when an event occurs externally, the content of the counter is incremented; this way, the content of the counter represents how many times an event has occurred. When we want to generate time delays, we connect the oscillator to the clock pin of the counter. So, when the oscillator ticks, the content of the counter is incremented. As a result, the content of the counter register represents how many ticks have occurred from the time we have cleared the counter. Since the speed of the oscillator in a microcontroller is known, we can calculate the tick period, and from the content of the counter register we will know how much time has elapsed.

![image](https://exploreembedded.com/wiki/images/8/85/Timer_Block_Diagram.jpg)

Figure 1: A general view of counters and timers in microcontrollers
Figure 1 shows the general view of a timer. All the Atmel microcontrollers have Timers as an inbuilt peripheral. ATmega328 has three timers: TIMER0, TIMER1, and TIMER2. They also have a Watchdog Timer, which can be used as a safeguard or software reset mechanism.

Here are a few details about each timer: TIMER0 TIMER0 is an 8-bit timer, meaning its counter register can record a maximum value of 255 (unsigned 8-bit value). TIMER0 is used by native Arduino timing function such as delay ( ). TIMER1 TIMER1 is a 16-bit timer, with a maximum counter value of 65535 (an unsigned 16-bit integer). The Arduino Servo library uses this timer. TIMER2 TIMER2 is an 8-bit timer that is very similar to TIMER0. It is utilized by the Arduino tone ( ) function.

<b>Pulse Width Modulation (PWM)</b> 

Pulse width modulation (PWM) is a powerful technique for controlling analog circuits with a microprocessor's digital output. It is a simple method of using a rectangular digital waveform to control an analog variable. PWM control is used in a variety of applications, ranging from communications to automatic control. Period T is normally kept constant. Pulse width, or “on” time, is varied to get the desired output. The Duty Cycle is the proportion of time that the pulse is „ON‟ or „high‟, and is expressed as a percentage: 


  ![image](https://www.arduino.cc/en/uploads/Tutorial/pwm.gif)


  `Duty cycle = (pulse ON time / pulse period T) * 100%`

Whatever duty cycle a PWM stream has, there is an average output voltage, as indicated by the dotted line. If the “on” time is small, the average output is low; if the “on” time is large, the average output is high. By controlling the duty cycle, we control this average output voltage.


<b>ADC (analog to digital convention)</b> 

Analog-to-digital converters are among the most widely used devices for data acquisition. Digital computers use binary (discrete) values, but in the physical world, everything is analog (continuous). Temperature, pressure (wind or liquid), humidity, and velocity are a few examples of physical quantities that we deal with every day. A physical quantity is converted to electrical (voltage, current) signals using a device called as a transducer. Transducers are also referred to as sensors. Sensors for temperature, velocity,pressure, light and many other natural quantities produce an output that is an analog voltage (or current). Therefore, we need an analog-to-digital converter to translate the analog signals to digital numbers, so that the microcontroller can read and process them.

![image](https://www.gammon.com.au/images/Arduino/ADC_internals.png)

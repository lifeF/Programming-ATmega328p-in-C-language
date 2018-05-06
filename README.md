# Programming-ATmega328p-in-C-language
Programming ATmega328p in C language


<b>Pulse Width Modulation (PWM)</b> 

Pulse width modulation (PWM) is a powerful technique for controlling analog circuits with a microprocessor's digital output. It is a simple method of using a rectangular digital waveform to control an analog variable. PWM control is used in a variety of applications, ranging from communications to automatic control. Period T is normally kept constant. Pulse width, or “on” time, is varied to get the desired output. The Duty Cycle is the proportion of time that the pulse is „ON‟ or „high‟, and is expressed as a percentage: 

  `Duty cycle = (pulse ON time / pulse period T) * 100%`

Whatever duty cycle a PWM stream has, there is an average output voltage, as indicated by the dotted line. If the “on” time is small, the average output is low; if the “on” time is large, the average output is high. By controlling the duty cycle, we control this average output voltage.

NeoPixel-60-Ring-Clock
======================

This project uses the DS1307 Real Time Clock with an Arduino to display the time as a series of colored arcs.

With the new NeoPixel 60 Ring, we have a perfect display for presenting the time with RGB LEDs!

Hours are represented by red, minutes by green, seconds by blue. The arcs overlap and the colors mix. Minutes and seconds are each represented by a single green or blue LED, respectively. In the 12 hour version, a single red LED represent 24 minutes. The image above represents 3:48.

To build this project you will need:

* 4 x NeoPixel 1/4 60 Ring - so you can make a NeoPixel 60 Ring
* DS1307 Real Time Clock breakout board kit
* Arduino Uno or other Arduino compatible microcontroller. This will even work with the Trinket 5V!
* Adafruit Perma-Proto Half-sized Breadboard PCB

If you are new to microcontrollers and Arduino, I would recommend starting out by building the circuit using the Arduino Uno and a breadboard.

If you are more familiar with Arduino, you can use a Trinket 5V and perfboard to build a more permanent electronics project.

This project requires the Adafruit_NeoPixel and RTC libraries.

For more information visit:

http://andydoro.com/ringclock/

https://learn.adafruit.com/neopixel-60-ring-clock/overview

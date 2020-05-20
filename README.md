NeoPixel 60 Ring Clock
======================

For more information visit:

http://andydoro.com/ringclock/ \
[Adafruit Learn Guide](https://learn.adafruit.com/neopixel-60-ring-clock/)

This project uses the DS1307 Real Time Clock with an Arduino to display the time as a series of colored arcs.

With the NeoPixel 60 Ring, we have a perfect display for presenting the time with RGB LEDs!

Hours are represented by red, minutes by green, seconds by blue. The arcs overlap and the colors mix. Minutes and seconds are each represented by a single green or blue LED, respectively. In the 12 hour version, a single red LED represent 24 minutes.

Hardware:
-------

* 4 x NeoPixel 1/4 60 Ring - so you can make a NeoPixel 60 Ring
* DS1307 Real Time Clock breakout board
* Arduino Uno or other Arduino compatible microcontroller. This will even work with the Trinket 5V!
* Adafruit Perma-Proto Half-sized Breadboard PCB

If you are new to microcontrollers and Arduino, I would recommend starting out by building the circuit using the Arduino Uno and a breadboard.

If you are more familiar with Arduino, you can use a Trinket 5V and perfboard to build a more permanent electronics project.


Software:
-------

Required libraries:

* [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
* [RTClib](https://github.com/adafruit/RTClib)
* [DST_RTC](https://github.com/andydoro/DST_RTC)


3D enclosure created by [arradan](https://www.thingiverse.com/arradan/about)




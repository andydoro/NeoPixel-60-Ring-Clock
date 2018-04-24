/**************************************************************************
 *                                                                       *
     NeoPixel Ring Clock
     by Andy Doro (mail@andydoro.com)
     http://andydoro.com/ringclock/
 *                                                                      *
 **************************************************************************


   Revision History

   Date      By    What
   20140320  AFD   First draft
   20160105  AFD   Faded arcs
   20160916  AFD   Trinket compatible
   20170727  AFD   added STARTPIXEL for 3D enclosure, variable starting point, added automatic DST support
   20180424  AFD   using DST library https://github.com/andydoro/DST_RTC
*/

// include the library code:
#include <Wire.h>
#include <RTClib.h>
#include "DST_RTC.h" // download from https://github.com/andydoro/DST_RTC

#include <Adafruit_NeoPixel.h>

// define pins
#define NEOPIN 3

#define BRIGHTNESS 64 // set max brightness

#define STARTPIXEL 33 // where do we start on the loop? use this to shift the arcs if the wiring does not start at the "12" point

RTC_DS1307 rtc; // Establish clock object

DST_RTC dst_rtc; // DST object


Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, NEOPIN, NEO_GRB + NEO_KHZ800); // strip object

byte pixelColorRed, pixelColorGreen, pixelColorBlue; // holds color values

void setup () {
  Wire.begin();  // Begin I2C
  rtc.begin();   // begin clock

  //Serial.begin(9600);
  // set pinmodes
  pinMode(NEOPIN, OUTPUT);

  if (! rtc.isrunning()) {
//    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
    // DST? If we're in it, let's subtract an hour from the RTC time to keep our DST calculation correct. This gives us
    // Standard Time which our DST check will add an hour back to if we're in DST.
    DateTime standardTime = rtc.now();
    if (dst_rtc.checkDST(standardTime) == true) { // check whether we're in DST right now. If we are, subtract an hour.
      standardTime = standardTime.unixtime() - 3600;
    }
    rtc.adjust(standardTime);
  }


  strip.begin();
  //strip.show(); // Initialize all pixels to 'off'

  strip.setBrightness(BRIGHTNESS); // set brightness

  // startup sequence
  delay(500);
  colorWipe(strip.Color(255, 0, 0), 20); // Red
  colorWipe(strip.Color(0, 255, 0), 20); // Green
  colorWipe(strip.Color(0, 0, 255), 20); // Blue
  delay(500);

}

void loop () {

  // get time
  DateTime theTime = dst_rtc.calculateTime(rtc.now()); // takes into account DST

  byte secondval = theTime.second();  // get seconds
  byte minuteval = theTime.minute();  // get minutes
  int hourval = theTime.hour();   // get hours
  hourval = hourval % 12; // This clock is 12 hour, if 13-23, convert to 0-11`

  hourval = (hourval * 60 + minuteval) / 12; //each red dot represent 24 minutes.

  // arc mode
  for (uint8_t i = 0; i < strip.numPixels(); i++) {

    if (i <= secondval) {
      // calculates a faded arc from low to maximum brightness
      pixelColorBlue = (i + 1) * (255 / (secondval + 1));
      //pixelColorBlue = 255;
    }
    else {
      pixelColorBlue = 0;
    }

    if (i <= minuteval) {
      pixelColorGreen = (i + 1) * (255 / (minuteval + 1));
      //pixelColorGreen = 255;
    }
    else {
      pixelColorGreen = 0;
    }

    if (i <= hourval) {
      pixelColorRed = (i + 1) * (255 / (hourval + 1));
      //pixelColorRed = 255;
    }
    else {
      pixelColorRed = 0;
    }

    strip.setPixelColor((i + STARTPIXEL) % 60, strip.Color(pixelColorRed, pixelColorGreen, pixelColorBlue));
  }

  /*
    // for serial debugging
    Serial.print(hourval, DEC);
    Serial.print(':');
    Serial.print(minuteval, DEC);
    Serial.print(':');
    Serial.println(secondval, DEC);
  */

  //display
  strip.show();

  // wait
  delay(100);

}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    //strip.setPixelColor(i, c);
    strip.setPixelColor((i + STARTPIXEL) % 60, c);
    strip.show();
    delay(wait);
  }
}


# Arduino, ESP8266, STM32, ESP32 and others uRTCLib

Master status:   [![Build Status](https://travis-ci.org/Naguissa/uUnixDate.svg?branch=master)](https://travis-ci.org/Naguissa/uUnixDate)

## What is this repository for? ##

Tiny and simplified library to convert to and from UNIX timestamps.

This code is a simplified version of Adafruit's RTCLib https://github.com/adafruit/RTClib

**WARNING:** This library is ONLY prepared to work with dates from 2000-01-01 and is not accurate past 2100-01-01

This library doesn't take in consideration TimeZone and Daylight saving. If you want to adapt to these adding or substracting hours * 3600 to the timestamp (at input if you feed it to library or to timestamp() return value)

Supported features:
* Convert from date (Y-M-D h:m:s) to UNIX timestamp and viceversa



## How do I get set up? ##

You can get it from Arduino libraries directly, searching by uUnixDate.

For manual installation:

 * Get the ZIP.
 * Rename to uUnixDate.zip
 * Install library on Arduino



## Documentation and extras ##

You can find all documentation and extras in this repository: https://github.com/Naguissa/uUnixDate_doc_and_extras

You can read documentation online here: https://naguissa.github.io/uUnixDate_doc_and_extras/



## Examples ##

Included on example folder, available on Arduino IDE.


## Who do I talk to? ##

 * [Naguissa](https://github.com/Naguissa)
 * https://www.foroelectro.net/librerias-arduino-ide-f29/uunixdate-libreria-arduino-para-manejar-fechas-y-u-t473.html
 * https://www.naguissa.com



## Contribute ##

Any code contribution, report or comment are always welcome. Don't hesitate to use GitHub for that.


 * You can sponsor this project using GitHub's Sponsor button: https://github.com/Naguissa/uUnixDate
 * You can make a donation via PayPal: https://paypal.me/foroelectro


Thanks for your support.


Contributors hall of fame: https://www.foroelectro.net/hall-of-fame-f32/contributors-contribuyentes-t271.html

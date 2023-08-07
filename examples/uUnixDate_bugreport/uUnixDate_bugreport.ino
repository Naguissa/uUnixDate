/**
 * \brief Tiny and simplified library to convert to and from UNIX timestamps.
 *
 * This code is a simplified version of Adafruit's RTCLib https://github.com/adafruit/RTClib
 *
 * This library doesn't take in consideration TimeZone and Daylight saving. If you want to adapt to these adding or substracting hours * 3600 to the timestamp (at input if you feed it to library or to timestamp() return value)
 *
 *
 * @file uUnixDate_example.ino
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uUnixDate">https://github.com/Naguissa/uUnixDate</a>
 * @see <a href="https://www.foroelectro.net/librerias-arduino-ide-f29/uunixdate-libreria-arduino-para-manejar-fechas-y-u-t473.html">https://www.foroelectro.net/librerias-arduino-ide-f29/uunixdate-libreria-arduino-para-manejar-fechas-y-u-t473.html</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 1.0.0
 */
#include "Arduino.h"
#include "uUnixDate.h"



void setup() {
    delay (2000);
	  Serial.begin(9600);
	  Serial.println("Serial OK");

    // Check bug, should be 1690405698 but gives 1690844898
    uUnixDate dateA = uUnixDate(2023, 7, 26, 23, 8, 18);
    Serial.print(dateA.year());
    Serial.print('/');
    Serial.print(dateA.month());
    Serial.print('/');
    Serial.print(dateA.day());
    Serial.print(' ');
    Serial.print(dateA.hour());
    Serial.print(':');
    Serial.print(dateA.minute());
    Serial.print(':');
    Serial.print(dateA.second());
    Serial.print(" -- ");
    Serial.println(dateA.timestamp());

    uUnixDate dateC = uUnixDate(dateA.timestamp());
    Serial.print(dateC.year());
    Serial.print('/');
    Serial.print(dateC.month());
    Serial.print('/');
    Serial.print(dateC.day());
    Serial.print(' ');
    Serial.print(dateC.hour());
    Serial.print(':');
    Serial.print(dateC.minute());
    Serial.print(':');
    Serial.print(dateC.second());
    Serial.print(" -- ");
    Serial.println(dateC.timestamp());

    // Extra check              949359600
    uUnixDate dateB = uUnixDate(2000, 2, 1, 0, 0, 0);
    Serial.print(dateB.year());
    Serial.print('/');
    Serial.print(dateB.month());
    Serial.print('/');
    Serial.print(dateB.day());
    Serial.print(' ');
    Serial.print(dateB.hour());
    Serial.print(':');
    Serial.print(dateB.minute());
    Serial.print(':');
    Serial.print(dateB.second());
    Serial.print(" -- ");
    Serial.println(dateB.timestamp());






	  Serial.println(" -- END --");

}



void loop() { }

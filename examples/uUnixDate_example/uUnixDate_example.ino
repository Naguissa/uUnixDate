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

    // dateA is 2023-01-20 12:34:56
    uUnixDate dateA = uUnixDate(2023, 01, 20, 12, 34, 56);


	Serial.print("dateA: ");

	Serial.print(dateA.year());
	Serial.print('-');
	Serial.print(dateA.month());
	Serial.print('-');
	Serial.print(dateA.day());

	Serial.print(' ');

	Serial.print(dateA.hour());
	Serial.print(':');
	Serial.print(dateA.minute());
	Serial.print(':');
	Serial.print(dateA.second());

	Serial.print(" --- ");
	Serial.println(dateA.timestamp());


    // dateB is dateA + 1h +1m +10s ---- 2023-01-20 13:36:06
    uUnixDate dateB = uUnixDate(dateA.timestamp() + 3670); // +1h +1m +10s

    Serial.print("dateB: ");

	Serial.print(dateB.year());
	Serial.print('-');
	Serial.print(dateB.month());
	Serial.print('-');
	Serial.print(dateB.day());

	Serial.print(' ');

	Serial.print(dateB.hour());
	Serial.print(':');
	Serial.print(dateB.minute());
	Serial.print(':');
	Serial.print(dateB.second());

	Serial.print(" --- ");
	Serial.println(dateB.timestamp());

    // dateC is dateB, alt setter ---- 2023-01-20 13:36:06
    uUnixDate dateC;
    dateC.setTimestamp(dateB.timestamp());

    Serial.print("dateC: ");

	Serial.print(dateC.year());
	Serial.print('-');
	Serial.print(dateC.month());
	Serial.print('-');
	Serial.print(dateC.day());

	Serial.print(' ');

	Serial.print(dateC.hour());
	Serial.print(':');
	Serial.print(dateC.minute());
	Serial.print(':');
	Serial.print(dateC.second());

	Serial.print(" --- ");
	Serial.println(dateC.timestamp());


    // dateD is 2020-01-01 00:00:00 -- 946684800
    uUnixDate dateD = uUnixDate(2000, 1, 1, 0, 0, 0);


	Serial.print("dateD: ");

	Serial.print(dateD.year());
	Serial.print('-');
	Serial.print(dateD.month());
	Serial.print('-');
	Serial.print(dateD.day());

	Serial.print(' ');

	Serial.print(dateD.hour());
	Serial.print(':');
	Serial.print(dateD.minute());
	Serial.print(':');
	Serial.print(dateD.second());

	Serial.print(" --- ");
	Serial.println(dateD.timestamp());


    // dateE is 2000-01-01 00:00:00 -- 946684800
    uUnixDate dateE = uUnixDate(946684800);


	Serial.print("dateE: ");

	Serial.print(dateE.year());
	Serial.print('-');
	Serial.print(dateE.month());
	Serial.print('-');
	Serial.print(dateE.day());

	Serial.print(' ');

	Serial.print(dateE.hour());
	Serial.print(':');
	Serial.print(dateE.minute());
	Serial.print(':');
	Serial.print(dateE.second());

	Serial.print(" --- ");
	Serial.println(dateE.timestamp());





	Serial.println(" -- END --");

}



void loop() { }

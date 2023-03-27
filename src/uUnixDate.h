/**
 * \class uUnixDate
 * \brief Tiny and simplified library to convert to and from UNIX timestamps.
 *
 * This code is a simplified version of Adafruit's RTCLib https://github.com/adafruit/RTClib
 *
 * This library doesn't take in consideration TimeZone and Daylight saving. If you want to adapt to these adding or substracting hours * 3600 to the timestamp (at input if you feed it to library or to timestamp() return value)
 *
 *
 * @file uUnixDate.cpp
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uUnixDate">https://github.com/Naguissa/uUnixDate</a>
 * @see <a href="https://www.foroelectro.net/librerias-arduino-ide-f29/uunixdate-libreria-arduino-para-manejar-fechas-y-u-t473.html">https://www.foroelectro.net/librerias-arduino-ide-f29/uunixdate-libreria-arduino-para-manejar-fechas-y-u-t473.html</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 1.1.0
 */
/** \file uRTCLib.h
 *   \brief uRTCLib header file
 */
#ifndef UUNIXDATE
	/**
	 * \brief Prevent multiple inclussion
	 */
	#define UUNIXDATE

    #include "Arduino.h"

    /*
	 * \brief Unixtime for 2000-01-01 00:00:00
	 */
    #define UUNIXDATE_BASE 946684800

    /*
	 * \brief Checks if a year is leap year
     *
     * @param Y Year to check
	 */
    #define UUNIXDATE_ISLEAP(Y) ((Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)) ? 1 : 0)


	class uUnixDate {
		public:
			/******* Constructors *******/
			uUnixDate();
			uUnixDate(const uint32_t);
			uUnixDate(const int16_t, const int8_t, const int8_t, const int8_t, const int8_t, const int8_t);

			/******* Functions ********/

			void setTimestamp(const uint32_t);
			void setDate(const int16_t, const int8_t, const int8_t, const int8_t, const int8_t, const int8_t);

			int8_t second();
			int8_t minute();
			int8_t hour();
			int8_t day();
			int8_t month();
			int16_t year();
			uint32_t timestamp();
			int8_t dow();

		private:
			// Internal data
			int8_t _s;
			int8_t _m;
			int8_t _h;
			int8_t _D;
			int8_t _M;
			int16_t _Y;
			uint32_t _ts;
			int8_t _dow;
	};

#endif



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
 * @see <a href="https://www.foroelectro.net/librerias-arduino-ide-f29/rtclib-arduino-libreria-simple-y-eficaz-para-rtc-y-t95.html">https://www.foroelectro.net/librerias-arduino-ide-f29/rtclib-arduino-libreria-simple-y-eficaz-para-rtc-y-t95.html</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 1.1.0
 */

#include "uUnixDate.h"

/**
 * \brief Constructor
 *
 * Will defailt to 2000-01-01 00:00:00
 */
uUnixDate::uUnixDate() {
    _s = 0;
    _m = 0;
    _h = 0;
    _D = 1;
    _M = 1;
    _Y = 2000;
    _ts = UUNIXDATE_BASE;
    _dow = 6;
}


/**
 * \brief Constructor
 *
 * @param ts Unix timestamp to set date
 */
uUnixDate::uUnixDate(const uint32_t ts) {
    setTimestamp(ts);
}

/**
 * \brief Constructor
 *
 * @param Y Year part of date to set
 * @param M Month part of date to set
 * @param D Day part of date to set
 * @param h Hour part of date to set
 * @param m Minute part of date to set
 * @param s Second part of date to set
 */
uUnixDate::uUnixDate(const int16_t Y, const int8_t M, const int8_t D, const int8_t h, const int8_t m, const int8_t s) {
    setDate(Y, M, D, h, m, s);
}


/**
 * \brief Set Timestamp of object
 *
 * @param ts Unix timestamp to set date
 */
void uUnixDate::setTimestamp(const uint32_t ts) {
    _dow = ((ts / 86400) + 4) % 7;
    _ts = ts;
    uint32_t t = ts - UUNIXDATE_BASE; // bring to 2000 timestamp from 1970
    _s = t % 60;
    t /= 60;
    _m = t % 60;
    t /= 60;
    _h = t % 24;
    int16_t days = t / 24;
    bool leap;
    _Y = 2000;
    while (true) {
        leap = UUNIXDATE_ISLEAP(_Y);
        if (days < 365 + leap) {
            break;
        }
        days -= (365 + leap);
        ++_Y;
    }

    for (_M = 1; _M < 12; ++_M) {
        int8_t daysPerMonth = 31;
        if (_M == 2)  {
            daysPerMonth = leap ? 29 : 28;
        } else if (_M == 4 || _M== 6 || _M == 9 || _M ==11) {
            daysPerMonth = 30;
        }
        if (days < daysPerMonth) {
            break;
        }
        days -= daysPerMonth;
    }
    _D = days + 1;
}

/**
 * \brief Set date of object
 *
 * @param Y Year part of date to set
 * @param M Month part of date to set
 * @param D Day part of date to set
 * @param h Hour part of date to set
 * @param m Minute part of date to set
 * @param s Second part of date to set
 */
void uUnixDate::setDate(const int16_t Y, const int8_t M, const int8_t D, const int8_t h, const int8_t m, const int8_t s) {
    _Y = Y;
    _M = M;
    _D = D;
    _h = h;
    _m = m;
    _s = s;
    int32_t days = D - 1;
    int16_t i;
    for (i = 1; i < M; ++i) {
        if (M == 2)  {
            days += (28 + UUNIXDATE_ISLEAP(Y));
        } else if (M == 4 || M== 6 || M == 9 || M ==11) {
            days += 30;
        } else {
            days += 31;
        }
    }
    for (i = 2000; i < Y; ++i) {
        days += (365 + UUNIXDATE_ISLEAP(i));
    }
    _ts = UUNIXDATE_BASE + (((days * 24 + h) * 60 + m) * 60) + s;
    _dow = ((_ts / 86400) + 4) % 7;


}


/**
 * \brief Getter - Gets second of stored date
 */
int8_t uUnixDate::second() {
    return _s;
}


/**
 * \brief Getter - Gets minute of stored date
 */
int8_t uUnixDate::minute() {
    return _m;
}


/**
 * \brief Getter - Gets hours of stored date
 */
int8_t uUnixDate::hour() {
    return _h;
}


/**
 * \brief Getter - Gets day of stored date
 */
int8_t uUnixDate::day() {
    return _D;
}


/**
 * \brief Getter - Gets month of stored date
 */
int8_t uUnixDate::month() {
    return _M;
}


/**
 * \brief Getter - Gets year of stored date
 */
int16_t uUnixDate::year() {
    return _Y;
}


/**
 * \brief Getter - Gets seconds of stored date
 */
uint32_t uUnixDate::timestamp() {
    return _ts;
}


/**
 * \brief Getter - Gets DayOfWeek of stored date. 0-Sunday to 6-Saturday
 */
int8_t uUnixDate::dow() {
    return _dow;
}

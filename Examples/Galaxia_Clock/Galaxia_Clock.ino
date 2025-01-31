///
/// @mainpage	Galaxia Clock Library
///
/// @details	Galaxia Clock example for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 09:49
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		Galaxia_Clock.ino
/// @brief		Main sketch
///
/// @details	Clock Library for Energia MT
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 09:49
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
/// @example    ReadMe.txt
///


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(ROBOTIS) // Robotis specific
#include "libpandora_types.h"
#include "pandora.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#include "Arduino.h"
#elif defined(RFDUINO) // RFduino specific
#include "Arduino.h"
#elif defined(SPARK) || defined(PARTICLE) // Particle / Spark specific
#include "application.h"
#elif defined(ESP8266) // ESP8266 specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#   error Platform not defined
#endif // end IDE



// Include application, user and local libraries
#include "rtosGlobals.h"
#include "Clock.h"

// Prototypes

// Define variables and constants
Clock myClock;

#define MAXCOUNT 16
uint8_t i = 0;
uint32_t chrono[MAXCOUNT];

#define initialPeriod_ms 1000
#define repeatedPeriod_ms 100

uint8_t status = 0;
const uint8_t myLED = BLUE_LED;

void clockFunction()
{
    chrono[i] = micros();
    i++;
    status = 1 - status;
    digitalWrite(myLED, status);
    //    Serial.print(".");
}


// Add setup code
void setup()
{
    delay(500);
    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println("*** Clock Library");
    delay(500);
    pinMode(myLED, OUTPUT);

    xdc_runtime_Types_FreqHz freq;
    BIOS_getCpuFreq(&freq);
    Serial.print("FreqHz.hi = ");
    Serial.println(freq.hi, DEC);
    Serial.print("FreqHz.lo = ");
    Serial.println(freq.lo, DEC);
    Serial.print("microsecondsToClockCycles = ");
    Serial.println(microsecondsToClockCycles(1), DEC);
    Serial.print("Clock_tickPeriod = ")
    Serial.println(Clock_tickPeriod, DEC);
    Serial.print("myClock.begin... ");
    myClock.begin(clockFunction, initialPeriod_ms, repeatedPeriod_ms); // 1000 ms = 1 s
    Serial.println("done");

    Serial.print("myClock.start... ");
    myClock.start();
    Serial.println("done");
    chrono[i] = micros();
    i++;

    Serial.print("# 0,\tus = ");
    Serial.println(chrono[0], DEC);
}

void printX10(int32_t number)
{
    Serial.print(number / 10, DEC);
    Serial.print(".");
    if (number < 0)
    {
        number *= -1;
    }
    Serial.print(number % 10, DEC);
}

// Add loop code
void loop()
{
    if (i >= MAXCOUNT)
    {
        myClock.stop();
        Serial.println();

        for (uint8_t j = 1; j < MAXCOUNT; j++)
        {
            Serial.print("# ");
            Serial.print(j, DEC);
            Serial.print(",\tus = ");
            Serial.print(chrono[j], DEC);
            Serial.print(" - ");
            Serial.print(chrono[j - 1], DEC);
            Serial.print(" = ");
            Serial.println(chrono[j] - chrono[j - 1], DEC);
        }
        Serial.println();

        Serial.print("Initial period quality = ");
        printX10((int32_t)(chrono[1] - chrono[0]) / initialPeriod - 1000);
        Serial.println("%");

        if (repeatedPeriod > 0)
        {
            Serial.print("Repeated period quality = ");
            printX10((int32_t)(chrono[MAXCOUNT - 1] - chrono[1]) / (MAXCOUNT - 2) / repeatedPeriod - 1000);
            Serial.println("%");
        }

        Serial.println("***");
        while (1);
    }

    delay(100);
}


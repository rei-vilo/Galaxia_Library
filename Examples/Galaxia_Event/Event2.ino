///
/// @file		Event2.ino
/// @brief		Events for Energia MT
/// @details	Example of Events for Hackster.io
/// @n
/// @n @b		Project EMT-event
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		05/06/2015 21:07
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Include core, application, user and local libraries
#include "Energia.h"
#include "rtosGlobals.h"

// Setup
void Event2_setup()
{
    myEvent2.begin();
    Serial.begin(115200);
    delay(10);
}

// Loop
void Event2_loop()
{
    myEvent2.send(Event_Id_02);

    mySemaphore.waitFor();
    Serial.print(millis(), DEC);
    Serial.print("\t: myEvent2  2  (");
    Serial.print(bin2String(Event_Id_02));
    Serial.println(")");
    mySemaphore.post();

    delay(5000);
}


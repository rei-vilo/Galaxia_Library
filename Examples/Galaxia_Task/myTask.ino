///
/// @file		myTask.ino
/// @brief		Sketch with Galaxia Task for Energia MT
/// @details	Task example with Galaxia library for Energia MT
/// @n
/// @n @b		Project Galaxia_Task
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		ReiVilo
/// @author		ReiVilo
///
/// @date		14/04/2016 17:16
/// @version	201
///
/// @copyright	(c) ReiVilo, 2015-2016
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Core library for code-sense - IDE-based
#if defined(EMBEDXCODE)
#if defined(ENERGIA_WITH_RTOS) || defined(ENERGIA_MT) // Energia MT only
#include "Energia.h"
#else
#error Energia MT only
#endif // end Energia MT
#endif // end embedXcode IDE

// Include application, user and local libraries
#include "Galaxia.h"


// Prototypes
void functionTask();


// Define variables and constants
Event   myEvent;
Task    myTask;
Clock   myClock;
uint8_t valueB = 0;

void functionTask()
{
    while (true)
    {
        myEvent.waitFor();
        valueB = 1 - valueB;
        digitalWrite(BLUE_LED, valueB);
    }
}

void functionTimer()
{
    myEvent.send();
}

// Setup
void myTask_setup()
{
    myEvent.begin();

    pinMode(BLUE_LED, OUTPUT);
    myTask.begin(functionTask, Task_numPriorities - 1);

    myClock.begin(functionTimer, 1000, 333);
    myClock.start();
}

// Loop
void myTask_loop()
{
    ;
}


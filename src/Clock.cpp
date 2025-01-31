//
// Clock.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project      Galaxia library for Energia MT
//
// Created by 	Rei Vilo, Jun 17, 2015 09:59
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015-2016
// Licence		CC = BY SA NC
//
// See 			Clock.h and ReadMe.txt for references
//


// Library header
#include "Clock.h"

// Code
Clock::Clock()
{
    ;
}

Clock::~Clock()
{
    ;
}

void Clock::begin(void (*ClockFunction)(void), uint32_t ClockTimeOut_ms, uint32_t ClockPeriod_ms)
{
    Error_Block eb;
    Error_init(&eb);

    Clock_Params_init(&ClockParams);
    ClockParams.startFlag = false; // Requires Clock_start

    // ClockParams.period = microsecondsToClockCycles(ClockPeriod_ms); // ms to be translated into ticks
    // ClockHandle = Clock_create( (Clock_FuncPtr)ClockFunction, microsecondsToClockCycles(ClockTimeOut_ms), &ClockParams, &eb);

    // Surprisingly, period already defined in ms for ClockParams.period andClockTimeOut_ms
    // Reason: Clock_tickPeriod = 1000
    // ClockPeriod_ms = in ms
    // ClockPeriod_ms * 1000 = in us
    // ClockPeriod_ms * 1000 / Clock_tickPeriod = in ticks

    ClockParams.period = ((ClockPeriod_ms * 1000) / Clock_tickPeriod);
    ClockHandle = Clock_create((Clock_FuncPtr)ClockFunction, (ClockTimeOut_ms * 1000) / Clock_tickPeriod, &ClockParams, &eb);

    if (ClockHandle == NULL)
    {
        // Serial.println("*** Clock create failed");
        System_abort("Clock create failed");
    }
}

void Clock::start()
{
    Clock_start(ClockHandle);
}

void Clock::stop()
{
    Clock_stop(ClockHandle);
}

//
// Timer.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode+
// http://embedXcode.weebly.com
//
// Project      Galaxia library for Energia MT
//
// Created by 	Rei Vilo, Jun 17, 2015 09:29
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015-2016
// Licence		CC = BY SA NC
//
// See 			Timer.h and ReadMe.txt for references
//


// Library header
#include "Timer.h"

// Code
Timer::Timer()
{
    ;
}

void Timer::begin(void (*timerFunction)(void), uint32_t ClockPeriod_ms) // , uint32_t unit)
{
    Error_Block eb;
    Error_init(&eb);

    // xdc_UInt TimerId = 3; // OK=3, NOK=2,1,0 MSP432=4 timers, only timer 3 available
    // Timer_ANY to take any available timer
    xdc_UInt TimerId = Timer_ANY;

    Timer_Params params;
    Timer_Params_init(&params);
    params.periodType = Timer_PeriodType_MICROSECS;
    params.period = (uint32_t)((uint64_t)(1000 * ClockPeriod_ms / Clock_tickPeriod)); // * unit; // 1 ms = 1000 us
    params.startMode = Timer_StartMode_USER; // Timer_start

    TimerHandle = Timer_create(TimerId, (Timer_FuncPtr)timerFunction, &params, &eb);

    if (TimerHandle == NULL)
    {
        // Serial.println("*** Timer create failed");
        System_abort("Timer create failed");
    }
}

void Timer::start()
{
    Timer_start(TimerHandle);
}

void Timer::stop()
{
    Timer_stop(TimerHandle);
}

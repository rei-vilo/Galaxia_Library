//
// Event.cpp
// Code file
// ----------------------------------
//
// Project      Galaxia library for Energia MT
//
//
// Created by 	Rei Vilo, Jun 08, 2015 09:53
// 				http://embeddedcomputing.weebly.com
//
// Copyright 	(c) Rei Vilo, 2015-2016
// Licence		CC = BY SA NC
//
// See 			Event.h and ReadMe.txt for references
//

#include "Event.h"

Event::Event()
{
    ;
}

void Event::begin()
{
    Error_Block eb;
    Error_init(&eb);
    
    Event_Params params;
    Event_Params_init(&params);
    
    EventHandle = Event_create(&params, &eb);
    
    if (EventHandle == NULL)
    {
        System_abort("Event create failed");
    }
}

uint32_t Event::waitFor(xdc_UInt andMask, xdc_UInt orMask)
{
    return Event_pend(EventHandle, andMask, orMask, BIOS_WAIT_FOREVER);
}

void Event::send(xdc_UInt eventId_number)
{
    Event_post(EventHandle, eventId_number);
}

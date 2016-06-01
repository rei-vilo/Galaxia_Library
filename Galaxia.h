///
/// @file		Galaxia.h
/// @brief		RTOS Clock, part of the Galaxia Library Suite
/// @details	Galaxia library Simple header for Energia MT
/// @n
/// @n @b		Project Galaxia library for Energia MT
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Rei Vilo, Jun 17, 2015 09:59
/// @version	201
///
/// @copyright	(c) Rei Vilo, 2015-2016
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///
///
/// The Galaxia Library Suite includes
///
/// * Thread elements
///     * HWI
///     * SWI (1)
///     * SWI with trigger (SWItrigger) (1)
///     * Task
///
/// * Synchronisation elements
///     * Clock
///     * Event
///     * Mailbox (2)
///     * Semaphore
///     * Timer (3)
///
/// @n  (1) SWI has been removed from RTOS for Energia MT 0101E0017
/// @n  (2) Mailbox supersedes Queue
/// @n  (3) Clock recommended over Timer
///
/// @n
/// @n
/// Examples include
///
/// * Galaxia_Clock
/// * Galaxia_Event
/// * Galaxia_HWI
/// * Galaxia_Mailbox
/// * Galaxia_Semaphore
/// * Galaxia_SWI
/// * Galaxia_SWItrigger
/// * Galaxia_Task
/// * Galaxia_Timer
/// * multiBlink_with_Clock
///
///
/// @see    http://embeddedcomputing.weebly.com/exploring-rtos.html
///

#ifndef Galaxia_h
#define Galaxia_h

// Threads
#include "Task.h"
#include "HWI.h"
// SWI has been removed from RTOS for Energia MT 0101E0017
//#include "SWI.h"
//#include "SWItrigger.h"

// Synchronisation
#include "Event.h"
// Mailbox supersedes Queue
#include "Mailbox.h"
#include "Semaphore.h"
#include "Clock.h"
// Clock recommended over Timer
#include "Timer.h"

#endif
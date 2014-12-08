/*
 * OpenHMD - Free and Open Source API and drivers for immersive technology.
 * Copyright (C) 2013 Fredrik Hultin.
 * Copyright (C) 2013 Jakob Bornecrantz.
 * Distributed under the Boost 1.0 licence, see LICENSE for full text.
 */

/* Internal Interface for Platform Specific Functions */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "openhmd.h"

#ifdef _MSC_VER
#define OHMD_THREAD_LOCAL __declspec( thread )
#else
#define OHMD_THREAD_LOCAL __thread
#endif

double ohmd_get_tick();
void ohmd_sleep(double seconds);

typedef struct ohmd_thread ohmd_thread;
typedef struct ohmd_mutex ohmd_mutex;

ohmd_mutex* ohmd_create_mutex();
void ohmd_destroy_mutex(ohmd_mutex* mutex);

void ohmd_lock_mutex(ohmd_mutex* mutex);
void ohmd_unlock_mutex(ohmd_mutex* mutex);

ohmd_thread* ohmd_create_thread(unsigned int (*routine)(void* arg), void* arg);
void ohmd_destroy_thread(ohmd_thread* thread);

#endif

//
// Created by ab on 16/02/2020.
//

#ifndef PSU_2019_MALLOC_DEBUG_H

#include <stddef.h>

// Those variable allow you to control dump(scale) function

//#define _DUMP : enable dump
//#define _VISUAL_DUMP : enable very cool visual dump (use scale arg)
//#define _NUMERIC_DUMP : enable value dump
//#define _ERROR_DUMP : check for infinite loop in memory

void iprint(size_t n);
void dump(int scaling);

#define PSU_2019_MALLOC_DEBUG_H

#endif // PSU_2019_MALLOC_DEBUG_H

#ifndef _UTILS_H_
#define _UTILS_H_

#include <stddef.h>
#include <stdio.h>

void Utils_EnsureArrayCapacity
(   
    void**          content,
    size_t          element_size,
    unsigned int*   current_capacity,
    unsigned int    expected_size
);

void Utils_PrintTabs(FILE* stream, unsigned int level);
void Utils_PrintLine(FILE* stream, char c, unsigned int size, unsigned int level);

#endif
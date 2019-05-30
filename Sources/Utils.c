#include "Utils.h"

#include <assert.h>
#include <stdlib.h>

static unsigned int max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

void Utils_EnsureArrayCapacity(void** content, size_t element_size, unsigned int* current_capacity, unsigned int expected_capacity)
{
    assert(*current_capacity > 0 || *content == NULL);

    if (expected_capacity <= *current_capacity)
    {
        return;
    }

    *current_capacity = max(expected_capacity, (*current_capacity) * 2);
    *content = realloc(*content, element_size * (*current_capacity));
}

void Utils_PrintTabs(FILE* stream, unsigned int level)
{
    fprintf(stream, "%*s", level * 4, "");
}

void Utils_PrintLine(FILE* stream, char c, unsigned int size, unsigned int level)
{
    Utils_PrintTabs(stream, level);
    for (int i = 0; i < size; ++i)
    {
        fputc(c, stream);
    }
    fputc('\n', stream);
}

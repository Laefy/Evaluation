#ifndef _UNIT_H_
#define _UNIT_H_

#include "Category.h"
#include "Assignment.h"

typedef enum { UNIT_TAG_ASSIGNMENT, UNIT_TAG_CATEGORY } UnitTag;

union _Unit
{
    int         tag;
    Assignment  assignment;
    Category    category;
};

typedef union _Unit Unit;

Assignment* Unit_MakeAssignment(Unit* unit, const char* name, unsigned int total);
Category*   Unit_MakeCategory(Unit* unit, const char* name, unsigned int coef);
void        Unit_Destroy(Unit* unit);
Score       Unit_ComputeScore(Unit* unit);
void        Unit_PrintReport(const Unit* unit, FILE* stream, unsigned int level);

#endif
#include "Unit.h"

#include <assert.h>
#include <string.h>

Assignment* Unit_MakeAssignment(Unit* unit, const char* name, unsigned int total)
{
    Assignment copy = Assignment_Create(name, total);
    memcpy(&unit->assignment, &copy, sizeof(Assignment));
    
    unit->tag = UNIT_TAG_ASSIGNMENT;
    return &unit->assignment;
}

Category* Unit_MakeCategory(Unit* unit, const char* name, unsigned int coef)
{
    Category copy = Category_Create(name, coef);
    memcpy(&unit->category, &copy, sizeof(Category));

    unit->tag = UNIT_TAG_CATEGORY;
    return &unit->category;
}

void Unit_Destroy(Unit* unit)
{
    if (unit->tag == UNIT_TAG_ASSIGNMENT)
    {
        Assignment_Destroy(&unit->assignment);
    }
    else
    {
        assert(unit->tag == UNIT_TAG_CATEGORY);
        Category_Destroy(&unit->category);
    }
}

Score Unit_ComputeScore(Unit* unit)
{
    if (unit->tag == UNIT_TAG_ASSIGNMENT)
    {
        return Assignment_ComputeScore(&unit->assignment);
    }
    else
    {
        assert(unit->tag == UNIT_TAG_CATEGORY);
        return Category_ComputeScore(&unit->category);
    }
}

void Unit_PrintReport(const Unit* unit, FILE* stream, unsigned int level)
{
    if (unit->tag == UNIT_TAG_ASSIGNMENT)
    {
        Assignment_PrintReport(&unit->assignment, stream, level);
    }
    else
    {
        assert(unit->tag == UNIT_TAG_CATEGORY);
        Category_PrintReport(&unit->category, stream, level);
    }
}

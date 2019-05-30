#include "Category.h"
#include "Unit.h"
#include "Utils.h"

#include <assert.h>
#include <stdlib.h>

static Unit* Category_AddUnit(Category* category);

Category Category_Create(const char* name, unsigned int coef)
{
    Category category =
    {
        .name = name,
        .coef = coef,
        .score = Score_Create(0),
        .units = NULL,
        .size = 0,
        .capacity = 0,
    };

    return category;
}

void Category_Destroy(Category* category)
{
    for (unsigned int i = 0; i < category->size; ++ i)
    {
        Unit_Destroy(&category->units[i]);
    }

    free(category->units);
}

Unit* Category_AddUnit(Category* category)
{
    unsigned int old_size = category->size;
    Utils_EnsureArrayCapacity((void**)&category->units, sizeof(Unit), &category->capacity, ++ category->size);
    return &category->units[old_size];
}

Assignment* Category_AddAssignment(Category* category, const char* name, unsigned int total)
{
    Unit* unit = Category_AddUnit(category); 
    return Unit_MakeAssignment(unit, name, total);
}

Category* Category_AddCategory(Category* category, const char* name, unsigned int coef)
{
    Unit* unit = Category_AddUnit(category); 
    return Unit_MakeCategory(unit, name, coef);
}

Score Category_ComputeScore(Category* category)
{
    assert(category->score.total == 0);
    assert(category->size > 0);

    for (unsigned int i = 0; i < category->size; ++ i)
    {
        Score unit = Unit_ComputeScore(&category->units[i]);
        Score_Add(&category->score, &unit);
    }

    Score r = category->score;
    Score_Multiply(&r, category->coef);
    return r;
}

void Category_PrintReport(const Category* category, FILE* stream, unsigned int level)
{
    fputc('\n', stream);
    Utils_PrintTabs(stream, level);
    int c = fprintf(stream, " %s : %d/%d (coef %d)\n", category->name, category->score.score, category->score.total, category->coef);
    Utils_PrintLine(stream, '-', c, level);

    for (unsigned int i = 0; i < category->size; ++ i)
    {
        Unit_PrintReport(&category->units[i], stream, level + 1);
    }
}

#ifndef _CATEGORY_H_
#define _CATEGORY_H_

#include "Assignment.h"
#include "Score.h"

#include <stdio.h>

union _Unit;

struct _Category
{
    int                 tag;
    
    const char*         name;
    const unsigned int  coef;
    Score               score;

    union _Unit*        units;
    unsigned int        size;
    unsigned int        capacity;
};

typedef struct _Category Category;

Category    Category_Create(const char* name, unsigned int coef);
void        Category_Destroy(Category* category);
Assignment* Category_AddAssignment(Category* category, const char* name, unsigned int total);
Category*   Category_AddCategory(Category* category, const char* name, unsigned int coef);
Score       Category_ComputeScore(Category* category);
void        Category_PrintReport(const Category* category, FILE* stream, unsigned int level);

#endif
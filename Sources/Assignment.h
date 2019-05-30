#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include "Score.h"
#include "Test.h"

#include <stdio.h>

struct _Assignment
{
    int                 tag;

    const char*         name;
    Score               score;

    Test*               tests;
    unsigned int        size;
    unsigned int        capacity;
};

typedef struct _Assignment Assignment;

Assignment  Assignment_Create(const char* name, unsigned int total);
void        Assignment_Destroy(Assignment* assignment);
void        Assignment_Test(Assignment* assignment, const char* message, TestResult result);
Score       Assignment_ComputeScore(Assignment* assignment);
void        Assignment_PrintReport(const Assignment* assignment, FILE* stream, unsigned int level);

#endif
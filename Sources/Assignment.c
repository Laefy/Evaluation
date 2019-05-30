#include "Assignment.h"
#include "Utils.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

Assignment Assignment_Create(const char* name, unsigned int total)
{
    Assignment assignment =
    {
        .name = name,
        .score = Score_Create(total),
        .tests = NULL,
        .size = 0,
        .capacity = 0,
    };

    return assignment;
}

void Assignment_Destroy(Assignment* assignment)
{
    for (unsigned int i = 0; i < assignment->size; ++ i)
    {
        Test_Destroy(&assignment->tests[i]);
    }

    free(assignment->tests);
}

void Assignment_Test(Assignment* assignment, const char* message, TestResult result)
{
    unsigned int old_size = assignment->size;
    Utils_EnsureArrayCapacity((void**)&assignment->tests, sizeof(Test), &assignment->capacity, ++ assignment->size);
    
    Test copy = Test_Create(message, result);
    memcpy(&assignment->tests[old_size], &copy, sizeof(Test));
}

Score Assignment_ComputeScore(Assignment* assignment)
{
    assert(assignment->size > 0);

    int score = assignment->score.total;

    for (unsigned int i = 0; i < assignment->size; ++ i)
    {
        if (Test_Fails(&assignment->tests[i]))
        {
            score = 0;
            break;
        }
    }

    assignment->score.score = score;
    return assignment->score;
}

void Assignment_PrintReport(const Assignment* assignment, FILE* stream, unsigned int level)
{
    fputc('\n', stream);
    Utils_PrintTabs(stream, level);
    int c = fprintf(stream, "%s (%d pts)\n", assignment->name, assignment->score.total);
    Utils_PrintLine(stream, '`', c - 1, level);

    for (unsigned int i = 0; i < assignment->size; ++ i)
    {
        Test_PrintReport(&assignment->tests[i], stream, level + 1);
    }
}

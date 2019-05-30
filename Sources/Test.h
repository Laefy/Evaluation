#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>

typedef enum { TEST_RESULT_SUCCESS, TEST_RESULT_FAILURE } TestResult;

struct _Test
{
    const char*         message;
    const TestResult    result;
};

typedef struct _Test Test;

Test    Test_Create(const char* message, TestResult result);
void    Test_Destroy(Test* test);
int     Test_Fails(const Test* test);
void    Test_PrintReport(const Test* test, FILE* stream, unsigned int level);

#endif
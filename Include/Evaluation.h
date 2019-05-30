#ifndef _EVALUATION_H_
#define _EVALUATION_H_

#include <stdio.h>

typedef enum { TEST_RESULT_SUCCESS, TEST_RESULT_FAILURE } TestResult;

typedef struct _Evaluation Evaluation;
typedef struct _Category Category;
typedef struct _Assignment Assignment;

Evaluation* Evaluation_Create(const char* name, const char* student, unsigned int total);
void        Evaluation_Destroy(Evaluation* evaluation);
Category*   Evaluation_AddCategory(Evaluation* evaluation, const char* name, unsigned int coef);
void        Evaluation_ComputeScore(Evaluation* evaluation);
void        Evaluation_PrintReport(const Evaluation* evaluation, FILE* stream);

Assignment* Category_AddAssignment(Category* category, const char* name, unsigned int total);
Category*   Category_AddCategory(Category* category, const char* name, unsigned int coef);

void        Assignment_Test(Assignment* assignment, const char* message, TestResult result);

#endif
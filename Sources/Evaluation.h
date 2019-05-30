#ifndef _EVALUATION_H_
#define _EVALUATION_H_

#include "Category.h"
#include "Assignment.h"

#include <stdio.h>

typedef struct _Evaluation Evaluation;

Evaluation* Evaluation_Create(const char* name, const char* student, unsigned int total);
void        Evaluation_Destroy(Evaluation* evaluation);
Category*   Evaluation_AddCategory(Evaluation* evaluation, const char* name, unsigned int coef);
void        Evaluation_ComputeScore(Evaluation* evaluation);
void        Evaluation_PrintReport(const Evaluation* evaluation, FILE* stream);

#endif
#include "Evaluation.h"
#include "Score.h"
#include "Unit.h"
#include "Utils.h"

#include <stdlib.h>
#include <string.h>

struct _Evaluation
{
    const char*         name;
    const char*         student;
    const unsigned int  total;
    Category            content;
};

Evaluation* Evaluation_Create(const char* name, const char* student, unsigned int total)
{
    Evaluation copy =
    {
        .name = name,
        .student = student,
        .total = total,
        .content = Category_Create("", 0),
    };

    Evaluation* evaluation = (Evaluation*)malloc(sizeof(Evaluation));
    memcpy(evaluation, &copy, sizeof(Evaluation));

    return evaluation;
}

void Evaluation_Destroy(Evaluation* evaluation)
{
    Category_Destroy(&evaluation->content);
    free(evaluation);
}

Category* Evaluation_AddCategory(Evaluation* evaluation, const char* name, unsigned int coef)
{
    return Category_AddCategory(&evaluation->content, name, coef);
}

void Evaluation_ComputeScore(Evaluation* evaluation)
{
    Category_ComputeScore(&evaluation->content);
}

void Evaluation_PrintReport(const Evaluation* evaluation, FILE* stream)
{
    int c1 = fprintf(stream, " Evaluation %s - %s\n", evaluation->name, evaluation->student);
    Utils_PrintLine(stream, '=', c1, 0);

    const Category* content = &evaluation->content;
    float score = (float)content->score.score / content->score.total * evaluation->total;
    fprintf(stream, " Total: %.2f / %d\n\n", score, evaluation->total);
    
    for (unsigned int i = 0; i < content->size; ++ i)
    {
        Category_PrintReport(&content->units[i].category, stream, 0);
        fputc('\n', stream);
    }

    fflush(stream);
}

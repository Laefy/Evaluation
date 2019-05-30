#include "../Include/Evaluation.h"

#include <stdio.h>

int main()
{
    Evaluation* evaluation = Evaluation_Create("Examen", "Jane Doe", 20);
    
    // EX1
    Category* ex1 = Evaluation_AddCategory(evaluation, "Exercice 1", 2);
    {
        // Q1
        Assignment* q1 = Category_AddAssignment(ex1, "Question 1", 1);
        Assignment_Test(q1, "T", TEST_RESULT_SUCCESS);

        // Q2
        Assignment* q2 = Category_AddAssignment(ex1, "Question 2", 3);
        Assignment_Test(q2, "T1", TEST_RESULT_SUCCESS);
        Assignment_Test(q2, "T2", TEST_RESULT_SUCCESS);
    }

    // EX2
    Category* ex2 = Evaluation_AddCategory(evaluation, "Exercice 2", 5);
    {
        Assignment* q = Category_AddAssignment(ex2, "Question", 1);
        Assignment_Test(q, "T", TEST_RESULT_FAILURE);
    }

    // EX3
    Category* ex3 = Evaluation_AddCategory(evaluation, "Exercice 3", 5);
    {
        // A
        Category* a = Category_AddCategory(ex3, "Part A", 1);
        {
            // Q1
            Assignment* q1 = Category_AddAssignment(a, "Question 1", 1);
            Assignment_Test(q1, "T1", TEST_RESULT_SUCCESS);
            Assignment_Test(q1, "T2", TEST_RESULT_FAILURE);

            // Q2
            Assignment* q2 = Category_AddAssignment(a, "Question 2", 1);
            Assignment_Test(q2, "T1", TEST_RESULT_SUCCESS);
            Assignment_Test(q2, "T2", TEST_RESULT_SUCCESS);
        }

        // EX3 - B
        Category* b = Category_AddCategory(ex3, "Part B", 2);
        {
           // Q1
            Assignment* q1 = Category_AddAssignment(b, "Question 1", 1);
            Assignment_Test(q1, "T", TEST_RESULT_SUCCESS);

            // Q2
            Assignment* q2 = Category_AddAssignment(b, "Question 2", 1);
            Assignment_Test(q2, "T", TEST_RESULT_FAILURE);
        }
    }

    Evaluation_ComputeScore(evaluation);
    Evaluation_PrintReport(evaluation, stdout);

    Evaluation_Destroy(evaluation);

    return 0;
}
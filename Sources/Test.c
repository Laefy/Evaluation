#include "Test.h"
#include "Utils.h"

Test Test_Create(const char* message, TestResult result)
{
    Test test =
    {
        .message = message,
        .result = result,
    };

    return test;
}

void Test_Destroy(Test* test)
{
    (void)(test);
}

int Test_Fails(const Test* test)
{
    return test->result == TEST_RESULT_FAILURE;
}

void Test_PrintReport(const Test* test, FILE* stream, unsigned int level)
{
    Utils_PrintTabs(stream, level);
    fprintf(stream, "Test: %s\n", test->message);

    const char* values[] =
    {
        [TEST_RESULT_SUCCESS] = "SUCCESS",
        [TEST_RESULT_FAILURE] = "FAILURE",
    };

    Utils_PrintTabs(stream, level);
    fprintf(stream, "   => %s\n", values[test->result]);
}


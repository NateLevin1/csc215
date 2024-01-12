#include "string.h"

#define TEST_INT(func, expected, arguments) \
    { \
    int result = func arguments; \
    if(result == expected) \
        printf("\033[32m✓\033[0m Passed: %s%s = %d\n", #func, #arguments, result); \
    else \
        printf("\033[31m✗ Failed:\033[0m %s%s should be %d, but got %d\n", #func, #arguments, expected, result); \
    };

#define TEST_STR(func, expected, arguments) \
    { \
    char* result = func arguments; \
    if(strcmp(result, expected) == 0) \
        printf("\033[32m✓\033[0m Passed: %s%s = \"%s\"\n", #func, #arguments, result); \
    else \
        printf("\033[31m✗ Failed: %s%s should be \"%s\", but got \"%s\"\033[0m\n", #func, #arguments, expected, result); \
    };

#define TEST_BOOL(boolean_expression) \
    { \
    if(boolean_expression) \
        printf("\033[32m✓\033[0m Passed: %s\n", #boolean_expression); \
    else \
        printf("\033[31m✗ Failed: %s\033[0m\n", #boolean_expression); \
    };

#define TEST_STR_ARR(func, expected, modified, arguments) \
    { \
    func arguments; \
    int size = sizeof(modified) / sizeof(*modified); \
    for(int i = 0; i < size; i++) { \
        if(modified[i] == expected[i]) \
            printf("\033[32m✓\033[0m Passed: %s%s[%d] = %s\n", #func, #arguments, i, modified[i]); \
        else \
            printf("\033[31m✗ Failed:\033[0m %s%s[%d] should be %s, but got %s\n", #func, #arguments, i, expected[i], modified[i]); \
    } \
    };

#define TEST_STR_MOD(func, expected, modified, arguments) \
    { \
    func arguments; \
    if(strcmp(modified, expected) == 0) \
        printf("\033[32m✓\033[0m Passed: %s%s = \"%s\"\n", #func, #arguments, modified); \
    else \
        printf("\033[31m✗ Failed: %s%s should be \"%s\", but got \"%s\"\033[0m\n", #func, #arguments, expected, modified); \
    };

#define BEGIN_TESTING(file) \
    printf("\n \033[36m---\033[0m %s \033[36m---\033[0m\n", file);

#define TEST(description) \
    printf("\n\033[34m-\033[0m %s\n", description);
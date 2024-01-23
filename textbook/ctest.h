/**
 *     .oooooo.       ooooooooooooo                        .
 *    d8P'  `Y8b      8'   888   `8                      .o8
 *   888                   888      .ooooo.    .oooo.o .o888oo
 *   888                   888     d88' `88b  d88(  "8   888
 *   888                   888     888ooo888  `"Y88b.    888
 *   `88b    ooo           888     888    .o  o.  )88b   888 .
 *    `Y8bood8P'          o888o    `Y8bod8P'  8""888P'   "888"
 *
 *
 *     C Test: A simple, macro-based testing framework for C
 *
 * Created by Nate Levin (@NateLevin1 on GitHub)
 * Last Updated: 2023-01-23
 *
 * Example Usage:
 * int main() {
 *     BEGIN_TESTING("filename.h");
 *
 *     TEST("describe what the test is testing") {
 *         TEST_INT(func, expected_return_int, (...arguments));
 *         TEST_STR(func, expected_return_str, (...arguments));
 *         TEST_BOOL(boolean_expression);
 *         TEST_STR_ARR(func, expected_str_arr, modified_str_arr, (...arguments));
 *     }
 * }
 *
 * NOTE: If your function modifies a string instead of returning a char*,
 *       use TEST_STR_MOD instead of TEST_STR. For example:
 *       TEST_STR_MOD(func, expected_str, modified_str, (...arguments)); // use when func modifies the string, instead of returning char*
 *
*/

#include <string.h>

#define BEGIN_TESTING(file) \
    printf("\n \033[36m---\033[0m %s \033[36m---\033[0m\n", file);

#define TEST(description) \
    printf("\n\033[34m-\033[0m %s\n", description);

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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include "homework1.h"

TEST_CASE("Test num_vowels function returns an integer")
{
    char s[] = "Test this!";
    CHECK(num_vowels(s) == 2);
}
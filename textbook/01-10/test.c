#include "stdio.h"
#include "acc_string.h"
#include "../testmacros.h"

int main() {
    BEGIN_TESTING("acc_string.h");

    TEST("10 (page 130)") {
        char* strings[] = { "Goransh", "Aditya", "Sarthak" };
        char* expected[] = { "Aditya", "Goransh", "Sarthak" };
        TEST_STR_ARR(acc_sort_strs, expected, strings, (strings, 3));
    }

    TEST("11 (page 130)") {
        TEST_INT(acc_countwords, 2, ("Hello World!"));
        TEST_INT(acc_countwords, 2, ("Hello     World!"));
        TEST_INT(acc_countwords, 5, ("Hello World!\nHow are you?"));

        TEST_INT(acc_countlines, 1, ("Hello World!"));
        TEST_INT(acc_countlines, 2, ("Hello World!\nHow are you?"));
    }

    TEST("12 (page 131)") {
        TEST_INT(is_palindrome, 1, ("racecar"));
        TEST_INT(is_palindrome, 1, ("madam"));
        TEST_INT(is_palindrome, 0, ("not-palindrome"));
        TEST_INT(is_palindrome, 0, ("ab"));
    }

    TEST("PE 21") {
        char str[] = "Hello; this, is a test";
        TEST_STR_MOD(delete_semis_and_replace_comma_w_period, "Hello this. is a test", str, (str));
        char str2[] = ";;;a;b,,,c,";
        TEST_STR_MOD(delete_semis_and_replace_comma_w_period, "ab...c.", str2, (str2));
    }

    TEST("PE 29") {
        char* students[] = { "Cyrus", "Edward", "Joseph", "Julissa", "Sheel" };
        char* output[6] = { 0 };
        char* expectedStudents[] = { "Cyrus", "Edward", "Joseph", "Julissa", "Nate", "Sheel" };
        TEST_STR_ARR(insert_sorted, expectedStudents, output, (students, 5, "Nate", output));
    }

    TEST("PE 30") {
        char* students[] = { "Cyrus", "Edward", "Joseph", "Julissa", "Nate", "Sheel" };
        char* output[5] = { 0 };
        char* expectedStudents[] = { "Cyrus", "Edward", "Joseph", "Julissa", "Sheel" };
        TEST_STR_ARR(remove_sorted, expectedStudents, output, (students, 6, "Nate", output));
    }
}


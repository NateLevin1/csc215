#include "acc_string.h"
#include "strings.h"

void acc_sort_strs(char** strings, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                char* temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int acc_countwords(char* string) {
    int count = 1;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\n') {
            count++;
            // consume any further whitespace
            while (string[i + 1] == ' ' || string[i + 1] == '\n') {
                i++;
            }
        }
    }
    return count;
}

int acc_countlines(char* string) {
    int lines = 1;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '\n') {
            lines++;
        }
    }
    return lines;
}

int is_palindrome(char* string) {
    int len = strlen(string);
    for (int i = 0; i < len / 2; i++) {
        if (string[i] != string[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void delete_semis_and_replace_comma_w_period(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ';') {
            // shift one character
            for (int j = i; j < strlen(string); j++) {
                string[j] = string[j + 1];
            }
            i--;
        }
        if (string[i] == ',') {
            string[i] = '.';
        }
    }
}

void insert_sorted(char** strings, int num_strs, char* string, char** output) {
    int i = 0;
    while (i < num_strs && strcmp(strings[i], string) < 0) {
        output[i] = strings[i];
        i++;
    }
    output[i] = string;
    while (i < num_strs) {
        output[i + 1] = strings[i];
        i++;
    }
}

void remove_sorted(char** strings, int num_strs, char* string, char** output) {
    int i = 0;
    while (i < num_strs && strcmp(strings[i], string) < 0) {
        output[i] = strings[i];
        i++;
    }
    while (i < num_strs - 1) {
        output[i] = strings[i + 1];
        i++;
    }
}

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fptr;
char* readline();

// Complete the timeInWords function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

char* get_n_word (int n){
    switch (n){
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "\b";            
    }
}

char* number_handler (int n){
    static char str[20];
    str[0] = '\0'; // make string empty 
    
    if (n < 20){
        strcat(str, get_n_word(n));
    } else if (n >= 20 && n < 30) {
        strcat(str, "twenty");
        if (n-20 != 0){
            strcat(str, " ");
            strcat(str, get_n_word(n-20));            
        }
    } else if (n >= 30 && n < 40) {
        strcat(str, "thirty ");
        strcat(str, get_n_word(n-30));
    } else if (n >= 40 && n < 50) {
        strcat(str, "forty ");
        strcat(str, get_n_word(n-40));
    } else if (n >= 50 && n < 60) {
        strcat(str, "fifty ");
        strcat(str, get_n_word(n-50));
    }
    return str;
}


char* timeInWords(int h, int m) {
    static char str[50];
    
    if (m == 0){
        strcat(str, number_handler(h));
        strcat(str, " o' clock");
    } else if (m == 1){
        strcat(str, "one minute past ");
        strcat(str, number_handler(h));
    } else if (m == 15){
        strcat(str, "quarter past ");
        strcat(str, number_handler(h));
    } else if (m == 30){
        strcat(str, "half past ");
        strcat(str, number_handler(h));
    } else if (m == 45){
        strcat(str, "quarter to ");
        strcat(str, number_handler(h+1));
    } else if (m <= 30 && m > 1){        
        strcat(str, number_handler(m));
        strcat(str, " minutes past ");
        strcat(str, number_handler(h));
    } else if (m > 30){
        strcat(str, number_handler(60-m));
        strcat(str, " minutes to ");
        strcat(str, number_handler(h+1));
    }
    return str;
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* h_endptr;
    char* h_str = readline();
    int h = strtol(h_str, &h_endptr, 10);

    if (h_endptr == h_str || *h_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = readline();
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = timeInWords(h, m);
    
    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}


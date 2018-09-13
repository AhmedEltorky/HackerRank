#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* readline();

// Complete the caesarCipher function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

int get_order_from_char(char c){
    c = tolower(c);
    switch(c){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case 'i':
            return 8;
        case 'j':
            return 9;
        case 'k':
            return 10;
        case 'l':
            return 11;
        case 'm':
            return 12;
        case 'n':
            return 13;
        case 'o':
            return 14;
        case 'p':
            return 15;
        case 'q':
            return 16;
        case 'r':
            return 17;
        case 's':
            return 18;
        case 't':
            return 19;
        case 'u':
            return 20;
        case 'v':
            return 21;
        case 'w':
            return 22;
        case 'x':
            return 23;
        case 'y':
            return 24;
        case 'z':
            return 25;
        default:
            return 100;       
    }
}

char get_char_from_order(int o){
    switch(o){
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        case 7:
            return 'h';
        case 8:
            return 'i';
        case 9:
            return 'j';
        case 10:
            return 'k';
        case 11:
            return 'l';
        case 12:
            return 'm';
        case 13:
            return 'n';
        case 14:
            return 'o';
        case 15:
            return 'p';
        case 16:
            return 'q';
        case 17:
            return 'r';
        case 18:
            return 's';
        case 19:
            return 't';
        case 20:
            return 'u';
        case 21:
            return 'v';
        case 22:
            return 'w';
        case 23:
            return 'x';
        case 24:
            return 'y';
        case 25:
            return 'z';
        default:
            return '?';       
    }
}

char* caesarCipher(char* s, int k) {
    int upper = 0;
    for (int i = 0;i < strlen(s);i++){
        if (isupper(s[i]) > 0){
            upper = 1;            
        }
        if (get_order_from_char(s[i]) != 100){
            s[i] = get_char_from_order((get_order_from_char(s[i]) + k) % 26);             
        }      
        if (upper == 1){
            upper = 0;
            s[i] = toupper(s[i]);
        }
    }
    
    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = caesarCipher(s, k);

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


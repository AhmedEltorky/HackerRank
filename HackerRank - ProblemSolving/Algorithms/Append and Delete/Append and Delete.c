#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the appendAndDelete function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

FILE* fptr;

int get_max_len(char* s, char* t){
    return (strlen(s) < strlen(t)) ? strlen(s): strlen(t);
}

char* appendAndDelete(char* s, char* t, int k) {
    
    if (k >= strlen(s) +  strlen(t)){
            return "Yes";
    } else if (strcmp(s, t) == 0){  // two strings are equals
        if (k % 2 == 0){
            return "Yes";            
        }     
    } else {
        int len = get_max_len(s, t);
        int index = -1;
        for (int i = 0;i < len;i++){
            if (s[i] != t[i]){
                index = i;
                break;
            }
        }
        if (index == -1){
            if (k == abs(strlen(s) - strlen(t))){
                return "Yes";            
            } else if ((k - abs(strlen(s) - strlen(t))) % 2 == 0) {
                return "Yes";
            } else {
                return "No";
            }
        }
        if (k >= ((strlen(s)-index) + (strlen(t)-index))){
            return "Yes";            
        }
    }
    
    return "No";
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* t = readline();

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = appendAndDelete(s, t, k);

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

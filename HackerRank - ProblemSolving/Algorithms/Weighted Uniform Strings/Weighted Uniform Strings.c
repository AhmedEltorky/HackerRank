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

// Complete the weightedUniformStrings function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//

int get_weight(char c){
    switch(c){
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;
        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        case 'i':
            return 9;
        case 'j':
            return 10;
        case 'k':
            return 11;
        case 'l':
            return 12;
        case 'm':
            return 13;
        case 'n':
            return 14;
        case 'o':
            return 15;
        case 'p':
            return 16;
        case 'q':
            return 17;
        case 'r':
            return 18;
        case 's':
            return 19;
        case 't':
            return 20;
        case 'u':
            return 21;
        case 'v':
            return 22;
        case 'w':
            return 23;
        case 'x':
            return 24;
        case 'y':
            return 25;
        case 'z':
            return 26;
        default:
            return 0;
    }
}

char** weightedUniformStrings(char* s, int queries_count, int* queries, int* result_count) {
    *result_count = queries_count;    
    static char** ret;
    ret = (char**) malloc(queries_count * sizeof(char*));
    for (int i = 0;i < queries_count;i++){
        *(ret + i) = (char*) malloc(3 * sizeof(char));
    }
    
    int sum;
    char last_char;
    for (int q = 0;q < queries_count;q++){
        ret[q] = "No";
        for (int i = 0;i < strlen(s);i++){
            sum = 0;
            last_char = s[i];
            for (int j = i;j < strlen(s);j++){
                if (s[j] == last_char){  
                    sum += get_weight(s[j]);
                    if (sum == queries[q]){
                        ret[q] = "Yes";
                        break;
                    } else if (sum > queries[q]){
                        break;                    
                    }
                } else {
                    break;
                }
            }
            if (ret[q] == "Yes"){
                break;
            }
        }
    }
    
    return ret;
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* queries_count_endptr;
    char* queries_count_str = readline();
    int queries_count = strtol(queries_count_str, &queries_count_endptr, 10);

    if (queries_count_endptr == queries_count_str || *queries_count_endptr != '\0') { exit(EXIT_FAILURE); }

    int* queries = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item_endptr;
        char* queries_item_str = readline();
        int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

        if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(queries + i) = queries_item;
    }

    int result_count;
    char** result = weightedUniformStrings(s, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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


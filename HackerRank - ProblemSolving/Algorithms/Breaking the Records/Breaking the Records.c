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
char** split_string(char*);

// Complete the breakingRecords function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//

void breakingRecords(int scores_count, int* scores, int* result_count) {
    int result[scores_count][3];
    *result_count = 2;
    
    for (int i = 0;i < scores_count;i++){
        result[i][0] = scores[i];
        result[i][1] = scores[i];
        result[i][2] = scores[i];
    }
    
    int max, min;
    int max_count = 0, min_count = 0;
    max = min = result[0][0];
    
    for (int i = 1;i < scores_count;i++){
        if (result[i][1] > max){
            max_count++;
            max = result[i][1];            
        } else {
            result[i][1] = max;
        }
        
        if (result[i][2] < min){
            min_count++;
            min = result[i][2];            
        } else {
            result[i][2] = min;
        }
    }
    
    int arr[2] = {max_count, min_count};
    
    fprintf(fptr, "%d %d\n", *(arr), *(arr+1));
    
    // return arr;
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** scores_temp = split_string(readline());

    int* scores = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* scores_item_endptr;
        char* scores_item_str = *(scores_temp + i);
        int scores_item = strtol(scores_item_str, &scores_item_endptr, 10);

        if (scores_item_endptr == scores_item_str || *scores_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(scores + i) = scores_item;
    }

    int scores_count = n;

    int result_count;
    // int* result = breakingRecords(scores_count, scores, &result_count);
    breakingRecords(scores_count, scores, &result_count);

    // fprintf(fptr, "%d\n", result_count);
    
//     for (int i = 0; i < result_count; i++) {
//         fprintf(fptr, "%d", *(result + i));

//         if (i != result_count - 1) {
//             fprintf(fptr, " ");
//         }
//     }

//     fprintf(fptr, "\n");

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}


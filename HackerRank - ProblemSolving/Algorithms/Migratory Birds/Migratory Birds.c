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

// Complete the migratoryBirds function below.
int migratoryBirds(int ar_count, int* ar) {    
    int freq_ar[ar_count][2];
    int indx = 0, max_count = 0;
    int NOT = 1, ret = 1000;
    
    for (int i = 0;i < ar_count;i++){
        freq_ar[i][0] = -1; 
        freq_ar[i][1] = 0;               
    }
    
    for (int i = 0;i < ar_count;i++){
        for (int j = 0;j < indx+1;j++){
            if (ar[i] == freq_ar[j][0]){
                freq_ar[j][1]++;
                NOT = 0;
            }
        }
        if (NOT == 1){
            freq_ar[indx][0] = ar[i];
            freq_ar[indx][1]++;
            indx++;
        }
        NOT = 1;
    }
    
    for (int i = 0;i < indx+1;i++){
        if (freq_ar[i][1] == max_count){
            if (freq_ar[i][0] < ret){
                ret = freq_ar[i][0];
            }
        } else if (freq_ar[i][1] > max_count){
            max_count = freq_ar[i][1];
            ret = freq_ar[i][0];            
        }
    }
    
    return ret;
    
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* ar_count_endptr;
    char* ar_count_str = readline();
    int ar_count = strtol(ar_count_str, &ar_count_endptr, 10);

    if (ar_count_endptr == ar_count_str || *ar_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** ar_temp = split_string(readline());

    int* ar = malloc(ar_count * sizeof(int));

    for (int i = 0; i < ar_count; i++) {
        char* ar_item_endptr;
        char* ar_item_str = *(ar_temp + i);
        int ar_item = strtol(ar_item_str, &ar_item_endptr, 10);

        if (ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(ar + i) = ar_item;
    }

    int result = migratoryBirds(ar_count, ar);

    fprintf(fptr, "%d\n", result);

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


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

// Complete the biggerIsGreater function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* biggerIsGreater(char* w) {
    int no_answer = 1;
    for (int i = 0;i < strlen(w)-1;i++){
        if (strcmp(&w[i], &w[i+1]) < 0){
            no_answer = 0;
            break;
        }
    }    
    if (no_answer == 1){
        return "no answer";        
    }

    int min = 1000, min_index = -1, index = -1;
    for (int j = 0;j < strlen(w)-1;j++){
        for (int i = 1;i < strlen(w);i++){
            if (strcmp(&w[i], &w[j]) > 0 && strcmp(&w[i], &w[j]) < min){
                min = strcmp(&w[i], &w[j]);
                min_index = i;
                index = j;
            }
        }
    }
    if (index != -1){
        char temp = w[index];
        w[index] = w[min_index];
        w[min_index] = temp;
    } else {
        return "Error";
    }
    // sorting
    // for (int j = strlen(w)-1;j > 0;j--){
    //     for (int i = min_index+1;i < j;i++){
    //         if (strcmp(&w[i], &w[i+1]) > 0){
    //             char temp = w[i];
    //             w[i] = w[i+1];
    //             w[i+1] = temp;
    //         }
    //     }
    // }
    return w;
    
//     char new_w[strlen(w)];
//     char ret_char[strlen(w)];
//     int min = 1000;
    
//     for (int i = 0;i < strlen(w);i++){
//         strcpy(new_w, w);
//         // fprintf(fptr, ">> %s\n", new_w);
//         // fprintf(fptr, ">>> %s\n", w);
//         for (int j = strlen(w)-1;j > 0;j--){
//             for (int k = j;k > 0;k--){
//                 char temp = new_w[k];
//                 new_w[k] = new_w[k-1];  
//                 new_w[k-1] = temp;  
//             }
//             if (strcmp(new_w, w) < min){
//                 min = strcmp(new_w, w);
//                 strcpy(ret_char, new_w);
//             }
//         }
//     }
//     fprintf(fptr, "##%s\n", ret_char);
//     return "no answer";
}

int main()
{
   fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* T_endptr;
    char* T_str = readline();
    int T = strtol(T_str, &T_endptr, 10);

    if (T_endptr == T_str || *T_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int T_itr = 0; T_itr < T; T_itr++) {
        char* w = readline();

        char* result = biggerIsGreater(w);

        fprintf(fptr, "%s\n", result);
    }

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


#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
FILE* fptr;

// Complete the alternate function below.
int alternate(char* s) {
    char start[strlen(s)];
    char second[strlen(s)];
    for (int i = 0;i < strlen(start);i++){start[i] = '0';}
    char c1, c2;
    int sum = 0, max = 0, check, start_index = 0, second_index = 0, char_exist = 0;
    
    for (int i = 0;i < strlen(s) - 1;i++){
        // check for start char
        for (int v = 0;v < start_index;v++){
            if (start[v] == s[i]){
                char_exist = 1; 
                break;
            }
        }
        if (char_exist == 1){
            char_exist = 0;
            continue;
        }
        c1 = s[i];
        start[start_index] = c1;
        start_index++;
        for (int i = 0;i < strlen(start);i++){second[i] = '0';}
        // choose second char
        for (int j = i+1;j < strlen(s);j++){
            if (s[j] == c1){
                break;
            } else {
                // check for second char
                for (int v = 0;v < second_index;v++){
                    if (second[v] == s[j]){
                        char_exist = 1; 
                        break;
                    }
                }
                if (char_exist == 1){
                    char_exist = 0;
                    continue;                    
                } else {
                    c2 = s[j]; 
                    second[second_index] = c2;
                    second_index++;
                }
            }
            check = 1;
            for (int k = j+1;k < strlen(s);k++){
                if (check == 1){
                    if (s[k] == c2){
                        sum = 0;
                        break;                        
                    } else if (s[k] == c1){
                        sum++;
                        check = 2;  
                    }
                } else if (check == 2){
                    if (s[k] == c1){
                        sum = 0;
                        break;                        
                    } else if(s[k] == c2){
                        sum++;
                        check = 1;  
                    }                    
                }   
            }
            if (sum >  max){
                max = sum;  
            }
            sum = 0;
        }
    }
    
    if (max > 0){max+=2;}
    return max;
}

int main()
{
    fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* l_endptr;
    char* l_str = ltrim(rtrim(readline()));
    int l = strtol(l_str, &l_endptr, 10);

    if (l_endptr == l_str || *l_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    int result = alternate(s);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}


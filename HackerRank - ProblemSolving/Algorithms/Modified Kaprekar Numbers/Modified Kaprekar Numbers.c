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

// Complete the kaprekarNumbers function below.
void kaprekarNumbers1(int p, int q){
    int mult, digit, ans, flag = 0;
    long s;
    
    for (int i = p;i <= q;i++){
        mult = 1;
        digit = 0;
        do {
            mult *= 10;
            s = i * i;
            ans = s/mult;
            digit++;
        } while(ans != 0);
        
        int n = digit/2;
        int m = digit - n;
        int n1 = s/(10*pow(10, m));
        int n2 = s - (n1*pow(10, m));
        if (n1 + n2 == i){
            printf("%d ", i);  
            flag = 1;
        }
    }
    
    if (flag == 0){
        printf("%s\n", "INVALID RANGE");        
    }
}


void kaprekarNumbers2(int p, int q) {
    int flag = 0;
    for (int i = p;i <= q;i++){
        long s = i * i;
        if (s/10 == 0){
            if (i == s){
                printf("%d ", i);
                flag = 1;
            }
        } else if (s/100 == 0){
            int n1 = s/10;
            int n2 = s - (n1*10);
            if (n1 + n2 == i){
                printf("%d ", i); 
                flag = 1;
            }
        } else if (s/1000 == 0){
            int n1 = s/100;
            int n2 = s - (n1*100);
            if (n1 + n2 == i){
                printf("%d ", i);
                flag = 1;
            }            
        } else if (s/10000 == 0){
            int n1 = s/100;
            int n2 = s - (n1*100);
            if (n1 + n2 == i){
                printf("%d ", i);
                flag = 1;
            }            
        } else if (s/100000 == 0){
            int n1 = s/1000;
            int n2 = s - (n1*1000);
            if (n1 + n2 == i){
                printf("%d ", i);
                flag = 1;
            }            
        } else if (s/1000000 == 0){
            int n1 = s/1000;
            int n2 = s - (n1*1000);
            if (n1 + n2 == i){
                printf("%d ", i);
                flag = 1;
            }            
        } else if (s/10000000 == 0){
            int n1 = s/10000;
            int n2 = s - (n1*10000);
            if (n1 + n2 == i){
                printf("%d ", i);  
                flag = 1;
            }            
        } else if (s/100000000 == 0){
            int n1 = s/10000;
            int n2 = s - (n1*10000);
            if (n1 + n2 == i){
                printf("%d ", i);  
                flag = 1;
            }            
        } else if (s/1000000000 == 0){
            int n1 = s/100000;
            int n2 = s - (n1*100000);
            if (n1 + n2 == i){
                printf("%d ", i); 
                flag = 1;
            }            
        } else if (s/10000000000 == 0){
            int n1 = s/100000;
            int n2 = s - (n1*100000);
            if (n1 + n2 == i){
                printf("%d ", i); 
                flag = 1;               
            }            
        } 
    }
    
    if (flag == 0){
        printf("%s\n", "INVALID RANGE");        
    }
}

// correct one
void kaprekarNumbers(int p, int q) {
    int flag = 0;

    for (int i = p;i <= q;i++){
        if (i == 1){
            printf("%d ", i);
            flag = 1;
            continue;
        }
        long s = pow(i, 2);
        char b[16];
        sprintf(b, "%ld", s);
        
        if (strlen(b) > 1){
            char n1[8], n2[8];
            strncpy(n1, b, strlen(b)/2);
            strcpy(n2, &b[strlen(b)/2]);
            char *ptr;
            int num1 = (int) strtol(n1, &ptr, 10);
            int num2 = (int) strtol(n2, &ptr, 10);

            if (num1 + num2 == i){
                printf("%d ", i); 
                flag = 1;
            }
        }
    }
    
    if (flag == 0){
        printf("%s\n", "INVALID RANGE");        
    }
}

int main()
{
    char* p_endptr;
    char* p_str = readline();
    int p = strtol(p_str, &p_endptr, 10);

    if (p_endptr == p_str || *p_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    kaprekarNumbers(p, q);

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


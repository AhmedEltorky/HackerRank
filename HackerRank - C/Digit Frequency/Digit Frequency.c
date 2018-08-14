#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char *s;
    s = malloc(1000 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    char c;
    int arr_count[10];
    for (int j = 0;j < strlen(s);j++){
        arr_count[j] = 0;        
    }
    
    for (int i = 0;i < strlen(s);i++){
        c = s[i];
        switch(c){
            case '1':
                arr_count[1]++;          
                break;
            case '2':
                arr_count[2]++;
                break;
            case '3':
                arr_count[3]++;
                break;
            case '4':
                arr_count[4]++;
                break;
            case '5':
                arr_count[5]++;
                break;
            case '6':
                arr_count[6]++;
                break;
            case '7':
                arr_count[7]++;
                break;
            case '8':
                arr_count[8]++;
                break;
            case '9':
                arr_count[9]++;
                break;
            case '0':
                arr_count[0]++;
                break;
            default:
                break;
        }        
    }
    printf("%d %d %d %d %d %d %d %d %d %d", arr_count[0], arr_count[1], arr_count[2], arr_count[3], arr_count[4], arr_count[5], arr_count[6], arr_count[7], arr_count[8], arr_count[9]);
    return 0;
}


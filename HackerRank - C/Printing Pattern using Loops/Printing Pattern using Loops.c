#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int max_r_c = n + (n - 1);
    int r, c, sub, max_comp;
    
    for (r = 0; r < max_r_c/2; r++) {
        sub = 0;
        for (c = 0; c < max_r_c/2; c++) {
            printf("%d ", n - sub);
            if (sub < r) {
                sub++;
            }
        }
        for (c = max_r_c/2; c < max_r_c; c++) {
            printf("%d ", n - sub);
            if (c > max_r_c - r - 2) {
                sub--;
            }
        }
        printf("\n");
    }
    // medium row
    sub = 0;
    for (c = 0; c < max_r_c; c++) {
        printf("%d ", n - sub);
        if (c < max_r_c/2) {
            sub++;
        } else {
            sub--;
        }
    }
    printf("\n");
    
    int new_r = max_r_c/2 - 1;
    for (r = max_r_c/2; r < max_r_c - 1; r++) {
        sub = 0;
        for (c = 0; c < max_r_c/2; c++) {
            printf("%d ", n - sub);
            if (sub < new_r) {
                sub++;
            }
        }
        for (c = max_r_c/2; c < max_r_c; c++) {
            printf("%d ", n - sub);
            if (c > max_r_c - new_r - 2) {
                sub--;
            }
        }
        printf("\n");
        new_r--;
    }
    
    return 0;
}
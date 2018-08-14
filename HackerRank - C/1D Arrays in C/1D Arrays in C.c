#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    // static array
    int arr[n];
    // dynamic array
    int* arr2;
    arr2 = (int*) malloc(n * sizeof(int));
    
    // you can use arr or arr2
    for (int i = 0;i < n;i++){
        scanf("%d", &arr2[i]);
        sum += arr2[i];
    }
    
    printf("%d", sum);
    
    return 0;
}
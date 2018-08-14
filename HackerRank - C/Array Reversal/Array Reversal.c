#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    
    // first method
    // int arr2[num];
    // for(i = 0;i < num;i++){
    //     arr2[i] = arr[num-i-1];        
    // }
    // arr = arr2;
    
    // second method - swap
    int temp;
    for (i = 0;i < num/2;i++){
        temp = arr[i];
        arr[i] = arr[num-1-i];
        arr[num-1-i] = temp;
    }
    
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
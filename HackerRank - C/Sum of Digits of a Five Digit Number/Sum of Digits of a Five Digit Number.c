#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int temp, new_n, sum = 0;
    for (int i = 0;i < 5;i++){
        temp = n / 10;
        new_n = temp;
        temp = n - (temp * 10);
        sum += temp;
        n = new_n;
    }
    printf("%d", sum);
    
    return 0;
}
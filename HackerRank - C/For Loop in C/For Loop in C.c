#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for (int i = a;i <= b;i++){
        if (i >= 1 && i <= 9){
            switch(i){
                case 1:
                    printf("%s\n", "one");
                    break;
                case 2:
                    printf("%s\n", "two");
                    break;
                case 3:
                    printf("%s\n", "three");
                    break;
                case 4:
                    printf("%s\n", "four");
                    break;
                case 5:
                    printf("%s\n", "five");
                    break;
                case 6:
                    printf("%s\n", "six");
                    break;
                case 7:
                    printf("%s\n", "seven");
                    break;
                case 8:
                    printf("%s\n", "eight");
                    break;
                case 9:
                    printf("%s\n", "nine");
                    break;
                default:
                    break;
            }            
        } else if (i > 9){
            if (i % 2 == 0){
                printf("%s\n", "even");
            } else {
                printf("%s\n", "odd");
            }
        }     
    }

    return 0;
}


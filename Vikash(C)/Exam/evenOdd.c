#include <stdio.h>

int main(){
    int n;
    printf("Enter a value to be checked for even or odd: ");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("%d is even\n", n);
    } else {
        printf("%d is odd\n", n);
    }


    //For displaying even and odd numbers in a range, uncomment the following lines:
    // printf("Enter range to be displaed for even and odd: ");
    // scanf("%d", &n);
    // for(int i = 1; i <= n; i++){
    //     if(i % 2 == 0){
    //         printf("%d is even\n", i);
    //     } else {
    //         printf("%d is odd\n", i);
    //     }
    // }

    
    return 0;
}
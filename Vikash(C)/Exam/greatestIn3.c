#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b){
        if(a>c){
            printf("Greatest number is: %d\n", a);
        } else {
            printf("Greatest number is: %d\n", c);
        }
    } else {
        if(b>c){
            printf("Greatest number is: %d\n", b);
        } else {
            printf("Greatest number is: %d\n", c);
        }
    }
    return 0;
}
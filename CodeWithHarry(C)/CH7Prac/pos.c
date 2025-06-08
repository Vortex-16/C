#include <stdio.h>

int pos(int *b){
int count=0;
for(int i=0;i<10;i++){
    if(*(b+i)>0){
        count++;
    }
}
return count;
}
void main() {
    int a[]= {1, 2, -3, 4, -5, 6, 7,-8, 9, 10};
    pos(&a);
    printf("The number of positive integers in the array is: %d\n", pos(a));
}
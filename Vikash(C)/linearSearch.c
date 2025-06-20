#include <stdio.h>

int main(){
    int arr[7]= {3,23,1,34,342,938,11,3414};

    int n;
    printf("Enter a number to search: ");
    scanf("%d", &n);
    // Linear Search
    for(int i = 0; i < 7; i++){
        if(arr[i] == n){
            printf("Found at index %d\n", i);
            return 0; 
        }
    }
}
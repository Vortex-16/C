#include <stdio.h>

int printArr(int *a) {
    printf("The array is: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
    return 0;
}
int revArr(int *a) {
    int temp;
    for (int i = 0; i < 5; i++) {
        temp = *(a + i);
        *(a + i) = *(a + 9 - i);
        *(a + 9 - i) = temp;
    }
    return 0;
}
void main() {
    int a[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArr(&a);
    revArr(a);
    printArr(a);
}
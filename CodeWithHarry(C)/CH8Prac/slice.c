#include <stdio.h>

int slice(char str[],int m,int n){
    int i = 0;
    char *ptr= &str[m];
    char *ptr1= &str[n];
    str=ptr;
    str[n]='\0';
    return str;

}
int main() {
    char str[] = "vikash";
    printf("%s", slice(str, 1,5 ));
    return 0;
}
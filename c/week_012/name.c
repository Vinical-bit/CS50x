#include <stdio.h>

int main(){
    char name[50];

    printf("what's your name? ");
    scanf("%s", name);

    printf("hello %s !\n", name);

    return 0;
}
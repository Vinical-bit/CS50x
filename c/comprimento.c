#include <stdio.h>
#include<strings.h>

int main(void)
{
    char name[100];
    printf("What's your name? ");
    scanf("%s", name);
    printf("%i\n", strlen(name));
}
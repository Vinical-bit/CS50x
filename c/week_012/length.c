#include <stdio.h>

int main(void)
{
    char name[100];

    printf("WHat's your name? ");
    scanf("%s",name);

    int n = 0;

    while(name[n] != '\0')
    {
        n++;
    }

    printf("Your name have %i letter\n",n);
}
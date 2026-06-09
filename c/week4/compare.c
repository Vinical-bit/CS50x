#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[50];
    char t[50];

    printf("s: ");
    scanf("%s", s);

    printf("t: ");
    scanf("%s", t);

    if ((strcmp(s, t) == 0))
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    
}
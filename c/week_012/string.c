#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    printf("input:  ");
    scanf("%s", s);
    
    printf("output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
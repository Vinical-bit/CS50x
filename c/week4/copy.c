#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <stdlib.h>

int main(void)
{
    char s[50];

    printf("s: ");
    scanf("%s", s);

    char *t = malloc(strlen(s) + 1);
    if (t == NULL) // Check if malloc succeeded
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
        strcpy(t, s);

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        t[i] = toupper(t[i]);
        printf("t: %c  s: %c\n", t[i], s[i]);
    }

    free(t); // devolver a memória alocada
}
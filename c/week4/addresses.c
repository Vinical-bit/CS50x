#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 75;
    int *p = &n;
    printf("%i\n", *p);

    char *s = "HI!";
    printf("%s\n", s);

    char *t = "Arise";
    printf("%s\n", t);
    printf("%c\n", t[0]);
    printf("%c\n", t[1]);
    printf("%c\n", t[2]);
    printf("%c\n", t[3]);
    printf("%c\n", t[4]);
}
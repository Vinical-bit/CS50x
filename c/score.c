#include <stdio.h>

int main(void)
{
    int s[3];

    printf("score 1: ");
    scanf ("%i", &s[0]);
    
    printf("score 2: ");
    scanf ("%i", &s[1]);
    
    printf("score 3: ");
    scanf ("%i", &s[2]);

    printf("Average: %.2f\n", (s[0] + s[1] + s[2]) / 3.0);
}

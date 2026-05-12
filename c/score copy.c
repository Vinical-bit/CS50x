#include <stdio.h>

int main(void)
{
    int s[3];

    for (int i = 0; i < 3; i++)
    {
        printf("score  %i: ", i + 1);
        scanf("%i", &s[i]);
    }

    printf("Average: %.2f\n", (s[0] + s[1] + s[2]) / 3.0);
}

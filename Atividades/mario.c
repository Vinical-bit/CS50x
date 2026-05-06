#include <stdio.h>

int n;
void ask()
{
    printf("height: ");
    scanf("%i", &n);
}

int main(void)
{
    n = 0;
    while (n <= 0)
    {
        ask();
    }
    for (int row = 0; row < n; row++)
    {
        for (int space = 0; space < n - row - 1; space++)
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}

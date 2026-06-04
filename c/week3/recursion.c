#include <stdio.h>

void draw(int n);

int main(void)
{
    int n;
    printf("Height: ");
    scanf("%d", &n);
    draw(n);
}

void draw(int n)
{
    // base 
    if (n <= 0)
    {
        return;
    }

    // print pyramid of height n - 1
    draw(n - 1);

    // print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

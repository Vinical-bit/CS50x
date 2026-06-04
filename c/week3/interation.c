#include <stdio.h>

void draw(int n);

int main(void)
{
    int height;

    printf("Height: ");
    scanf("%d", &height);

    draw(height);
}

void draw(int n)
{
    //for each row of pyramid
    for (int i =0; i < n; i++)
    {
        // each column of pyramids
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
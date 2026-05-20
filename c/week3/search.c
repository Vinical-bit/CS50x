#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int numbers[] = {10, 20, 30, 50, 200, 100, 1000, 75};
    printf("Number ");
    scanf("%i", &n);
    

    for (int i = 0; i < 8; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            /* return 0; */
        }
        
    }
   /* return 1; */
   printf("nof found\n");
}

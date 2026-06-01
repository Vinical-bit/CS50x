#include <stdio.h>

float average(int numbers[], int length); 

int main(void)
{
    int score[3];
    
    for (int i = 0; i < 3; i++)
    {
        printf("score  %i: ", i + 1);
        scanf("%i", &score[i]);
    }
    
    printf("Average: %.2f\n", average(score,3));
}


float average(int numbers[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return sum / (float) length;
}

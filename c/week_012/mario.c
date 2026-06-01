#include <stdio.h>

int main()
{
    const int n = 4;
    //each row
    for(int row = 0; row < n; row++)
    {
        //each column
        for(int column = 0; column < n; column++)
        {
           printf("#"); 
        } 
        printf("\n");
    }
    
}
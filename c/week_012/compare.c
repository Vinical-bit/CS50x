#include <stdio.h>

int main()
{
    int x, y;
    
    printf("what's x ? ");
    scanf("%d", &x);
    
    printf("what's y ?");
    scanf("%d", &y);

    if (x < y) {
        printf(" x is less than y\n");
    }
    else if (x > y) {
        printf("x is greater than y\n");
    }
    
    else{
        printf( "x is equal to y\n");
    }

    return 0;
}
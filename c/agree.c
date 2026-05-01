#include <stdio.h>

int main(){
    char c;
    printf("Do you agree? ");
    scanf("%c", &c);

    if (c == 's' || c == 'S')
    {
        printf("agreed \n");
    }
    
    else if (c == 'n' || c == 'N')
    {
        printf("not agreed \n");
    }
    
    else
        printf("i don't get you said");

}

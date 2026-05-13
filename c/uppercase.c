#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];

    printf("before: ");
    scanf("%s",s);
    printf("AFTER:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // lowercase//
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        
        // not lowercase //
        else
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }
    
    

}
#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[4][20] = {"kelly","David","john","vinical"};
    char numbers[4][14] = {"+1-617-495-1000","+2-176-549-1000","+4-949-468-2750","81-99427-9275"}; // to usando string literal pq é mais facil de ler, mas poderia ser char numbers[4][14] = {"1-617-495-1000","2-176-549-1000","4-949-468-2750","81-99427-9275"}; e ai a gente teria que colocar o + na hora de imprimir o numero, ou seja, printf("Found: +%s", numbers[i]); alem disso como é um numero de telefone as vezes pode  ter um 0 na frente do numero, e ai a gente teria que colocar o 0 na hora de imprimir o numero, ou seja, printf("Found: 0%s", numbers[i]); ja que o 0 pode não se considerado como 01 por exemplo, o comp entende como so 1.
    char name[20];

    printf("Name: ");
    scanf("%s",name);

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found: %s", numbers[i]);
            return 0;
        }
        
    }
    
}
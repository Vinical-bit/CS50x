#include <stdio.h>
#include <string.h>

typedef struct // struct é uma estrutura de dados que pode conter vários tipos de dados diferentes, ou seja, é uma coleção de variáveis de diferentes tipos de dados. A struct é usada para agrupar dados relacionados e dar um nome a esse grupo de dados. A struct é definida usando a palavra-chave struct seguida pelo nome da struct e um bloco de código que contém as variáveis que fazem parte da struct. A struct pode ser usada para criar variáveis do tipo struct, que podem ser usadas para armazenar os dados relacionados.
{
    char *name;
    char *number;
} person;

int main(void)
{
    person people[4];
    people[0].name = "kelly";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+2-176-549-1000";

    people[2].name = "john";
    people[2].number = "+4-949-468-2750";

    people[3].name = "vinical";
    people[3].number = "81-99427-9275";

    char name[20];
    printf("Name: ");
    scanf("%s", name);

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, name) == 0) // o strcmp vai checar se as string são iguais, o ==0 significa que as string são iguais, se fosse ==1 significaria que a primeira string é maior que a segunda string, e se fosse ==-1 significaria que a primeira string é menor que a segunda string.
        {
            printf("Found: %s", people[i].number);
            return 0;
        }	

    }
    

}
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char name[100];    char number[100];

    printf("Name: ");
    scanf("%s", name);

    printf("Number: ");
    scanf("%s", number);

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}
#include <stdio.h>

int main(void)
{
    long num;
    int i;
    int mult = 0;
    int rest = 0;

    printf("Number: ");
    scanf("%li", &num);

    while (num > 0)
    {i++;
        int digito = num%10;
        if(i % 2 == 0)
        {
            digito = digito*2;
            if(digito > 9)
            {
                mult += 1 + (digito % 10);
            }
        }
        else
        {
            rest += digito;
        }
        num = num/10;
    } 
int total = mult + rest;
    if(total % 10 == 0)
    {
        printf("Valido!");
    }
    else
    {
        printf("Invalido !");
    }
}
if (i == 15 || i == 16)
{
    printf("Bandeira : Visa")
}

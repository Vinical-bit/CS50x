#include <stdio.h>

int main(void)
{
    long num;
    int i;
    int mult = 0;
    int rest = 0;
    long orig;

    printf("Number: ");
    scanf("%li", &num);
    orig = num;

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
            else
            {
                mult += digito;
            }
        }
        else
        {
            rest += digito;
        }
        num = num/10;
    } 
    int total = mult + rest;
    while (orig >= 100)
    {
        orig /= 10;
    }

    if (total % 10 == 0)
    {

        if (i == 15 && (orig == 34 || orig == 37))
            {
                printf("AMEX\n");
            }

        else if (i == 16 && (orig >= 51) && (orig <= 55))
            {
                printf("MASTERCARD\n");
            }

        else if ((i == 13 || i == 16) && (orig / 10 == 4))
            {
                printf("VISA\n");
            }

        else
            {
                printf("INVALID\n");
            }
    }

    else
    {
        printf("INVALID\n");
    }


}


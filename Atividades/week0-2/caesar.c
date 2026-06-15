#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int pi;
    int ci;
    // verificar o argc
    if (argc != 2)
    {
        return 1;
    }

    // caso o usuario não coloque apena o numero do k
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // verifica se é digito ou não | o '!' é o sinal de inversão/negação
        // como a gente não quer carctere a gente usa ele para ele avisa
        // quando não for digito
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // transformar o argv[1] em inteiro
    int k = atoi(argv[1]);

    // pedir plainext
    string texto = get_string("Plaintext: ");

    // pecorrer cada caractere
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // verificar se é letra
        if (isalpha(texto[i]))
        {
            // letra maiuscula
            if (isupper(texto[i]))
            {
                // - 65 pois ele equivale a 'A'
                pi = texto[i] - 65;

                // aqui pegamos o valor e adicionamos k que é o pulo de letras
                ci = (pi + k) % 26;

                // aplicar deslocamento
                texto[i] = ci + 65;
            }

            // letra minuscula
            if (islower(texto[i]))
            {
                pi = texto[i] - 97;
                ci = (pi + k) % 26;
                texto[i] = ci + 97;
            }
        }
    }

    // resultado criptografado
    printf("ciphertext: %s\n", texto);
    return 0;
}

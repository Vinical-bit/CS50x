#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Receber o texto
    string book = get_string("Text: ");

    // checar quantas letras tem
    int letters = count_letters(book);
    // checar quantas palavras tem
    int words = count_words(book);

    // checar quantas sentensas tem
    int sentences = count_sentences(book);

    // L = letras por 100 palavras
    float L = ((float) letters / words) * 100;

    // S = 100 numero medio de frases por 100 palavras --> qualquer sequencia de caracteres
    // separados por um espaço
    float S = ((float) sentences / words) * 100;

    // calcular
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // indicar o grau dele
    int grade = round(index); // é para arredondar

    if (grade >= 1 && grade <= 15)
    {
        printf("Grade: %i\n", grade);
    }

    // se for maior que 16 --> 16+
    if (grade >= 16)
    {
        printf("Grade: 16+\n");
    }

    // menor que 1
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // se for algum caracter 'A' a 'Z'/ 'a' a 'z'
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
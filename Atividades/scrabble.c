#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int POINTS[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int compute_score(string word);
void show(int s1, int s2);

int main(void)
{
    //Pegar as palavras
    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");

    //calcular os valores
    int score1 = compute_score(s1);
    int score2 = compute_score(s2);

    //comparar os valores
    //player 1
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        show(score1, score2);
    }
    //player 2
    else if(score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    //empate
    else
    {
        printf("Tie!\n");
    }

}




void show(int s1, int s2)
{
    printf("score 1: %i\n", s1);
    printf("score 2: %i\n", s2);
}

int compute_score(string word)
{
//pegar o valor de cada caractere
    int sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))                                       // if (word[i] >= 'a' && word[i] <= 'z') se eu escrevesse com letra maiucula ele não passaria e eu receberia 0
        {
            int maiusc = toupper(word[i]);
            //somar o valor da array com minha variavel
            sum += POINTS[maiusc - 'A'];
        }
    }
    return sum;
}
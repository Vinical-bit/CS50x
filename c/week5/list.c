#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}

int main(void)
{
    node *list = NULL;

    for (int = 0; i < 4; i++)
    {
        node *n = malloc(sizeof(node))
        if (n == NULL)
        {
            fprintf("Memory allocation failed\n");
            return 1;
        }
        
        printf("Number: ");
        scanf("%d", &n->number); // Preenche o campo number do nó com o número lido

        n ->next= NULL; // Inicializa o campo next do nó para NULL

        N->next = list; // Faz o campo next do nó apontar para a lista atual
        list = n; // Atualiza a lista para apontar para o novo nó 

        // imprimindo os números da lista
        node *ptr = list;
        while (ptr != NULL)
        {
            printf("%d\n",ptr->number);
            ptr = ptr->next;
        }
        
       // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        //{
         //  printf("%d\n", ptr->number);
        //}  uma versão mais elegante do loop acima
    }
}
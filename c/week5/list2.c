#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}

void unload(node *list);

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 4; i++)
    {
        // alocar node para numero
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
         unload(list);
         return 1;   
        }

        printf("Number: ");
        scanf(%d, &n -> number); // Preenche o campo number do nó com o número lido
        n -> next = NULL; // Inicializa o campo next do nó para NULL

        // se a lista estiver vazia
        if (list == NULL)
        {
            list = n; // Atualiza a lista para apontar para o novo nó
        }

        // se o numero pertencer ao inicio da lista
        else if (n -> number < list -> number)
        {
            n -> next = list; // Faz o campo next do nó apontar para a lista atual
            list = n;
        }

        // se o numero pert3encer ao final da lista
        else
        {
            // interagindo sobre os nodes da lista
            for (node *ptr = list; ptr != NULL; ptr = ptr -> next)
            {
                // se estiver no finbal da lista
                if (ptr -> next == NULL   )
        }

    }

        printf("%d\n", ptr -> number);
        ptr =  ptr -> next;
    }

    // free memory
    unload(list);
    return 0;
}

void unload(node *list)
{
    node *ptr = list;]
    while (ptr != NULL)
    {
        node *next = ptr -> next;
        free(ptr);
        ptr = next;
    }
    
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct no
    {
        int valor;
        struct no *proximo;
    } No;

    // Inserir no inicio

    void inserir_inicio(No * *lista, int num)
    {
        No *novo = malloc(sizeof(No));

        if (novo)
        {
            novo->valor = num;
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            printf("Erro ao alocar memoria!\n");
        }
    }
    // Inserir no fim

    void inserir_fim(No * *lista, int num)
    {
        No *aux, *novo = malloc(sizeof(No));

        if (novo)
        {
            novo->valor = num;
            novo->proximo = NULL;

            // eh o primeiro
            if (*lista == NULL)
            {
                {
                    *lista = novo;
                }
            }
            else
            {
                aux = *lista;
                while (aux)
                {
                    /* code */
                }
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Lista encadeada

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

// Inserir no inicio

void inserir_inicio(Lista *lista, int num)
{ // Nota 1
    /*1 - Já que irá inserir no início, precisamos nos referir a lista, que será um nó, através de um ponteiro.  Finalmente, o nó inserido apontará para o ponteiro de lista*/
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
    {
        printf("Malloc Error!\n");
    }
}
// Inserir no fim

void inserir_fim(Lista *lista, int num)
{
    No *novo, *aux = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->proximo)
            {
                aux = aux->proximo;
                aux->proximo = novo;
            }
        }
        lista->tam++;
    }
    else
    {
        printf("Malloc Error");
    }
}

void inserir_meio(Lista *lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        //é o primeiro?
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while (aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
        lista->tam++;
    }
    else
    {
        printf("Malloc Error");
    }
}

void imprimir(Lista lista)
{
    No *no = lista.inicio;
    printf("\n\tLista tamanho %d: ", lista.tam);
    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main()
{
    int opcao, valor, anterior;
    // No *lista = NULL;
    Lista lista;

    criar_lista(&lista);
    do
    {
        printf("\n\t 0 - Sair\n\t 1 - Inserir inicio\n\t 2 - Inserir final\n\t 3 - Inserir meio\n\t 4 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_inicio(&lista, valor);
            break;

        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_fim(&lista, valor);
            break;

        case 3:
            printf("Digite um valor e o valor de referência: ");
            scanf("%d%d", &valor, &anterior);
            inserir_meio(&lista, valor, anterior);
            break;

        case 4:
            imprimir(lista);
            break;

        default:
            if (opcao != 0)
            {
                printf("Invalid!\n");
            }
            break;
        }

    } while (opcao != 0);

    return 0;
}
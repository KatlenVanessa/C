#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	int valor;
	struct No *proximo;
} No;

typedef struct
{
	No *inicio;
	int tamanho;
} Lista;

// Insercao no inicio da lista
void inserir_inicio(Lista *lista, int valor)
{
	No *novo = (No *)malloc(sizeof(No));
	novo->valor = valor; // a regiao de memoria apontada por novo, na posicao valor vai
						 // receber ...
						 //(*novo).valor = valor sao a mesma coisa
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	lista->tamanho++;
}

// Insercao no fim da lista
void inserir_fim(Lista *lista, int valor)
{
	No *no, *novo = (No *)malloc(sizeof(No));
	novo->valor = valor; // a regi�o de memoria apontada por novo, na posicao valor vai
						 // receber ...
						 //(*novo).valor = valor � a mesma coisa
	novo->proximo = NULL;
	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
	}
	else
	{
		no = lista->inicio;
		while (no->proximo != NULL)
		{
			no = no->proximo;
			no->proximo = novo;
		}
	}
	lista->tamanho++;
}
// imprimir a lista
void imprimir(Lista *lista)
{
	No *inicio = lista->inicio;
	printf("Tamanho da lista: %d\n", lista->tamanho);
	while (inicio != NULL)
	{
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n\n");
}

int main()
{
	Lista lista;
	lista.inicio = NULL;
	lista.tamanho = 0;

	int opcao, valor;

	do
	{
		printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n5 - Sair\n");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			printf("Digite o numero a ser inserido!\n");
			scanf("%d", &valor);
			inserir_inicio(&lista, valor);
			break;
		case 2:
			imprimir(&lista);
			break;
		case 3:
			printf("Digite o numero a ser inserido!\n");
			scanf("%d", &valor);
			inserir_fim(&lista, valor);
			break;
		case 5:
			printf("Finalizando...");
			break;
		default:
			printf("Opcao invalida!\n");
		}
	} while (opcao != 5);

	return 0;
}

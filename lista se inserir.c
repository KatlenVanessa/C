#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct {
	No *inicio;
	int tamanho;
}Lista; 

//Insercao no inicio da lista
void inserir_inicio(Lista *lista, int valor ){
	No *novo = (No*)malloc(sizeof(No));
	novo->valor = valor;//a região de memoria apontada por novo, na posicao valor vai receber ...
						//(*novo).valor = valor é a mesma coisa	
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	lista->tamanho++;
}
//imprimir a lista
void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	printf("Tamanho da lista: %d\n", lista->tamanho);
	while(inicio != NULL ){
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n\n");
}

int main(){
	Lista lista;
	lista.inicio = NULL;
	lista.tamanho = 0;
	
	int opcao, valor;
	
	do{
		printf("1 - Inserir no inicio\n2 - Imprimir\n5 - Sair");
		scanf("%d ", &opcao);
		switch(opcao){
		case 1:
			printf("Digite o numero a ser inserido!\n");
			scanf("%d ", &valor);
			inserir_inicio(&lista, valor);
			break;
		case 2 : 
			imprimir(&lista);
			break;
		case 5:
			printf("Finalizando...");
			break;
		default: 
		printf("Opcao invalida!\n");
			
		}
	}while(opcao!=5);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

//https://www.youtube.com/watch?v=lgPgknuUK-s&t=2326s

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
	novo->valor = valor;//a região de memoria apontada por novo, na posicao valor vai 
						//receber ...
						//(*novo).valor = valor é a mesma coisa	
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	lista->tamanho++;
}


//Insercao no fim da lista
void inserir_fim(Lista *lista, int valor ){
	No *no, *novo = (No*)malloc(sizeof(No));
	novo->valor = valor;//a região de memoria apontada por novo, na posicao valor vai 
						//receber ...
						//(*novo).valor = valor é a mesma coisa	
	novo->proximo = NULL;
	if(lista->inicio == NULL){
		lista->inicio = novo;
	}else{
		no = lista->inicio;
		while(no->proximo != NULL){
			no = no->proximo;
		no->proximo = novo;
		}
	}
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
		printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Imprimir\n5 - Sair\n");
		scanf("%d ", &opcao);
		switch(opcao){
		case 1:
			printf("Digite o numero a ser inserido!\n");
			scanf("%d ", &valor);
			inserir_inicio(&lista, valor);
			break;
		case 2:
			printf("Digite o numero a ser inserido!\n");
			scanf("%d", &valor);
			inserir_fim(&lista, valor);
			break;
		case 3 : 
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

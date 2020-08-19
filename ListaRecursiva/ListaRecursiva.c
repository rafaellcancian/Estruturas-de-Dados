#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct nodo {
	int dado;
	struct nodo *prox;	
}Celula;

void exibirR(Celula *l) {
	if (l) {
		printf("%d\t", l->dado);
		exibirR(l->prox);
	}
}

Celula *inserirR(int valor, Celula *l) {
	if (l && valor > l->dado) {
		l->prox = inserirR(valor, l->prox);
		
		return l;
	} else {
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		
		novo->prox = l;		
		novo->dado = valor;
	
		return novo;
	}
}

int contaR(Celula *l) {	
	if (l) {
		return 1 + contaR(l->prox);
	}
	return 0;
}

void exibirParesR(Celula *l) {	
	if (l) {
		if (l->dado % 2 == 0) {
			printf("%d\t", l->dado);
		}
		exibirParesR(l->prox);
	}
}

int main() {
	Celula *lista = NULL;
	int i, valor;
	
	srand(time(NULL));
	printf("Valores gerados aleatoriamente:\n\n");
	for (i = 0; i < TAM; i++) {
		valor = rand() % 100;
		printf("%d\t", valor);
		lista = inserirR(valor, lista);
	}
	
	printf("\n\nValores inseridos na lista de forma ordenada:\n\n");	
	exibirR(lista);
	
	int totalLista = contaR(lista);
	
	printf("\n\nTotal de elementos na lista: %d", totalLista);
	printf("\n\nValores pares:\n\n");
	exibirParesR(lista);
	
	return 0;
}

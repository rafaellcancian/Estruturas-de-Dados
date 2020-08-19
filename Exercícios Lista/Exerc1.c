/*/
1. Escreva uma função que receba uma lista encadeada simples e retorne quantos elementos há.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
	int dado;
	struct no *prox;
}Celula;

Celula *inserirLista(int valor, Celula *l);
int contarLista(Celula *l);

int main() {
	Celula *lista = NULL;
	int i;
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++) {
		lista = inserirLista(rand() % 100, lista);
	}
	
	printf("Quantidade de elementos na lista: %d\n", contarLista(lista));
	
	return 1;
}

int contarLista(Celula *l){
	Celula *p;
	int contador=0;
	
	if (!l) return 0;
	
	for(p = l; p ; p = p->prox){
		contador++;
	}
	
	return contador;
}

Celula *inserirLista(int valor, Celula *l) {
		Celula *p, *pR;
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		
		novo->dado = valor;
		novo->prox = NULL;

		if (!l) return novo;

		for (pR = NULL, p = l; p; pR = p, p = p->prox) {
			if (valor < p->dado) {
				break;
			}
		}

		if (p == l) {
			novo->prox = l;
			return novo;
		} else if (!p) {
			pR->prox = novo;
			return l;
		}
		
		pR->prox = novo;
		novo->prox = p;
		
		return l;
}

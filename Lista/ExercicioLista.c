#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
	int dado;
	struct no *prox;
}Celula;

Celula *inserirLista(int valor, Celula *l);
void exibir(Celula *l);
Celula *concatenarlistas(Celula *lista1, Celula *lista2);
Celula *retirarRepetidos(Celula *lista1, Celula *lista2);

int main() {
	Celula *lista1 = NULL;
	Celula *lista2 = NULL;
	int i;
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++) {
		lista1 = inserirLista(rand() % 30, lista1);
		lista2 = inserirLista(rand() % 30, lista2);
	}

	printf("Exibindo a primeira lista\n");
	exibir(lista1);
	printf("\nExibindo a segunda lista\n");
	exibir(lista2);
	
	Celula *listaconcatenada = concatenarlistas(lista1, lista2);
	printf("\nExibindo as listas concatenadas\n");
	exibir(listaconcatenada);
	
	Celula *listaRepetida = retirarRepetidos(lista1, lista2);
	printf("\nExibindo os numeros repetidos das listas\n");
	exibir(listaRepetida);
	
	return 1;
}

void exibir(Celula *l){
	Celula *p;
	if(!l){
		printf("Estrutura vazia\n");
		return;
	}
	for(p = l; p ; p = p->prox){
		printf("%d\n", p->dado);
	}
}

Celula *inserirLista(int valor, Celula *l) {
		Celula *p, *pR;
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		novo->dado = valor;
		novo->prox = NULL;

		if (!l) return novo; //primeira vez

		//percorrer para localizar sua posicao
		for (pR = NULL, p = l; p; pR = p, p = p->prox) {
			if (valor < p->dado) {
				//achei a posicao do valor
				break;
			}
		}
		//inicio
		if (p == l) {
			novo->prox = l; //ou novo->prox = p;
			return novo;
		} else if (!p) { //fim
			pR->prox = novo;
			return l;
		}
		//meio
		pR->prox = novo;
		novo->prox = p;
		return l;
}
	
Celula *concatenarlistas(Celula *lA, Celula *lB) {
	Celula *p,*ltemp = NULL;
	
	for (p = lA; p; p = p->prox) {
		ltemp = inserirLista(p->dado, ltemp);
	}
	
	for (p = lB; p; p = p->prox) {
		ltemp = inserirLista(p->dado, ltemp);
	}
    
    return ltemp;
}

Celula *retirarRepetidos(Celula *lA, Celula *lB) {
	Celula *p1,*p2,*ltemp = NULL;
	
	for (p1 = lA; p1; p1 = p1->prox) {
		for (p2 = lB; p2; p2 = p2->prox) {
			if (p1->dado == p2->dado) {
				ltemp = inserirLista(p1->dado, ltemp);
			}
		}
	}
	
	return ltemp;	
}

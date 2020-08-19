/*/
3. Escreva uma fun��o que receba uma lista encadeada simples e devolva o endere�o de um n� que esteja o mais pr�ximo poss�vel do meio da lista.
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
	
	printf("Quantidade de elementos na lista: %d", contarLista(lista));
	
	return 1;
}



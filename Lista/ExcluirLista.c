#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct no {
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
Celula *inserirLista(int valor, Celula *l);
void exibir(Celula *l);
Celula *ordenar(Celula *l);
int contarElementos(Celula *l);
void exibirMediana(Celula *l);
Celula *excluir(int valor, Celula *l);

int main() {
	Celula *lista = NULL;
	long long int i;
	int valor;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		//lista = inserirLista(rand() % 1000, lista);
		lista = inserir(rand() % 100, lista);
	}
	lista = ordenar(lista);

	printf("Exibindo a lista\n");
	exibir(lista);
	//exibirMediana(lista);
	printf("\nDigite um valor para ser exluido: ");
	scanf("%d", &valor);
	excluir(valor, lista);
	printf("\nExibindo a lista apos a exclusao\n");
	exibir(lista);
	return 1;
}
//Inserir na pilha/lista - nossa lista é falsa
Celula *inserir(int valor, Celula *l){
	Celula *novo;
	//Alocar memória
	novo = (Celula *)malloc(sizeof(Celula));
	//Depositar valores na pilha/lista
	novo -> dado = valor;
	novo -> prox = l;
	//Engatar
	return novo;
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

Celula *ordenar(Celula *l) {
	//Método da bolha
	Celula *p;
	int houvetroca;
	int aux;
	do {
		houvetroca = 0;
		for (p = l; p->prox; p = p->prox) {
			if (p->dado > p->prox->dado) {
				houvetroca = 1;
				aux = p->dado;
				p->dado = p->prox->dado;
				p->prox->dado = aux;
			}
		}
	} while(houvetroca);
	return l;
}

int contarElementos(Celula *l){
	Celula *p;
	int conta=0;
	for(p = l; p ; p = p->prox){
		conta++;
	}
	return conta;
}

void exibirMediana(Celula *l) {
	Celula *p;
	//contar quantidade de elementos
	int qtdElementos = contarElementos(l);
	int i;

	for(p=l, i=1; i<(qtdElementos/2); p=p->prox, i++);

	if(qtdElementos % 2==0){
		printf("\nMediana Par: %d %d", p->dado, p->prox->dado);
	} else{
		printf("\nMediana Impar: %d\n", p->prox->dado);
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
	
Celula *excluir(int valor, Celula *l) {
	Celula *p,*pR;
	
	if (!l) return l;
	
	for (pR=NULL, p=l; p; pR=p, p=p->prox) {
		if (valor == p->dado) {
			break;
		}
	}
	
	if (!p) return l;
	
	if (p == l) {
		l=l->prox;
		free(p);
		
		return l;
	}
	
	if (!p->prox) {
		free(p);
		pR->prox = NULL;
		
		return l;
	}
	
	pR->prox = p->prox;
	free(p);
	
	return l;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

typedef struct {
	Celula *inicio;
	Celula *fim;
} Fila;

int senhas = 0, contador = 0;

void inicializacao(Fila *f) {
	f->inicio = NULL;
	f->fim = NULL;
}

void inserirFila(int valor, Fila *f) {
	Celula *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	if (!f->fim) {
		f->fim = novo;
		f->inicio = novo;
	} else {
		f->fim->prox = novo;
		f->fim = novo;
	}
}

void removerFila(Fila *f) {
	Celula *lixo;

	if (f->inicio) {
		lixo = f->inicio;
		f->inicio = f->inicio->prox;
		free(lixo);

		if (!f->inicio) {
			f->fim = NULL;
		}
	} else {
		printf("ERRO: A fila está vazia.\n\n");
	}

}

void gerarFichaNormal(Fila *f1) {
	system("cls");
	senhas++;
	inserirFila(senhas, f1);
}

void gerarFichaPrioritaria(Fila *f2) {
	system("cls");
	senhas++;
	inserirFila(senhas, f2);	
}

void atender(Fila *f1, Fila *f2) {
	if ((!f1->inicio) && (!f2->inicio)) {
		system("cls");
		printf("ERRO: Ambas as filas estão vazias.\n\n");
		return;		
	}
	
	if (!f1->inicio) {
		system("cls");
		printf("Foi atendido (fila prioritária): %d\n\n", f2->inicio->dado);
		removerFila(f2);
		contador = 0;
		return;
	}
	
	if (contador < 3) {
		system("cls");
		printf("Foi atendido (fila normal): %d\n\n", f1->inicio->dado);
		removerFila(f1);
		contador++;
	} else if (contador == 3) {
		if (!f2->inicio) {
			system("cls");
			printf("AVISO: A fila prioritária está vazia, o atendimento foi pulado.\n\n");
			contador = 0;
			return;
		}
		
		system("cls");
		printf("Foi atendido (fila prioritária): %d\n\n", f2->inicio->dado);
		removerFila(f2);
		contador = 0;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Fila fila1;
	Fila fila2;

	inicializacao(&fila1);
	inicializacao(&fila2);
	
	int n;
	
	while(1) {
		if (senhas == 0) {
			printf("=== Desafio sobre Filas\n\nEscolha uma opção abaixo:\n\n[1] Gerar Ficha Normal\n[2] Gerar Ficha Prioritária\n[3] Atender\n[4] Sair\n\nOpção: ", senhas);
		} else {
			printf("=== Desafio sobre Filas\n\nÚltima senha gerada: %d\n\nEscolha uma opção abaixo:\n\n[1] Gerar Ficha Normal\n[2] Gerar Ficha Prioritária\n[3] Atender\n[4] Sair\n\nOpção: ", senhas);
		}
		scanf("%d", &n);
		
		switch (n) {
			case 1: gerarFichaNormal(&fila1); break;
			case 2: gerarFichaPrioritaria(&fila2); break;
			case 3: atender(&fila1, &fila2); break;
			case 4: exit(0); break;
			default: {
				system("cls");
				printf("ERRO: A opção inserida é inválida.\n\n");
				break;
			}
		}
	}
}









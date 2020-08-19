#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int ContaPalavras(char *nomearquivo);

int main() {
	setlocale(LC_ALL, "Portuguese");

	int totalpalavras=0;
	char nomearquivo[200];

	do {
		printf("Digite o nome de um arquivo (com a extensão): ");
		scanf("%[^\n]s", nomearquivo);
		fflush(stdin);
		
		totalpalavras = ContaPalavras(nomearquivo);
	} while (totalpalavras == -1);

	printf("\nNúmero total de palavras: %d\n\n", totalpalavras);

	system("pause");
	return 0;
}

int ContaPalavras(char *nomearquivo) {
	FILE *arquivo;

	int palavras=0,bloqueio=0;
	char c;

	arquivo = fopen(nomearquivo, "r");

	if (!arquivo) {
		system("cls");
		printf("ERRO: O arquivo não existe.\n\n");
		return -1;
	}

	while (!feof(arquivo)) {
		
		if (feof(arquivo)) break;

		c = fgetc(arquivo);

		if (!isspace(c)) {
			bloqueio = 0;
		}
		else if ((isspace(c)) && (bloqueio == 0)) {
			palavras++;
			bloqueio = 1;
		}
	}

	fclose(arquivo);

	return palavras;
}

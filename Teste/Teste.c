#include <stdio.h>

#define TAM 4

int contaParesR(int *v, int n) {
	if (n > 0) {
		if (v[n - 1] % 2 == 0) {
			return 1 + contaParesR(v, n - 1);
		}
		return 0 + contaParesR(v, n - 1);
	}
	return 0;
}

int somaR(int *v, int n) {
	if (n > 0) {
		return v[n - 1] + somaR(v, n - 1);
	}
	return 0;
}

float fatR(int n) {
	if (n > 1) {
		return n * fatR(n - 1);
	}
	return 1;
}

int main() {
	int vetor[TAM] = {10, 15, 7, 14};
	int fatorial;
	
	printf("Digite um fatorial: ");
	scanf("%d", &fatorial);
	
	int totalPares = contaParesR(vetor, TAM);
	int totalSoma = somaR(vetor, TAM);
	float resultadoFatorial = fatR(fatorial);
	
	printf("\nTotal de pares: %d\n", totalPares);
	printf("Total da soma: %d\n", totalSoma);
	printf("Resultado do fatorial: %.0f\n", resultadoFatorial);
		
	return 0;
}


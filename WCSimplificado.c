#include <stdio.h>
#define I_MAIUSCULA 65
#define F_MAIUSCULA 90
#define I_MINUSCULA 97
#define F_MINUSCULA 122
#define I_NUMEROS 48
#define F_NUMEROS 57
#define ESPACO 32
#define LINHA '\n'
#define TABULACAO 9

int main(){	
	char c;
	int letras, espacos=0, simbolos=0, maiuscula=0;
	int numeros = 0, minuscula=0, linhas = 0, tabulacao = 0;
	FILE *arquivo = fopen("Texto.txt", "rt");

	if (!arquivo){
		fprintf(stderr, "\nVAI DA NAO PRO ARQUIVO\n");
	}

	do {
		c = fgetc (arquivo);
		if (c >= I_MAIUSCULA && c <= F_MAIUSCULA){
			maiuscula++;
			continue;
		}
		if (c >= I_MINUSCULA && c <= F_MINUSCULA){
			minuscula++;
			continue;
		}
		if (c >= I_NUMEROS && c <= F_NUMEROS){
			numeros++;
			continue;
		}
		if (c == ESPACO){
			espacos++;
			continue;
		}
		if (c == LINHA){
			linhas++;
			continue;
		}
		if (c == TABULACAO){
			tabulacao++;
			continue;
		}

			else {
				simbolos++;
			}

	}while (c != EOF);//Ou !feof(arquivo);

	letras = maiuscula + minuscula;
	fclose (arquivo);
	printf("\nESTE ARQUIVO CONTEM:\n");
	printf("NUMEROS: %d\n", numeros);
	printf("LETRAS: %d\n", letras);
	printf("MAIUSCULAS: %d\n", maiuscula);
	printf("MINUSCULAS: %d\n", minuscula);
	printf("LINHAS: %d\n", linhas);
	printf("ESPACOS: %d\n", espacos);
	printf("TABULACAO: %d\n", tabulacao);	
	printf("SIMBOLOS: %d\n", simbolos);


}
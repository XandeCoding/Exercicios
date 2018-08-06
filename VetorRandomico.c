#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int aleatorio (){
	int r;
	srand(time(NULL));

	r = rand() % 1001;

	printf("Random Number either 0 or 1: %d", r);
	return r;
}
int *cria_vetor (int tamanho){
	int *vetor = (int *) malloc (tamanho * sizeof(int));

		return (vetor);
}
void enche_arquivo (FILE **arquivo, int tamanho){
	int cont_1, num;
	
	srand(time(NULL));
	// fprintf(*arquivo, "%d\n", tamanho);
	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		// num = rand() % 1000;
		fprintf(*arquivo, "%d ", rand() % 1000);
		// fwrite (&num, sizeof(int), 1, *arquivo);
	}
}
void imprime_vetor (int *vetor, int tamanho){
	int cont_1;

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		printf("%d ", vetor[cont_1]);
	}
	printf("\n");
}

int main(){	
	int tamanho;
	FILE *arquivo = fopen("vetor_random.txt", "wt");
		if (!arquivo){
			fprintf(stderr, "\nNAO FOI POSSIVEL ABRIR ARQUIVO-1\n");
		}

	scanf("%d", &tamanho);
	
	enche_arquivo (&arquivo, tamanho);
	// imprime_vetor (vetor, tamanho);
		
		
		fclose (arquivo);



	
}
#include <stdio.h>
#define TAM 100

void le_matriz (int *matriz, int tamanho);
void imprime_matriz (int *matriz, int tamanho);
void troca (int *num_1, int *num_2);
void selection_sort_matriz (int *matriz, int tamanho, int pos_h);

int main(){
	int matriz[TAM][TAM];
	int tamanho, cont_1, cont_2, aux;

	scanf("%i", &tamanho);

	le_matriz (&matriz[0][0], tamanho);

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		selection_sort_matriz (&matriz[0][0], tamanho, cont_1);
	}

	imprime_matriz(&matriz[0][0], tamanho);

}
void le_matriz (int *matriz, int tamanho){
	int cont_1, cont_2;

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		for (cont_2 = 0; cont_2 < tamanho; cont_2++){
			int aux = cont_1 * tamanho;
			scanf("%d", &matriz[aux+cont_2]);
		}
	}
}
void imprime_matriz (int *matriz, int tamanho){
	int cont_1, cont_2;

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		printf("\n");
		for (cont_2 = 0; cont_2 < tamanho; cont_2++){
			int aux = cont_1 * tamanho;
			printf("%i ", matriz[aux+cont_2]);
		}
	}
}

void troca (int *num_1, int *num_2){
	int aux;

	aux = *num_1;
	*num_1 = *num_2;
	*num_2 = aux;
}
void selection_sort_matriz (int *matriz, int tamanho, int pos_h){
	int cont_1, cont_2, menor;

	for (cont_1 = 0; cont_1 < (tamanho-1); cont_1++){
		menor = cont_1;
		for (cont_2 = cont_1 +1; cont_2 < tamanho; cont_2++){
			int aux_menor = menor * tamanho;
			int aux_atual = cont_2 * tamanho;

			if (matriz[aux_menor+pos_h] > matriz[aux_atual+pos_h]){
				menor = cont_2;
			}
		}
		if (matriz[(menor*tamanho)+pos_h] != matriz[(cont_1*tamanho)+pos_h]){
			troca (&matriz[(menor*tamanho)+pos_h], &matriz[(cont_1*tamanho)+pos_h]);		}
	}
}

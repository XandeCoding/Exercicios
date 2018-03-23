#include <stdio.h>
#include <stdlib.h>
#define TAM 9

int sudoku[TAM][TAM];

void le_matriz();
int teste_sudoku1();
int teste_sudoku2();

int main(){
	le_matriz();
	teste_sudoku1();
	teste_sudoku2();
}

void le_matriz(){
	int cont_1, cont_2;

	for (cont_1 = 0; cont_1 < 9; cont_1++){
		int aux = cont_1 * TAM;
		for (cont_2 = 0; cont_2 < 9; cont_2++){
			scanf("%d", sudoku[aux+cont_2]);
		}
	}
}
int teste_sudoku1(){
	int cont_1, cont_2, total = 0;

	for (cont_1 = 0; cont_1 < TAM; cont_1++){
		if (total != 0 && total != 45){
			printf("\ninvalido");
			exit(0);
		}

		total = 0;
		int aux = cont_1 * TAM;
		for (cont_2 = 0; cont_2 < TAM; cont_2++){
			int *pont = sudoku[aux+cont_2];
			total += *pont;
		}
	}
	return(1);
}

int teste_sudoku2 (){
	int cont_1, cont_2, total;
	
	for (cont_1 = 0; cont_1 < TAM; cont_1+=3){
		int aux_cima = (cont_1) * TAM;
		int aux_meio = (cont_1+1) * TAM;
		int aux_baixo = (cont_1+2) * TAM;

		printf("\n");
		for (cont_2 = 0; cont_2 < TAM; cont_2+=3){	 
			total = 0;		
			int *esq_cima = sudoku[aux_cima+(cont_2)];
			int *meio_cima = sudoku[aux_cima+(cont_2+1)];
			int *dir_cima = sudoku[aux_cima+(cont_2+2)];
			int *esq_meio = sudoku[aux_meio+(cont_2)];
			int *centro = sudoku[aux_meio+(cont_2+1)];
			int *dir_meio = sudoku[aux_meio+(cont_2+2)];
			int *esq_baixo = sudoku[aux_baixo+(cont_2)];
			int *meio_baixo = sudoku[aux_baixo+(cont_2+1)];
			int *dir_baixo = sudoku[aux_baixo+(cont_2+2)];

				total = *esq_cima + *meio_cima + *dir_cima +
					*esq_meio +* centro + *dir_meio +
					*esq_baixo + *meio_baixo + *dir_baixo;
					printf("\ntotal %i invalido", total);
					exit(0);
				}
		}
	}

	printf("\nvalido");
	return(1);

	



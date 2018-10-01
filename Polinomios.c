#include <stdio.h>
#include <stdlib.h>
#define TAM 400
 
typedef struct {
    float coeficiente;
    int expoente;
}polinomios;
 
    polinomios polinomio_1[100];
	int posicao;
 
void le_polinomio (polinomios *polinomio);
void imprime_polinomio (polinomios *polinomio);
int add_num (char operacao);
 
int main(){
    int casos_teste, tamanho, tam_polinomio_1, tam_polinomio_2, tamanho_total = 0;
    char operacao;
	polinomios aux;
 
    scanf("%d", &casos_teste);
 
    while (casos_teste--){
        getchar();
        scanf("%c", &operacao);

			printf ("\nDigite o tamanho do polinomio 1\n");
            scanf("%d", &tamanho);
			posicao = tamanho;
			printf ("\nDigite os valores do polinomio seguidos pelo expoente\n");
            le_polinomio (polinomio_1);
 
			printf ("\nDigite o tamanho do polinomio 2\n");
            scanf("%d", &tamanho);
			printf ("\nDigite os valores do polinomio seguidos pelo expoente\n");
            	while (tamanho--){
					add_num (operacao);
				}
       

    imprime_polinomio (polinomio_1);   
    }
}
 
void le_polinomio (polinomios *polinomio){
    int cont_1;
 
    for (cont_1 = 0; cont_1 < posicao; cont_1++){
        scanf("%f", &polinomio[cont_1].coeficiente);
        scanf("%d", &polinomio[cont_1].expoente);
        }
}
 
void imprime_polinomio (polinomios *polinomio){
    int cont_1;
 
    for (cont_1 = 0; cont_1 < posicao; cont_1++){
 
        if (polinomio[cont_1].coeficiente >= 0){
            printf("+");
        }
        if (polinomio[cont_1].coeficiente < 0){
            printf("-");
            polinomio[cont_1].coeficiente *= -1;
        }
        printf("%.2f", polinomio[cont_1].coeficiente);
         if (polinomio[cont_1].expoente){
                printf("^%d ",polinomio[cont_1].expoente);
         }
    }
    printf("\n");
}
int add_num (char operacao){
	int cont_1;
	polinomios aux;
	
	scanf("%f", &aux.coeficiente);
    scanf("%d", &aux.expoente);
	for (cont_1 = 0; cont_1 < posicao; cont_1++){
		if (aux.expoente == polinomio_1[cont_1].expoente){
			if (operacao == '+'){
				polinomio_1[cont_1].coeficiente += aux.coeficiente;
			}
			else if (operacao == '-'){
				polinomio_1[cont_1].coeficiente -= aux.coeficiente;
			}
			return (1);
		}
	}
	polinomio_1[posicao++] = aux;
}
	
	

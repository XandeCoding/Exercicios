#include <stdio.h>
#include <stdlib.h>
#define TAM 400
 
typedef struct {
    float coeficiente;
    int expoente;
}polinomios;
 
    polinomios polinomio_1[50], polinomio_2[50], polinomio_3[100];
 
void le_polinomio (polinomios *polinomio, int tamanho);
void imprime_polinomio (polinomios *polinomio, int tamanho);
int soma_polinomio (int tam_poli_1, int tam_poli_2);
int subtrai_polinomio (int tam_poli_1, int tam_poli_2);
 
int main(){
    int casos_teste, tam_polinomio_1, tam_polinomio_2, tamanho_total = 0;
    char operacao;
 
    scanf("%d", &casos_teste);
 
    while (casos_teste--){
        getchar();
        scanf("%c", &operacao);
            scanf("%d", &tam_polinomio_1);
            le_polinomio (polinomio_1, tam_polinomio_1);
 
            scanf("%d", &tam_polinomio_2);
            le_polinomio  (polinomio_2, tam_polinomio_2);
 
 
        if (operacao == '+'){
            tamanho_total = soma_polinomio (tam_polinomio_1,tam_polinomio_2);
        }
 
        if (operacao == '-'){
            tamanho_total = subtrai_polinomio (tam_polinomio_1, tam_polinomio_2);
        }
    imprime_polinomio (polinomio_3, tamanho_total);    
    }
}
 
void le_polinomio (polinomios *polinomio, int tamanho){
    int cont_1;
 
    for (cont_1 = 0; cont_1 < tamanho; cont_1++){
        scanf("%f", &polinomio[cont_1].coeficiente);
        scanf("%d", &polinomio[cont_1].expoente);
        }
}
 
void imprime_polinomio (polinomios *polinomio, int tamanho){
    int cont_1;
 
    for (cont_1 = 0; cont_1 < tamanho; cont_1++){
 
        if (polinomio[cont_1].coeficiente >= 0){
            printf("+");
        }
        if (polinomio[cont_1].coeficiente < 0){
            printf("-");
            polinomio[cont_1].coeficiente *= -1;
        }
        printf("%.2f", polinomio[cont_1].coeficiente);
         if (polinomio[cont_1].expoente){
                printf("X^%d",polinomio[cont_1].expoente);
         }
    }
    printf("\n");
}
 
int soma_polinomio (int tam_poli_1, int tam_poli_2){
    int cont_1 = 0, cont_2 = 0, posicao = 0;
 
    while (cont_1 < tam_poli_1 && cont_2 < tam_poli_2){
        if (polinomio_1[cont_1].expoente > polinomio_2[cont_2].expoente){
            polinomio_3[posicao++] = polinomio_1[cont_1];
            cont_1++;
        }
            else {
                if (polinomio_2[cont_2].expoente > polinomio_1[cont_1].expoente){
                polinomio_3[posicao++] = polinomio_2[cont_2];
                cont_2++;
                }
                else if (polinomio_1[cont_1].expoente == polinomio_2[cont_2].expoente){
                    polinomio_3[posicao].coeficiente = (polinomio_1[cont_1].coeficiente + polinomio_2[cont_2].coeficiente);
                    polinomio_3[posicao++].expoente = polinomio_1[cont_1].expoente;
                    cont_1++;
                    cont_2++;
                }
            }
    }
 
        for (;cont_1 < tam_poli_1; cont_1++){
            polinomio_3[posicao++] = polinomio_1[cont_1];
        }
        for (;cont_2 < tam_poli_2; cont_2++){
            polinomio_3[posicao++] = polinomio_2[cont_2];
        }
    return(posicao);
           
}
int subtrai_polinomio (int tam_poli_1, int tam_poli_2){
int cont_1 = 0, cont_2 = 0, posicao = 0;
 
    while (cont_1 < tam_poli_1 && cont_2 < tam_poli_2){
        if (polinomio_1[cont_1].expoente > polinomio_2[cont_2].expoente){
            polinomio_3[posicao++] = polinomio_1[cont_1];
            cont_1++;
        }
            else {
                if (polinomio_2[cont_2].expoente > polinomio_1[cont_1].expoente){
                polinomio_3[posicao++] = polinomio_2[cont_2];
                polinomio_3[posicao].coeficiente *= -1;
                cont_2++;
                }
                else if (polinomio_1[cont_1].expoente == polinomio_2[cont_2].expoente){
                    polinomio_3[posicao].coeficiente = (polinomio_1[cont_1].coeficiente - polinomio_2[cont_2].coeficiente);
                    polinomio_3[posicao++].expoente = polinomio_1[cont_1].expoente;
                    cont_1++;
                    cont_2++;
                }
            }
    }
 
        for (;cont_1 < tam_poli_1; cont_1++){
            polinomio_3[posicao++] = polinomio_1[cont_1];
        }
        for (;cont_2 < tam_poli_2; cont_2++){
            polinomio_3[posicao++] = polinomio_2[cont_2];
        }
    return(posicao);
           
}
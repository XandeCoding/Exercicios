#include <stdio.h>
#include <string.h>
#define TAM 10000

int e_letra (char *letra);
void troca (char *letra_1, char *letra_2);
void criptografia(char *string);

int main(){
	int quantidade;
	char linha[TAM];
// Leio a quantidade de linhas que devem ser processadas
	scanf("%i", &quantidade);
	getchar();

	while (quantidade--){
		// Processo a criptografia
		scanf("%[^\n]", linha);
		getchar();
		criptografia(linha);
		// As imprimo
		printf("%s\n", linha);
	}

}

void troca (char *letra_1, char *letra_2){
	char aux;

	aux = *letra_1;
	*letra_1 = *letra_2;
	*letra_2 = aux;
}
int e_letra (char *letra){
	if (*letra >= 'a' && *letra <= 'z'){
		return (1);
	}
	if (*letra >= 'A' && *letra <= 'Z'){
		return (1);
	}
		return(0);
}
void criptografia(char *string){
	int cont_1, cont_2, tamanho;

	tamanho = strlen(string);

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		if (e_letra(&string[cont_1])){
			string[cont_1] += 3;
		}
	}

	for (cont_1 = 0, cont_2 = (tamanho-1);cont_1 < (tamanho/2) ;
	 cont_1++, cont_2--){
		troca(&string[cont_1], &string[cont_2]);
	}

	for (cont_1 = (tamanho/2); cont_1 < tamanho; cont_1++){
		string[cont_1] -= 1;
	}
}
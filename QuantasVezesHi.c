#include <stdio.h>
#include <string.h>
#define I 'i'
#define H 'h'
#define BUFF 5000

int vezes_hi (char *string, int tamanho){
	int qtd = 0;

	if (tamanho == 0) return 0;

		if (string[tamanho] == I){
			if (string[tamanho-1] == H){
				qtd ++;
				qtd += vezes_hi (string, tamanho-2); 
			}
		}

		else {
			qtd += vezes_hi (string, tamanho-1);
		}

	return (qtd);
}

int main(){
	int casos, tamanho;
	char string[BUFF];

	scanf("%d", &casos);

	while (casos--){
		getchar();
		scanf("%[^\n]", string);
		tamanho = strlen(string);

		printf("QUANTIDADE HI %d\n", vezes_hi(string, tamanho));
	}
}
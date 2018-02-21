#include <stdio.h>
#include <stdlib.h>

int **matriz;

void pinta_matriz (int tamanho, int cor);
void imprime_matriz (int tamanho);
void cria_matriz (int tamanho, int cor);
void libera_matriz (int tamanho);
void quadrado_bordas (int horizontal, int vertical, int raio, int cor, int tamanho);
void quadrado_cheio (int horizontal, int vertical, int raio, int cor, int tamanho);

int main(){
	int tamanho, cor;
	int pos_h, pos_v, raio, estilo, digito;

	scanf("%d %d", &tamanho, &cor);
	cria_matriz (tamanho, cor);



	pinta_matriz(tamanho, cor);

	while (1){
		do{
			scanf("%d %d", &pos_h, &pos_v);
				if (pos_h == -1 || pos_v == -1){
						imprime_matriz (tamanho);
						return (0);
					}
			scanf("%d %d %d", &digito, &raio, &estilo);

		}while (cor < 0 || cor > 255 || pos_h >= tamanho
		 || pos_h >= tamanho || raio >= tamanho);


		switch (estilo){
			case 1:
				quadrado_bordas (pos_h, pos_v, raio, digito, tamanho);
				break;
			case 2:
				quadrado_cheio (pos_h, pos_v, raio, digito, tamanho);
				break;
		}
	}

	libera_matriz(tamanho);
}

void imprime_matriz (int tamanho){
	int cont_1, cont_2;

	int *inicial = &matriz[0][0];
	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		printf("\n");
		for (cont_2 = 0; cont_2 < tamanho; cont_2++){
			int aux = cont_1 * tamanho;
			printf("%d ", inicial[aux+cont_2]);
		}
	}
}
void pinta_matriz (int tamanho, int cor){
	int cont_1, cont_2;
	int *inicial = &matriz[0][0];

	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		int aux = cont_1 * tamanho;
		for (cont_2 = 0; cont_2 < tamanho; cont_2++){
			inicial[aux+cont_2] = cor;
		}
	}
}
void cria_matriz (int tamanho, int cor){
	int cont_1;

	//matriz = (int **) malloc (tamanho* sizeof(int *));
	 matriz = malloc (sizeof(int *) * tamanho);
	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
		//*(matriz+cont_1) = (int *) malloc (tamanho * sizeof(int));
		 matriz[cont_1] = malloc (sizeof (int) * (tamanho+1));
			if (matriz[cont_1] == NULL) {
		         printf("\nFatal Error! (function: cria_matriz)\n");
		         exit(1);
	      }
	}
}
void libera_matriz (int tamanho){
	int cont;

	for (cont = 0; cont < tamanho; cont++){
		free(*matriz+cont);
	}
		free(matriz);
}
void quadrado_bordas (int horizontal, int vertical, int raio, int cor, int tamanho){
	int cont_1, aux;

	int *inicial = &matriz[0][0];

	int aux_cima = (vertical-raio) * tamanho;
	int aux_baixo = (vertical + raio) * tamanho;
	int aux_esquerda = horizontal - raio;
	int aux_direita = raio + horizontal;


	// Desenha parte de Cima
	for (cont_1 = aux_esquerda; cont_1 <= aux_direita; cont_1++){
		inicial[aux_cima+cont_1] = cor;
	}
	// Desenha parte de Baixo
	for (cont_1 = aux_esquerda; cont_1 <= aux_direita; cont_1++){
		inicial[aux_baixo+cont_1] = cor;
	}
	//Desenha parte Esquerda
	for (cont_1 = vertical-raio; cont_1 <= vertical+raio; cont_1++){
		aux = cont_1 * tamanho;
		inicial[aux+aux_esquerda] = cor;
	}
	// Desenha parte Direita
	for (cont_1 = vertical-raio; cont_1 <= vertical+raio; cont_1++){
		aux = cont_1 * tamanho;
		inicial[aux+aux_direita] = cor;
	}
	// // Teste
	// 	for (cont_1 = 0; cont_1 < tamanho; cont_1++){
	// 		aux = 2 * tamanho;
	// 		inicial[aux+cont_1] = cor;
	// 	}
}
void quadrado_cheio (int horizontal, int vertical, int raio, int cor, int tamanho){
	int cont_1, cont_2;
	int *inicial = &matriz[0][0];

	int aux_cima = vertical - raio;
	int aux_baixo = vertical + raio;
	int aux_direita = horizontal + raio;
	int aux_esquerda = horizontal - raio;

	for (cont_1 = aux_cima; cont_1 <= aux_baixo; cont_1++){
		int aux = cont_1 * tamanho;
		for (cont_2 = aux_esquerda; cont_2 <= aux_direita; cont_2++){
			inicial[aux+cont_2] = cor;
		}
	}
}

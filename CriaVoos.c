#include <stdio.h>
#include <stdlib.h>
#define FIM 0
#define BOL '*'

typedef struct {
	int nvoo;
	int nlug;
	int nmarc;
}aviao;


int main(){
	int cont, realocar;
	aviao *voo;
	FILE *arquivo = fopen("BD.DAT", "wb");

	voo = (aviao *) malloc (5 * sizeof(aviao));

	for (cont = 0, realocar = 0; 1; cont++, realocar++){
		printf("Digite o %d%c, numero do voo\n", cont, BOL);
			scanf("%d", &voo[cont].nvoo);
			if (voo[cont].nvoo == 0) break;
		printf("Digite o %d%c, numero de lugares\n", cont, BOL);
			scanf("%d", &voo[cont].nlug);
		printf("Digite o %d%c, numero de reservados\n", cont, BOL);
			scanf("%d", &voo[cont].nmarc);

		if (realocar >= 5){
			voo = (aviao *) realloc (voo, sizeof(aviao)*(cont+5));
			realocar = 0;
			if (!voo){
				printf("\nNAO FOI POSSIVEL ALOCAR\n");
				break;
			}
		}
	}
				fwrite (voo, sizeof(aviao), cont, arquivo);
				fclose (arquivo);
				free(voo);
				
			
	printf("\nPROGRAMA SENDO ENCERRADO\n");
	return(0);

}

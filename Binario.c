#include <stdio.h>

int binario(int num){
    int numero = num%2;
    if (num == 0){
        return (0);
    }
    binario(num/2);
    return (printf("%d", numero));
}

int main(){
    int num;


    while(1){
        printf("\nDIGITE UM NUMERO\n");
        scanf("%d", &num);
        if (num == 0){
        printf("LEITURA ENCERRADA/n");
        }
        binario(num);
        printf("\n");
    }

}

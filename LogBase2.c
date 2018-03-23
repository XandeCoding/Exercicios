#include <stdio.h>

int LogBase2 (int num){

	if (num == 1){
		return (0);
	}
		return ( LogBase2(num/2));
}

int main(){
	int casos, logaritmo;

	scanf("%d", &casos);

	while (casos--){
		scanf("%d", &logaritmo);

		printf("LOG E %d\n", LogBase2(logaritmo));
	}
}

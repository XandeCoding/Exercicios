#include <stdio.h>

int LogBase2 (int num){
	int loga = 0;

	if (num == 1){
		return (0);
	}

	loga++;
	loga += LogBase2(num/2);
		return (loga);
}

int main(){
	int casos, logaritmo;

	scanf("%d", &casos);

	while (casos--){
		scanf("%d", &logaritmo);

		printf("LOG E %d\n", LogBase2(logaritmo));
	}
}
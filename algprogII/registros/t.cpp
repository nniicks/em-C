#include <stdio.h>

int a(int x){
	return x+1;
}

int main(){
	int numero = 0;

	for(int i = 0; i < 3; i++){
		numero = a(numero);
		printf("%d\n", numero);
	}
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define t 3

struct tipo_pessoa{
	int idade;
	float peso;
	char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){

	tipo_pessoa lista[t];
	int i;

	for(i = 0; i < t; i++){

	printf("Insira os dados (%d):\n", i+1);
	puts("nome: ");
	fgets(lista[i].nome, 50, stdin);
	fflush(stdin);

	puts("idade: ");
	scanf("%d", &lista[i].idade);
	fflush(stdin);

	puts("peso: ");
	scanf("%f", &lista[i].peso);
	fflush(stdin);

	}
	system("class");

	puts("seus dados:\n");
	for(i = 0; i < t; i++){
	
    printf("------------- pessoa %d ------------\n", i+1);
	printf("\tnome: %s\n", lista[i].nome);
	printf("\tidade: %d\n", lista[i].idade);
	printf("\tpeso: %.2fKg\n", lista[i].peso);

	}
	printf("-------------------------------\n");


}
#include <stdio.h>

int main(){
    int aux, ultimo, penultimo, numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    ultimo = numero % 10;
    aux = numero;

    numero = numero / 10;

    penultimo = numero % 10;



    printf("A soma dos ultimos dois digitos do numero %d eh %d", aux, ultimo+penultimo);


}
#include <stdio.h>

/*Escreva um programa que receba dois numeros inteiros positivos i e j e
devolva o menor inteiro m maior que i e multiplo de j

Para transformar um numero inteiro i no menor inteiro m maior que i e
multiplo de um numero inteiro j, a seguinte formula pode ser utilizada:
m = i + j  i mod j.*/


int main(){
    int i, j, menor_int;

    printf("Informe um numero inteiro:\n");
    scanf("%d", &i);

    printf("Informe outro numero inteiro:\n");
    scanf("%d", &j);

    menor_int = i + j - (i % j);

    printf("O menor numero inteiro que eh maior do que %d e eh tambem multiplo de %d eh o %d.", i, j, menor_int);

}
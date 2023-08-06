/*Dada uma sequencia de n numeros inteiros, com 1 <= n <= 100,
imprimi-la em ordem inversa a de leitura.*/

#include <stdio.h>

#define MAX 100

int main(){
    int n, seq[MAX] /*inv[n]*/;

    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &seq[i]);

    }

    for(int i = n - 1; i > -1; i--){
        printf("%d ", seq[i]);
    }
/*
    for(int i = n; i > -1; i--){
        inv[n-i] = seq[i-1];
    }

    for(int i = 0; i < n; i++){
        printf("%d ", inv[i]);
    }
*/
    return 0;
}


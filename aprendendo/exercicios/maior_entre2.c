/*faça um programa que receba dois numeros e mostre o maior deles.
caso eles sejam iguais deve-se mostar a mensagem "os numero sao iguais"*/

#include <stdio.h>

int main(){
    float num1,num2;

    printf("Digite um numero inteiro qualquer: ");
    scanf("%f", &num1);

    printf("Digite um segundo numero inteiro qualquer: ");
    scanf("%f", &num2);

    if (num1 == num2){
        printf("Os numeros sao iguais");

    }

    if (num1 > num2){
        printf("O maior numero eh %.1f", num1);
    }

    if (num1 < num2){
        printf("O maior numero eh %.1f", num2);
    }

}
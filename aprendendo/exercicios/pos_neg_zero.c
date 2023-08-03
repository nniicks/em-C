#include <stdio.h>

int main(){
    float num;

    printf("Digite um numero real\n");
    scanf("%f", &num);

    if(num > 0){
        printf("O numero %.2f eh positivo!", num);

    }

    if(num < 0){
        printf("O numero %.2f eh negativo!", num);
    }

    if(num == 0){
        printf("O numero digitado eh igual a zero(0)!");
    }
}
#include <stdio.h>

int mdc(int x, int y){
    
    int aux;

    while(y !=0){
        aux = x % y;
        x = y;
        y = aux;

    }

    return x;
    
}

int main(){
    int a, b, resultado;

    printf("Informe dois numeros inteiros:\n");
    scanf("%d %d", &a, &b);

    resultado = mdc(a, b);

    printf("O mdc entre %d e %d eh: %d!",a, b, resultado);

    return 0;

}
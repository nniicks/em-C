#include <stdio.h>

void soma_prod(int a, int b, int *soma, int *prod);

int main(){
    int num1, num2, s, p;
    
    scanf("%d %d", &num1, &num2);
    
    soma_prod(num1, num2, &s, &p);
    
    printf("soma entre %d e %d = %d\n", num1, num2, s);
    printf("produto entre %d e %d = %d\n", num1, num2, p);
    
    
    return 0;
}


void soma_prod(int a, int b, int *soma, int *prod){
    
    *soma = a + b;
    *prod = a * b;
}

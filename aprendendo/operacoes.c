#include <stdio.h>

int main(){
    int a, b, soma, sub, mult, div;
    
   /* printf("Digite um valor:\n");

    scanf("%d", &a);
    
    printf("Digite outro valor:\n");
   
    scanf("%d", &b);
   
    c = a + b;
   
    printf("A soma entre %d e %d é %d\n", a,b,c);
    */

   printf("Digite dois valores: ");

   scanf("%d %d", &a, &b);

   soma = a + b;
   sub = a - b;
   mult = a * b;
   div = a / b;

   printf("A soma entre %d e %d eh: %d\n", a, b, soma);
   
   printf("A subtracao entre %d e %d eh: %d\n", a, b, sub);
   
   printf("A multiplicacao entre %d e %d eh: %d\n", a, b, mult);
   
   printf("A divisao de %d por %d eh: %d\n", a, b, div);
}



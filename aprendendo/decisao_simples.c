#include <stdio.h>

/* if - SINTAXE -:
if(<condicional>){

    <bloco_de_comandos>

} 


IF-ELSE - SINTAXE -:
if(<condicional>){

    <bloco_de_comandos1
}

else {
    <bloco_de_comandos2
}

-------------------------------------------------

- OPERADORES LÓGICOS -:
-CONJUNÇÃO ("e" lógico): &&
    eh vrdd quando tudo for vrdd
    
-DISJUNÇÃO ("ou" lógico): ||
    eh vrdd se ao menos 1 for vrdd
    
-INVERSÃO (negação -"não lógico"): !
    eh vrdd quando o operando é falso        */


int main(){
    int num;

    printf("Informe um valor: ");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("O numero %d eh par!", num);
    }

    else {
        printf("O numero %d eh impar!", num);
    }
    
}
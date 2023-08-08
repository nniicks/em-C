#include <stdio.h>

#define MAX 100

int main(){

    char palavra[MAX];
    int n = 0, espacos = 1;

    printf("Informe uma palavra ou uma frase:\n");
    scanf("%[^\n]", palavra);

    while(palavra[n] != '\0'){
        n++;
    }

    for(int i = 0; i < n; i++){
        if (palavra[i] == ' '){
            espacos++;
        }
    }

    printf("A frase '%s' possui %d caracter(es) e contem %d palavra(s)!", palavra, n, espacos);

    return 0;

   /*na condiçao do for, eu tbm poderia ter colocado palavra[i] != '\0'
   ao inves de i < n*/ 
}

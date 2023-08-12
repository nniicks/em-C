/*Dadas duas sequencias de caracteres (uma contendo uma frase e
outra contendo uma palavra), determine o numero de vezes que a
palavra ocorre na frase. Considere que essas sequencias tem no
maximo 100 caracteres cada uma.
Exemplo:
Para a palavra ANA e a frase:
ANA E MARIANA GOSTAM DE BANANA.
Temos que a palavra ocorre 4 vezes na frase*/

#include <stdio.h>

#define MAX 100

int main(){

    char palavra[MAX], frase[MAX];
    int flag, contador = 0,p = 0, i = 0, j;



    scanf("%s", palavra);
    fflush(stdin);
    scanf("%[^\n]", frase);
    fflush(stdin);

    while(palavra[p] != '\0'){
        p++;
    }

    while(frase[i] != '\0'){
        /*flag = 0;*/
        
        if(frase[i] == palavra[0]){
            flag = 0;

            j = 1;
            
            while(frase[i + j] == palavra[j]){
                printf("%c ", frase[i+j]);
                printf("%c ", palavra[j]);
                

                flag++;
                j++;
            
            }
        }
        if(flag + 1 == p){
            contador++;
        }

        i++;
    }

    printf("%d", contador);


    
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void leitura(char *palavra, int n);

void imprime(char *palavra, int n);

void troca(char *palavra, int n);

int ord(char c){
    
    return int(c);
}

int main(){
    char *palavra;
    int n;
    
    scanf("%d", &n);
    
    palavra = (char *) malloc(n * sizeof(char));
    if(palavra == NULL){
        return 0;
    }
    
    leitura(palavra, n);
    
    troca(palavra, n);
    
    imprime(palavra, n);
}

void leitura(char *palavra, int n){
    
    scanf("%s", palavra);
}

void troca(char *palavra, int n){
    char *p;
    int aux;
    
    for(p = palavra; p < palavra + n; p++){
        aux = ord(*p);
        if(aux >= 97 &&  aux <= 122){
            *p = toupper(*p);
        }
    }
    
}

void imprime(char *palavra, int n){
    char *p;
    
    for(p = palavra; p < palavra + n; p++){
        printf("%c", *p);
    }
    
}

//imprimindo a string de um jeito psicopata
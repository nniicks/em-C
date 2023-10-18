/* ler varias palavras ate uma palavra com 4 caracteres for digitada,
depois printar a maior string e a menor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20

int conta(char *palavra);

int main(){
    char *palavra, *p_maior, *p_menor;
    int aux, maior = - 1, menor = 21;
    
    palavra = (char *) malloc(M * sizeof(char));
    if(palavra == NULL){
        return 0;
    }
    
    p_maior = (char *) malloc(M * sizeof(char));
    if(p_maior == NULL){
        return 0;
    }
    p_menor = (char *) malloc(M* sizeof(char));
    if(p_menor == NULL){
        return 0;
    }
    
    do{
        printf("Digite uma palavra:\n");
        scanf("%s", palavra);
        
        aux = conta(palavra);
        if(aux == 4){
            break;
        }
        
        if(aux > maior){
            maior = aux;
            strcpy(p_maior, palavra);
        }
        
        if(aux < menor){
            menor = aux;
            strcpy(p_menor, palavra);
        }
        
    }while(1);
    
    printf("Maior palavra: %s\n", p_maior);
    printf("Menor palavra: %s\n", p_menor);
    
    free(palavra);
    free(p_maior);
    free(p_menor);
    
    return 0;
    
}

int conta(char *palavra){
    int soma = 0;
    char *p;
    
    p = palavra;
    while(*p != '\0'){
        soma++;
        p++;
    }
    
    return soma;

}
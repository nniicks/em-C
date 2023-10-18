#include <stdio.h>
#include <stdlib.h>
#define M 100

int conta(char *palavra, int p);

int main(){
    char *palavra;
    
    palavra = (char *) malloc(M * sizeof(char));
    if(palavra == NULL){
        return 0;
    }
    
    printf("Digite uma palavra:\n");
    scanf("%[^\n]", palavra);
    
    printf("Essa palavra possui %d caracteres, incluindo espacos:", conta(palavra, 0));
    
    free(palavra);
    
    return 0;
}

int conta(char *palavra, int p){
    
    if(*(palavra+p) == '\0'){
        return 0;
    }else{
        return 1 + conta(palavra, p+1);
    }
    
}
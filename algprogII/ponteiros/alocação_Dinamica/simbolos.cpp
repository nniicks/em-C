#include <stdio.h>
#include <stdlib.h>

int ord(char c){
    
    return int(c);
}

int main(){
    char *vetor, *p;
    int  n, aux, maiusculas = 0, minusculas = 0, espacos = 0, acentos =  0, digitos = 0;
    
    scanf("%d", &n);
    getchar();
    
    vetor = (char *) malloc(n * sizeof(char));
    
    if(vetor != NULL){
        scanf("%[^\n]", vetor);
        getchar();
        
        for(p = vetor; p < vetor + n; p++){
            aux = ord(*p);
            
            if(aux >= 97 && aux <= 122){
                minusculas++;
                digitos++;
            }else if(aux >= 65 && aux <= 90){
                maiusculas++;
                digitos++;
            }else if(aux == -61){
                acentos++;
            }else if(*p == ' '){
                espacos++;
            }
        
      
        }
    printf("Quantidade total de caracteres: %d\n", digitos);  
    printf("Quantidade de letras maiusculas: %d\n", maiusculas);
    printf("Quantidade de letras minusculas: %d\n", minusculas);
    printf("Quantidade de espacos: %d\n", espacos);
    printf("Quantidade de simbolos de pontuacao: %d\n", acentos);
    
    free(vetor);
    
    }else{
        printf("Impossivel alocar vetor na memoria!");
    }
    
    return 0;
    
}
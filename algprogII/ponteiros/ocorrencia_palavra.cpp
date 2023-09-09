/*Escreva uma fun¸c˜ao que receba duas cadeias de caracteres como parˆametros e verifique se a segunda cadeia ocorre dentro da primeira 
(busque apenas pela primeira ocorrˆencia). Use aritmeticade ponteiros para acessar os caracteres das cadeias*/

#include <stdio.h>
#define M 50

void verifica(char *p, char *q);

int main(){
    char plv1[M], plv2[M];
    
    printf("Informe uma palavra/frase:\n");
    scanf("%[^\n]", plv1);
    getchar();
    
    printf("Informe uma outra palavra/frase:\n");
    scanf("%[^\n]", plv2);
    getchar();
    
    verifica(plv1, plv2);
    
    return 0;
}


void verifica(char *p, char *q) {
    
    while(*p != '\0') {
        char *pont_aux = p; // guarda a posição inicial
        
        // verifica se a segunda cadeia ocorre na primeira
        while(*q != '\0' && *q == *pont_aux) {
            q++;
            pont_aux++;
        }
    
        if(*q == '\0') {
            printf("Ocorre\n");
            return;
        }
        
        p++;
    }
    
    printf("Não ocorre\n");
}

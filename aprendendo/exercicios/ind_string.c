#include <stdio.h>
#include <string.h>

#define n 50

int main(){
    char texto[n];
    int i, j;

    printf("Digite uma palavra:\n");
    gets(texto);
    j = strlen(texto);
    printf("\nTamanho do texto: %d\n\n", j);

    printf("impressao de posicao a posicao:\n");
    for (i = 0;i < j; i++){
        printf("%c", texto[i]);
    }
    
}
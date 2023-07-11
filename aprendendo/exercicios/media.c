#include <stdio.h>

int main(){
    int n1, n2, n3, n4, media;

    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);

    printf("Digite o segundo valor: ");
    scanf("%d", &n2);

    printf("Digite o terceiro valor: ");
    scanf("%d", &n3);

    printf("Digite o quarto valor: ");
    scanf("%d", &n4);

    media = (n1 + n2 + n3 + n4)/4;

    printf("A media entre %d, %d, %d e %d eh: %d", n1, n2, n3, n4, media);

}
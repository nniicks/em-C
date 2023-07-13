#include <stdio.h>


int main(){

    float n1, n2, n3, media;

    printf("Insira a nota do trabalho:\n");
    scanf("%f", &n1);

    printf("Insira a nota da avaliacao:\n");
    scanf("%f", &n2);

    printf("Insira a nota do exame final:\n");
    scanf("%f", &n3);

    media = (n1*2 + n2*3 + n3*5)/10;
    printf("Media: %.2f\n", media);

    if (media >= 8 && media <=10){
        printf("Conceito A.");
    }

    if (media >= 7 && media < 8){
        printf("Conceito B.");
    }

    if (media >= 6 && media < 7){
        printf("Conceito C.");

    }

    if (media >= 5 && media < 6){
        printf("Conceito D.");
    }

    if (media >= 0 && media < 5){
        printf("Conceito E.");
    }
}

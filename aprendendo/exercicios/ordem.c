#include <stdio.h>

/*Escreva um programa que receba tres valores, armazenando-os nas
variaveis x, y e z, e ordene esses valores de modo que, ao final, o
menor valor esteja armazenado na variavel x, o valor intermediario
esteja armazenado na variavel y e o maior valor esteja armazenado na
variavel z*/

int main(){
    int x, y, z;

    printf("Informe tres numeros reias, separados por espaco\n");
    scanf("%d %d %d", &x, &y, &z);

    if (x <= y && x <= z){

        if (y < z){
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",x,y,z);
        }

        else{
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",x,z,y);

        }

    }

    if (y <= x && y <= z){

        if (x < z){
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",y,x,z);

        }

        else{
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",x,z,x);
        }
    }

    if (z <= x && z <= y){

        if (x < y){
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",z,x,y);
        }
        else{
            printf("O valores de x, y e z sao, respectivamente, %d, %d e %d",z,y,x);
        }
    }

    
    }


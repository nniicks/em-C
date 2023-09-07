/*Escreva um programa que cadastre o nome, a altura, o peso, o cpf e sexo de algumas
pessoas. Com os dados cadastrados, em seguida, localize uma pessoa através do seu CPF
(informado pelo usuário) e imprima o seu IMC (IMC = PESO/ALTURA^2).
Funcionalidade adicional 1: permita consultar várias vezes, até que se digite 0 (zero) para
terminar.
Funcionalidade adicional 2: crie um menu no programa para que, além de consultar IMC por
CPF, liste (IMC e nome) de todas as pessoas do sexo masculino.*/

#include <stdio.h>
#include <string.h>
#define M 50

struct novoT{
    char nome[M], sexo[M];
    int cpf;
    float altura, peso, IMC;
};

void cadastro(novoT v[M], novoT *p);

void busca(novoT v[M], novoT *p, int  *cpf, int  *tamanho);

void masc(novoT v[M], novoT *p, int *tam);

int main(){
    
    novoT lista[M], *q;
    int cp, aux = 0;
    char n;
    
    printf("Informe os seguintes dados:\n");
    q = lista;
    do{
        cadastro(lista, q);
        q+=1;
        aux+=1;
        
        printf("Deseja informar dados de mais uma pessoa? (s/n):\n");
        scanf("%c", &n);
        getchar();
    }while(n != 'n');
    
    do{
        printf("Informe um numero de cpf:\n");
        scanf("%d", &cp);
        getchar();
    
        busca(lista, q, &cp, &aux);
    }while(cp != 0);
    
    masc(lista, q, &aux);
    
    return 0;

}

void cadastro(novoT v[M], novoT *p){
    
    printf("Nome da pessoa:\n");
    scanf("%[^\n]", p->nome);
    getchar();
    
    printf("O sexo de(a) %s:\n", p->nome);
    scanf("%[^\n]", p->sexo);
    getchar();
    
    printf("O CPF:\n");
    scanf("%d", &p->cpf);
    getchar();
    
    printf("Agora alura:\n");
    scanf("%f", &p->altura);
    getchar();
    
    printf("Por fim o peso:\n");
    scanf("%f", &p->peso);
    getchar();
    
    p->IMC = p->peso/(p->altura * p->altura);
    
   
}

void busca(novoT v[M], novoT *p, int *cpf, int *tamanho){
    
    printf("\n");
    for(p = v; p < v + *tamanho; p++){
        if(p->cpf == *cpf){
            printf("IMC de %s eh: %.2f\n", p->nome, p->IMC);
        }
    }
    
}

void masc(novoT v[M], novoT *p, int *tam){
    
    printf("----- IMC de pessoas do sexo masculino -----\n\n");
    for(p = v; p < v + *tam; p++){
        if(strcmp(p->sexo,"masculino") == 0){
            printf("IMC de %s eh: %.2f\n", p->nome, p->IMC);
        }
    }

}
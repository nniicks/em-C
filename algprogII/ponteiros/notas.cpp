#include <stdio.h>
#define M 20
#define A 2

struct novoTipo{
    char nome[M];
    int matric;
    float n1, n2, n3;
};

void cadastro(novoTipo lista[A]);

void media(novoTipo lista[A], float *m);

void maiorMedia(novoTipo lista[A], float *m);


int main(){
    novoTipo lista[A];
    float mediaG = 0.0;
    
    cadastro(lista);
    media(lista, &mediaG);
    maiorMedia(lista, &mediaG);
    
    return 0;
}


void cadastro(novoTipo lista[A]){
    
    novoTipo *p;
    
    for(p = lista; p < lista + A; p++){
        printf("Informe a matriculo do aluno(a):\n");
        scanf("%d", &p->matric);
        getchar();
        
        printf("Informe o nome do(a) aluno(a):\n");
        scanf("%[^\n]", p->nome);
        getchar();
        
        printf("Informe a nota da p1 do aluno(a) %s:\n", p->nome);
        scanf("%f", &p->n1);
        getchar();
        
        printf("Informe a nota da p2 do(a) aluno(a) %s:\n", p->nome);
        scanf("%f", &p->n2);
        getchar();
        
        printf("Informe a nota da p3 do(a) aluno(a) %s:\n", p->nome);
        scanf("%f", &p->n3);
        getchar();
        
    }
}



void media(novoTipo lista[A], float *m){
    
    float soma = 0;
    novoTipo *p;
    
    for(p = lista; p < lista + A; p++){
        soma = p->n1 + p->n2 + p->n3;
        if(soma/3 > *m){
            *m = soma/3;
        }
        
    }
}


void maiorMedia(novoTipo lista[A], float *m){
    
    novoTipo *p;
    
    for(p = lista; p < lista + A; p++){
        if((p->n1 + p->n2 + p->n3)/3 == *m){
            printf("\n");
            printf("Aluno(a) com maior media geral: %s", p->nome);
        }
    }
}
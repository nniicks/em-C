/*. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matr´ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
(a) Permita ao usuario entrar com os dados de 5 alunos. ´
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior media geral. ´
(d) Encontre o aluno com menor media geral ´
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovac¸ao*/

#include <stdio.h>
#include <string.h>
#define A 5
#define M 20

struct novoTipo{
    int mat;
    char nome[M];
    float p1, p2, p3;
};

void entradas(novoTipo v[A], novoTipo *p);

void status(novoTipo v[A], novoTipo *p);

void maior_P1(novoTipo v[A], float *maior, char ap1[M], novoTipo *p);

void maior_MD(novoTipo v[A], float *maior, char aMDG[M], novoTipo *p);

void menor_MD(novoTipo v[A], float *menor, char aMENOR[M], novoTipo *p);


int main(){
    
    novoTipo lista[A], *q;
    float maiorM = 0, menorM = 11, maiorP1 = 0;
    char alP1[M], alMaior[M], alMenor[M];
    
    entradas(lista, q);
    
    status(lista, q);
    
    maior_P1(lista, &maiorP1, alP1, q);
    
    maior_MD(lista, &maiorM, alMaior, q);
    
    menor_MD(lista, &menorM, alMenor, q);
    
    printf("\n--------------------------\n\n");
    printf("Aluno(a) com maior nota da p1: %s --- nota p1: %.2f\n", alP1, maiorP1);
    printf("Aluno(a) com maior media geral: %s --- media: %.2f\n", alMaior, maiorM);
    printf("Aluno(a) com menor media geral: %s --- media: %.2f\n", alMenor, menorM);
        
    
    return 0;
    
}

void entradas(novoTipo v[A], novoTipo *p){
    
    for(p = v; p < v + A; p++){
        
        printf("Informe a matricula  do(a) aluno(a):\n");
        scanf("%d", &p->mat);
        getchar();
        
        printf("Informe o nome do(a) aluno(a):\n");
        scanf("%[^\n]", p->nome);
        getchar();
        
        printf("Informe as notas da p1, p2 e p3 do(a) aluno(a) %s:\n", p->nome);
        scanf("%f %f %f", &p->p1, &p->p2, &p->p3);
        getchar();
        
    }
   
    
}

void status(novoTipo v[A], novoTipo *p){
    
    printf("-----SITUACAO ACADEMICA------\n");
    for(p = v; p < v + A; p++){
        if((p->p1 + p->p2 + p->p3)/3 >= 6){
            printf("Status do(a) aluno(a) %s: APROVADO(A)!\n", p->nome);
        }else{
            printf("Status do(a) aluno(a) %s: REPROVADO(A)!\n", p->nome);
        }
    }
    
    
}


void maior_P1(novoTipo v[A], float *maior, char ap1[M], novoTipo *p){
    
    
    for(p = v; p < v + A; p++){
        if(p->p1 > *maior){
            *maior = p->p1;
            strcpy(ap1, p->nome);
            
        }
    } 
    
}

void maior_MD(novoTipo v[A], float *maior, char aMDG[M], novoTipo *p){
    
    for(p = v ; p < v + A; p++){
        if((p->p1 + p->p2 + p->p3)/3 > *maior){
            *maior = (p->p1 + p->p2 + p->p3)/3;
            strcpy(aMDG, p->nome);
        }
    
    }
}


void menor_MD(novoTipo v[A], float *menor, char aMENOR[M], novoTipo *p){
    
    for(p = v; p < v + A; p++){
        if((p->p1 + p->p2 + p->p3)/3 < *menor){
            *menor = (p->p1 + p->p2 + p->p3)/3;
            strcpy(aMENOR, p->nome);
        
        }   
        
    }
    
}

/*Escreva um programa que cadastre o nome, a matrícula e duas notas de N alunos
(N≤50). Em seguida, imprima a matrícula, o nome e a média de cada um deles.*/

#include <stdio.h>
#define M 50

struct novoT{
    char nome[M];
    int mat;
    float n1, n2;
};

void cadastro(novoT v[M], novoT *p);

void media(novoT v[M], int *alunos, novoT *p);

int main(){
    
    novoT lista[M], *q;
    int aux = 0;
    char n;
    
    q = lista; /*q esta apontando para a primeira posicao do vetor lista*/
    
    do{
        printf("Informe as seguintes informacoes do estudante:\n");
        cadastro(lista, q);
        q+= 1;
        aux+= 1;
        
        printf("Deseja entrar com dados de mais estudantes? (s/n):\n");
        scanf("%c", &n);
    }while(n !=  'n');
    
    printf("\n");
    media(lista, &aux, q);

    return 0;

}

void cadastro(novoT v[M], novoT *p){
    
    printf("\n");
    printf("Matricula:\n");
    scanf("%d", &p->mat);
    getchar();
    
    printf("Nome do(a) aluno(a):\n");
    scanf("%[^\n]", p->nome);
    getchar();
    
    printf("Notas da p1 e p2 do(a) aluno(a) %s:\n", p->nome);
    scanf("%f %f", &p->n1, &p->n2);
    getchar();

    
}

void media(novoT v[M], int *alunos, novoT *p){
    
    float soma;
    
    for(p = v; p < v + *alunos; p++){
        soma = p->n1 + p->n2;
        printf("A meida do(a) aluno(a) %s eh %.2f\n", p->nome, soma/2);
        
    }
}




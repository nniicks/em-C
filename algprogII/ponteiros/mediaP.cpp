/*Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de
alunos: Curso, Nome, Codigo da Disciplina, Nota1 e Nota2. Considere uma turma de
ate 10 alunos. Apos ler todos os dados digitados, e depois de armazena-los em um vetor
de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas medias
finais (use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/

#include <stdio.h>
#define A 2
#define M 30

struct novoTipo{
    char curso[M], nome[M];
    int codDisc;
    float n1, n2;
};

void entradas(novoTipo v[A], novoTipo *p);

void medias(novoTipo v[A], novoTipo *p);

int main(){
    novoTipo alunos[A], *q;
    
    entradas(alunos, q);
    medias(alunos, q);
    
    return 0;
}

void entradas(novoTipo v[A], novoTipo *p){
    
    for(p = v; p < v + A; p++){
        
        printf("Informe o curso:\n");
        scanf("%[^\n]", p->curso);
        getchar();
        
        printf("Informe o nome do(a) aluno(a):\n");
        scanf("%[^\n]", p->nome);
        getchar();
        
        printf("Informe o codido da disciplina:\n");
        scanf("%d", &p->codDisc);
        getchar();
        
        printf("Informe as nota da p1 e p2 do(a) aluno(a) %s:\n", p->nome);
        scanf("%f %f", &p->n1, &p->n2);
        getchar();
        
    }
}

void medias(novoTipo v[A], novoTipo *p){
    float media;
    
    printf("\n----- MEDIAS GERAIS -----\n\n");
    for(p = v; p < v + A; p++){
        media = ((p->n1 * 1)  + (p->n2 * 2)) / 3;
        printf("Aluno(a) %s, media geral: %.2f\n", p->nome, media);
        
    }
    
}
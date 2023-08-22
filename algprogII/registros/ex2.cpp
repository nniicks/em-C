/*Construa uma estrutura tAluno com número de matrícula, nome (com até 30 caracteres) e curso (com até 30 caracteres), 
nesta ordem. Leia do usuário as informações de 5 alunos e armazene em vetor dessa estrutura. Em seguida, 
leia um nome de curso, pesquise e liste todos os alunos (a matrícula e nome) que fazem o curso.*/

#include <stdio.h>
#include <string.h>
#define MAX 30
#define A 5

struct novo_tipo{
    int mat;
    char nome[MAX], curso[MAX];
};

int main(){
    novo_tipo aluno[A];
    char aux[MAX];
    
    for(int i = 0; i < A; i++){
        scanf("%d", &aluno[i].mat);
        getchar();
        scanf("%[^\n]", aluno[i].nome);
        getchar();
        scanf("%[^\n]", aluno[i].curso);
        getchar();
    }
    
    scanf("%[^\n]", aux);
    
    for(int i = 0; i < A; i++){
        if(strcmp(aux, aluno[i].curso) == 0){
            printf("%d %s\n", aluno[i].mat, aluno[i].nome);
        }
    }
    
    return 0;
}
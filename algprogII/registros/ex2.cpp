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
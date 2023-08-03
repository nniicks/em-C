#include <stdio.h>

int main(){
    int matricula;
    char turma;
    float nota;

    printf("Informe o codigo da matricula, a turma e a nota do aluno: ");
    scanf("%d %c %f", &matricula, &turma, &nota);

    printf("O codigo da matricula eh %d, a turma eh %c e a nota do aluno eh %.1f", matricula, turma, nota);

}
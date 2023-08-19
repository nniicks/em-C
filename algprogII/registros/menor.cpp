/*Dadas duas descrições de tarefas e seus horários de
início no formato hh:mm:ss, escreva um programa que
verifica qual das duas tarefas será iniciada antes.
Considere que a descrição de uma tarefa tenha no
máximo 50 caracteres.*/

#include <stdio.h>
#define MAX 50

struct novo_tipo{
    int hh, mm, ss;
    char nome[MAX];
};

int main(){
    novo_tipo t1, t2;
    int tempo1, tempo2;

    printf("Informe o nome da primeira tarefa:\n");
    scanf("%[^\n]", t1.nome);
    fflush(stdin);

    printf("Informe o horario de inicio da primeira tafera, (hh:mm:ss):\n");
    scanf("%d:%d:%d", &t1.hh, &t1.mm, &t1.ss);
    fflush(stdin);

    printf("Informe o nome da segunda tarefa:\n");
    scanf("%[^\n]", t2.nome);
    fflush(stdin);

    printf("Informe o horario de inicio da segunda tafera, (hh:mm:ss):\n");
    scanf("%d:%d:%d", &t2.hh, &t2.mm, &t2.ss);
    fflush(stdin);

    tempo1 = t1.hh*3600 + t1.mm*60 + t1.ss;
    tempo2 = t2.hh*3600 + t2.mm*60 + t2.ss;

    if(tempo1 <= tempo2){
        printf("A tarefa %s vai ser realizada antes da tarefa %s!", t1.nome, t2.nome);
        
    }else{
        printf("A tarefa %s vai ser realizada antes da tarefa %s!", t2.nome, t1.nome);
    }

    return 0;

}
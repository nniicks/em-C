/*5) Crie um programa que permita armazenar o nome, a altura e da data de nascimento de
até 10 pessoas.
Cada pessoa deve ser representada por uma struct dentro de um vetor.
A data de nascimento também deve ser uma struct.
O nome e a altura de cada pessoa devem ser informados pelo teclado.
O programa deve, na tela de abertura, apresentar opções para:
● 1 - inserir uma pessoa;
● 2 - listar todos os nomes e respectivas alturas;
● 3 - listar os nomes das pessoas que nasceram antes de uma certa data fornecida.
Os itens 2 e 3 acima devem ser implementados em uma função separada.*/

#include <stdio.h>
#define T 10
#define M 50

struct nasc{
    int dia, mes, ano;
};

struct novoT{
    char nome[M];
    float altura;
    nasc data;
};

int menu();
void criacao(novoT *p);
void nome_altura(novoT *q, int *quant);
void dat_nasc(novoT *pont,int *quant, nasc dataFornecida);

int main(){
    novoT lista[T], *pont_aux;
    int escolha, quantidade = 0;
    nasc data_aux;
    
    pont_aux = lista;
    
    escolha = menu();
    
    while(escolha != 4){
        if(escolha == 1){
             criacao(pont_aux);
             pont_aux++;
             quantidade++;
             
        }else if(escolha == 2){
            nome_altura(lista, &quantidade);
        }else if(escolha == 3){
            printf("Informe a data: dia/mes/ano\n");
            scanf("%d/%d/%d", &data_aux.dia, &data_aux.mes, &data_aux.ano);
            getchar();
            
            dat_nasc(lista, &quantidade, data_aux);
        }
        escolha = menu();
    }
    
    printf("---- FIM DO PROCESSO ----");
    
    return 0;
    
}


int menu(){
    int aux;
    
    printf("\n\n----- MENU -----\n");
    printf("(1) - Inserir uma pessoa\n");
    printf("(2) - Listar todos os nomes e respectivas alturas\n");
    printf("(3) - Listar os nomes das pessoas que nasceram ate certa data\n");
    printf("(4) - Terminar\n");
    scanf("%d", &aux);
    getchar();
    
    if(aux == 1){
        return 1;
    }else if(aux == 2){
        return 2;
    }else if(aux == 3){
        return 3;
    }else{
        return 4;
    }
}


void criacao(novoT *p){
    
    printf("Informe o nome:\n");
    scanf("%[^\n]", p->nome);
    getchar();
    
    printf("Informe a altura:\n");
    scanf("%f", &p->altura);
    getchar();
    
    printf("Informe a data de nascimento: dia/mes/ano\n");
    scanf("%d/%d/%d", &p->data.dia, &p->data.mes, &p->data.ano);
    getchar();
    
}


void nome_altura(novoT *q, int *quant){
    novoT *qaux;
    
    for(qaux = q; qaux < q + *quant; qaux++){
        printf("LISTA DE PESSOAS CADASTRADAS:\n");
        printf("Nome: %s\n", qaux->nome);
        printf("Altura: %.2f\n", qaux->altura);
    }
}


void dat_nasc(novoT *pont, int *quant, nasc dataFornecida){
    novoT *p_aux;
    int flag = 0;
    
    for(p_aux = pont; p_aux < pont + *quant; p_aux++){
        
        if(p_aux->data.ano < dataFornecida.ano){
            printf("PESSOAS QUE NASCDERAM ANTES DE %d/%d/%d\n", dataFornecida.dia, dataFornecida.mes, dataFornecida.ano);
            printf("Nome: %s\n", p_aux->nome);
            flag = 1;
        }else if(p_aux->data.mes < dataFornecida.mes){
            printf("Nome: %s\n", p_aux->nome);
        }else if(p_aux->data.dia < dataFornecida.dia){
            printf("Nome: %s\n", p_aux->nome);
        }
    }
    
    if(flag == 0){
        printf("Nenhuma pessoa da lsita nasceu antes de %d/%d/%d !\n", dataFornecida.dia, dataFornecida.mes, dataFornecida.ano);
    }
}

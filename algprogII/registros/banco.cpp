/*4) Escreva um programa que simule contas bancárias, com as seguintes especificações:
● Ao iniciar o programa, o programa deve criar contas bancárias para três clientes.
- Cada conta terá o nome e o CPF do cliente associado a ela.
- No ato da criação da conta o cliente precisará fazer um depósito inicial.
● Após as contas serem criadas, o sistema deverá possibilitar realizações de saques
ou depósitos nas contas.
○ Sempre que uma operação de saque ou depósito seja realizada, o sistema
deverá imprimir o nome do titular e o saldo final da conta.*/

#include <stdio.h>
#define M 50
#define C 3

struct novoT{
    int cpf;
    char nome[M];
    float conta;
};

void criacao(novoT *p);

void operacoes(novoT *q);

int menu();

int main(){
    novoT lista[C];
    
    criacao(lista);
    operacoes(lista);
    
    return 0;
}


void criacao(novoT *p){
    novoT *pontAux;
    
    for(pontAux = p; pontAux < p + C; pontAux++){
        printf("Informe o nome:\n");
        scanf("%[^\n]", pontAux->nome);
        getchar();
        
        printf("Informe o CPF:\n");
        scanf("%d", &pontAux->cpf);
        getchar();
        
        printf("Faça o deposito inicial:\n");
        scanf("%f", &pontAux->conta);
        getchar();
  
    }
}


void operacoes(novoT *q){
    int escolha, cpfAux, flag;
    novoT *ptAux;
    float saque_dep;
    
    escolha = menu();
    
    while(escolha != 3){
        if(escolha == 1){
            printf("Informe o CPF:\n");
            scanf("%d", &cpfAux);
            
            flag = 0;
            for(ptAux = q; ptAux < q + C; ptAux++){
                if(cpfAux == ptAux->cpf){
                    printf("Informe o valor a ser retirado:\n");
                    scanf("%f", &saque_dep);
                    flag = 1;
                    
                    if(ptAux->conta < saque_dep){
                        printf("Saldo insuficiente!\n");
                    }else{
                        ptAux->conta -= saque_dep;
                        printf("\nNome do Titular: %s\n", ptAux->nome);
                        printf("Saldo atual: %.2f\n", ptAux->conta);
                    }
                }
            }if(flag == 0){
                printf("CPF não encontrado!\n");
            }
        }
        if(escolha == 2){
            printf("Informe o CPF:\n");
            scanf("%d", &cpfAux);
            
            flag = 0;
            for(ptAux = q; ptAux < q + C; ptAux++){
                if(cpfAux == ptAux->cpf){
                    printf("Informe o valor a ser depositado:\n");
                    scanf("%f", &saque_dep);
                    ptAux->conta += saque_dep;
                    flag = 1;
                    
                    printf("Nome do titular: %s\n", ptAux->nome);
                    printf("Saldo atual: %.2f\n", ptAux->conta);
                }
            }if(flag == 0){
                printf("CPF não encontrado!\n");
            }
            
        }
        
        escolha = menu();
            
    }
    
    printf("\nOPERAÇÕES ENCERRADAS!\n");
    
}

int menu(){
    int aux;
    
    printf("\n\n----- MENU -----\n");
    printf("(1) - SAQUE\n");
    printf("(2) - DEPÓSITO\n");
    printf("(3) - ENCERRAR\n");
    
    scanf("%d", &aux);
    
    if(aux == 1){
        return 1;
    }else if(aux == 2){
        return 2;
    }else{
        return 3;
    }
    
}
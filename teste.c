#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct{
    char nome[MAX];
    int dia, mes, ano;
}Contato;

void imprime(Contato **lista, int quant);

int cadastrar(Contato **lista, int quant, int tam);

void alterar_lista(Contato **lista, int quant);

void salvar(Contato **lista, int quant, char nome[]);

int ler_arquivo(Contato **lista, char nome[]);

int main(){
    Contato *lista[MAX];
    char arquivo[] = {"nomes.txt"};
    int quant = 0, opc;
    
    do{
        printf("\n0 - Sair\n1 - Imprimir\n2 - Cadastrar\n3 - Alterar\n4 - Salvar no arquivo\n5 - Ler do arquivo\n");
        scanf("%d", &opc);
        getchar();
        
        if(opc == 1){
            imprime(lista, quant);
        }else if(opc == 2){
            quant += cadastrar(lista, quant, MAX);
        }else if(opc == 3){
            alterar_lista(lista, quant);
        }else if(opc == 4){
            salvar(lista, quant, arquivo);
        }else if(opc == 5){
            quant = ler_arquivo(lista, arquivo);
        }else{
            printf("Opcao invalida!!\n");
        }
        
    }while(opc != 0);
    
    
    return 0;
}

void imprime(Contato **lista, int quant){
    
    printf("\n----- Lista de Contatos -----\n");
    for(int i = 0; i < quant; i++){
        printf("Codigo: %d\n", i+1);
        printf("Nome: %s\n", lista[i]->nome);
        printf("Data de aniversario: %2d/%2d/%4d\n", lista[i]->dia, lista[i]->mes, lista[i]->ano);
        printf("----------------------------------------\n");
    }
}

int cadastrar(Contato **lista, int quant, int tam){ //Melhor deixar void, já que é uma função que apenas atualiza dados
    if(quant < tam){
        Contato *aux = malloc(sizeof(Contato));
        if(aux != NULL){
            
            printf("Digite o nome da pessoa:\n");
            scanf("%[^\n]", aux->nome);
            printf("Digite a data de aniversario: dd/mm/aa\n");
            scanf("%2d/%2d/%2d", &aux->dia, &aux->mes, &aux->ano);
            getchar();
            
            lista[quant] = aux;
            
        }else{
            printf("Erro ao alocar memoria!!\n");
            return 0;
        }
        
        return 1;
    }else{
        printf("\nAgenda ja foi completamente preenchida!!\n");
        return 0;
    }
}

void alterar_lista(Contato **lista, int quant){
    int aux;
    
    imprime(lista, quant);
    
    printf("Digite o codigo do contato que deseja alterar:\n");
    scanf("%d", &aux);
    
    aux--;
    if(aux < quant && aux >=0){
        Contato *novo = malloc(sizeof(Contato));
        if(novo != NULL){
    
            printf("Digite o nome da pessoa:\n");
            scanf("%[^\n]", novo->nome);
            printf("Digite a data de aniversario: dd/mm/aa\n");
            scanf("%2d/%2d/%4d", &novo->dia, &novo->mes, &novo->ano);
            getchar();
            
            lista[aux] = novo;
            
        }else{
            printf("Erro ao alocar memoria!\n");
        }
        
    }else{
        printf("Codigo invalido!!\n");
    }
}

void salvar(Contato **lista, int quant, char nome[]){
    FILE *arq = fopen(nome, "w");
    
    if(arq != NULL){
        fprintf(arq, "Numero de pessoas na agenda: %d\n", quant);
        for(int i = 0; i < quant; i++){
            fprintf(arq, "------------------------------------------------------------------------\n");
            fprintf(arq, "Codigo de registro: %d\n", i+1);
            fprintf(arq, "Nome da pessoa: %s\tData de aniversario: %2d/%2d/%4d\n", lista[i]->nome, lista[i]->dia, lista[i]->mes, lista[i]->ano);
            
            //fprintf(arq, "\n");
        }
        fclose(arq);
        
    }else{
        printf("Nao foi possivel abrir o arquivo!\n");
    }
}

int ler_arquivo(Contato **lista, char nome[]){
    FILE *arq = fopen(nome, "r");
    int quant =  0;
    if(arq != NULL){

        fscanf(arq, "Numero de pessoas na agenda: %d", &quant);
        for(int i =  0; i < quant; i++){
            Contato *aux = malloc(sizeof(Contato));
            fscanf(arq, "\n------------------------------------------------------------------------\n");
            fscanf(arq, "Codigo de registro: %*d\n"); //Isso é feito para ignorar o codigo lido, evitando problemas
            fscanf(arq, "Nome da pessoa: %[^\t]\tData de aniversario: %d/%d/%d\n", aux->nome, &aux->dia, &aux->mes, &aux->ano);
            lista[i] = aux;//Aqui vou atualizar os dados da minha lista
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo!\n");
    }
    return quant;
}

//teste
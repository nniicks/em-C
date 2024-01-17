#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    char nome[MAX], curso[MAX];
    int idade, RGA;
} Pessoa;

void cadastrar_pessoa(Pessoa *lista, int n);

void imprime(Pessoa *lista, int n);

void salvar_no_arquivo(Pessoa *lista, int n);

int main() {
    Pessoa lista[MAX];
    int opc;
    int n = 0;
    
    do {
        printf("0 - Sair\n1 - Cadastrar\n2 - Imprimir\n");
        scanf("%d", &opc);
        getchar();

        if (opc == 1) {
            cadastrar_pessoa(lista, n);
            n++;  
            
        } else if (opc == 2) {
            imprime(lista, n);
        }
    }while (opc != 0);
    
    salvar_no_arquivo(lista, n);
    
    free(lista);  
    return 0;
}

void cadastrar_pessoa(Pessoa *lista, int n) {
    printf("Nome: ");
    scanf(" %49[^\n]", lista[n].nome); 
    
    printf("Curso: ");
    scanf(" %49[^\n]", lista[n].curso);
    
    printf("Idade: ");
    scanf("%d", &lista[n].idade);
    
    printf("RGA: ");
    scanf("%d", &lista[n].RGA);
}

void imprime(Pessoa *lista, int n) {
    int i;
    printf("Total de pessoas cadastradas: %d\n", n);
    
    for(i = 0; i < n ; i++){
        printf("\n---------------------\n");
        printf("Nome: %s\n", (lista+i)->nome);
        printf("Curso: %s\n", (lista+i)->curso);
        printf("Idade: %d\n", (lista+i)->idade);
        printf("RGA: %d\n", (lista+i)->RGA);
        printf("\n---------------------\n");
    }
    printf("\n\n");
    
}

void salvar_no_arquivo(Pessoa *lista, int n){
    FILE *arq = fopen("cadastro.txt", "w");
    /*se esse arquivo nao existir, essa funçao vai criar ele.
    se ele ja existir, o "w" vai apagar tudo oq estiver nesse arquivo e
    recria ele*/
    
    if(arq != NULL){
        for(int i = 0; i < n; i++){
            fprintf(arq, "Nome do academico: %s\n", lista[i].nome);
            fprintf(arq, "Idade: %d anos\n", lista[i].idade);
            fprintf(arq, "Curso: %s\n", lista[i].curso);
            fprintf(arq, "RGA: %d\n", lista[i].RGA);
            fprintf(arq, "\n");
        }
        fclose(arq);
    }else{
        printf("Erro: nao foi possivel abrir o arquivo!!\n");
    }
}
/*fopen possui dois parametros. o primeiro eh o nome do arquivo. 
o segundo vai determinar oq vc vai fazer nesse arquivo; ler? escerver? e etc*/
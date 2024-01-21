//trabalhando com arquivo binario

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

void ler_do_arquivo(Pessoa *lista);

int main() {
    Pessoa lista[MAX];
    int opc;
    int n = 0;
    
    do {
        printf("0 - Sair\n1 - Cadastrar\n2 - Imprimir\n3 - Salvar em arquivo binario\n4 - Ler do arquivo binario\n");
        scanf("%d", &opc);
        getchar();

        if (opc == 1) {
            cadastrar_pessoa(lista, n);
            n++;  
            
        }else if (opc == 2){

            imprime(lista, n);
            
        }else if(opc == 3){
            salvar_no_arquivo(lista, n);
            
        }else if(opc == 4){
            ler_do_arquivo(lista);
        }
    }while(opc != 0);
      
    return 0;
}

void cadastrar_pessoa(Pessoa *lista, int n){
    printf("Nome: ");
    scanf(" %49[^\n]", lista[n].nome); 
    
    printf("Curso: ");
    scanf(" %49[^\n]", lista[n].curso);
    
    printf("Idade: ");
    scanf("%d", &lista[n].idade);
    
    printf("RGA: ");
    scanf("%d", &lista[n].RGA);
}

void imprime(Pessoa *lista, int n){
    //se n for 0, eu vou verificar se tem algo salvo no arquivo
    if(n == 0){
        FILE *aux = fopen("cadastro2.txt", "r");
        fscanf(aux, "Numero de pessoas cadastradas: %d", &n);
    }
    printf("Total de pessoas cadastradas: %d\n", n);
    
    for(int i = 0; i < n ; i++){
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
    FILE *arq = fopen("cadastro2.txt", "wb");
    
    if(arq != NULL){
        fprintf(arq, "Numero de pessoas cadastradas: %d\n", n);
        fwrite(lista, sizeof(Pessoa), n, arq);
        
        fclose(arq);
    }else{
        printf("Erro: nao foi possivel abrir o arquivo!!\n");
    }
}
/*fwrite(oq nos queremos escrever no arquivo. nesse caso é o vetor, 
o tamanho do objeto que eu quero escerver no arquivo, quantidade de 
objetos desse tipo eu quero escrever nesse arquivo, e o ponteiro para
o arquivo)*/

void ler_do_arquivo(Pessoa *lista){
    FILE *arq = fopen("cadastro2.txt", "rb");
    int quant;

    if (arq != NULL) {
        //le a quantidade de pessoas cadastradas do arquivo
        fscanf(arq, "Numero de pessoas cadastradas: %d", &quant);
        //limpa o buffer do arquivo
        while (fgetc(arq) != '\n');
        
        fread(lista, sizeof(Pessoa), quant, arq);
        
        fclose(arq);
    }else {
        printf("Erro ao abrir o arquivo!!\n");
    }
}
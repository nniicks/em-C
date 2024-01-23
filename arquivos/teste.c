#include <stdio.h>
#include <stdlib.h>

/*
        modos de abertura de arquivos:
        w -> escrita
        r -> leitura
        a -> adicionar mais conteudo apartir do final do arquivo
        r+ -> leitura e escrita
        w+ -> leitura de escrita(apaga o conteudo caso caso tenha algo escrito)
        a+ -> leitura e escrita(adiciona ao final do arquivo)
    
    função feof(ponteiro do arquivo) retorna verdadeiro quando o ponteiro
    chegar no final do arquivo
*/

void escrever(char nome_arquivo[]);

void ler(char nome_arquivo[]);

int main(){
    char nome[] = {"texte.txt"};
    
    escrever(nome);
    ler(nome);
    
    return 0;
}

void escrever(char nome_arquivo[]){
    FILE *arq = fopen(nome_arquivo, "w");
    char letra;
    
    if(arq != NULL){
        printf("Digite um texto e pressione ENTER para finalizar!\n");
        scanf("%c", &letra);
        
        while(letra != '\n'){
            fputc(letra, arq);
            scanf("%c", &letra);
        }
        fclose(arq);
    }else{
        printf("Erro ao abrir o arquivo!!\n");
    }    
}

void ler(char nome_arquivo[]){
    FILE *arq = fopen(nome_arquivo, "r");
    char letra;
    
    if(arq != NULL){
        printf("Texto lido do arquivo:\n");
        while(!feof(arq)){
            letra = fgetc(arq);
            printf("%c", letra);
        }
        fclose(arq);
        
    }else{
        printf("Erro ao abrir o arquivo!\n");
    }
}
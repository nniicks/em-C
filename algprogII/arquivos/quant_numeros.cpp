#include <stdio.h>
#include <stdlib.h>


int main(){
    int valor, quant = 0;
    char nome_arq[30];
    FILE *pt_arq;     //ponteiro pro arquivo
    
    printf("Digite o nome do arquivo:\n");
    scanf("%s", nome_arq);

    printf("%s", nome_arq);
    pt_arq = fopen(nome_arq, "r");         //abrindo o arquivo e atribuindo ao ponteiro o endereço

    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        return 0;
    }

    while(feof(pt_arq) == 0){    //essa funcao retorna 1 quando vc chega no final do arquivo
        fscanf(pt_arq, "%d", &valor);       //a cada fscanf esse ponteiro anda uma posicao no arquivo. ou seja, ele da ++ sozinho no ponteiro a cada leitura de valor
        printf("Valor lido do arquivo: %d\n", valor);
        quant++;
    }
    
    printf("Total de valores lidos do arquivo: %d\n", quant);

    fclose(pt_arq);

   
    return 0;
    
}
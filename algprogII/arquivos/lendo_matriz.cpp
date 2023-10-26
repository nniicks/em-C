#include <stdio.h>
#include <stdlib.h>


int main(){
    int **M, l, c;
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

    fscanf(pt_arq, "%d %d", &l, &c);    //lendo as dimensoes da matriz atraves do arquivo

    M = (int **) malloc(l * sizeof(int *));
    if(M == NULL){
        return 0;
    }
    for(int **k = M; k < M + l; k++){
        *k = (int *) malloc(c * sizeof(int ));
        if(*k == NULL){
            return 0;
        }
    }
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(pt_arq, "%d", (*(M+i)+j));         //lendo os valores contidos no arquivo e guardando na matriz M
        }
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", *(*(M+i)+j));
        }
        printf("\n");
    }

    fclose(pt_arq);

    for(int **i = M; i < M + l; i++){
        free(*i);
    }
    free(M);
    return 0;
    
}
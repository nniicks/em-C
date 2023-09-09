/*Escreva uma funcao que receba uma cadeia de caracteres e uma letra e devolva um vetor de inteiros
contendo as posicoes da cadeia nas quais a letra foi encontrada e um inteiro contendo o tamanho
do vetor criado (total de letras iguais encontradas). Voce deve utilizar a notacao de ponteiros para
manipulacao dos vetores.*/

#include <stdio.h>
#define M 30

int busca(char palv[M], char *letra, int *v);

int main(){
    char p[M], l;
    int V[M], quantidade, *q; /*v ja eh um pont pra primeira posicao do vetor*/
    
    printf("Informe uma palavra/frase:\n");
    scanf("%[^\n]", p);
    getchar();
    
    printf("Agora informe uma letra:\n");
    scanf("%c", &l);
    getchar();
    quantidade = busca(p, &l, V);
    
    
    
    printf("A palavra/frase '%s' possui %d letras %c!\n", p, quantidade, l);
    printf("E a letra '%c' foi encontrada nas seguintes posicoes:\n", l);
    for(q = V; q < V + quantidade; q++){
        printf("%d ", *q);
    }
}


int busca(char plv[M], char *letra, int *v){ /*v esta recebendo o endereço da primeira posicao do vetor V da main*/
    int quat = 0;
    char *p;
    
    for(p = plv; *p != '\0'; p++){
        if(*p == *letra){
            *(v + quat) = p - plv;
            quat++;
        }
        
    }
    
    return quat;
    
}

/* p - plv; esta operacao aqui tem haver com aritmetica de ponteiros. nesse caso especifico, esta operacao retorna a distancia
em que o p esta do inicio no meu vetor (plv aponta para o comeco do vetor). e nesse caso como eu estou subtraindo da 
primeira poscicao, o meu resultado vai ser justamente a posicao a onde p esta. e pelo q eu entendi, esta operacao sempre retorna
um numero inteiro*/

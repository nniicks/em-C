/*Crie uma funcao para somar dois vetores. Esta funcao deve receber dois vetores e retornar a soma
em um terceiro vetor. Caso os tamanhos dos dois vetores a serem somados sejam diferentes, entao
a funcao deve retornar zero (0). Caso a funcao seja concluıda com sucesso, ela deve retornar o valor
um (1). Utilize somente aritm´etica de ponteiros para manipula¸c˜ao do vetor. Escreva um programa
para testar a funcao desenvolvida.
*/

#include <stdio.h>
#define T 20

int soma(int *p, int *q, int *r, int *t1, int *t2);
void cria(int *p1, int *q1, int *resultante);

int main(){
    int V1[T], V2[T], R[T];
    
    cria(V1, V2, R);
    
    return 0;
}

void cria(int *p1, int *q1, int *resultante){
    int valor, *p1aux, *q1aux, tamUM, tamDOIS, flag;
    p1aux = p1;
    q1aux = q1;
    
    /*p1 e q1 estao apontando para as primeiras posicoes dos seus respectivos vetores*/
    
    printf("Entre com os valores para o primeiro vetor, e digite 0 para parar:\n");
    scanf("%d", &valor);
    
    while(valor != 0){
        *p1aux = valor;
        *p1aux++;
        
        scanf("%d", &valor);
    }
    
    printf("Agora entre com os valores para o segundo vetor, e digite 0 para parar:\n");
    scanf("%d", &valor);
    
    while(valor != 0){
        *q1aux = valor;
        q1aux++;
        
        scanf("%d", &valor);
    }
    
    tamUM = p1aux - p1;
    tamDOIS = q1aux - q1;
    
    flag = soma(p1, q1, resultante, &tamUM, &tamDOIS);
    
}

int soma(int *p, int *q, int *r, int *t1, int *t2){
    //os ponteiros p e q estao apontando para a primeira posicao de V1 e V2
    int *i;
    
    if(*t1 != *t2){
        printf("Não eh possivel somar esses vetores pois eles possuem tamanhos diferentes!");
        return 0;              // n tem como somar eles, pois sao de tamanhos diferentes
    }else{
        for(i = r; i < r + *t1; i++){
            *i = *p + *q;
            p++;
            q++;
        }
    }
    
    printf("O vetor resultante da soma desses dois vetores eh: ");
    for(i = r; i < r + *t1; i++){
        printf("%d ", *i);
    }
    
    return 1;
    
}

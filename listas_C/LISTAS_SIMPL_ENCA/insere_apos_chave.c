/*funcao que insere um elemento em uma lista logo apos uma determinada chave x.se essa chave nao existir na lista, 
a inserção ocorrerá no final da lista*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

void insere_apos_chave(celula **lista, int numero, int chave);

void imprime(celula *lista);

int main(){
    celula *lista = NULL;
    int valor, chave, tam = 0;
    
    printf("Digite um inteiro e um valor de referencia. Digite 0 0 para sair:\n");
    scanf("%d %d", &valor, &chave);
    
    while(valor != 0 && chave != 0){
        tam++;
        insere_apos_chave(&lista, valor, chave);
        
        printf("Digite um inteiro e um valor de referencia. Digite 0 0 para sair:\n");
        scanf("%d %d", &valor, &chave);
    }
    
    printf("\n------ LISTA: %d -------\n", tam);
    imprime(lista);
    printf("--------- FIM LISTA ----------\n");
    
    return 0;
    
}

void insere_apos_chave(celula **lista, int numero, int chave){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        //lista esta vazia?
        if(*lista == NULL){
            //insercao no inicio
            
            nova->proximo = NULL;
            *lista = nova;   //inicio da lista eh essa nova celula
        }else{
            aux = *lista;     //faz o aux apontar para o inicio da lista
            
            /*aux->proximo ser igual a NULL significa que aux esta na ultima celula da minha lista*/
            while(aux->chave != chave && aux->proximo != NULL){
                aux = aux->proximo;
            }
            
            /*quem eh o proximo da nova celula? eh aux->proximo. se o aux for a ultima celula, 
            o proximo eh NULL, se o aux nao for o ultimo, significa que a chave foi encontrada na lista.*/
            nova->proximo = aux->proximo;
            aux->proximo = nova;
            
            /*aux, que tem o elemento de referencia, tem como proximo a nova celula que foi criada*/
        }
        
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void imprime(celula *lista){
    
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
}
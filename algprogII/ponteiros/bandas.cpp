#include <stdio.h>
#include <string.h>
#define M 20
#define B 10

struct novo_tipo{
    char nomeBanda[M],tipoMus[M];
    int numeInt, posi;
};

/*posicao = q - v;*/

void le_bandas(novo_tipo v[B], novo_tipo *p);

void busca(struct novo_tipo v[B], char gen[M], char Bandas_Gen[B][M], int aux);


int main(){
    
    novo_tipo bandas[B], *q;
    q = bandas;
    char opcao, genero[M], bandas_doGenero[B][M], (*pntc)[M];
    int flag = 0;
    
    do{
        
        le_bandas(bandas, q);
        q+= 1;
        flag+= 1; /* pra saber ate onde meu vetor foi preenchido*/
        
        printf("Deseja inserir informacoes de mais uma banda? s/n:\n");
        scanf("%c", &opcao);
        getchar();
        
    }while(opcao != 'n');
    
    printf("Agora informe o genero muscial: \n");
    scanf("%s", genero);
    getchar();
    
    busca(bandas, genero, bandas_doGenero, flag);
    
    printf("A seguir eh mostrado todas as bandas, que foram informadas, e que sao do genero %s:\n", genero);
    for(pntc = bandas_doGenero; pntc < bandas_doGenero + flag; pntc++){
        printf("%s\n", *pntc);
    }
    
    return 0;
}

void le_bandas(novo_tipo v[B], novo_tipo *p){
    
    printf("Informe o nome da banda: \n");
    scanf("%[^\n]", p->nomeBanda);
    getchar();
    
    printf("Informe o genero musical da banda %s: \n", p->nomeBanda);
    scanf("%[^\n]", p->tipoMus);
    getchar();
    
    printf("Informe a quantidade de integrantes que a banda %s possui:\n", p->nomeBanda);
    scanf("%d", &p->numeInt);
    getchar();
    
    printf("Informe a posicao que essa banda ocupa no seu gosto musical:\n");
    scanf("%d", &p->posi);
    getchar();
    
    
}

void busca(struct novo_tipo v[B], char gen[M], char Bandas_Gen[B][M], int aux){
    char (*q)[M] = Bandas_Gen;  // declara q como um ponteiro para uma string (array de caracteres).
    
    for (struct novo_tipo *p = v; p < v + aux; p++) {
        if (strcmp(p->tipoMus, gen) == 0) {
            strcpy(*q, p->nomeBanda);  // copia o nome da banda em vez do tipo musical.
            q++;  // avança para a próxima posição de memória na matriz Bandas_Gen
        }
    }
}

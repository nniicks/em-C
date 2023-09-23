/*Faca um programa que leia os dados de 10 alunos (Nome, matricula, Media Final), arma- ´
zenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores,
o vetor dos aprovados e o vetor dos reprovados, considerando a media mınima para a
aprovacao como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos ˜
dados do vetor de reprovados*/
#include <stdio.h>
#define T 5
#define M 30


struct novoT{
    char nome[M];
    int matricula;
    float media;
};


int main(){
    novoT lista[T], *p;
    int aprov[T], reprov[T], *p_ap, *p_rp,a = 0, r = 0; 
    p_ap = aprov;
    p_rp = reprov;
    
    for(p = lista; p < lista + T; p++){
        printf("Digite o nome:\n");
        scanf("%[^\n]", p->nome);
        getchar();
        
        printf("Digite a matricula:\n");
        scanf("%d", &p->matricula);
        getchar();
        
        printf("Informe a media:\n");
        scanf("%f", &p->media);
        getchar();
    }
    
    for(p = lista; p < lista + T; p++){
        if(p->media >= 5){
            *p_ap = p->matricula;
            a++;
            p_ap++;
        }else{
            *p_rp = p->matricula;
            p_rp++;
            r++;
        }
    }
    
    if(a != 0){
         printf("CODIGO MATRICULAS ALUNOS APROVADOS!\n");
        
        for(p_ap = aprov; p_ap < aprov + a; p_ap++){
            printf("%d ", *p_ap);
        }
    }else{
        printf("\nNENHUM ALUNO PASSOU!");
    }
    
    if(r != 0){
         printf("\nCODIGO MATRICULAS REPROVADOS!\n");
        
        for(p_rp = reprov; p_rp < reprov + r; p_rp++){
            printf("%d ", *p_rp);
        }
    }else{
        printf("\nNENHUM ALUNO REPROVADO!!");
    }
    
 
    
    return 0;
    
    
}
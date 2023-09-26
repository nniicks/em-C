#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v1, *v2, n, *p, *q, resultado = 0;
    
    printf("Informe a dimensao do vetor: ");
    scanf("%d", &n);
    
    v1 = (int *) malloc(n * sizeof(int));  // essas operacoes vao guardar em v1 o endereço onde começa a bloco de memoria alocado
    v2 = (int *) malloc(n * sizeof(int));
    
    if(v1 != NULL && v2 != NULL){      // se um deles apontar para NULL, siginifca que n foi possivel fazer a alocação
        printf("\nInforme as coordenadas do primeiro vetor:\n");
        for(p = v1; p < v1 + n; p++){
            scanf("%d", p);
        }
        
        printf("Informe as coordenadas do segundo vetor:\n");
        for(p = v2; p < v2 + n; p++){
            scanf("%d", p);
        }
        
        q = v2;
        for(p = v1; p < v1 + n; p++){
            resultado+= *p * *q;
            q++;
        }
        
        printf("O produto escalar entre os vetores eh: %d\n", resultado);
        
        free(v1);  //liberando cada um desses espeços da memoria depois de usalos
        free(v2);
        
    }else{
        printf("Impossivel alocar os vetores na memoria!\n");
    }

    return 0;
}
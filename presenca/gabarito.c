/*Uma prova consta de 20 questoes, cada uma com cinco alternativas
identificadas pelas letras A, B, C, D e E. Dado o cartao gabarito da
prova e o cartao de respostas de n estudantes, com 1 <= n <= 100,
computar o numero de acertos de cada um dos estudantes.
*/

#include <stdio.h>

#define quests 5


int main(){

    int n, acertos = 0;
    char gabarito[quests], cartao_resp[quests];
    

    for(int i = 0; i < quests; i++){
        printf("Informe a letra(MAIUSCULA) correta da questao numero %d: ", i+1);
        scanf("%c", &gabarito[i]);
        fflush(stdin);
    }

    printf("\nDigite agora a quantidade de alunos: ");
    scanf("%d", &n);
    fflush(stdin);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < quests; j++){
            printf("Digite a letra(MAIUSCULA) que o(a) %d aluno(a) marcou para a questao numero %d: ", i+1, j+1);
            scanf("%c", &cartao_resp[j]);
            fflush(stdin);
        }
        acertos = 0;
       for(int i = 0; i < quests; i++){
        if(cartao_resp[i] == gabarito[i]){
            acertos++;
            }
        }
        printf("\nO(A) %d aluno(a) acertou %d questao(oes)\n", i+1, acertos);
    }

    return 0;
}
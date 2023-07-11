#include <stdio.h>

/*dividendo = (divisor * quociente) + resto*/

int main(){
    int  horas, minutos, segundos, aux;

    printf("Informe o tempo cronometrado em segundos: ");
    scanf("%d", &segundos);
    aux = segundos;

    horas = segundos / 3600;

    segundos = segundos - (3600*horas);

    minutos = segundos / 60;

    segundos = segundos - (60*minutos);

    printf("Dentro de %d segundos, existem:\n", aux);
    printf("Horas: %d\n", horas);
    printf("Minutos: %d\n", minutos);
    printf("Segundos: %d\n", segundos);


}
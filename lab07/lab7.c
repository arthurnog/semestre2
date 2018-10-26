/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include "func.h"*/

typedef struct car{
  float axl, cont, vel;
  /*fazer isso usando uma lista ligada ou um vetor mesmo?*/
}
/*axl = aceleracao, cont = controle, vel = velocidade*/

/*criar 3 filas de prioridade referente a cada uma das propriedades*/
int main(){
  int IT, MC, C, P, i, j;
  /*IT = numero de iteracoes, MC = numero maximo de carros*/
  scanf("%d %d", &IT, &MC);
  for(i=0; i<IT; i++){
    /*C = numero de carros adicionados,
      P = numero de carros escolhidos na iteracao*/
    scanf("%d %d", &C, &P);
    for(j=0; j<C; j++){
      /*scanf("%f %f %f", &a, &c, &v)
        inserir(a,c,v)*/
      /*nesse for os dados dos carros serao guardados*/
    }
    for(j=0; j<P; j++){
      /*nesse for os carros sao escolhidos e retirados do vetor*/
    }
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int eMax = 30;

int main(){
  FILE* arq_in = fopen("read.txt", "r");
  char string[1000];

  while(fscanf(arq_in, "% [^\n]s", string) !=EOF)) {

  }
  fclose(arq_in);

  return 0;
}

/*
  pseudo codigo das funcoes
 criar 4 listas de tamanho indefinido
 a cada linha lida o primeiro termor vai pra lista CPF, o segundo pra lista NOME
 o terceiro pra lista EMAIL e o ultimo pra lista IDADE.
 ao ordenar a lista IDADE a troca de posicao sera feita com as outras listas (talvez
 isso consuma muita memória, pensar num jeito melhor).
 printar(CPF[i], NOME[i], EMAIL[i], IDADE[i])
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct /*struct com os dados a serem analisados pelo programa*/
{
  long int CPF;
  char NOME[41];
  char EMAIL[31];
  int IDADE;
} Pessoa;

int main(){
  FILE* arq_in = fopen("read.txt", "r");
  char string[1000];
  //Descobrir o numero de linhas que o texto tem
  //usar esse numero pra definir o tamanho da lista de pessoas usando malloc
  //ordenar essa lista usando a idade e o cpf
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

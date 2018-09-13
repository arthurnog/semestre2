#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*tipos são definidos dentro ou fora da main?*/
typedef struct /*struct com os dados a serem analisados pelo programa*/
{
  long int CPF;
  char NOME[70];
  char EMAIL[71];
  int IDADE;
} pessoa;

void troca(pessoa *a, pessoa *b){
  pessoa aux = *a;
  *a = *b;
  *b = aux;
}

void ordena(pessoa per[], int n){
  int a, b;
  for (a=0;a<n-1;a++){
    for (b=0;b<n-a-1;b++){
      if (per[b].IDADE > per[b+1].IDADE)
        troca(&per[b],&per[b+1]);
      if (per[b].IDADE == per[b+1].IDADE) {
        if (per[b].CPF > per[b+1].CPF)
          troca(&per[b],&per[b+1]);
      }
    }
  }
}

int main(){
  FILE *arq_in = fopen("read.txt", "r");
  char string[1000];
  int i=0;
  int n = 1;
  //usar realloc
  //ordenar essa lista usando a idade e o cpf
  //cpf, nome, email, idade\n
  pessoa *per = NULL;
  per = (pessoa*)realloc(per, n*sizeof(pessoa));

  while(fscanf(arq_in, "%ld, %s %s %d", &per[i].CPF, per[i].NOME, per[i].EMAIL, &per[i].IDADE) != EOF) {
    //enquanto o charactere EOF não aparecer eu vou pegar as informações da linha e aloca na struct


    printf("%ld, %s %s %d\n", per[i].CPF, per[i].NOME, per[i].EMAIL, per[i].IDADE);

    "%d"  4423256,
    "%s"  ctabtsd,v \n\0

    i++; /*i = numero de pessoas*/
    if (i >= n){
      n = n*2;
      per = (pessoa*)realloc(per, n*sizeof(pessoa));
    }
  }

  ordena(per,i);

  //escrever a saida ordenada em outro arquivo (?)
  FILE *arq_out = fopen("write.txt", "w");
  int j;
  for (j=0; j<i; j++)
    fprintf (arq_out, "%ld, %s %s %d\n", per[j].CPF, per[j].NOME, per[j].EMAIL, per[j].IDADE);

  fclose(arq_out);
  fclose(arq_in);
  free(per);
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

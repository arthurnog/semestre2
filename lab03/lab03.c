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
  int i=0;
  int n = 1;
  /*usar realloc*/
  /*ordenar essa lista usando a idade e o cpf*/
  /*cpf, nome, email, idade\n*/
  pessoa *per = NULL;
  per = (pessoa*)realloc(per, n*sizeof(pessoa));

  while(scanf("%ld,%[A-Z A-Z],%[A-z@gmail.com],%d", &per[i].CPF, per[i].NOME, per[i].EMAIL, &per[i].IDADE)) {
    i++; /*i = numero de pessoas*/
    if (i >= n){
      n = n*2;
      per = (pessoa*)realloc(per, n*sizeof(pessoa));
    }
  }

  ordena(per,i);

  /*escrever a saida ordenada*/
  int j;
  for (j=0; j<i; j++)
    printf ("%ld,%s,%s,%d\n", per[j].CPF, per[j].NOME, per[j].EMAIL, per[j].IDADE);

  free(per);
  return 0;
}

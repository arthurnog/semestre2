#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/*tipos são definidos dentro ou fora da main?*/
typedef struct /*struct com os dados a serem analisados pelo programa*/
{
  long int CPF;
  char NOME[70];
  char EMAIL[71];
  int IDADE;
} pessoa;

/*FUNCAO QUE TROCA DUAS PESSOAS DE LUGAR*/
void troca(pessoa *a, pessoa *b){
  pessoa aux = *a;
  *a = *b;
  *b = aux;
}

/*FUNCAO QUE ORDENA PELA IDADE, E QUANDO A IDADE FOR IGUAL ELA ORDENA PELO CPF*/
/*
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
*/

void merge(pessoa v[], pessoa aux[], int inicio1, int inicio2, int fim2) {
  int i = inicio1, j = inicio2, fim1 = inicio2 - 1, k = 0;
  while ((i <= fim1) && (j <= fim2)) {
    if (v[i].IDADE < v[j].IDADE)
      aux[k++] = v[i++];
    else if ((v[i].IDADE == v[j].IDADE) && (v[i].CPF < v[j].CPF))
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
  }
  while (i <= fim1)
    aux[k++] = v[i++];
  while (j <= fim2)
    aux[k++] = v[j++];
  for (i = 0; i < k; i++)
    v[i + inicio1] = aux[i];
}

void ordena(pessoa v[], pessoa aux[], int inicio, int fim) {
  int meio = (inicio + fim) / 2;
  if (inicio < fim) {
    ordena(v, aux, inicio, meio);
    ordena(v, aux, meio + 1, fim);
    merge(v, aux, inicio, meio + 1, fim);
  }
}


int main(){
  int i = 0;
  int n = 1;

  pessoa *per = NULL;
  per = (pessoa*)realloc(per, n*sizeof(pessoa));

  while(scanf("%ld,%[^,],%[^,],%d", &per[i].CPF, per[i].NOME, per[i].EMAIL, &per[i].IDADE) != EOF) {
    i++; /*i = numero de pessoas*/
    if (i >= n){
      n = n*2;
      per = (pessoa*)realloc(per, n*sizeof(pessoa));
    }
  }
  pessoa *aux = NULL;
  aux = (pessoa*)realloc(aux, i*sizeof(pessoa));
  ordena(per,aux,0,i-1);
  /*ordena(per,i);*/

  /*escrever a saida ordenada*/
  int j;
  for (j=0; j<i; j++)
    printf ("%011ld, %s, %s, %d \n", per[j].CPF, per[j].NOME, per[j].EMAIL, per[j].IDADE);

  free(per);
  free(aux);
  return 0;
}

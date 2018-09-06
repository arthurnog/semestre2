#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*tipos são definidos dentro ou fora da main?*/
typedef struct /*struct com os dados a serem analisados pelo programa*/
{
  long int CPF;
  char NOME[41];
  char EMAIL[31];
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
  //usar realloc
  //ordenar essa lista usando a idade e o cpf
  //cpf, nome, email, idade\n
  pessoa *per;
  per = (pessoa*)realloc(per, 10*sizeof(pessoa));

  while(fscanf(arq_in, "%[^\n]s", string) !=EOF) {
    //enquanto o charactere EOF não aparecer eu vou pegar as informações da linha e aloca na struct
    fscanf(arq_in, "%li, %s, %s, %d\n", per[i].CPF, per[i].NOME, per[i].EMAIL, per[i].IDADE);
    i++; /*i = numero de pessoas*/
  }

  ordena(per,i);
  //escrever a saida ordenada em outro arquivo (?)
  FILE *arq_out = fopen("write.txt", "w");
  int j;
  for (j=0; j<i; j++)
    fprintf (arq_out, "%li, %s, %s, %d\n", per[j].CPF, per[j].NOME, per[j].EMAIL, per[j].IDADE);

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

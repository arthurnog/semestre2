/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha{
  int lugar;
  char registro[53];
  struct pilha *prox;
} pilha;

struct fila{
  int lugar;
  char registro[53];
  struct fila *prox;
  struct fila *ant;
} fila;

pilha *criar_pilha(char nome[]){
  pilha *novo = (pilha*) malloc(sizeof(pilha));
  novo->registro = nome;
  novo->prox = NULL;
  return novo;
}

fila *criar_fila(char nome[]){
  fila *novo = (fila*) malloc(sizeof(fila));
  novo->registro = nome;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

/*o maximo de pessoas na fila e no auditorio e 30*/
/*o maximo da pilha e 5*/

fila *inserir_fila(fila *row, fila *novo){
  /*a fila tera duas cabecas e sera circular CUIDADO COM O ENDERECO DO COMECO DA FILA*/
  /*O lugar DAS DUAS CABECAS SERA 0*/
  if (row->prox->prox != NULL){
    no *p = row->prox;
    while (p->prox->prox == NULL)
      p = p->prox;
    if(p->lugar < 30){
      novo->lugar = p->lugar + 1;
      novo->prox = p->prox;
      p->prox->ant = novo;
      p->prox = novo;
    }
    return fila;
  }
  else{
    novo->lugar = 1;
    return novo;
  }
}

no *inserir_pilha(no *pilha, no *novo){
  /*se o resto da divisao por 5 for 0 entao a pilha esta cheia*/
  if (pilha->lugar % 5 != 0)
    novo->prox = pilha;
  return novo;
}

void remover_fila(no *fila, no *pilha){
  no *p = fila;
  fila = fila->prox;
  pilha = inserir_pilha(pilha, p);
}


int main(){


  return 0;
}

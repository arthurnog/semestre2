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

fila *inserir_fila(fila *row, char nome[]){
  /*a fila tera uma cabeca e sera circular CUIDADO COM O ENDERECO DO COMECO DA FILA*/
  /*O lugar DAS DUAS CABECAS SERA 0*/
  if (fila->ant->lugar < 30){
    fila *novo = criar_fila(nome);
    novo->ant = row->ant;
    novo->prox = row;
    row->ant = novo;
    novo->lugar = novo->ant->lugar++;
  }
  return row
}

pilha *inserir_pilha(pilha *stack, char nome, int pos){
  /*se o resto da divisao por 5 for 0 entao a pilha esta cheia*/
  /*as pilhas sera-o listas ligadas simples*/
  if (stack->lugar % 5 != 0){
    pilha *novo = criar_pilha(nome);
    novo->prox = stack;
    novo->lugar = pos;
    return novo;
  } else {
    return stack;
  }
}

/*ao remover da fila ela sera' inserida em uma pilha*/
pilha *remover_fila(fila *row, pilha *stack){
  /*na-o esquecer que a fila tem cabeça agora*/
  stack = inserir_pilha(stack, row->prox->nome, row->prox->lugar);
  fila *trash = row->prox;
  row->prox = trash->prox;
  trash->prox->ant = row;
  free(trash);
  return stack;
}

/*FAZER AS PILHAS COM CABECA-????*/
pilha *remover_pilha(pilha *stack){
  /*se a pilha for com cabeca
  if (stack->prox != NULL){
    pilha *trash = stack->prox;
    stack->prox = trash->prox;
    free(trash);
    return stack;
  }*/
  /*se nao*/
  if (stack != NULL){
    pilha *trash = stack;
    stack = stack->prox;
    free(trash);
    return stack;
  }
}

fila *libera_fila(fila *row){
  fila *trash;
  while(row != NULL){
    trash = row;
    row = trash->prox;
    free(trash);
  }
  return row;
}

pilha *libera_pilha(pilha *stack){
  pilha *trash;
  while(stack != NULL){
    trash = stack;
    stack = trash->prox;
    free(trash);
  }
  return stack;
}

int main(){
  char cmd[2] = "J";
  int num;
  while(cmd != "D"){
    /*a fila é criada com uma cabeca, o lugar da cabeca e 0 e o registro e [Q]*/
    fila *Row = criar_fila("[Q]");
    Row->lugar = 0;
    /*as pilhas serao listas ligadas simples*/
    pilha *s1. *s2, *s3, *s4, *s5, *s6;
    /*---------------------------------*/
    scanf("%c", &cmd);
    if(cmd == "Q"){
      /*aqui serao feitas modificacoues na fila*/
      scanf("%c", &cmd);
      if(cmd == "I"){
        scanf("%d", &num);
        int i;
        for(i = 0; i<num; i++){
          char nome[53];
          scanf("%s\n", &nome);
          Row = inserir_fila(Row, nome);
        }
      }
      else if(cmd == "R"){
        scanf("%d", &num);
        int i;
        for(i = 0; i<num; i++){
          char nome[53];
          scanf("%s\n", &nome);
          if(Row->prox->lugar <= 5)
            s1 = remover_fila(Row, s1);
          else if(Row->prox->lugar <= 10)
            s2 = remover_fila(Row, s2);
          else if(Row->prox->lugar <= 15)
            s3 = remover_fila(Row, s3);
          else if(Row->prox->lugar <= 20)
            s4 = remover_fila(Row, s4);
          else if(Row->prox->lugar <= 25)
            s5 = remover_fila(Row, s5);
          else if(Row->prox->lugar <= 30)
            s6 = remover_fila(Row, s6);
        }
      }
    }
    if(cmd == "S"){
      scanf("%c", &cmd);
      scanf("%d", &num);
      int i;
      for(i = 0; i < num; i++){
        if (s6 != NULL)
          s6 = remover_pilha(s6);
        else if(s5 !=NULL)
          s5 = remover_pilha(s5);
        else if(s4 !=NULL)
          s4 = remover_pilha(s4);
        else if(s3 !=NULL)
          s3 = remover_pilha(s3);
        else if(s2 !=NULL)
          s2 = remover_pilha(s2);
        else if(s1 !=NULL)
          s1 = remover_pilha(s1);
      }
    }
  }
}
  return 0;
}

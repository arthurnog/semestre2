/*
Arthur Lucas da Silva Nogueira
213293
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
  char nome[21];
  struct pessoa *prox;
  struct pessoa *ant;
}pessoa;

/*funcao CRIAR NO*/
pessoa *criar_no(char name[]){
  pessoa *no = (pessoa*)malloc(sizeof(pessoa));
  no->nome = name;
  no->prox = no;
  no->ant = no;
  return no;
}

/*funcao IMPRIMIR*/
void imprimir(pessoa *lista, int sentido){
  /*sentido normal*/
  if (sentido == 1){
    pessoa *p = lista->prox;
    printf("%s ", &lista->nome);
    while (p != lista){
      printf("%s ", &p->nome);
      p = p->prox;
    }
  }
  /*sentido inverso*/
  else{
    pessoa *p = lista->ant;
    printf("%s ", &lista->nome);
    while (p != lista){
      printf("%s ", &p->nome);
      p = p->ant;
    }
  }
}


/*funcao INSERE*/
/*se o elemento ja existe ele so vira a cabeca*/
pessoa *inserir(pessoa *lista, char nome[], int pos, int sentido){
  pessoa *novo = criar_no(nome);
  int i;
  pessoa *p = lista;
  /*sentido normal*/
  if (sentido == 1){
    for(i = 0; i < pos-1; i++){
      p = p->prox;
    }
    p->ant->prox = novo;
    novo->ant = p->ant;
    novo->prox = p;
    p->ant = novo;
  }
  /*sentido inverso*/
  else{
    for(i = 0; i < pos-1; i++){
      p = p->ant;
    }
    p->prox->ant = novo;
    novo->prox = p->prox;
    novo->ant = p;
    p->prox = novo;
  }
  return novo;
}

/*funcao REMOVE*/
pessoa *remover(pessoa *lista, int pos, int sentido){
  int i;
  /*sentido normal*/
  if (sentido == 1){
    for(i = 0; i < pos-1; i++){
      lista = lista->prox;
    }
    pessoa *trash = lista;
    lista->prox->ant = lista->ant;
    lista->ant->prox = lista->prox;
    lista = lista->prox;
    free(trash);
  }
  else {
    for(i = 0; i < pos-1; i++){
      lista = lista->ant;
    }
    pessoa *trash = lista;
    lista->ant->prox = lista->prox;
    lista->prox->ant = lista->ant;
    lista = lista->ant;
    free(trash);
  }
  return lista;
}

/*funcao LE*/
void le(pessoa *lista, int pos, int sentido){
  int i;
  if (sentido == 1){
    for(i = 0; i < pos-1; i++){
      lista = lista->prox;
    }
  }
  else {
    for(i = 0; i < pos-1; i++){
      lista = lista->ant;
    }
  }
  imprimir(lista, sentido);
}

/*funcao TROCA*/
void troca(pessoa *lista, char nome1[], char nome2[]){
  pessoa *aux1 = lista;
  pessoa *aux2 = lista;
  while(aux1->nome != nome1){
    aux1 = aux1->prox;
  }
  while(aux2->nome != nome2){
    aux2 = aux2->prox;
  }
  aux1->nome = nome2;
  aux2->nome = nome1;
}

/*funcao MUDAR SENTIDO na verdade sera apenas uma variavel que sera igual a 0
  ou 1, caso seja igual a 1 as funcoes giram no sentido normal,
  se for igual a 0 ela ira no sentido oposto*/
int mudar_sentido(int sentido){
  if (sentido == 1)
    sentido = 0;
  else
    sentido = 1;
  return sentido;
}

int main(){
  int sentido = 1;


  return 0;
}

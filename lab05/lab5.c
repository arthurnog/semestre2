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
void imprimir(pessoa *lista){
  pessoa *p = lista->prox;
  printf("%s ", &lista->nome);
  while (p != lista){
    printf("%s ", &p->nome);
    p = p->prox;
  }
}
/*funcao INSERE*/
/*se o elemento ja existe ele so vira a cabeca*/
pessoa *inserir(pessoa *lista, char nome[], int pos){
  pessoa *novo = criar_no(nome);
  int i;
  pessoa *p = lista;
  for(i = 0; i < pos-1; i++){
    p = p->prox;
  }
  p->ant->prox = novo;
  novo->ant = p->ant;
  novo->prox = p;
  p->ant = novo;
  return novo;
}

/*funcao REMOVE*/
pessoa *remover(pessoa *lista, int pos){
  int i;
  for(i = 0; i < pos-1; i++){
    lista = lista->prox;
  }
  pessoa *trash = lista;
  lista->prox->ant = lista->ant;
  lista->ant->prox = lista->prox;
  lista = lista->prox;
  free(trash);
  return lista;
}

/*funcao LE*/
void le(pessoa *lista, int pos){
  int i;
  for(i = 0; i < pos-1; i++){
    lista = lista->prox;
  }
  imprimir(lista);
}

/*funcao TROCA*/

/*funcao MUDAR SENTIDO na verdade sera apenas uma variavel que sera igual a 0
  ou 1, caso seja igual a 1 as funcoes giram no sentido normal,
  se for igual a 0 ela ira no sentido oposto*/





int main(){


  return 0;
}

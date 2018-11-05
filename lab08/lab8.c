/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  int info;
  struct no *esq, *dir;
} no;

int main(){
  int N = 9; char ordm[4] = "123"; int a;
  while(N != 0 && ordm != "0"){
    scanf("%d %s\n", &N, ordm);
    int i;
    for(i = 0; i<N; i++){
      scanf("%d", &a);
      /*arvore = inserir a na arvore*/
    }
    /*diametro(arvore);*/
    /*imprimir(arvore, ordm);*/
  }
  return 0;
}

no *busca(no *r, int v){
  while(r != NULL && r->info != v){
    if(r->info > v)
      r = r->esq;
    else
      r = r->dir;
  }
  return r;
}

no *inserir(no *r, int v){
  if(r == NULL){
    r = (no*)malloc(sizeof(no));
    r->info = v;
    r->esq = NULL;
    r->dir = NULL;
  }
  else{
    if(r->info >v)
      r->esq = inserir(r->esq, v);
    else
      r->dir = inserir(r->dir, v);
  }
  return r;
}

/*
Pré-ordem: Você deve visitar primeiro a raiz, depois a sub-árvore esquerda e por último a sub-árvore direita.
Em-ordem: Você deve visitar primeiro a sub-árvore esquerda, depois a raiz e por último a sub-árvore direita.
Pós-ordem: Você deve visitar primeiro a sub-árvore esquerda, depois a sub-árvore direita e por último a raiz.
*/

/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  int info;
  struct no *esq, *dir;
} no;

no *busca(no *r, int v);
no *inserir(no *r, int v);
no *liberar(no *r);
int altura(no *r);
void diametro(no *r);
void imprimir(no *r, char cmd[]);

int main(){
  int N = 9; char ordm[4] = "123"; int a;
  while(N != 0 && ordm != "0"){
    scanf("%d %s\n", &N, ordm);
    int i; no *tree = NULL;
    for(i = 0; i<N; i++){
      scanf("%d", &a);
      tree = inserir(tree, a);
    }
    diametro(tree);
    imprimir(tree, ordm);
    tree = liberar(tree);
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

no *liberar(no *r){
  if(r != NULL){
    r->esq = liberar(r->esq);
    r->dir = liberar(r->dir);
    free(r);
  }
  return NULL;
}

int altura(no *r){
  int h_esq, h_dir;
  if(r == NULL)
    return 0;
  else{
    h_esq = 1+altura(r->esq);
    h_dir = 1+altura(r->dir);
    if(h_esq > h_dir)
      return h_esq;
    else
      return h_dir;
  }
}

void diametro(no *r){
  int D = 1+altura(r->esq)+altura(r->dir);
  printf("Diametro da arvore binaria: %d", D)
}

void imprimir(no *r, char cmd[]){
  if(r != NULL){
    if(cmd == "pre"){
      printf("%d", r->info);
      imprimir(r->esq, cmd);
      imprimir(r->dir, cmd);
    }
    else if(cmd == "in"){
      imprimir(r->esq, cmd);
      printf("%d", r->info);
      imprimir(r->dir, cmd);
    }
    else if(cmd == "pos"){
      imprimir(r->esq, cmd);
      imprimir(r->dir, cmd);
      printf("%d", r->info);
    }
  }
}

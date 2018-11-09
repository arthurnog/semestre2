/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  char palavra[9];
  int altura;
  struct no *esq, *dir;
} no;
/*LER AVL COM MUITA ATENCAO!!!*/
int main(){
  char word[9];
  /*como as palavras reservadas sao todas em letras minusculas e nenhuma delas
  tem mais de 8 letras e valido fazer isso*/
  while(scanf("%[a-z]", word) != EOF){
    /*if word esta na lista de palavras reservadas*/
      /*inserir word na arvore AVL*/
  }
  /*impressao zig zag*/
  return 0;
}

no *criar_no(char word[]) {
  no *novo = (no*)malloc(sizeof(no));
  if(novo == NULL)
    return NULL;
  no->palavra = word;
  no->altura = 1;
  no->esq = NULL;
  no->dir = NULL;
  return novo;
}

int altura(no *raiz){
  if(raiz == NULL)
    return 0;
  return raiz->altura;
}

int fator_balanceamento(no *r){
  if(r == NULL)
    return 0;
  return altura(r->dir) - altura(r->esq);
}

int max(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}

no *rot_esq(no *a){
  no *b = a->dir;
  no *c = b->esq;

  b->esq = a;
  a->dir = c;

  a->altura = max(altura(a->esq), altura(a->dir)) +1;
  b->altura = max(altura(b->esq), altura(b->dir)) +1;

  return b;
}

no *rot_dir(no *b){
  no *a = b->esq;
  no *c = a->dir;

  a->dir = b;
  b->esq = c;

  b->altura = max(altura(b->esq), altura(b->dir))+1;
  a->altura = max(altura(a->esq), altura(a->dir))+1;

  return a;
}

no *inserir(no *r, char word[]){
  int balanceamento;
  if(r == NULL)
    return criar_no(word);
  /*com o strcmp eu verifico qual a ordem das palavras em ordem alfabetica*/
  if(strcmp(word, r->palavra)<0)
    r->esq = inserir(r->esq, word);
  else if(strcmp(word, r->palavra)>0)
    r->dir = inserir(r->dir, word);
  else
    return r;

  r->altura = 1+ max(altura(r->esq), altura(r->dir));

  balanceamento = fator_balanceamento(r);

  if(balanceamento >1 && strcmp(word, r->esq->palavra)<0)
    return rot_dir(r);

  if(balanceamento < -1 && strcmp(word, r->dir->palavra)>0)
    return rot_esq(r);

  if(balanceamento >1 && strcmp(word, r->esq->palavra)>0){
    r->esq = rot_esq(r->esq);
    return rot_dir(r);
  }

  if(balanceamento < -1 && strcmp(word, r->dir->palavra)<0){
    r->dir = rot_dir(r->dir);
    return rot_esq(r);
  }

  return r;
}

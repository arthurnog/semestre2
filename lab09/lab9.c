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

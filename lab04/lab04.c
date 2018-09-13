#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conj1 {
  int elem1;
  struct conj1 *prox;
}conj1;

typedef struct conj2 {
  int elem2;
  struct conj2 *prox;
}conj2;

/*insere elementos na lista
void insere(int x, conj *p){
  conj *nova;
  nova = malloc (sizeof (celula));
  nova->elem = x;
  nova->prox = p->prox;
  p->prox = nova;
}
*/

/*remove elementos da lista
void remove (conj *p) {
  conj *trash;
  trash = p->prox;
  p->prox = trash->prox;
  free(trash);
}
*/

//https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html

int main(){



  return 0;
}

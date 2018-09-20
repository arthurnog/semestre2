#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conj {
  int elem;
  struct conj *prox;
}conj;

/*imprime a lista, depois da execucao de toda funca a funcao imprime e chamada*/
void imprime(conj *lista) {
  conj *p;
  p = lista;
  if (p == NULL)
    return;
  else{
    printf("%d", p->elem);
    imprime(p->prox);
  }
}


/*insere elemento na lista (cmnd == i)*/
void inserir(conj *lista, int num) {
  conj *atual = lista;
  if (atual == NULL){
    novo = malloc (sizeof (celular));
    novo->elem = num;
    atual = novo;
    imprime(lista);
    return;
  }
  else if (num < atual->prox->elem){
    conj *novo;
    novo = malloc (sizeof (celular));
    novo->elem = num;
    novo->prox = atual->prox;
    atual->prox = novo;
    imprime(lista);
    return;
  }
  else if (num == atual->elem)
    imprime(lista);
    return;
  else
    inserir(atual->prox,num);
}


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

int main(){



  return 0;
}

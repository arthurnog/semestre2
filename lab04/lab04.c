#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conj {
  int elem;
  struct conj *prox;
}conj;

/*imprime a lista, depois da execucao de toda funca a funcao imprime e chamada*/
/*nao esquecer os {} no começo e no final do print*/
void imprime(conj *lista) {
  if (lista->prox == NULL)
    printf("%d", lista->elem);
  else{
    printf("%d,", lista->elem);
    imprime(lista->prox);
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
  else if (num == atual->elem)
    imprime(lista);
    return;
  else if (num < atual->elem){
    conj *novo;
    novo = malloc (sizeof (celular));
    novo->elem = num;
    conj *aux;
    aux = lista;
    novo->prox = aux;
    lista = novo;
    imprime(lista);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct con {
  int elem;
  struct con *prox;
}con;

/*imprime a lista, depois da execucao de toda funca a funcao imprime e chamada*/
/*OS DOIS CONJUNTOS SAO IMPRESSOS*/
/*nao esquecer os {} no começo e no final do print*/
void imprime(con *lista) {
  if (lista->prox == NULL)
    printf("%d", lista->elem);
  else{
    printf("%d,", lista->elem);
    imprime(lista->prox);
  }
}


/*insere elemento na lista (cmd == i)*/
void inserir(con *lista, int num) {
  con *atual = lista;
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
    con *novo;
    novo = malloc (sizeof (celular));
    novo->elem = num;
    con *aux;
    aux = lista;
    novo->prox = aux;
    lista = novo;
    imprime(lista);
  }
  else if (num < atual->prox->elem){
    con *novo;
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

/*pertence (cmd == p)*/
void pertence(con *lista, int num){
  if (lista == NULL)
    printf("NAO\n");
    return;
  else if (lista->elem == num)
    printf("SIM\n");
    return;
  else
    pertence(lista->prox, num);
}

/*remove elementos dos conuntos (cmd == r)*/
void remover(con *lista, int num){
  if (lista->elem == num){
    con *trash;
    trash = lista->prox;
    lista->prox = trash->prox;
    free(trash);
    return;
  }
  else if (lista == NULL)
    return;
  else
    remover(lista->prox, num);
}

/*uniao dos conjuntos fica no conjunto 1 (cmd == u)*/
con *uniao(con *con1, con *con2){
  
}


/*insere elementos na lista
void insere(int x, con *p){
  con *nova;
  nova = malloc (sizeof (celula));
  nova->elem = x;
  nova->prox = p->prox;
  p->prox = nova;
}
*/

/*remove elementos da lista
void remove (con *p) {
  con *trash;
  trash = p->prox;
  p->prox = trash->prox;
  free(trash);
}
*/

int main(){



  return 0;
}

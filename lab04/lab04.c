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
    return;
  }
  else if (num == atual->elem)
    return;
  else if (num < atual->elem){
    con *novo;
    novo = malloc (sizeof (celular));
    novo->elem = num;
    con *aux;
    aux = lista;
    novo->prox = aux;
    lista = novo;
    return;
  }
  else if (num < atual->prox->elem){
    con *novo;
    novo = malloc (sizeof (celular));
    novo->elem = num;
    novo->prox = atual->prox;
    atual->prox = novo;
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
void uniao(con *lista1, con *lista2){
  /*uniao acaba quando a lista2 acaba*/
  if (lista2 == NULL)
    return;
  else{
    inserir(lista1, lista2->elem);
    uniao(lista1, lista2->prox);
  }
}

/*funcao de busca*/
int busca(con *lista, num){
    if (lista == NULL)
      return 1;
    else if (lista->elem == num)
      return 0;
    else
      pertence(lista->prox, num);
}

/*interseccao dos conjuntos fica no conjunto 1 (cmd == x)*/
void intersec(con *lista1, con *lista2){
  if (lista1 == NULL)
    return;
  else{
    /*se o elemento do conjunto 1 nao esta no conjunto 2 ele e removido*/
    if (busca(lista2, lista1->elem)){
      remover(lista1, lista1->elem);
    }
    itersec(lista1->prox, lista2);
  }
}

/*a subtracao e basicamente o inverso da interseccao. se um elemento ESTA no
  ele sera removido (cmd == b)*/
void subt(con *lista1, con *lista2){
  if (lista1 == NULL)
    return;
  else{
    if (! busca(lista2, lista1->elem)){
      remover(lista1, lista1->elem);
    }
    subt(lista1->prox,lista2);
  }
}

int main(){



  return 0;
}

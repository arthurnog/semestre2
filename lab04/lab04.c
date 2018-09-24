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
  if (lista == NULL){
    return;
  }
  else if (lista->prox == NULL)
    printf("%d", lista->elem);
  else{
    printf("%d,", lista->elem);
    imprime(lista->prox);
  }
}

/*funcao "criar no"*/
con *criar_no(int num) {
  con *no = (con*) malloc(sizeof(con));
  no->elem = num;
  no->prox = NULL;
  return no;
}


/*insere elemento na lista (cmd == i)*/
con *inserir(con *lista, int num) {
  con *atual = lista;
  if (atual == NULL){
    con *novo = criar_no(num);
    atual = novo;
    return atual;
  }
  else if (num == atual->elem)
    return atual;
  else if (num < atual->elem){
    con *novo = criar_no(num);
    novo->prox = atual;
    return novo;
  }
  else if (num < atual->prox->elem && num > atual->elem){
    con *novo = criar_no(num);
    novo->prox = atual->prox;
    atual->prox = novo;
    return atual;
  }
  else
    return inserir(atual->prox,num);
}

/*pertence (cmd == p)*/
void pertence(con *lista, int num){
  if (lista == NULL){
    printf("NAO\n");
    return;
  }
  else if (lista->elem == num){
    printf("SIM\n");
    return;
  }
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
    lista1 = inserir(lista1, lista2->elem);
    uniao(lista1, lista2->prox);
  }
}

/*funcao de busca*/
int busca(con *lista, int num){
    if (lista == NULL)
      return 1;
    else if (lista->elem == num)
      return 0;
    else
      return busca(lista->prox, num);
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
    intersec(lista1->prox, lista2);
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
  /*enquanto o s não for digitado o programa continuara recebendo comandos*/
  char cmd;
  int elem, c; /*elem = elemento, c = conjunto*/
  con *conj1 = NULL;
  con *conj2 = NULL;
  while (cmd != 's') {
    scanf("%c", &cmd);
    if (cmd == 'i'){
      scanf(" %d %d \n", &elem, &c);
      if (c == 1)
        conj1 = inserir(conj1, elem);
      else if (c == 2)
        conj2 = inserir(conj2, elem);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
    else if(cmd == 'p'){
      scanf(" %d %d \n", &elem, &c);
      if (c == 1)
        pertence(conj1, elem);
      else if (c == 2)
        pertence(conj2, elem);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
    else if(cmd == 'r'){
      scanf(" %d %d \n", &elem, &c);
      if (c == 1)
        remover(conj1, elem);
      else if (c == 2)
        remover(conj2, elem);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
    else if(cmd == 'u'){
      uniao(conj1, conj2);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
    else if(cmd == 'x'){
      intersec(conj1, conj2);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
    else if(cmd == 'b'){
      subt(conj1, conj2);
      printf("{"); imprime(conj1); printf("}\n");
      printf("{"); imprime(conj2); printf("}\n");
    }
  }
  printf("{"); imprime(conj1); printf("}\n");
  printf("{"); imprime(conj2); printf("}\n");

  free(conj1);
  free(conj2);

  return 0;
}

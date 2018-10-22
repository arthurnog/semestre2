/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  int lugar;
  char registro[53];
  struct no *prox;
}no;

no *criar_no(char nome[]){
  no *novo = (no*) malloc(sizeof(no));
  strcpy(novo->registro, nome);
  novo->prox = NULL;
  return novo;
}


/*o maximo de pessoas na fila e no auditorio e 30*/
/*o maximo da pilha e 5*/

no *inserir_fila(no *fim, char nome[]){
  /*a fila sera' uma lista ligada com cabeca com dois ponteiros,
    um apontando pra cabeca e outro apontando para o fim da fila*/
  /*O lugar DA CABECA SERA 0*/
  if(fim->lugar < 30){
    no *novo = criar_no(nome);
    novo->lugar = fim->lugar+1;
    fim->prox = novo;
    novo->prox = NULL;
    fim = novo;
  }
  return fim;
}

/*essa funcao verifica se a pilha esta cheia*/
int verificar_pilha(no *pilha){
  int count = 0;
  while(pilha!=NULL){
    count = count+1;
    pilha = pilha->prox;
  }
  if (count < 5)
    return 0;
  else
    return 1;
}

no *inserir_pilha(no *stack, char nome[], int pos){
  /*as pilhas sera-o listas ligadas simples*/
  if (!verificar_pilha(stack)){
    if (stack == NULL){
      no *novo = criar_no(nome);
      novo->lugar = pos;
      return novo;
    }
    else{
      no *novo = criar_no(nome);
      novo->prox = stack;
      novo->lugar = pos;
      return novo;
    }
  } else {
    return stack;
  }
}

/*ao remover da fila ela sera' inserida em uma pilha*/
no *remover_fila(no *row, no *stack){
  /*na-o esquecer que a fila tem cabeça*/
  stack = inserir_pilha(stack, row->prox->registro, row->prox->lugar);
  no *trash = row->prox;
  row->prox = trash->prox;
  free(trash);
  return stack;
}

/*as pilhas sao listas ligadas simples*/
no *remover_pilha(no *stack){
  if (stack != NULL){
    no *trash = stack;
    stack = stack->prox;
    free(trash);
  }
  return stack;
}

no *libera_fila(no *row){
  no *trash;
  while(row != NULL){
    trash = row;
    row = trash->prox;
    free(trash);
  }
  return row;
}

no *libera_pilha(no *stack){
  no *trash;
  while(stack != NULL){
    trash = stack;
    stack = trash->prox;
    free(trash);
  }
  return stack;
}

/*essas func,oes ira-o imprimir a fila e as pilhas quando o cmd for igual a P*/
void imprime_fila(no *row){
  no *aux = row->prox;
  printf("%s", row->registro);
  while(aux != NULL){
    printf("%d,", aux->lugar);
    aux = aux->prox;
  }
}

void imprime_pilha(no *stack){
  if (stack != NULL){
    imprime_pilha(stack->prox);
    printf("%d,", stack->lugar);
  }
}
/*---------------------------------------------------------------------------*/

/*essa funcao imprime os dados de todas as pessoas no auditorio e na fila*/
void dados_fila(no *row){
  no *aux = row->prox;
  while(aux!=NULL){
    printf("%d,%s\n", aux->lugar, aux->registro);
    aux = aux->prox;
  }
}
/*---------------------------------------------------------------------------*/

int main(){
  char cmd[2] = "J";
  int num;
  /*a fila é criada com uma cabeca, o lugar da cabeca e 0 e o registro e [Q]*/
  no *row = criar_no("[Q]");
  no *end = row;
  row->lugar = 0;
  /*uma fila auxiliar e criada para a impressao dos dados no fim do programa*/
  no *dados = criar_no("dados");
  no *fimd = dados;
  dados->lugar = 0;
  /*as pilhas serao listas ligadas simples*/
  no *s1 = NULL, *s2 = NULL, *s3 = NULL, *s4 = NULL, *s5 = NULL, *s6 = NULL;
  /*---------------------------------*/
  while(cmd[0] != 'D'){
    scanf("%c", &cmd[0]);
    if(cmd[0] == 'Q'){
      /*aqui serao feitas modificacoues na fila*/
      scanf("%c", &cmd[0]);
      if(cmd[0] == 'I'){
        scanf("%d", &num);
        int i;
        for(i = 0; i<num; i++){
          char nome[53];
          scanf("%[^\n]s", nome);
          end = inserir_fila(end, nome);
          fimd = inserir_fila(fimd, nome);
        }
        /*no *t;
        printf("\n");
        for(t = row->prox; t != NULL; t = t->prox){
          printf("%i",t->lugar);
        }
        printf("\n");*/
      }
      else if(cmd[0] == 'R'){
        scanf("%d", &num);
        int i;
        for(i = 0; i<num; i++){
          if(row->prox->lugar <= 5)
            s1 = remover_fila(row, s1);
          else if(row->prox->lugar <= 10)
            s2 = remover_fila(row, s2);
          else if(row->prox->lugar <= 15)
            s3 = remover_fila(row, s3);
          else if(row->prox->lugar <= 20)
            s4 = remover_fila(row, s4);
          else if(row->prox->lugar <= 25)
            s5 = remover_fila(row, s5);
          else if(row->prox->lugar <= 30)
            s6 = remover_fila(row, s6);
        }
      }
    }
    if(cmd[0] == 'S'){
      scanf("%c", &cmd[0]);
      scanf("%d", &num);
      int i;
      for(i = 0; i < num; i++){
        if (s6 != NULL)
          s6 = remover_pilha(s6);
        else if(s5 !=NULL)
          s5 = remover_pilha(s5);
        else if(s4 !=NULL)
          s4 = remover_pilha(s4);
        else if(s3 !=NULL)
          s3 = remover_pilha(s3);
        else if(s2 !=NULL)
          s2 = remover_pilha(s2);
        else if(s1 !=NULL)
          s1 = remover_pilha(s1);
      }
    }
    if(cmd[0] == 'P'){
      imprime_fila(row); printf("\n");
      printf("[S1]"); imprime_pilha(s1); printf("\n");
      printf("[S2]"); imprime_pilha(s2); printf("\n");
      printf("[S3]"); imprime_pilha(s3); printf("\n");
      printf("[S4]"); imprime_pilha(s4); printf("\n");
      printf("[S5]"); imprime_pilha(s5); printf("\n");
      printf("[S6]"); imprime_pilha(s6); printf("\n");
    }
  }
  if(cmd[0] == 'D'){
    dados_fila(dados);
  }
  libera_fila(row);
  libera_fila(dados);
  libera_pilha(s1);
  libera_pilha(s2);
  libera_pilha(s3);
  libera_pilha(s4);
  libera_pilha(s5);
  libera_pilha(s6);
  return 0;
}

/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  char palavra[9];
  int altura;
  struct no *esq, *dir;
} no;

no *criar_no(char word[]);
int altura(no *raiz);
int fator_balanceamento(no *r);
int max(int a, int b);
no *rot_esq(no *a);
no *rot_dir(no *b);
no *inserir(no *r, char word[]);
no *rot_zag(no *x);
no *rot_zig(no *x);
no *minimo(no *r);
no *remover(no *r, char word[]);
no *adicionar_fila(char word[], int high, no *fim);
void imprime_fila(no *fila);
no *liberar_fila(no *fila);
void imprimir_arvore(no *raiz, no *fila, no *fim, int direcao);


int main(){
  char word[9];
  no *palavras_reservadas = NULL;
  no *arvore = NULL;
  no *fila = (no*)malloc(sizeof(no));
  fila->esq = NULL;
  fila->dir = NULL;
  fila->palavra = "head";
  no *fim = fila;
  /*primeiro eu crio uma arvore de busca com todas as palavras reservadas*/
  palavras_reservadas = inserir(palavras_reservadas, "auto");
  palavras_reservadas = inserir(palavras_reservadas, "double");
  palavras_reservadas = inserir(palavras_reservadas, "int");
  palavras_reservadas = inserir(palavras_reservadas, "struct");
  palavras_reservadas = inserir(palavras_reservadas, "break");
  palavras_reservadas = inserir(palavras_reservadas, "else");
  palavras_reservadas = inserir(palavras_reservadas, "long");
  palavras_reservadas = inserir(palavras_reservadas, "switch");
  palavras_reservadas = inserir(palavras_reservadas, "case");
  palavras_reservadas = inserir(palavras_reservadas, "enum");
  palavras_reservadas = inserir(palavras_reservadas, "register");
  palavras_reservadas = inserir(palavras_reservadas, "typedef");
  palavras_reservadas = inserir(palavras_reservadas, "char");
  palavras_reservadas = inserir(palavras_reservadas, "extern");
  palavras_reservadas = inserir(palavras_reservadas, "return");
  palavras_reservadas = inserir(palavras_reservadas, "union");
  palavras_reservadas = inserir(palavras_reservadas, "continue");
  palavras_reservadas = inserir(palavras_reservadas, "for");
  palavras_reservadas = inserir(palavras_reservadas, "signed");
  palavras_reservadas = inserir(palavras_reservadas, "void");
  palavras_reservadas = inserir(palavras_reservadas, "do");
  palavras_reservadas = inserir(palavras_reservadas, "if");
  palavras_reservadas = inserir(palavras_reservadas, "static");
  palavras_reservadas = inserir(palavras_reservadas, "while");
  palavras_reservadas = inserir(palavras_reservadas, "default");
  palavras_reservadas = inserir(palavras_reservadas, "goto");
  palavras_reservadas = inserir(palavras_reservadas, "sizeof");
  palavras_reservadas = inserir(palavras_reservadas, "volatile");
  palavras_reservadas = inserir(palavras_reservadas, "const");
  palavras_reservadas = inserir(palavras_reservadas, "float");
  palavras_reservadas = inserir(palavras_reservadas, "short");
  palavras_reservadas = inserir(palavras_reservadas, "unsigned");
  /*como as palavras reservadas sao todas em letras minusculas e nenhuma delas
  tem mais de 8 letras e valido fazer isso*/
  while(scanf("%[a-z]", word) != EOF){
    if (!busca(palavras_reservadas, word))
      inserir(arvore, word);
  }
  imprimir_arvore(arvore, fila, fim, 0);
  fila  = liberar_fila(fila);
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

int busca(no *r, word[]){
  if(r == NULL)
    return 0;
  else{
    if(word == r->palavra)
      return 1;
    else{
      if(strcmp(word, r->palavra)<0)
        return busca(r->esq, word);
      else
        return busca(r->dir, word);
    }
  }
}

no *inserir(no *r, char word[]){
  int balanceamento;
  if(r == NULL)
    return criar_no(word);

  if(busca(r, word))
    return r;
  else{
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
  }
}

/*zig = rotacão direita, zag = rotaçao esquerda*/
no *rot_zag(no *x){
  no *y = x->dir;
  y->dir = x->esq;
  x->esq = x;
  return y;
}

no *rot_zig(no *x){
  no *y = x->esq;
  x->esq = y->dir;
  y->dir = x;
  return y;
}

no *minimo(no *r){
  if(strcmp(r->dir->palavra, r->esq->palavra)<0)
    return r->dir;
  else
    return r->esq;
}

no *remover(no *r, char word[]){
  no *temp;
  int balanceamento;
  if(r==NULL)
    return r;
  if(strcmp(word, r->palavra)<0)
    r->esq = remover(r->esq, word);
  else if(strcmp(word,r->palavra)>0)
    r->dir = remover(r->dir, word);
  else{
    if((r->esq == NULL) || (r->dir == NULL)){
      temp = r->esq ? r->esq : r->dir;
      if(temp == NULL){
        temp = r;
        r = NULL;
      }
      else
        *r = *temp;
      free(temp);
    }
    else{
      temp = minimo(r->dir);
      strcpy(r->palavra, temp->palavra);
      r->dir = remover(r->dir, temp->palavra);
    }
  }
  if(r == NULL)
    return r;
  r->altura = 1 + max(altura(r->esq), altura(r->dir));
  balanceamento = fator_balanceamento(r);

  if(balanceamento > 1 && fator_balanceamento(r->esq) >= 0)
    return rot_dir(r);

  if(balanceamento > 1 && fator_balanceamento(r->esq) < 0){
    r->esq = rot_esq(r->esq);
    return rot_dir(r);
  }

  if(balanceamento < -1 && fator_balanceamento(r->dir) <=0)
    return rot_esq(r);

  if(balanceamento < -1 && fator_balanceamento(r->dir) > 0){
    r->dir = rot_dir(r->dir);
    return rot_esq(r);
  }

  return r;
}

/*imprimir a arvore em zig-zag do jeito que deve ser feito se tornou um desafio,
entao eu tive a ideia de adicionar todos os elementos a serem impressos em uma
e entao eu imprimi-los na ordem e da maneira correta*/
no *adicionar_fila(char word[], int high, no *fim){
  /*o fim da fila sempre aponta para nulo e o ponteiro que aponta para o proximo
  é o dir e o esq aponta sempre pra nulo*/
  /*pra isso funcionar a fila devera ter uma cabeca*/
  no *a = (no*)malloc(sizeof(no));
  a->palavra = word;
  a->altura = high;
  a->dir = NULL;
  a->esq = NULL;
  fim->dir = a;
  fim = a;
  return fim;
}

void imprime_fila(no *fila){
  /*a impressao e feita de forma que os nos com a mesma altura fiquem na mesma linha*/
  no *aux = fila->dir;
  printf("[ ");
  while(aux != NULL){
    printf("%s ", aux->palavra);
    if(aux->dir->altura != aux->altura)
      printf("]\n[ ");
    aux = aux->dir;
  }
  printf("]");
}

no *liberar_fila(no *fila){
  /*depois da impressao a memoria alocada para a fila e liberada*/
  no *a
  while(fila!=NULL){
    a = fila;
    fila = fila->dir;
    free(a);
  }
  return fila;
}

void imprimir_arvore(no *raiz, no *fila, no *fim, int direcao){
  /*nessa funcao cada no da arvore sera adicionada em uma fila e entao removida
  da arvore e depois que a arvore estive completamente vazia a fila sera impressa
  de forma que os nos que estao na mesma altura seja impressos juntos*/
  /*a variavel direcao indica se ela vai rotacionar zig(0) ou zag(1)*/
  /*quando a funcao for chamada na main a direcao sera 0*/
  while(raiz != NULL){
    if(direcao == 0){
      adicionar_fila(raiz->palavra, raiz->altura, fim);
      raiz = rot_zig(raiz);
      raiz->dir = remover(raiz->dir, raiz->dir->palavra);
      direcao = 1;
    }
    else{
      adicionar_fila(raiz->palavra, raiz->altura, fim);
      raiz = rot_zag(raiz);
      raiz->esq = remover(raiz->esq, raiz->esq->palavra);
      direcao = 0;
    }
  }
  imprime_fila(fila);
}

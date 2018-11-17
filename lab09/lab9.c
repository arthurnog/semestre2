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
int busca(no *r, char word[]);


int main(){
  char word[9];
  no *palavras_reservadas = NULL;
  no *arvore = NULL;
  no *fila = (no*)malloc(sizeof(no));
  fila->esq = NULL;
  fila->dir = NULL;
  strcpy(fila->palavra,"head");
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
  while(scanf("%s", word) != EOF){
    char *w = word;
    printf("\n%20s", w);

    while(*w != '\0'){

      while(*w != '\0'){
        if((*w >= 'a' && *w <= 'z') || (*w >= 'A' && *w <= 'Z'))
          break;

        w++;
      }


      char *p = w;
      char b = 'f';
      while(*p != '\0'){
        if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
          p++;
        else{
          *p = '\0';
          b = 'v';
        }
      }

      if(b == 'v')
        p++;

      printf("-->{ %s }\n", w);
      printf("start { %p }\n", palavras_reservadas);
      if (*w != '\0' && busca(palavras_reservadas, w) == 0){
        printf("-->[ %s ]", w);
        // arvore = inserir(arvore, w);
      }
      printf("  end { %p }\n", palavras_reservadas);

      w = p;
    }
  }

  // imprimir_arvore(arvore, fila, fim, 0);
  // fila  = liberar_fila(fila);

  return 0;
}

no *criar_no(char word[]) {
  no *novo = (no*) malloc(sizeof(no));

  if(!novo)
    return NULL;

  strcpy(novo->palavra, word);
  novo->altura = 1;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;
}

int altura(no *raiz){
  if(!raiz)
    return 0;

  return raiz->altura;
}

int fator_balanceamento(no *r){
  if(!r)
    return 0;

  return altura(r->dir) - altura(r->esq);
}

int max(int a, int b){
  if(a > b)
    return a;

  return b;
}

no *rot_esq(no *a){
  no *b = a->dir;
  no *c = b->esq;

  b->esq = a;
  a->dir = c;

  a->altura = max( altura(a->esq), altura(a->dir) ) +1;
  b->altura = max( altura(b->esq), altura(b->dir) ) +1;

  return b;
}

no *rot_dir(no *b){
  no *a = b->esq;
  no *c = a->dir;

  a->dir = b;
  b->esq = c;

  b->altura = max( altura(b->esq), altura(b->dir) ) + 1;
  a->altura = max( altura(a->esq), altura(a->dir) ) + 1;

  return a;
}

int busca(no *r, char word[]){
  printf("\n-------------\n");
  printf("R: %p\n", r);
  if(!r)
    return 0;

  printf("WORD %s\n", word);
  printf("PALA %s\n", r->palavra);
  if(strcmp(word, r->palavra) == 0)
    return 1;

  if(strcmp(word, r->palavra) < 0)
    return busca(r->esq, word);

  return busca(r->dir, word);
}

no* inserir(no* r, char word[]){
  //normal inseririon
  if(!r)
    return criar_no(word);

  if(strcmp(word, r->palavra) < 0)
    r->esq = inserir(r->esq, word);
  else
    r->dir = inserir(r->dir, word);

  /* ### Balanceia a arvore ### */

  r->altura = max( altura(r->esq), altura(r->dir) ) + 1;

  int balanceamento = fator_balanceamento(r);

  // balanceamento -> -1, 0, 1

  if(balanceamento > 1){
    int b = fator_balanceamento(r->dir);

    if(b == -1)
      r->dir = rot_dir(r->dir);

    r = rot_esq(r);
  }

  if(balanceamento < -1){
    int b = fator_balanceamento(r->esq);

    if(b == 1)
      r->esq = rot_esq(r->esq);

    r = rot_dir(r);
  }

  return r;
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

  return r->esq;
}

no *remover(no *r, char word[]){
  no *temp;
  int balanceamento;

  if(!r)
    return NULL;

  if(strcmp(word, r->palavra)<0)
    r->esq = remover(r->esq, word);
  else if(strcmp(word,r->palavra)>0)
    r->dir = remover(r->dir, word);
  else{
    if(r->esq == NULL || r->dir == NULL){
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

  if(!r)
    return NULL;

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
  strcpy(a->palavra, word);
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
  no *a;

  while(fila){
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
  while(raiz)
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

  imprime_fila(fila);
}

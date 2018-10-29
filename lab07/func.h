/*Arthur Lucas da Silva Nogueira 213293*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pai(i) ((i-1)/2)

typedef struct car{
  float axl, cont, vel;
  /*fazer isso usando uma lista ligada ou um vetor mesmo?*/
}

typedef struct heap{
  car **v;
  int n, tamanho;
} heap;

void troca(car **a, car **b){
  car **c;
  c = a;
  a = b;
  b = c;
}

void subir_axl(heap *fp, int k){
  if (k>0 && fp->v[pai(k)]->axl <fp->v[k]->axl){
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_axl(fp, pai(k));
  }
}

void subir_cont(heap *fp, int k){
  if (k>0 && fp->v[pai(k)]->cont <fp->v[k]->cont){
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_cont(fp, pai(k));
  }
}

void subir_vel(heap *fp, int k){
  if (k>0 && fp->v[pai(k)]->vel <fp->v[k]->vel){
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_vel(fp, pai(k));
  }
}

void inserir(heap *fp, car *p, int flag){
  fp->v[fp->n] = p;
  fp->n++;
  if(flag == 0)
    subir_axl(fp, fp->n-1);
  else if(flag == 1)
    subir_cont(fp, fp->n-1);
  else if(flag == 2)
    subir_vel(fp, fp->n-1);
}

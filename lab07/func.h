/*Arthur Lucas da Silva Nogueira 213293*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pai(i) ((i-1)/2)
#define F_ESQ(i) (2*i +1)
#define F_DIR(i) (2*i +2)

typedef struct car{
  float axl, cont, vel;
  int p0, p1, p2;
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
    int aux;
    aux = fp->v[k]->p0;
    fp->v[k]->p0 = fp->v[pai(k)]->p0;
    fp->v[pai(k)]->p0 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_axl(fp, pai(k));
  }
}

void subir_cont(heap *fp, int k){
  if (k>0 && fp->v[pai(k)]->cont <fp->v[k]->cont){
    int aux;
    aux = fp->v[k]->p1;
    fp->v[k]->p1 = fp->v[pai(k)]->p1;
    fp->v[pai(k)]->p1 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_cont(fp, pai(k));
  }
}

void subir_vel(heap *fp, int k){
  if (k>0 && fp->v[pai(k)]->vel <fp->v[k]->vel){
    int aux;
    aux = fp->v[k]->p2;
    fp->v[k]->p2 = fp->v[pai(k)]->p2;
    fp->v[pai(k)]->p2 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir_vel(fp, pai(k));
  }
}

void inserir(heap *fp0, heap *fp1, heap *fp2, car *p){
  fp0->v[fp0->n] = p;
  fp0->n++;
  p->p0 = fp0->n;
  fp1->v[fp1->n] = p;
  fp1->n++;
  p->p1 = fp1->n;
  fp2->v[fp2->n] = p;
  fp2->n++;
  p->p2 = fp2->n;
  subir_axl(fp0, fp0->n-1);
  subir_cont(fp1, fp1->n-1);
  subir_vel(fp2, fp2->n-1);
}

/*
void descer(heap *fp, int k, int flag){
  int maior_filho;
  if(F_ESQ(k) < fp->n){
    maior_filho = F_ESQ(k);
    if(flag == 0){
      if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->axl < fp->v[F_DIR(k)]->axl)
        maior_filho = F_DIR(k);
      if(fp->v[k]->axl < fp->v[maior_filho]->axl){
        troca(&fp->v[k], &fp->v[maior_filho]);
        descer(fp, maior_filho, flag);
      }
    }
    else if(flag == 1){
      if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->cont < fp->v[F_DIR(k)]->cont)
        maior_filho = F_DIR(k);
      if(fp->v[k]->cont < fp->v[maior_filho]->cont){
        troca(&fp->v[k], &fp->v[maior_filho]);
        descer(fp, maior_filho, flag);
      }
    }
    else if(flag == 2){
      if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->vel < fp->v[F_DIR(k)]->vel)
        maior_filho = F_DIR(k);
      if(fp->v[k]->vel < fp->v[maior_filho]->vel){
        troca(&fp->v[k], &fp->v[maior_filho]);
        descer(fp, maior_filho, flag);
      }
    }
  }
}
*/

descer_axl(heap *fp, int k, int flag){
  int maior_filho;
    if(F_ESQ(k) < fp->n){
      maior_filho = F_ESQ(k);
      if(flag == 0){
        if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->axl < fp->v[F_DIR(k)]->axl)
          maior_filho = F_DIR(k);
        if(fp->v[k]->axl < fp->v[maior_filho]->axl){
          int aux;
          aux = fp->v[k]->p0;
          fp->v[k]->p0 = fp->v[maior_filho]->p0;
          fp->v[maior_filho]->p0 = aux;
          troca(&fp->v[k], &fp->v[maior_filho]);
          descer(fp, maior_filho, flag);
      }
    }
  }
}

descer_cont(heap *fp, int k, int flag){
  int maior_filho;
    if(F_ESQ(k) < fp->n){
      maior_filho = F_ESQ(k);
      if(flag == 1){
        if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->cont < fp->v[F_DIR(k)]->cont)
          maior_filho = F_DIR(k);
        if(fp->v[k]->cont < fp->v[maior_filho]->cont){
          int aux;
          aux = fp->v[k]->p1;
          fp->v[k]->p1 = fp->v[maior_filho]->p1;
          fp->v[maior_filho]->p1 = aux;
          troca(&fp->v[k], &fp->v[maior_filho]);
          descer(fp, maior_filho, flag);
      }
    }
  }
}

descer_vel(heap *fp, int k, int flag){
  int maior_filho;
    if(F_ESQ(k) < fp->n){
      maior_filho = F_ESQ(k);
      if(flag == 2){
        if (F_DIR(k) < fp->n && fp->v[F_ESQ(k)]->vel < fp->v[F_DIR(k)]->vel)
          maior_filho = F_DIR(k);
        if(fp->v[k]->vel < fp->v[maior_filho]->vel){
          int aux;
          aux = fp->v[k]->p2;
          fp->v[k]->p2 = fp->v[maior_filho]->p2;
          fp->v[maior_filho]->p2 = aux;
          troca(&fp->v[k], &fp->v[maior_filho]);
          descer(fp, maior_filho, flag);
      }
    }
  }
}

void extrair(heap *fp, int flag){
  car *item = fp->v[0];
  printf("%f %f %f\n", fp->v[0]->axl, fp->v[0]->cont, fp->v[0]->vel);
  troca(&fp->v[0], &fp->v[fp->n-1]);
  fp->n--;
  /*descer(fp, 0, flag);*/
  if(flag == 0)
    descer_axl(fp, fp->n-1, flag);
  else if(flag == 1)
    descer_cont(fp, fp->n-1, flag);
  else if(flag == 2)
    descer_vel(fp, fp->n-1, flag);
  free(fp->v[n]);
}

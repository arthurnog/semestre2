/*
o que sabemos?
o lab funciona com listas de prioridade, o problema é que eu devo fazer 3 listas
e não posso fazer uma busca, quando eu quiser acessar um elemento eu
tenho que ir direto nele.
Uma ideia é deixar armazenado na struct a posicao em cada uma das listas.
o vetor vai ser compostos de ponteiros que apontam para um carro, ponteiros de
diferentes listas, em posicoes diferentes apontarão para um mesmo carro.
*/

/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pai(i) ((i-1)/2)
#define F_ESQ(i) (2*i +1)
#define F_DIR(i) (2*i +2)

typedef struct car{
  float axl, cont, vel;
  int p0, p1, p2;/*posicoes dentros das 3 listas*/
}

typedef struct heap{
  car **v;/*o vetor do heap é formado por ponteiros apontando para os mesmo carros*/
  int n, tamanho;/*n = posicao final atual (comeca no 0), tamanho = tamanho máximo*/
} heap;

/*
ok, agora supondo que eu tenha 3 heaps com um espaco definido, fp0 fp1 fp2
ao inserir e ao remover eu devo fazer isso das 3 listas, na insercao
eu devo guardar as posicoes nos vetores dentor da struct
EU TO COM MUITO SONO!!!!
*/

void troca(car **a, car **b){
  car **c;
  c = a;
  a = b;
  b = c;
}

void subir0(heap *fp, int k){
  if(k>0 && fp->v[pai(k)]->axl < fp->v[k]->axl){
    int aux;
    aux = fp->v[k]->p0;
    fp->v[k]->p0 = fp->v[pai(k)]->p0;
    fp->v[pai(k)]->p0 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir0(fp, pai(k));
  }
}

void subir1(heap *fp, int k){
  if(k>0 && fp->v[pai(k)]->axl < fp->v[k]->axl){
    int aux;
    aux = fp->v[k]->p1;
    fp->v[k]->p1 = fp->v[pai(k)]->p1;
    fp->v[pai(k)]->p1 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir1(fp, pai(k));
  }
}

void subir2(heap *fp, int k){
  if(k>0 && fp->v[pai(k)]->axl < fp->v[k]->axl){
    int aux;
    aux = fp->v[k]->p2;
    fp->v[k]->p2 = fp->v[pai(k)]->p2;
    fp->v[pai(k)]->p2 = aux;
    troca(&fp->v[k], &fp->v[pai(k)]);
    subir2(fp, pai(k));
  }
}

void inserir(heap *fp0, *fp1, *fp2, car *c){
  fp0->v[fp0->n] = c;
  fp0->n++;
  c->p0 = fp0->n;
  subir0(fp0, fp0->n-1);
  /*---------------------*/
  fp1->v[fp1->n] = c;
  fp1->n++;
  c->p1 = fp1->n;
  subir1(fp1, fp1->n-1);
  /*--------------------*/
  fp2->v[fp2->n] = c;
  fp2->n++;
  c->p2 = fp2->n;
  subir2(fp2, fp2->n-1);
}

/*
o problema agora e a hora de extrair
quando eu fizer a extracao eu vou ter que tirar das 3 listas
tendo como referencia as posicoes salvas dentro da struct
*/

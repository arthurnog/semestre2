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
eu devo guardar as posicoes nos vetores dentro da struct
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

void extrair0(heap *fp0, *fp1, *fp2, int a0, ok){
  /*a variavel ok indica se os dados ja' foram impressos ou nao.
  se sim ok = 1 se nao ok = 0*/
  /*as variaveis a seguir guardam as posicoes do carro que ira ser retirado
  nos outros dois heaps*/
  int a1 = fp0->v[a0]->p1;
  int a2 = fp0->v[a0]->p2;
  if(ok == 0){/*se ok==0 entao o carro ainda nao foi impresso*/
    printf("%f %f %f\n", fp0->v[a0]->axl, fp0->v[a0]->cont, fp0->v[a0]->vel);
    ok = 1;
    /*como o carro ainda não foi impresso ele
    tambem nao foi retirado das outras duas filas*/
    extrair1(fp0, fp1, fp2, a1, ok);
    extrair2(fp0, fp1, fp2, a2, ok);
  }
  int aux;
  aux = fp0->v[a0]->p0;
  fp0->v[a0]->p0 = fp0->v[fp0->n-1]->p0;
  fp0->v[fp0->n-1]->p0 = aux;
  troca(&fp0->v[a0], &fp0->v[fp0->n-1]);
  fp0->n--;
  descer0(fp0, a0);
  free(fp0->v[n]);
}

void extrair1(heap *fp0, *fp1, *fp2, int a1, ok){
  int a0 = fp1->v[a1]->p0;
  int a2 = fp1->v[a1]->p2;
  if (ok == 0){
    printf("%f %f %f\n", fp1->v[a1]->axl, fp1->v[a1]->cont, fp1->v[a1]->vel);
    ok = 1;
    extrair0(fp0, fp1, fp2, a0, ok);
    extrair2(fp0, fp1, fp2, a2, ok);
  }
  int aux;
  aux = fp1->v[a1]->p1;
  fp1->v[a1]->p1 = fp1->v[fp1->n-1]->p1;
  fp1->v[fp1->n-1]->p1 = aux;
  troca(&fp1->v[a1], &fp1->v[fp1->n-1]);
  fp1->n--;
  descer1(fp1, a1);
  free(fp1->v[n]);
}

void extrair2(heap *fp0, *fp1, *fp2, int a2, ok){
  int a0 = fp2->v[a2]->p0;
  int a1 = fp2->v[a2]->p1;
  if (ok == 0){
    printf("%f %f %f\n", fp2->v[a2]->axl, fp2->v[a2]->cont, fp2->v[a2]->vel);
    ok = 1;
    extrair0(fp0, fp1, fp2, a0, ok);
    extrair1(fp0, fp1, fp2, a1, ok);
  }
  int aux;
  aux = fp2->v[a2]->p2;
  fp2->v[a2]->p2 = fp2->v[fp2->n-1]->p2;
  fp2->v[fp2->n-1]->p2 = aux;
  troca(&fp2->v[a2], &fp2->v[fp2->n-1]);
  fp2->n--;
  descer2(fp2, a2);
  free(fp->v[n]);
}

void descer0(heap *fp, int k){
  int maior_filho;
  if(F_ESQ(k)<fp->n){
    maior_filho = F_ESQ(k);
    if(F_DIR(k)<fp->n && fp->v[F_ESQ(k)]->axl < fp->v[F_DIR(k)]->axl)
      maior_filho = F_DIR(k);
    if(fp->v[k]->axl<fp->v[maior_filho]->axl){
      int aux;
      aux = fp->v[k]->p0;
      fp->v[k]->p0 = fp->v[maior_filho]->p0;
      fp->v[maior_filho]->p0 = aux;
      troca(&fp->v[k], &fp->v[maior_filho]);
      descer0(fp, maior_filho);
    }
  }
}

void descer1(heap *fp, int k){
  int maior_filho;
  if(F_ESQ(k)<fp->n){
    maior_filho = F_ESQ(k);
    if(F_DIR(k)<fp->n && fp->v[F_ESQ(k)]->cont < fp->v[F_DIR(k)]->cont)
      maior_filho = F_DIR(k);
    if(fp->v[k]->cont<fp->v[maior_filho]->cont){
      int aux;
      aux = fp->v[k]->p1;
      fp->v[k]->p1 = fp->v[maior_filho]->p1;
      fp->v[maior_filho]->p1 = aux;
      troca(&fp->v[k], &fp->v[maior_filho]);
      descer1(fp, maior_filho);
    }
  }
}

void descer2(heap *fp, int k){
  int maior_filho;
  if(F_ESQ(k)<fp->n){
    maior_filho = F_ESQ(k);
    if(F_DIR(k)<fp->n && fp->v[F_ESQ(k)]->vel < fp->v[F_DIR(k)]->vel)
      maior_filho = F_DIR(k);
    if(fp->v[k]->vel<fp->v[maior_filho]->vel){
      int aux;
      aux = fp->v[k]->p2;
      fp->v[k]->p2 = fp->v[maior_filho]->p2;
      fp->v[maior_filho]->p2 = aux;
      troca(&fp->v[k], &fp->v[maior_filho]);
      descer2(fp, maior_filho);
    }
  }
}

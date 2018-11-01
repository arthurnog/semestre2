/*Arthur Lucas da Silva Nogueira 213293*/

/*
o que sabemos?
o lab funciona com listas de prioridade, o problema é que eu devo fazer 3 listas
e não posso fazer uma busca, quando eu quiser acessar um elemento eu
tenho que ir direto nele.
Uma ideia é deixar armazenado na struct a posicao em cada uma das listas.
o vetor vai ser compostos de ponteiros que apontam para um carro, ponteiros de
diferentes listas, em posicoes diferentes apontarão para um mesmo carro.
*/

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

void troca(car **a, car **b);

void subir0(heap *fp, int k);

void subir1(heap *fp, int k);

void subir2(heap *fp, int k);

void inserir(heap *fp0, *fp1, *fp2, car *c);

void extrair0(heap *fp0, *fp1, *fp2, int a0, ok);

void extrair1(heap *fp0, *fp1, *fp2, int a1, ok);

void extrair2(heap *fp0, *fp1, *fp2, int a2, ok);

void descer0(heap *fp, int k);

void descer1(heap *fp, int k);

void descer2(heap *fp, int k);

/*Arthur Lucas da Silva Nogueira 213293*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char tipo[2];
  int col, lin, inten, numeros, i;
  int mask = 0x00000011; /*opaerado para pegar os dois ultimos bits do numero binario*/
  int *p /*vetor*/
  scanf("%c\n", &tipo);
  scanf("%d %d\n", &col, &lin);
  scanf("%d\n", &inten);
  numeros = col*lin;
  p = malloc(numeros * sizeof(int)); /*eu posso fazer isso?*/
  for (i=0; i < numeros; i++)
    scanf("%d", &p[i]);/*alocando os números*/

/*pegar os dois ultimos bits de cada numero e juntar os pares de 4 em 4 formando
varios numeros binarios, cada um desses numeros representa um caracter que ira
formar o texto que será printado no fim do programa*/

/*
  pseudo code:
  for (i = 0; i< numeros; i+=4)
    for (j=0; j<4; j++)
      usar mask(p[i+j]) //isso forma um caractere
    print caractere //se for \n ele pula a linha se for \0 ele tem que parar
*/
  return 0;
}

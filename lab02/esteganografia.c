/*Arthur Lucas da Silva Nogueira 213293*/

#include <stdio.h>
#include <stdlib.h>

/*converte inteiro em binario, mas apenas os bits mais insignificantes*/
int conv1(int num1) {
  int num2, mult=1, l;
  for (l=0;l<2;l++){
    num2 += (num1%10)*mult;
    num1 = num1/10;
    mult = mult*10;
  }
  return num2;
}

/*converte binário pra inteiro*/
int conv2(int letra) {
  int num = 0, mult = 1;
  num = (letra%10)*mult;
  letra = letra/10;
  mult = mult*2;
  return num;
}

int main() {
  char tipo;
  int col, lin, inten, numeros, i, j, letra, mult;
  int *p; /*vetor*/
  scanf("%s\n", &tipo);
  scanf("%d %d\n", &col, &lin);
  scanf("%d\n", &inten);
  numeros = col*lin;
  p = malloc(numeros * sizeof(int));
  for (i=0; i < numeros; i++)
    scanf("%d", &p[i]);/*alocando os números*/

  for (i=0; i<numeros; i += 4){
    for (j=0; j<4; j++){
      letra = 0;
      mult = 1; /*sera uma potencia de 100*/
      letra += conv1(p[i+j]) * mult;
    printf("%c", conv2(letra));

    }
  return 0;
  }

  return 0;
}

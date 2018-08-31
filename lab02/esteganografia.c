/*Arthur Lucas da Silva Nogueira 213293*/
#include <stdio.h>
#include <stdlib.h>

/*converte inteiro em binario, mas apenas os bits mais insignificantes*/
int conv1(int num1) {
  int num2=0, mult=1, l;
  for (l=0;l<2;l++){
    num2 += (num1%2)*mult;

    num1 = num1/2;
    mult = mult*10;
  }
  return num2;
}

/*converte binário pra inteiro*/
int conv2(int letra) {
  int i, num = 0, mult = 1;
  for (i=0;i<8;i++){
    num += (letra%10)*mult;
    letra = letra/10;
    mult *= 2;
  }
  return num;
}

int main() {
  char tipo[3];
  int col, lin;
  int inten;
  int numeros = col*lin;
  int *p; /*vetor*/
  int i, j;


  scanf("%s", tipo);
  scanf("%d %d", &col, &lin);
  scanf("%d", &inten);

  p = malloc(numeros * sizeof(int));



  for (i=0; i < numeros; i++)
    scanf("%d", &p[i]);/*alocando os números*/

  int letra, mult;
  for (i=0; i<numeros; i += 4){
    letra = 0;
    mult = 1000000; /*sera uma potencia de 100*/

    for (j=0; j<4; j++){
      letra += conv1(p[i+j]) * mult;
      mult = mult/100;
    }

    if(letra == 0)
      break;

    printf("%c", conv2(letra));
  }

  return 0;
}

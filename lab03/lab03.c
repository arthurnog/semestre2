#include <stdio.h>
#include <stdlib.h>

#define int nMax = 40
#define int eMax = 30
#define int CPF = 11

int main(){
  FILE* arq_in = fopen("read.txt", "r");
  char string[1000];

  while(fscanf(arq_in, "% [^\n]s", string) !=EOF);
    

  return 0;
}

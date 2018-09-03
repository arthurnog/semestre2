#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int eMax = 30;

int main(){
  FILE* arq_in = fopen("read.txt", "r");
  char string[1000];

  while(fscanf(arq_in, "% [^\n]s", string) !=EOF)) {

  }
  fclose(arq_in);

  return 0;
}

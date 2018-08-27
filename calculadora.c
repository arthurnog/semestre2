#include <stdio.h>

int main(){
  int n;
  int i;
  float op1, op2;
  float result;
  char oper;

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%f %c %f", &op1, &oper, &op2);

    if (oper == '/') {
      result = op1 / op2;
      printf("%.1f\n", result);
    } else if (oper == '+') {
      result = op1 + op2;
      printf("%.1f\n", result);
    } else if (oper == '-') {
      result = op1 - op2;
      printf("%.1f\n", result);
    } else if (oper == '*') {
      result = op1 * op2;
      printf("%.1f\n", result);
    } else {
      printf("ERRO\n");
    }
  }
}

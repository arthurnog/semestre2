#include <stdio.h>

int main() {

  int list[3], i;

  for(i = 0; i < 3; i++)
    scanf("%d", &list[i]);

  if ((list[0]<=list[1]) && (list[0]<=list[2]))
    printf("menor: %d\n", list[0]);
  else if ((list[1]<=list[0]) && (list[1]<=list[2]))
    printf("menor: %d\n", list[1]);
  else if ((list[2]<=list[0]) && (list[2]<=list[1]))
    printf("menor: %d\n", list[2]);

  return 0;
}

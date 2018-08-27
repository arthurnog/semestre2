/*Arthur Lucas da Silva Nogueira 213293*/

#include <math.h>   /*Biblioteca com a funcao de raiz quadrada*/
#include <stdio.h>  /*Biblioteca para input e output*/

#define WIDTH 3 //128
#define HEIGHT 2//96

void edge(int matriz[][WIDTH]);

int pad(int mat[][WIDTH+2]) {
  /*padding*/
  int i,j;
  for (j=0; j<WIDTH+2; j++) {
    mat[0][j] = 0;
    mat[HEIGHT+1][j] = 0;
  }
  for (i=0; i<HEIGHT+2; i++) {
    mat[i][0] = 0;
    mat[i][WIDTH+1] = 0;
  }
  return 0;
}

int filtro(int mat[][WIDTH+2], int mat2[][WIDTH], int fx[][3], int fy[][3], int i, int j){
  int a, b, c;
  /*fx*/
  a = fx[0][0]*mat[i-1][j-1]+fx[0][1]*mat[i-1][j]+fx[0][2]*mat[i-1][j+1]
  +fx[1][0]*mat[i][j-1]+fx[1][1]*mat[i][j]+fx[1][2]*mat[i][j+1]+fx[2][0]*mat[i+1][j-1]
  +fx[2][1]*mat[i+1][j]+fx[2][2]*mat[i+1][j+1];
  /*fy*/
  b = fy[0][0]*mat[i-1][j-1]+fy[0][1]*mat[i-1][j]+fy[0][2]*mat[i-1][j+1]
  +fy[1][0]*mat[i][j-1]+fy[1][1]*mat[i][j]+fy[1][2]*mat[i][j+1]+fy[2][0]*mat[i+1][j-1]
  +fy[2][1]*mat[i+1][j]+fy[2][2]*mat[i+1][j+1];
  /*tirando a media*/
  c = (int)sqrt((double)(pow((double)a,2.0)+pow((double)b,2.0)));
  mat2[i-1][j-1] = c;

  return 0;
}
int main() {
  int i, j, mat[HEIGHT+2][WIDTH+2], mat2[HEIGHT][WIDTH];
  int fx[][3] = {{1,0,-1},{2,0,-2},{1,0,-1}};
  int fy[][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};

  /*Lendo a matriz*/
  for (i = 1; i<HEIGHT+1; i++) {
    for (j = 1; j<WIDTH+1; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  /*printando a resposta*/
  for (i = 0; i<HEIGHT; i++) {
    for (j = 0; j<WIDTH; j++) {
      mat2[i][j] = 0;
    }
  }

  /*padding*/
  pad(mat);

  /*APLICANDO OS FILTROS*/
  for (i = 1; i<HEIGHT+1; i++) {
    for (j = 1; j<WIDTH+1; j++) {
      filtro(mat, mat2, fx, fy, i, j);
    }
  }
  /*imprimindo a matriz*/
  for (i = 0; i<HEIGHT; i++) {
    for (j = 0; j<WIDTH; j++) {
      if (j != WIDTH-1)
        printf("%d ", mat2[i][j]);
      else
        printf("%d\n", mat2[i][j]);
    }
  }
  return 0;
}

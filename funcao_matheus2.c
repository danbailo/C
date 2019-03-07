#include <stdio.h>

void lerMatriz(float M[2][2]);
void printMatriz(float M[2][2]);
float soma(float M[2][2]);

int main(){
  float M[2][2];

  lerMatriz(M);
  printf("\n");
  printMatriz(M);
  printf("\n");
  printf("%.1f ", soma(M));

  return 0;
}

void lerMatriz(float M[2][2]){
  int i,j;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      scanf("%f", &M[i][j]);
    }
  }
}

void printMatriz(float M[2][2]){
  int i,j;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("%.1lf ", M[i][j]);
    }
    printf("\n");
  }
}

float soma(float M[2][2]){
  int i,j;
  float mult = 1;

  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      mult = mult * M[i][j];
    }
  }
  return mult;
}

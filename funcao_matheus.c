#include<stdio.h>
#define DIM 3

void array(int matriz[][DIM]){
  int linha,coluna;

  for(linha=0 ; linha < DIM ; linha++){
    for(coluna=0 ; coluna < DIM ; coluna++){
      printf("Entre com o elemento matriz[%d][%d]: ", linha+1, coluna+1);
      scanf("%d", &matriz[linha][coluna]);
    }
  }
}

void print_array(int matriz[][DIM]){
  int linha,coluna;

  for(linha=0 ; linha < DIM ; linha++){
    for(coluna=0 ; coluna < DIM ; coluna++){
      printf("%3d ", matriz[linha][coluna]);
    }
    printf("\n");
  }
}

int main(){
  int matriz[DIM][DIM];

  array(matriz);
  printf("\n");
  print_array(matriz);
  
  return 0;
}

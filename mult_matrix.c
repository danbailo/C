/*Algoritmo que realiza multiplicação de matriz genéricas, ou seja, serve
para qualquer matriz que o usuário digitar contanto que respeite a regra de
multiplicação de matrizes. Na regra de produto de matrizes, diz que:
Dadas duas matrizes A=(aij)mxn e B=(bjk)nxp, chamamos o produto AB
e matriz C(cik)mxp. Logo, para realizar a multiplicação de matrizes, é
preciso que essas tenham o mesmo número de colunas, obrigatoriamente.
A matriz formada terá o número de linhas da primeira e o número de colunas
da segunda.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  int i,j,x,M,N,K,P;

  float Aux=0;

  printf("Digite a quantidade de linhas da matriz A: ");
  scanf("%d",&M);
  printf("Digite a quantidade de colunas da matriz A: ");
  scanf("%d",&N);

  float matrizA[M][N];

  for(i=0; i<M; i++){
    for(j=0; j<N; j++){
      printf("Informe os Componentes da Matriz A(por linha): ");
      scanf("%f", &matrizA[i][j]);
    }
    printf("\n");
  }
  printf("Digite a quantidade de linhas da matriz B: ");
  scanf("%d",&K);
  while(N!=K){
    printf("Por favor, insira um valor igual ao número de colunas da matriz A\n");
    printf("Digite a quantidade de linhas da matriz B: ");
    scanf("%d",&K);
  }
  printf("Digite a quantidade de colunas da matriz B: ");
  scanf("%d",&P);

  float matrizB[K][P];

  for(i=0; i<K; i++){
    for(j=0; j<P; j++){
      printf("Informe os componentes da Matriz B(por linha): ");
      scanf("%f", &matrizB[i][j]);
    }
    printf("\n");
  }

  printf("Matriz A \n\n");
  for(i=0; i<M; i++){
    for(j=0; j<N; j++){
      printf("%6.f", matrizA[i][j]);
      /* "%6.f" significa para eliminar 6 casas decimais dos componentes dados */
    }
    printf("\n\n");
  }
  printf("Matriz B \n\n");
  for(i=0; i<K; i++){
    for(j=0; j<P; j++){
      printf("%6.f", matrizB[i][j]);
    }
    printf("\n\n");
  }

  float matrizC[M][P];

  for(i=0; i<M; i++){
    for(j=0; j<P; j++){
       for(x=0; x<N; x++){
         Aux+= (matrizA[i][x]*matrizB[x][j]);
/* x significa que a quantidade de colunas da Matriz A é mesma  que as linhas
da Matriz B */
        }
        matrizC[i][j]=Aux;
        Aux=0;
/* Aux significa guardar valor para não ser perdido durante o algoritmo*/
    }
  }
  printf("\n\n");
  printf("Matriz Gerada da Multiplicacao A*B \n\n");
  for(i=0; i<M; i++){
    for(j=0; j<P; j++){
      printf("%6.f", matrizC[i][j]);
    }
    printf("\n\n");
  }
  printf("\n\n");
  return 0;
}

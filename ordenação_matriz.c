#include<stdio.h>

int main(){

  int vetor[5]={101,13,5,22,15};
  int atual,i,j;

  for(i=0;i<5;i++){
    printf("%d ",vetor[i]);
  }
  printf("\n");
  printf("\n");
  for(i=1;i<5;i++){
    atual = vetor[i];
    j = i-1;
    while((j>=0) && (atual<vetor[j])){
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = atual;
  }
  for(i=0;i<5;i++){
    printf("%d ",vetor[i]);
  }
  return 0;
}

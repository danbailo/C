#include <stdio.h>

int main(){

  int i,pares=0;
  int vetor[20];

  printf("Digite 20 números\n");
  for (i = 0; i < 20; i++){
    scanf("%d",&vetor[i]);
    if(vetor[i]%2==0){
      pares++;
    }
  }
  printf("%d pares",pares);
}

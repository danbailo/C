#include <stdio.h>

int main(){

  int v[5]={101,13,5,22,15};
  int a,b,c;
  c=0;
  printf("Vetor sem ordenação: ");
  for(int i=0;i<5;i++){
    printf("%d ",v[i]);
  }
  while(c<5){
    for(int j=1; j<5; j++){
      if(v[j-1]>v[j]){
        a = v[j-1];
        b = v[j];
        v[j-1] = b;
        v[j] = a;
      }
    }
    c++;
  }
  printf("\n");
  printf("\n");
  printf("Vetor ordenado: ");
  for(int i=0;i<5;i++){
    printf("%d ",v[i]);
  }
  return 0;
}

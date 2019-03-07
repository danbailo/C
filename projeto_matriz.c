#include <stdio.h>

int main(){

  int v[3]={3,2,1};
  int a,b,c;
  c=0;
  printf("Vetor sem ordenação: ");
  for(int i=0;i<3;i++){
    printf("%d ",v[i]);
  }
  while(c<1){
    for(int j=1; j<3; j++){
      if(v[j-1]>v[j]){
        a = v[j-1];
        b = v[j];
        v[j-1] = b;
        v[j] = a;
      }
    }
    c++;
  }
  // for(int i=0; i<5; i++){
  //   for(int j=1; j<5; j++){
  //     if(v[j-1]>v[j]){
  //       a = v[j-1];
  //       b = v[j];
  //       v[j-1] = b;
  //       v[j] = a;
  //     }
  //   }
  // }
  printf("\n");
  printf("\n");
  printf("Vetor ordenado: ");
  for(int i=0;i<3;i++){
    printf("%d ",v[i]);
  }
  return 0;
}

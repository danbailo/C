#include <stdio.h>

int somaptr(int* n1, int* n2){

  int res;

  res = *n1 + *n2;
  printf("%d", res);

  return res;
  printf("aisdjasidj");
}

int main(){

  int n1,n2;
  int n3=10, n4=20;

  n1=15;
  n2=30;

  somaptr(&n1, &n2);
  somaptr(&n3, &n4);

  return 0;
}

#include <stdio.h>

int main(){

  int sample[10];
  int *p;
  int *q;

  sample[0]=10;
  sample[5]=50;
  p=sample;//Recebe o primeiro elemento da matriz, mesmo sem especificar
  q=&sample[5];// Recebe o quarto elemento da matriz que tem o índice 5;

  printf("%d\n",sample[0]);
  printf("%d\n",*p);
  printf("%d",*q);
}

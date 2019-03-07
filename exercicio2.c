#include <stdio.h>

int main(){

  int i=10, j=20;
  int temp;
  int *p1,*p2;

  p1 = &i;
  p2 = &j;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  printf("%d %d\n", i,j);
  return 0;
}

#include <stdio.h>
#include <stdbool.h>

int soma(int *a, int *b){
  int c;

  c = *a + *b;

  return c;
}

bool teste(int c){
  if(c>100){
    return true;
  }
  else{
    return false;
  }
}

int main(){

  int a,b;
  int c=1;

  a = 5;
  b = 7;

  printf("%d \n",soma(&a, &b));

  c = soma(&a, &b) * 10;

  printf("%d \n",c);

  printf("%d\n", teste(c));

  int *n=NULL;
  // int h = 23;
  // n= &h;
  printf("%d ",*n);

  return 0;
}

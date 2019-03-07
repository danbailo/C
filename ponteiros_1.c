#include <stdio.h>

int main(){

  int *m;
  int q,count=100;

  //& == "o endereço de";
  m = &count;
  //m recebe o endereço de count, endereço da memória;

  //* == "no endereço de";
  q = *m;
  //q recebe o valor que está no endereço de m;

  printf("%d\n", *m);
  printf("%d", q);


}

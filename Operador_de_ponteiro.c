#include <stdio.h>

int main(){

  int target, source;
  int *m;//Declaração de ponteiro do tipo int;

  source=10;
  m=&source;//m recebe o endereço de source;
  //& Lê-se "o endereço de", diferente do valor da variável, pois é o valor
  //armazenado no endereço da memória;

  target=*m;//target recebe o endereço de m;
  //* Lê-se "no endereço de", devolve o valor da variável localizada no
  //endereço que segue;

  printf("%d",target);
}

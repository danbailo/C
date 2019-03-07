#include <stdio.h>

int main(){

  char e1[17] = "erro de leitura ";
  char e2[] = "fala quebrada ";//o compilador c automaticamente calcula a
  //dimensão da matriz;
  //LEMBRE-SE SEMPRE QUE O /0 CONTA COMO UM CARACTER;
  printf("%stem comprimento %d\n", e1, sizeof e1);
  printf("\n%stem comprimento %d\n", e2, sizeof e2);
}

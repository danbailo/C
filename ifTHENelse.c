//O operador ? funciona como um if-then-else, avalia a primeira expressão, e se
//ela for verdadeira, a segunda expressão se torna o valor, se não, a terceira torna;
#include <stdio.h>

int main(){

  int y,x;

  y = 10>9?100:200;
  x = 10>11?100:200;

  printf("y=%d\n",y);
  printf("x=%d",x);

}

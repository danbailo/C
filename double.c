#include <stdio.h>

int main(){
  int *a,*b;
  int valorA, valorB;

  valorA = 6.7;
  valorB = 8.5;

  // "a" é um ponteiro, logo ele só pode receber endereços, que é utilizado
  // com a sintaxe & para mostrar o endereço;
  a = &valorA;
  // *a = valorA;

  b = &valorB;
  *b = valorB;

  printf("Valor de valorA: %d\nValor de a: %d\n",*a,valorA);
  printf("Endereço de valorA: %p\nEndereço de a: %p\n",a,&valorA);

  printf("\n");

  printf("Valor de valorB: %d\nValor de b: %d\n",*b,valorB);
  printf("Endereço de valorB: %p\nEndereço de b: %p\n",b,&valorB);

  printf("\n");

  printf("Mesclando a e b \n");
  printf("\n");

  a = b;
  // b = a;

  printf("Valor de a: %d\n", *a);
  printf("Valor de b: %d\n", *b);

  printf("valor de valorA: %d\n",valorA);
  printf("valor de valorB: %d\n",valorB);
  printf("\n");

  *a = 10;

  printf("Valor de a: %d\n", *a);
  printf("Valor de b: %d\n", *b);

  printf("valor de valorA: %d\n",valorA);
  printf("valor de valorB: %d\n",valorB);
  printf("\n");

  *b = 17;

  printf("Valor de a: %d\n", *a);
  printf("Valor de b: %d\n", *b);

  printf("valor de valorA: %d\n",valorA);
  printf("valor de valorB: %d\n",valorB);
  printf("\n");

  *a = 13;

  printf("Valor de a: %d\n", *a);
  printf("Valor de b: %d\n", *b);

  printf("valor de valorA: %d\n",valorA);
  printf("valor de valorB: %d\n",valorB);
  printf("\n");


  return 0;
}

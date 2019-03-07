#include <stdio.h>

int main(){

  int* pointer;
  int* pointer2;
  int teste=10;
  int teste2=15;


  pointer = &teste;

  printf("teste = %d\n", teste);
  printf("*pointer = %d\n", *pointer);

  pointer2 = &teste2;
  pointer = pointer2;

  printf("teste2 = %d\n", teste2);
  printf("*pointer2 = %d\n", *pointer2);
  printf("*pointer = %d\n", *pointer);

  *pointer2= 49;

  printf("teste2 = %d\n", teste2);
  printf("*pointer2 = %d\n", *pointer2);
  // printf("*pointer = %d\n", *pointer);

  *pointer = 20;

  printf("teste2 = %d\n", teste2);
  printf("*pointer2 = %d\n", *pointer2);
  printf("*pointer = %d\n", *pointer);

  teste = *pointer;

  printf("teste = %d\n", teste);

  *pointer = 17;
  teste = *pointer;

  printf("teste = %p\n", &teste);
  printf("teste2 = %p\n", &teste2);
  printf("pointer = %p\n", pointer);
  printf("pointer2 = %p\n", pointer2);


}

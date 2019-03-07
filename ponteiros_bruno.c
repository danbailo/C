#include <stdio.h>

int main(){

  int a,b;
  int *x,*y;

  printf("Posição de a e b na memória!\n%p\n%p",&a,&b);
  printf("\n\nDigite um valor númerico para a e um valor para b:\n");
  scanf("%d%d", &a, &b);

  x = &a;
  y = &b;
  printf("\nx Está apontando para a, e y está apontando para b\n");
  printf("%p\n%p",x,y);
  printf("\n\nO conteúdo de x é %d",*x);
  printf("\nO conteúdo de y é %d\n",*y);
}

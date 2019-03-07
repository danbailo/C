#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
  insere(Raiz, 20, NULL);
  insere(Raiz, 15, NULL);
  insere(Raiz, 14, NULL);
  insere(Raiz, 16, NULL);
  insere(Raiz, 30, NULL);
  emOrdem(Raiz);
  // busca(Raiz,13);
  // int flag = busca(Raiz,220);
  // printf("flag:%d",flag);
  // busca(Raiz,2);
  printf("\n");
  remover(Raiz,14);
  abb_retira(Raiz,14);
  printf("\n");
  emOrdem(Raiz);
  // printAltura();

  return 0;
}

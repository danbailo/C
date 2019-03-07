#include "revisao_p2.h"

int main(){
  insere(raiz,50,NULL);
  insere(raiz,20,NULL);
  insere(raiz,75,NULL);
  insere(raiz,25,NULL);
  insere(raiz,2,NULL);
  insere(raiz,60,NULL);
  insere(raiz,80,NULL);
  insere(raiz,21,NULL);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,50);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,20);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,75);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,25);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,2);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,60);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,80);
  pre_ordem(raiz);
  printf("\n");

  remover(&raiz,21);
  pre_ordem(raiz);
  printf("\n");

  return 0;
}

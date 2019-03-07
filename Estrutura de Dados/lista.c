#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

  Lista *L1 = criaLista();

  insere_dupla(L1,15);
  insere_dupla(L1,32);
  insere_dupla(L1,54);
  insere_dupla(L1,235);
  insere_dupla(L1,93);
  insere_dupla(L1,111);
  insere_dupla(L1,655);
  printf("LISTA PRINCIPAL: ");
  imprime(L1);

  printf("\nInicio -> %d",L1->inicio->chave);
  printf("\nFim -> %d\n",L1->fim->chave);

  busca_dupla(L1, 111);
  busca_dupla(L1, 235);
  busca_dupla(L1,93);
  printf("\n");

  printf("\n");
  remover(L1,655);
  imprime(L1);
  printf("\nFim -> %d\n",L1->fim->chave);

  printf("\n");
  remover(L1,111);
  imprime(L1);
  printf("\nFim -> %d\n",L1->fim->chave);

  printf("\n");
  remover(L1,54);
  imprime(L1);

  return 0;
}

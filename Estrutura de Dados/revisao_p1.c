#include <stdio.h>
#include <stdlib.h>
#include "revisao_p1.h"

int main(){

  Lista *vetor[10];

  for(int i=0; i<10; i++){
    vetor[i] = crialista();
  }
  insereFim(vetor[1],33);
  insereFim(vetor[1],45);
  insereFim(vetor[1],122);
  insereFim(vetor[1],323);
  insereFim(vetor[1],93);
  insereFim(vetor[1],91);

  insereFim(vetor[2],33);
  insereFim(vetor[2],45);
  insereFim(vetor[2],122);
  insereFim(vetor[2],323);
  insereFim(vetor[2],93);
  insereFim(vetor[2],91);


  imprime(vetor[1]);
  tam(vetor[1]);
  divide_lista(vetor[1]);
  soma_media(vetor[1]);
  maior_menor(vetor[1]);
  imprime_circular(vetor[1]);




  {
  // printf("\nInicio: %d", vetor[1]->inicio->chave);
  // printf("\nFim: %d", vetor[1]->fim->chave);
  // printf("\n");
  // busca(vetor[1],122);
  // printf("\n");
  // busca(vetor[1],233);
  //
  // printf("\n");
  // printf("\nRemovendo primeiro elemento\n");
  // remover(vetor[1],33);
  // imprime(vetor[1]);
  // printf("\nInicio: %d", vetor[1]->inicio->chave);
  // printf("\nFim: %d", vetor[1]->fim->chave);
  //
  // printf("\n");
  //
  // printf("\nRemovendo último elemento\n");
  // remover(vetor[1],93);
  // imprime(vetor[1]);
  // printf("\nInicio: %d", vetor[1]->inicio->chave);
  // printf("\nFim: %d", vetor[1]->fim->chave);
  //
  // printf("\n");
  //
  // printf("\nSoma e média\n");
  // soma_media(vetor[1]);
  // maior_menor(vetor[1]);
  //
  // printf("\n");
  // insereFim(vetor[2],123);
  // insereFim(vetor[2],2353);
  // insereFim(vetor[2],111);
  // insereFim(vetor[2],523);
  // imprime(vetor[2]);
  //
  // printf("\nCircular e junta lista\n");
  // junta_lista(vetor[1],vetor[2]);
  // imprime_circular(vetor[1]);
}

  return 0;
}

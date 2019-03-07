#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  struct SNo *prox;
  int chave;
}SNo;

typedef struct Pilha{
  SNo *topo;
}Pilha;

Pilha *criaPilha(){
  Pilha *P = (Pilha*)malloc(sizeof(Pilha));
  P->topo = NULL;
  return P;
}



int main(){

}

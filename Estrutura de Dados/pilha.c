#include<stdio.h>
#include<stdlib.h>

typedef struct SNo {
  int chave;
  struct SNo *prox;
}SNo;

typedef struct Pilha {
  SNo *topo;
  SNo *base;
  int tam;
}Pilha;

Pilha *criaPilha(){
  Pilha *P = (Pilha*)malloc(sizeof(Pilha));
  P->topo = NULL;
  P->base = NULL;
  P->tam=0;
  return P;
}

void insere(Pilha *P,int valor){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = P->topo;
  P->topo = novo;
  if(novo->prox == NULL){
    P->base = novo;
  }
}

void imprime(Pilha *P){
  SNo *temp = P->topo;
  if(temp == NULL){
    printf("Não há nós presentes na pilha!\n");
    return;
  }
  while(temp!=NULL){
    printf("%d\n", temp->chave);
    temp = temp->prox;
  }
}

void busca(Pilha *P, int valor){
  SNo *temp = P->topo;
  if(temp == NULL){
    printf("Não há nós presentes na pilha!\n");
    return;
  }
  while(temp!=NULL){
    if(temp->chave==valor){
      printf("\n%d Está na pilha!", valor);
      return;
    }
    temp = temp->prox;
  }
  printf("\nO elemento %d não está na pilha!", valor);
}

void remover(Pilha *P){
  SNo* temp = P->topo;
  if(P->topo==P->base){
    P->topo=P->base=NULL;
  }
  else{
    P->topo=P->topo->prox;
  }
  free(temp);
}


int main(){

  Pilha *P1 = criaPilha();

  insere(P1, 23);
  insere(P1, 133);
  insere(P1, 655);
  insere(P1, 443);
  imprime(P1);

  printf("Topo->%d \n",P1->topo->chave);
  printf("Base->%d ",P1->base->chave);

  printf("\n");
  printf("\n");
  remover(P1);
  imprime(P1);

  printf("Topo->%d \n",P1->topo->chave);
  printf("Base->%d ",P1->base->chave);

  printf("\n");
  printf("\n");
  remover(P1);
  remover(P1);
  imprime(P1);

  printf("Topo->%d \n",P1->topo->chave);
  printf("Base->%d ",P1->base->chave);

  printf("\n");
  printf("\n");
  remover(P1);
  imprime(P1);



  return 0;
}

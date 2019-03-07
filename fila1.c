#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;

typedef struct Fila{
  SNo *Inicio;
  SNo *Fim;
}Fila;

void insere(Fila *F,int valor){
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  SNo *Temp = F->Inicio;
  Novo->chave=valor;
  Novo->prox=NULL;

  if(Temp==NULL){//primeira vez;
    F->Inicio=Novo;
  }
  else{//ja existe nós na fila;
    while(Temp->prox!=NULL){
      Temp=Temp->prox;
    }
    Temp->prox=Novo;
  }
}

void imprime(Fila *F){
  SNo *Temp = F->Inicio;
  if(Temp==NULL){
    printf("Fila vazia!\n");
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp=Temp->prox;
  }
  printf("\n");
}

void busca(Fila *F,int valor){
  SNo *Temp = F->Inicio;
  if(Temp==NULL){
    printf("Fila vazia!\n");
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      printf("O elemento %d ESTÁ na lista!\n",valor);
      return;
    }
    Temp=Temp->prox;
  }
  printf("O elemento %d NÃO ESTÁ na lista!\n",valor);
}

void remover(Fila *F){
  SNo *Temp = F->Inicio;
  if(Temp==NULL){
    printf("Fila vazia!");
    return;
  }
  if(F->Inicio==F->Fim){
    F->Inicio=F->Fim=NULL;
    free(F->Inicio);
  }
  if(Temp!=NULL){
    F->Inicio = F->Inicio->prox;
    free(Temp);
  }
}

Fila *criaFila(){
  Fila *F = (Fila*) malloc(sizeof(Fila*));
  F->Inicio = NULL;
  F->Fim = NULL;
  return F;
}

int main(){

  Fila *F1 = criaFila();

  insere(F1,10);
  insere(F1,20);
  insere(F1,30);
  insere(F1,40);
  imprime(F1);
  printf("\n");
  busca(F1,10);
  busca(F1,20);
  busca(F1,35);
  printf("\n");
  imprime(F1);
  remover(F1);
  imprime(F1);
  remover(F1);
  imprime(F1);
  remover(F1);
  imprime(F1);
  remover(F1);
  imprime(F1);


  return 0;
}

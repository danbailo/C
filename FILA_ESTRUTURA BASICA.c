#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo* prox;
}SNo;

typedef struct Fila{
  SNo* Inicio;
  SNo* Fim;
}Fila;

void inserefim(int valor, Fila *F){
  SNo* Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = NULL;
  if(F->Inicio==NULL){//Primeira inserção;
    F->Inicio = Novo;
  }
  else{
    F->Fim->prox = Novo;
  }
  F->Fim = Novo;
}

void insere_ordenado(Fila *F,int valor){
  SNo *Aux = F->Inicio;
  SNo *Ant = NULL;

  SNo *Novo = (SNo *) malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox= NULL;

  if (F->Inicio == NULL){
      F->Inicio = Novo;
      F->Fim = Novo;
  }
  else if (Aux->chave > Novo->chave || Aux->chave == Novo->chave ){
         F->Inicio = Novo;
         Novo->prox = Aux;
  }
  else{
    while((Aux != NULL) && (Aux->chave < Novo->chave)){
      Ant = Aux;
      Aux = Aux->prox;
    }
    Ant->prox = Novo;
    Novo->prox = Aux;
  }
}

void imprime(Fila *F){
  SNo* Temp = F->Inicio;
  if(Temp==NULL){
    printf("Lista vazia!");
    return;
  }
  else{
    while(Temp!=NULL){
      printf("%d ",Temp->chave);
      Temp = Temp->prox;
    }
  }
}

void remover(Fila *F){
  SNo* Temp = F->Inicio;
  if(F->Inicio==F->Fim){
    F->Inicio=F->Fim=NULL;
  }
  else{
    F->Inicio=F->Inicio->prox;
  }
  free(Temp);
}

Fila *criaFila(){
  Fila* F = (Fila*)malloc(sizeof(Fila));
  F->Inicio = NULL;
  F->Fim = NULL;
  return F;
}

int main(){
  Fila *F1 = criaFila();

  insere_ordenado(F1, 123);
  insere_ordenado(F1, 123);
  insere_ordenado(F1, 233);
  insere_ordenado(F1, 563);
  insere_ordenado(F1, 233);

  imprime(F1);
  return 0;
}

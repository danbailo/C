#include<stdio.h>
#include<stdlib.h>

typedef struct SNo {
  int chave;
  struct SNo *prox;
}SNo;

typedef struct Fila {
  SNo *inicio;
  SNo *fim;
  int tam;
}Fila;

Fila *criaFila(){
  Fila *F = (Fila*)malloc(sizeof(Fila));
  F->inicio = NULL;
  F->fim = NULL;
  F->tam=0;
  return F;
}

void insereBRUNO(Fila *F, int valor) {
  SNo *novo = (SNo *)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  if(F->inicio == NULL) { // quando nao tem elementos
    F->inicio = novo;
    F->fim = novo;
  }
  else {
    F->fim->prox = novo;
    F->fim = novo;
  }
}

void insere(Fila *F,int valor){
  SNo* novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  if(F->inicio==NULL){//Primeira inserção;
    F->inicio = novo;
  }
  else{
    F->fim->prox = novo;
  }
  F->fim = novo;
}


void imprime(Fila *F){
  SNo *temp = F->inicio;
  if(temp == NULL){
    printf("\nNão há nós presentes na fila!\n");
    return;
  }
  while(temp!=NULL){
    printf("%d ", temp->chave);
    temp = temp->prox;
  }
}

void busca(Fila *F, int valor){
  SNo *temp = F->inicio;
  if(temp == NULL){
    printf("Não há nós presentes na fila!\n");
    return;
  }
  while(temp!=NULL){
    if(temp->chave==valor){
      printf("\n%d Está na fila!", valor);
      return;
    }
    temp = temp->prox;
  }
  printf("\nO elemento %d não está na fila!", valor);
}

void remover(Fila *F){
  SNo* temp = F->inicio;
  if(F->inicio==F->fim){
    F->inicio=F->fim=NULL;
  }
  else{
    F->inicio=F->inicio->prox;
  }
  free(temp);
}

// int main(){
//
//   Fila *F1 = criaFila();
//
//   insere(F1, 23);
//   insere(F1, 133);
//   insere(F1, 655);
//   insere(F1, 443);
//   imprime(F1);
//
//   printf("\nInicio->%d \n",F1->inicio->chave);
//   printf("Fim->%d ",F1->fim->chave);
//
//   printf("\n");
//   printf("\n");
//   remover(F1);
//   imprime(F1);
//
//   printf("\nInicio->%d \n",F1->inicio->chave);
//   printf("Fim->%d ",F1->fim->chave);
//   printf("\n");
//   printf("\n");
//   remover(F1);
//   imprime(F1);
//
//   printf("\nInicio->%d \n",F1->inicio->chave);
//   printf("Fim->%d ",F1->fim->chave);
//
//   printf("\n");
//   printf("\n");
//   remover(F1);
//   imprime(F1);
//
//   printf("\nInicio->%d \n",F1->inicio->chave);
//   printf("Fim->%d ",F1->fim->chave);
//
//   remover(F1);
//   printf("\n");
//   imprime(F1);
//
//   return 0;
// }

int main(){

  Fila *F1 = criaFila();

  insere(F1, 13);
  insere(F1, 53);
  insere(F1, 123);
  insere(F1, 523);
  insere(F1, 493);
  imprime(F1);

  return 0;
}

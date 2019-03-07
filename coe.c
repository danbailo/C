#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  struct SNo *prox;
  int chave;
}SNo;

SNo *Inicio = NULL;

void insere(int valor){
  SNo *Novo = (SNo *)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = Inicio;
  Inicio = Novo;
}

void imprime(){
  SNo *Temp = (SNo *)malloc(sizeof(SNo));
  Temp = Inicio;
  if(Temp == NULL){
    return;
  }
  while(Temp!=NULL){
    printf("%d ", Temp->chave);
    Temp = Temp->prox;
  }
}

void busca(int valor){
  SNo *Temp = Inicio;
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

int main(){

  insere(10);
  insere(54);
  insere(23);
  insere(12);
  imprime();
  busca(23);
  busca(54);
  busca(12);

  return 0;
}

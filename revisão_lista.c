#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo* prox;
}SNo;

SNo* Inicio = NULL;

void inserefim(int valor){
  SNo *Temp = Inicio;
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = NULL;
  if(Temp == NULL) { // primeira insercao
      Inicio = Novo;
  }
  else { // ja existem nohs na lista
      while(Temp->prox != NULL) {
          Temp = Temp->prox;
      }
      Temp->prox = Novo;
  }
}

void insere(int valor){
  SNo* Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = Inicio;
  Inicio = Novo;
}


void imprime(){
  SNo* Temp = Inicio;
  int c=0;
  if (Temp==NULL) {
    printf("Lista vazia!\n");
    return;
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp = Temp->prox;
    c++;
  }
  printf("\nA lista possui %d elementos!",c);
}

void busca(int valor){
  SNo* Temp = Inicio;
  if (Temp==NULL) {
    printf("Lista vazia!\n");
    return;
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      printf("\nO elemento %d ESTÁ na lista!",valor);
      return;
    }
    Temp = Temp->prox;
  }
  printf("\nO elemento %d NÃO ESTÁ na lista!",valor);
}

void remover(int valor){
  SNo* Temp = Inicio;
  SNo* Ant = NULL;
  if (Temp==NULL) {
    printf("Lista vazia!\n");
    return;
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      if(Temp==Inicio){
        Inicio = Inicio->prox;
      }
      else{
        Ant->prox=Temp->prox;
      }
      free(Temp);
      return;
    }
    Ant=Temp;
    Temp=Temp->prox;
  }
  return;
}

int main(){
  inserefim(5);
  inserefim(8);
  imprime();
  return 0;

}

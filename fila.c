#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;

SNo *Inicio = NULL;
SNo *Fim = NULL;

void insere(int valor) {
  SNo *temp = Inicio;
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = NULL;
  if(temp == NULL) { // primeira insercao
      Inicio = Novo;
      Fim->prox = Novo;
  }
  else { // ja existe nohs na lista
      while(temp->prox != NULL) {
          temp = temp->prox;
      }
      temp->prox = Novo;
  }
}

void imprime(){
  SNo *Temp = Inicio;
  if(Temp==NULL){
    printf("Lista vazia!");
    return;
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp=Temp->prox;
  }
  printf("\n");
}

int main(){

  insere(10);
  insere(20);
  insere(30);
  insere(40);
  insere(50);
  imprime();
  imprime();

  return 0;
}

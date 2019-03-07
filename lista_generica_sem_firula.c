//remover();
//somatotal();
//removertodas();
#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;


void insere(int valor,SNo **Inicio){
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = (*Inicio);
  (*Inicio) = Novo;
  //printf("%p\n",Novo);
  //printf("%p\n",(*Inicio));
  //printf("%d\n",(*Inicio)->chave);
}

void imprime(SNo *Inicio){
  SNo *Temp = Inicio;
  printf("%p\n",Temp);
  printf("%p\n",Inicio);
  if(Temp==NULL){
    printf("Lista vazia!\n");
    return;
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp = Temp->prox;
  }
  printf("\n");
}

int busca(int valor,SNo *Inicio){
  SNo *Temp = Inicio;
  if(Temp==NULL){
    printf("Lista vazia!\n");
    return 0;
  }
  while(Temp!=NULL){
    if(Temp->chave == valor){
      printf("O elemento %d está na lista!\n",valor);
      return 1;
    }
    Temp = Temp->prox;
  }
  printf("O elemento %d NÃO está na lista!\n",valor);
  return 0;
}

int remover(int valor,SNo *Inicio){
  SNo *Temp = Inicio;
  SNo *Ant = NULL;
  if(Temp==NULL){
    printf("Nada p/ remover, lista vazia!");
    return 1;
  }
  while(Temp!=NULL){
    if(Temp->chave == valor){
      if(Temp==Inicio){
        Inicio=Inicio->prox;
      }
      else{
        Ant->prox=Temp->prox;
      }
      free(Temp);
      return 1;
    }
    Ant = Temp;
    Temp = Temp->prox;
  }
  return 0;
}

void somatotal(SNo *Inicio){
  SNo *Temp = Inicio;
  if(Temp==NULL){
    printf("Lista vazia!\n");
    return;
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp = Temp->prox;
  }
  printf("\n");
}

int main(){

  SNo *Inicio = NULL;

  insere(10,&Inicio);
  imprime(Inicio);
  //insere(20);
  /*insere(30);
  insere(40);
  insere(40);
  imprime();
  busca(10);
  busca(20);
  busca(30);
  busca(40);
  busca(50);
  somatotal();
  imprime();
  remover(40);
  imprime();
  remover(20);
  imprime();
  remover(10);
  imprime();
  remover(30);
  imprime();
  remover(40);
  imprime();
  remover(10);*/
  return 0;
}

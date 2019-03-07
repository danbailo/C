#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo* prox;
}SNo;

typedef struct Lista{
  struct SNo* Inicio;
  struct SNo* Fim;
  int qtd;
}Lista;

void insere(int valor, Lista *L){
  SNo* Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = L->Inicio;
  L->Inicio = Novo;
}

void imprime(Lista *L){
  SNo* Temp = L->Inicio;

  if(Temp==NULL){
    printf("Lista vazia!");
  }

  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp = Temp->prox;
  }
  printf("\n");
}

int busca(int valor, Lista *L){
  SNo* Temp = L->Inicio;

  if(Temp==NULL){
    printf("Lista vazia!\n");
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      printf("%d ESTÁ na lista!\n", valor);
      return 1;
    }
    Temp = Temp->prox;
  }
  printf("%d NÃO está na lista!\n", valor);
  return 0;
}

void remover(int valor, Lista *L){
  SNo* Temp = L->Inicio;
  SNo* Ant = NULL;

  if(Temp==NULL){
    printf("Lista vazia!");
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      if(Temp==L->Inicio){
        L->Inicio = L->Inicio->prox;
      }
      else{
        Ant->prox=Temp->prox;
      }
      free(Temp);
    }
    Ant = Temp;
    Temp = Temp->prox;
  }
}

Lista *criaLista(){
    Lista *L =(Lista*)malloc(sizeof(Lista));
    L->Inicio = NULL;
    L->Fim = NULL;
    L->qtd = 0;

    return L;
}

int main(){

  Lista *L1 = criaLista();

  insere(5,L1);
  insere(9,L1);
  insere(23,L1);
  imprime(L1);
  busca(5,L1);
  busca(20,L1);
  busca(35,L1);
  remover(23,L1);
  remover(5,L1);
  imprime(L1);
  return 0;
}

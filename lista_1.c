#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo* prox;
}SNo;

SNo* Inicio=NULL;
SNo* Fim=NULL;

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

void insere_ord(int valor){
  SNo *Temp = Inicio;
  SNo *Aux = NULL;
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave=valor;
  if(Inicio==NULL){//primeira inserção;
    Novo->prox=Inicio;
    Inicio=Novo;
    return;
  }
  else{
    if(valor<Temp->chave){//primeira posição;
      Novo->prox=Temp;
      Inicio=Novo;
      return;
    }
    else{
      while(Temp!=NULL){
        if(valor>Temp->chave){
          Aux=Temp;
          Temp=Temp->prox;
        }
        else{
          Novo->prox=Temp;
          Aux->prox=Novo;
        }
      }
      Aux->prox=Novo;
      Novo->prox=NULL;
    }
  }
}

void imprime(){
  SNo *Temp=Inicio;
  if(Temp==NULL){
    printf("Lista vazia!");
  }
  while(Temp!=NULL){
    printf("%d ",Temp->chave);
    Temp=Temp->prox;
  }
}

int busca(int valor){
  SNo *Temp=Inicio;
  if(Temp==NULL){
    printf("Lista vazia!");
    return 0;
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      printf("O valor %d está na lista!\n",valor);
      return 1;
    }
    Temp=Temp->prox;
  }
  printf("O valor %d NÃO está na lista!\n",valor);
  return 0;
}

void remover(int valor){
  SNo *Temp=Inicio;
  SNo *Ant=NULL;
  if(Temp==NULL){
    printf("Nada para remover, a lista está vazia!\n");
    return;
  }
  while(Temp!=NULL){
    if(Temp->chave==valor){
      if(Temp==Inicio){
        Inicio=Inicio->prox;
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

int soma(){
  SNo *Temp = Inicio;
  int s=0;

  if(Temp==NULL){
    printf("Não há elementos para somar!");
    // return 0;
  }
  while(Temp!=NULL){
    s+=Temp->chave;
    Temp = Temp->prox;
  }
  printf("\nA soma total de elementos da lista é %d", s);
  return 0;
}

int maior(){
  SNo* Temp = Inicio;
  int m=0;
  if(Temp==NULL){
    printf("Lista vazia!");
  }
  while(Temp!=NULL){
    if(Temp->chave>m){
      m=Temp->chave;
    }
    Temp=Temp->prox;
  }
  printf("\nO maior número da lista é %d", m);
  return m;
}

int menor(){
  SNo* Temp = Inicio;
  int n=Temp->chave;
  if(Temp==NULL){
    printf("Lista vazia!");
  }
  while(Temp!=NULL){
    if(Temp->chave<n){
      n=Temp->chave;
    }
    Temp=Temp->prox;
  }
  printf("\nO menor número da lista é %d", n);
  return n;
}

int main(){
  // insere_ord(29);
  insere_ord(5);
  insere_ord(4);
  insere_ord(6);
  insere_ord(7);
  insere_ord(71);
  // insere_ord(1);
  // insere_ord(54);
  // insere_ord(2);
  imprime();

  return 0;
}

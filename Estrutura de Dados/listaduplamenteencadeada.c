#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
  struct SNo *antprox;
}SNo;

typedef struct Lista {
  SNo *inicio;
  SNo *fim;
  int tam;
}Lista;

Lista *criaLista(){
  Lista *L = (Lista*)malloc(sizeof(Lista));
  L->inicio = NULL;
  L->fim = NULL;
  L->tam=0;
  return L;
}

void insere(Lista *L,int valor){
  L->tam++;
  SNo *Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = L->inicio;
  Novo->antprox = NULL;
  L->inicio = Novo;
  SNo *temp = L->inicio;
  L->fim = Novo;
  // SNo *temp = L->fim;
  while(temp!=NULL){
    if(temp->prox==NULL){
      L->fim = temp;
    }
    temp = temp->prox;
  }
}

void inserefim(Lista *L,int valor){
  SNo* Novo = (SNo*)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = NULL;
  if(L->inicio==NULL){//Primeira inserção;
    L->inicio = Novo;
  }
  else{
    L->fim->prox = Novo;
  }
  L->fim = Novo;
}

void imprime(Lista *L){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  while(temp!=NULL){
    printf("%d ", temp->chave);
    temp = temp->prox;
  }
}

void busca(Lista *L, int valor){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  while(temp!=NULL){
    if(temp->chave==valor){
      printf("\n%d Está na lista!", valor);
      return;
    }
    temp = temp->prox;
  }
  printf("\nO elemento %d não está na lista!", valor);
}

void remover(Lista *L, int valor){
  SNo *temp = L->inicio;
  SNo *ant = NULL;
  if(temp == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  while(temp!=NULL){
    if(temp->chave==valor){
      if(temp==L->inicio){
        L->inicio=L->inicio->prox;
      }
      else{
        ant->prox=temp->prox;
        L->fim = ant;
      }
      printf("O elemento %d foi removido da lista!", valor);
      free(temp);
      return;
    }
    ant=temp;
    temp=temp->prox;
    if(temp->chave!=valor){
      printf("O elemento %d não está presente lista!", valor);
      return;
    }
  }
  return;
}

int main(){

  Lista *L1 = criaLista();
  insere(L1,233);
  insere(L1,12);
  insere(L1,33);
  insere(L1,78);
  imprime(L1);

  return 0;
}

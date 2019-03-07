#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
  struct SNo *anterior;
}SNo;

typedef struct Lista{
  SNo *inicio;
  SNo *fim;
  int tam;
}Lista;

Lista *crialista(){
  Lista *L = (Lista*)malloc(sizeof(Lista));
  L->inicio=NULL;
  L->fim=NULL;
  L->tam=0;
  return L;
}

void insereInicio(Lista *L, int valor){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = L->inicio;
  L->inicio = novo;
  if(novo->prox == NULL){
    L->fim = novo;
  }
}

void insereFim(Lista *L, int valor){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  L->tam++;
  if(L->inicio==NULL){
    L->inicio = novo;
  }
  else{
    L->fim->prox = novo;
  }
  L->fim = novo;
}

  void tam(Lista *L){
    printf("\nO tamanho da lista é %d",L->tam);
  }

void divide_lista(Lista *L){
  if((L->tam)%2 == 0){

  }
  else{
    printf("\né impar");
  }

}

void insereD(Lista *L, int valor){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  L->tam++;
  novo->anterior = L->fim;
  if(L->inicio==NULL){
    L->inicio = novo;
  }
  else{
    L->fim->prox = novo;
  }
  L->fim = novo;
}

void imprime(Lista *L){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Lista vazia!");
    return;
  }
  while(temp != NULL){
    printf("%d ",temp->chave);
    temp = temp->prox;
  }
  return;
}

void busca(Lista *L, int valor){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Lista vazia!");
    return;
  }
  while(temp != NULL){
    if(temp->chave==valor){
      printf("O elemento %d está na Lista!",valor);
      return;
    }
    temp = temp->prox;
  }
  printf("O elemento %d não está na Lista!",valor);
  return;
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
        if(temp==L->fim){
          // ant->prox=temp->prox;
          L->fim = ant;
        }
        ant->prox=temp->prox;
      }
      printf("O elemento %d foi removido da lista!\n", valor);
      free(temp);
      L->tam--;
      return;
    }
    ant=temp;
    temp=temp->prox;
  }
  printf("O elemento %d não está presente na lista!\n", valor);
  return;
}

int soma_media(Lista *L){
  SNo *temp = L->inicio;
  float soma = 0;
  float media = 0;
  if(temp == NULL){
    printf("Lista vazia!");
    return 0;
  }
  while(temp != NULL){
    soma+=temp->chave;
    temp = temp->prox;
  }
  media = soma/L->tam;
  printf("A soma é: %.2f\n",soma);
  printf("A media é: %.2f\n",media);
  return 1;
}

void maior_menor(Lista *L){
  SNo *temp = L->inicio;
  int maior=-999999;
  int menor=999999;
  if(temp == NULL){
    printf("Lista vazia!");
    return;
  }
  while(temp != NULL){
    if(maior<temp->chave){
      maior = temp->chave;
    }
    if(menor>temp->chave){
      menor = temp->chave;
    }
    temp = temp->prox;
  }
  printf("Maior: %d\n",maior);
  printf("Menor: %d\n",menor);
  return;
}

void junta_lista(Lista *L0,Lista *L1){
  L0->fim->prox = L1->inicio;
  L1->fim->prox = L0->inicio;
}

void imprime_circular(Lista *L){//enviar
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  else{
    SNo *aux = temp->prox;
    if(aux==NULL){//imprime quando so tem 1 elemento na lista
      printf("%d ", temp->chave);
      return;
    }
    printf("%d ",temp->chave);
    while(aux!=temp){
      printf("%d ", aux->chave);
      aux = aux->prox;
    }
  }
}

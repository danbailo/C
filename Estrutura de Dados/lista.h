#include<stdio.h>
#include<stdlib.h>

typedef struct SNo {
  int chave;
  struct SNo *prox;
  struct SNo *anterior;
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

void insereqq(Lista *L, int valor, int ref){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  SNo *temp = L->inicio;
  novo->chave = valor;
  while(temp!=NULL){
    if(temp->chave<=ref){
      novo->prox = temp;
    }
  }
}

void insereInicio(Lista *L,int valor){
  SNo *novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = L->inicio;
  L->inicio = novo;
  if(novo->prox == NULL){
    L->fim = novo;
  }
}

void insereFim(Lista *L,int valor){
  SNo* novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  if(L->inicio==NULL){//Primeira inserção;
    L->inicio = novo;
  }
  else{
    L->fim->prox = novo;
  }
  L->fim = novo;
}

void insere_dupla(Lista *L,int valor){
  SNo* novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  novo->prox = NULL;
  novo->anterior = L->fim;
  if(L->inicio==NULL){//Primeira inserção;
    L->inicio = novo;
  }
  else{
    L->fim->prox = novo;
  }
  L->fim = novo;
  L->tam++;
}

void insere_circular(Lista *L,int valor){//enviar bruno
  SNo* novo = (SNo*)malloc(sizeof(SNo));
  novo->chave = valor;
  if(L->inicio==NULL){//Primeira inserção;
    novo->prox = NULL;
    L->inicio = novo;
    L->fim = novo;
  }
  else{
    novo->prox = L->inicio;
    L->fim->prox = novo;
    L->fim = novo;
  }
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

void imprime_dupla(Lista *L){
  SNo *tempAnt = L->fim;
  if(tempAnt == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  printf("TempAnt:");
  while(tempAnt!=NULL){
    printf("%d ", tempAnt->chave);
    tempAnt = tempAnt->anterior;
  }
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

void busca_dupla(Lista *L, int valor){
  SNo *temp = L->inicio;
  SNo *tempAnt = L->fim;
  if( temp == NULL && tempAnt == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  while(temp!=NULL || tempAnt!=NULL){
    if(temp->chave==valor){
      printf("\n%d Está na lista e foi encontrado com o 'temp'", valor);
      return;
    }
    else if(tempAnt->chave==valor){
      printf("\n%d Está na lista e foi encontrado com o 'tempAnt'", valor);
      return;
    }
    temp = temp->prox;
    tempAnt = tempAnt->anterior;
  }
  printf("\nO elemento %d não está na lista!", valor);
}

void busca_circular(Lista *L, int valor){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Não há nós presentes na lista!\n");
    return;
  }
  else{
    while(temp!=L->fim){
      if(temp->chave==valor){
        printf("\n%d Está na lista!", valor);
        return;
      }
      else{
        printf("\nO elemento %d não está na lista!", valor);
        return;
      }
      temp = temp->prox;
    }
  }
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
      return;
    }
    ant=temp;
    temp=temp->prox;
  }
  printf("O elemento %d não está presente na lista!\n", valor);
  return;
}

// void remover_dupla(Lista *L, int valor){
//   SNo *temp = L->inicio;
//   SNo *tempAnt = L->fim;
//   SNo *Aux = NULL;
//   if((temp == NULL) && (tempAnt == NULL)){
//     printf("Não há nós presentes na lista!\n");
//     return;
//     while((temp == NULL) || (tempAnt == NULL)){
//       if(temp->chave==valor){
//         if(temp==L->inicio){
//           L->inicio=L->inicio->prox;
//           tempAnt->anterior = NULL;
//         }
//
//       }
//       if(tempAnt->chave==valor){
//
//       }
//       ant=temp;
//       temp=temp->prox;
//     }
//     printf("O elemento %d não está presente na lista!\n", valor);
//     return;
// }

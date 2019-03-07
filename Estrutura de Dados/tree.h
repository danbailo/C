#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *FE;
  struct SNo *FD;
}SNo;

SNo *Raiz=NULL;

void preOrdem(SNo *R){
  if(R==NULL)
    return;

  printf("\n%i",R->chave);
  preOrdem(R->FE);
  preOrdem(R->FD);
}

void posOrdem(SNo *R){
  if(R==NULL)
    return;

  posOrdem(R->FE);
  posOrdem(R->FD);
  printf("\n%i",R->chave);
}

void emOrdem(SNo *R){
  if(R==NULL)
    return;

  emOrdem(R->FE);
  printf("%i\n",R->chave);
  emOrdem(R->FD);
}

void insere(SNo *R, int valor, SNo *Pai){
  if(R==NULL){//condicao de parada
    SNo *Novo = (SNo *)malloc(sizeof(SNo));
    Novo->chave = valor;
    Novo->FD = NULL;
    Novo->FE = NULL;
    if(Pai == NULL){
      Raiz = Novo;
      return;
    }
    else if(valor > Pai->chave)
      Pai->FD = Novo;
    else if(valor < Pai->chave)
      Pai->FE = Novo;
  }
  else if(valor > R->chave){
    insere(R->FD, valor, R);
  }
  else if(valor < R->chave){
    insere(R->FE, valor, R);
  }
  else{
    printf("\nO elemento já está na árvore!");
    return;
  }
}

int busca(SNo *R, int valor){
  if(R==NULL){//Condição de parada;
    printf("\nO elemento %d não está na árvore!", valor);
    return 0;
  }
  else if(valor > R->chave){
    busca(R->FD, valor);
    // return 0;
  }
  else if(valor < R->chave){
    busca(R->FE, valor);
    // return 0;
  }
  else{
    printf("\nO elemento %d está na árvore!", valor);
    return 1;
  }
  return 0;
}

int maiorINT(SNo *R){//maior elemento com função int;
  if(R==NULL)//arvore vazia;
    return 0;

  if(R->FD==NULL){//Condição de parada;
    return R->chave;
  }
  return maiorINT(R->FD);//retornar a empilhada das recursões;
}

SNo* maior(SNo *R){
  if(R==NULL)//arvore vazia;
    return NULL;

  if(R->FD==NULL){//Condição de parada;
    return R;
  }
  return maior(R->FD);
}

void printMaior(SNo *R){
  if(R==NULL){
    printf("Árvore vazia!");
    return;
  }
  printf("\nO maior elemento da árvore é %d",R->chave);
}

SNo* menor(SNo *R){
  if(R==NULL)//arvore vazia;
    return NULL;

  if(R->FE==NULL){//Condição de parada;
    return R;
  }
  return menor(R->FE);
}

void printMenor(SNo *R){
  if(R==NULL){
    printf("Árvore vazia!");
    return;
  }
  if(R==NULL)
    return;
  printf("\nO menor elemento da árvore é %d",R->chave);
}

int altura(SNo *R){
  int AD,AE;

  if(R==NULL)
    return 0;

  AD = altura(R->FD);
  AE = altura(R->FE);

  if(AD>AE){
    // printf("A altura da árvore é %d",AD);
    return (AD+1);
  }
  else{
    // printf("A altura da árvore é %d",AE);
    return (AE+1);
  }
}

void printAltura(){
  printf("\nA altura da árvore é %d",altura(Raiz));
}

void remover(SNo *R, int valor){

  if( 0 == 1){
    printf("a miseravi");
    // if(R->FD == NULL && R->FE == NULL){//nó folha;
    // }
  }
}

SNo* abb_retira(SNo* R, int valor){
  if (R == NULL)
    return NULL;
  else if (R->chave > valor)
    R->FE = abb_retira(R->FE, valor);
  else if (R->chave < valor)
    R->FD = abb_retira(R->FD, valor);
  else { /* achou o nó a remover */
    if (R->FE == NULL && R->FD == NULL) {/* nó sem filhos */
      free (R);
      R = NULL;
    }
    else if (R->FE == NULL) {/* nó só tem filho à direita */
      SNo* temp = R;
      R = R->FD;
      free (temp);
    }
    else if (R->FD == NULL) {/* só tem filho à esquerda */
      SNo* temp = R;
      R = R->FE;
      free (temp);
    }
    else {/* nó tem os dois filhos */
      SNo* aux = R->FE;
      while (aux->FD != NULL) {
        aux = aux->FD;
    }
    R->chave = aux->chave; /* troca os valores dos nós */
    aux->chave = valor;
    R->FE = abb_retira(R->FE,valor);
    }
  }
  return R;
}

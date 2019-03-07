#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10

typedef struct SNo{
  struct SNo *prox;
  int chave;
}SNo;

typedef struct Fila{
  SNo *Inicio;
  SNo *Fim;
}Fila;

Fila *criafila(){
  Fila *F = (Fila*)malloc(sizeof(Fila));
  F->Inicio = NULL;
  F->Fim = NULL;
  return F;
}

void insere_ordenado(Fila *F, int valor){
  SNo *Aux = F->Inicio;
  SNo *Ant = NULL;

  SNo *Novo = (SNo *) malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox= NULL;

  if (F->Inicio == NULL){
      F->Inicio = Novo;
      F->Fim = Novo;
  }
  else if (Aux->chave > Novo->chave ){
         F->Inicio = Novo;
         Novo->prox = Aux;
  }
  else{
    while((Aux != NULL) && (Aux->chave < Novo->chave)){
      Ant = Aux;
      Aux = Aux->prox;
    }
    Ant->prox = Novo;
    Novo->prox = Aux;
  }
}

void bucket(int vetor[], int tam_vetor, Fila *B[], int tam_B){

  float maior=-99999;
  float menor= 99999;
  float divisor;
  int i,j;

  for(i=0; i<tam_vetor; i++){
    if(maior < vetor[i]){
      maior = vetor[i];
    }
    if(menor > vetor[i]){
      menor = vetor[i];
    }
  }

  divisor = ceil((maior)/TAM);

  // insere_ordenado(B[5],10);
  // printf("%d ", B[5]->Inicio->chave);

  for(i=0; i<10; i++){
    j = floor(vetor[i]/divisor);
  }

  printf("%d ",vetor[5]);

  printf("\n");
  // printf("maior %.0f", maior);
  // printf("\nmenor %.0f", menor);
  // printf("\ndivisor %.0f\n", divisor);
}

int main(){
  int vetor[]={22,45,19,8,10,6,72,81,33,18};
  Fila *B[TAM];

  for(int j=0; j<TAM; j++){
    B[j]=criafila();
  }

  // insere_ordenado(B[5],253);
  // printf("%d ", B[5]->Inicio->chave);
  // printf("\n");

  // for(int j=0; j<TAM; j++){
  //   printf("%d", B[j]->Inicio->chave);
  // }

  printf("Vetor antes da ordenação: ");
  for(int i=0; i<10; i++){
    printf("%i ", vetor[i]);
  }
  printf("\n");

  bucket(vetor,10,B,10);

  // printf("Vetor depois da ordenação: ");
  // for(int i=0; i<10; i++){
  //   imprime(B[i]);
  // }
  // printf("\n");
  // insere_ordenado(B[1],24);
  // imprime(B[2]);

  return 0;
}

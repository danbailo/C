#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 15

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;

typedef struct Fila{
  SNo *Inicio;
  SNo *Fim;
}Fila;

Fila *criaFila(){
  Fila* F = (Fila*)malloc(sizeof(Fila));
  F->Inicio = NULL;
  F->Fim = NULL;
  return F;
}

void insere_ordenado(Fila *F,int valor){
  SNo *Aux = F->Inicio;
  SNo *Ant = NULL;

  SNo *Novo = (SNo *) malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox= NULL;

  if (F->Inicio == NULL){
      F->Inicio = Novo;
      F->Fim = Novo;
  }
  else if (Aux->chave > Novo->chave  || Aux->chave == Novo->chave){
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

int desenfileira(Fila *F, int vetor[],int c) {
    SNo *Temp = F->Inicio;
    SNo *Aux = NULL;

    if(F->Inicio == NULL) {
        return c;
    }
    while(Temp != NULL) {
        vetor[c]= Temp->chave;
        Aux = Temp;
        Temp = Temp->prox;
        free(Aux);
        c++;
    }
    return c;
}

void bucket(Fila *B[], int tam_vetor_fila, int vetor[], int tamanho_vetor){
  int i,j=0,c=0, maior =-999999999;
  int casa,pos,exp;

  for(i=0; i<tamanho_vetor; i++){
    if(maior<vetor[i]){
      maior=vetor[i];
    }
  }

  casa = maior;
  while(casa>0){
    casa = (casa/10);
    c++;
  }

  exp =(pow(10,(c-1)));

  for(i=0;i<TAM;i++){
    pos = vetor[i]/exp;
    insere_ordenado(B[pos],vetor[i]);
  }
  for(i=0;i<tam_vetor_fila;i++){
    j = desenfileira(B[i],vetor,j);
  }
}

int main(){

  int vetor[] = {-123,345,7444,982225,2,424,-56,91,1413,1,12323,1413,32,90,111};

  Fila *B[10];

  for(int i=0;i<10;i++){
      B[i] = criaFila();
  }
  printf("Vetor: ");
  for (int i=0;i<TAM;i++){
      printf("%d ",vetor[i]);
  }
  printf("\n");

  printf("\n");

  bucket(B,10,vetor,TAM);

  printf("Vetor ordenado: ");
  for (int i=0;i<TAM;i++){
      printf("%d ",vetor[i]);
  }
  printf("\n");

  return 0;
}

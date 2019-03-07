#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
    int chave;
    struct SNo *FE, *FD;
}SNo;

SNo *raiz = NULL;

SNo* criarNo(int valor){
   SNo *Novo = (SNo *)malloc(sizeof(SNo));
   Novo->chave = valor;
   Novo->FD = NULL;
   Novo->FE = NULL;
   return Novo;
}

void insere3(SNo *R, int valor) {
   if(R->chave>valor){
       if(R->FD==NULL){
           R->FD=criarNo(valor);
       }
       else{
           insere3(R->FD,valor);
       }
   }
   else if(R->chave<valor){
       if(R->FE==NULL){
           R->FE=criarNo(valor);
       }
       else{
           insere3(R->FE,valor);
       }
   }
   else{
       printf("Jah existe!\n");
   }
}

void emOrdem(SNo *raiz){
  if(raiz == NULL)
    return;

  emOrdem(raiz->FE);
  printf("%d",raiz->chave);
  emOrdem(raiz->FD);
}

int main(){

  insere3(raiz,15);
  insere3(raiz,13);
  insere3(raiz,112);
  insere3(raiz,10);
  insere3(raiz,15);

  emOrdem(raiz);

}

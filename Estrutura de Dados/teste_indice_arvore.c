#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  struct No *esquerda;
  struct No *direita;
  int chave;
}No;

No *raiz = NULL;

No *cria_No(int valor){
  No *No_arv = (No*)malloc(sizeof(No));
  No_arv->chave = valor;
  No_arv->esquerda = NULL;
  No_arv->direita = NULL;

  return No_arv;
}

// funcao que insere um No na arvore
No *insere(No *r, int valor){
  if(raiz == NULL){//primeira insercao
    return raiz = cria_No(valor);
  }
  if(r == NULL){
    return cria_No(valor);
  }
  if(valor < r->chave){
    r->esquerda = insere(r->esquerda,valor);
  }
  else if(valor > r->chave){
    r->direita = insere(r->direita,valor);
  }
  else{
    printf("o valor ja esta na arvore\n");
    return r;
  }
  return r;
}

void busca(No *r, int valor){
  if(r == NULL){//condicao de parada
    printf("\n%d nao está na arvore!",valor);
    return;
  }
  else if(r->chave > valor){
    busca(r->esquerda,valor);
  }
  else if(r->chave < valor){
    busca(r->direita,valor);
  }
  else{//condicao de parada
    printf("\n%d elemento está na árvore!",valor);
    return;
  }
}

void remover(No **pRaiz, int numero){

  if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
      printf("\n%d nao existe na arvore!\n",numero);
      return;
  }
  if(numero < (*pRaiz)->chave){
    remover(&(*pRaiz)->esquerda, numero);
  }
  else if(numero > (*pRaiz)->chave){
    remover(&(*pRaiz)->direita, numero);
  }
  else{
    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
    No *pAux = *pRaiz;// quem programar No Embarcadero vai ter que declarar o pAux No inicio do void! :[
    if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){//no folha
      free(pAux);
      (*pRaiz) = NULL;
    }
    else{// so tem o filho da direita
      if ((*pRaiz)->esquerda == NULL){
        (*pRaiz) = (*pRaiz)->direita;
        pAux->direita = NULL;
        free(pAux);
        pAux = NULL;
      }
      else{//so tem filho da esquerda
        if ((*pRaiz)->direita == NULL){
          (*pRaiz) = (*pRaiz)->esquerda;
          pAux->esquerda = NULL;
          free(pAux);
          pAux = NULL;
        }
        else{//Escolhi fazer o maior filho direito da subarvore esquerda.
          No *eAux = (*pRaiz)->esquerda;
          pAux = eAux;
          No *dAux = (*pRaiz)->direita;
          No *iAux = eAux->direita;
          eAux->direita = dAux;
          //insere o iaux no daux
          if(iAux!=NULL){
            //insere_no(daux,iaux);
            // printf("%i %i\n",eAux->direita->chave,dAux->chave);
            // printf("iAUX:%d\n",iAux->chave);
            while(dAux!=NULL){
              if(iAux->chave < eAux->chave){
                if(eAux->esquerda == NULL){
                  eAux->esquerda = iAux;
                  break;
                }
                else{
                  eAux = eAux->esquerda;
                }
              }
              else{
                if(eAux->direita == NULL){
                  eAux->direita = iAux;
                  break;
                }
                else{
                  eAux = eAux->direita;
                }
              }
            }
          }
          // printf("AUX CHAVE:%d",eAux->chave);
          free((*pRaiz));
          *pRaiz = pAux;
        }
      }
    }
  }
}

void pre_ordem(No *r){
  if(r!=NULL){ //cp
    printf("\n%d",r->chave);
    pre_ordem(r->esquerda);
    pre_ordem(r->direita);
  }
  if(raiz == NULL)
    printf("Nenhum elemento foi inserido na árvore!\n");

  return;
}

void em_ordem(No *r){
  if(r!=NULL){ //cp
    em_ordem(r->esquerda);
    printf("\n%d",r->chave);
    em_ordem(r->direita);
  }

  if(raiz == NULL)
    printf("Nenhum elemento foi inserido na árvore!\n");

  return;
}

void pos_ordem(No *r){
  if(r!=NULL){ //cp
    pos_ordem(r->esquerda);
    pos_ordem(r->direita);
    printf("\n%d",r->chave);
  }

  if(raiz == NULL)
    printf("Nenhum elemento foi inserido na árvore!\n");

  return;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  struct no *direito;
  struct no *esquerdo;
  int chave;
}no;

no *raiz = NULL;

void pre_ordem(no *r){

  if(r!=NULL){
    printf("%d\n",r->chave);
    pre_ordem(r->esquerdo);
    pre_ordem(r->direito);
  }

  if(raiz == NULL){
    printf("arvore vazia!\n");
    return;
  }
}

no *novo_no(int valor){
  no *temp = (no*)malloc(sizeof(no));
  temp->chave = valor;
  temp->direito = temp->esquerdo = NULL;
  return temp;
}

no *insere(no *r, int valor){
  if(raiz == NULL){//primeira insercao
    return raiz = novo_no(valor);
  }
  if(r == NULL){
    return novo_no(valor);
  }
  if(valor < r->chave){
    r->esquerdo = insere(r->esquerdo,valor);
  }
  else if(valor > r->chave){
    r->direito = insere(r->direito,valor);
  }
  else{
    printf("o valor ja esta na arvore\n");
    return r;
  }
  return r;
}

no *busca(no* r, int valor){
  if(r==NULL){//Condição de parada;
    printf("O elemento %d não está na árvore!\n", valor);
    return NULL;
  }
  else if(valor < r->chave){
    busca(r->esquerdo,valor);
  }
  else if(valor > r->chave){
    busca(r->direito,valor);
  }
  else
    printf("O elemnto %d esta na arvore!\n",valor);

  return r;
}

int maior_elemento(no *r){//maior elemento com função int;
  if(r==NULL)//arvore vazia;
    return 0;

  if(r->direito==NULL){//Condição de parada;
    return r->chave;
  }
  return maior_elemento(r->direito);//retornar a empilhada das recursões;
}

int menor_elemento(no *r){//maior elemento com função int;
  if(r==NULL)//arvore vazia;
    return 0;

  if(r->esquerdo==NULL){//Condição de parada;
    return r->chave;
  }
  return menor_elemento(r->esquerdo);//retornar a empilhada das recursões;
}

//funcao para remover um paciente por codigo
void remover(no **r, int valor){

  if(*r == NULL){   // esta verificacao serve para caso o valor nao exista na arvore.
      printf("\n%d nao existe na arvore!\n",valor);
      return;
  }
  if(valor < (*r)->chave){
    remover(&(*r)->esquerdo, valor);
  }
  else if(valor > (*r)->chave){
    remover(&(*r)->direito, valor);
  }
  else{
    // se nao eh menor nem maior, logo, eh o valor que estou procurando! :)
    no *pAux = *r;// quem programar No Embarcadero vai ter que declarar o pAux No inicio do void! :[
    if (((*r)->esquerdo == NULL) && ((*r)->direito == NULL)){//no folha
      free(pAux);
      (*r) = NULL;
    }
    else{// so tem o filho da direito
      if ((*r)->esquerdo == NULL){
        (*r) = (*r)->direito;
        pAux->direito = NULL;
        free(pAux);
        pAux = NULL;
      }
      else{//so tem filho da esquerdo
        if ((*r)->direito == NULL){
          (*r) = (*r)->esquerdo;
          pAux->esquerdo = NULL;
          free(pAux);
          pAux = NULL;
        }
        else{//Escolhi fazer o maior filho direito da subarvore esquerdo.
          no *eAux = (*r)->esquerdo;
          pAux = eAux;
          no *dAux = (*r)->direito;
          no *iAux = eAux->direito;
          eAux->direito = dAux;
          //insere o iaux no daux
          if(iAux!=NULL){
            //insere_no(daux,iaux);
            while(dAux!=NULL){
              if(iAux->chave < eAux->chave){
                if(eAux->esquerdo == NULL){
                  eAux->esquerdo = iAux;
                  break;
                }
                else{
                  eAux = eAux->esquerdo;
                }
              }
              else{
                if(eAux->direito == NULL){
                  eAux->direito = iAux;
                  break;
                }
                else{
                  eAux = eAux->direito;
                }
              }
            }
          }
          // printf("AUX CHAVE:%d",eAux->chave);
          free((*r));
          *r = pAux;
        }
      }
    }
  }
}

int altura(no *r){
  int altura_direito,altura_esquerdo;

  if(r==NULL)//condicao de parada
    return 0;

  altura_direito = altura(r->direito);
  altura_esquerdo = altura(r->esquerdo);

  if(altura_direito>altura_esquerdo){
    // printf("A altura da árvore é %d",AD);
    return (altura_direito+1);
  }
  else{
    // printf("A altura da árvore é %d",AE);
    return (altura_esquerdo+1);
  }
}

int main(){

  insere(raiz, 14);
  insere(raiz, 6);
  insere(raiz, 19);
  insere(raiz, 27);
  insere(raiz, 34);
  insere(raiz, 1);
  insere(raiz, 34);
  pre_ordem(raiz);
  printf("altura:%d\n",altura(raiz));

  busca(raiz,14);
  busca(raiz,1);
  busca(raiz,34);
  busca(raiz,233);

  printf("maior:%d\n",maior_elemento(raiz));
  printf("menor:%d\n",menor_elemento(raiz));

  printf("\n");
  remover(&raiz,14);
  pre_ordem(raiz);

  printf("\n");
  remover(&raiz,19);
  pre_ordem(raiz);


  return 0;
}

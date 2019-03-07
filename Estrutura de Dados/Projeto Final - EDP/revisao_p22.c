#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  struct no *esquerda;
  struct no *direita;
  int chave;
}no;

struct arvore{
  no *raiz;
}arvore;

no *cria_no(int valor){
  no *no_arv = (no*)malloc(sizeof(no));
  no_arv->chave = valor;
  no_arv->esquerda = NULL;
  no_arv->direita = NULL;

  return no_arv;
}

// funcao que insere um no na arvore
void insere(no *no_arvore, int valor, no *pai) {
  if(arvore.raiz == NULL) { // condicao de parada
    arvore.raiz = cria_no(valor);
  }
  else{
    if(no_arvore == NULL) { // condicao de parada
      no_arvore = cria_no(valor);
      if(pai == NULL) {
        arvore.raiz = NULL;
        return;
      }
      else if(valor > pai->chave)
        pai->direita = no_arvore;
      else if(valor < pai->chave)
        pai->esquerda = no_arvore;

      printf("PAI: %d\n",pai->chave);
    }
    else if(valor > no_arvore->chave) {
      insere(no_arvore->direita, valor, no_arvore);
    }
    else if(valor < no_arvore->chave) {
      insere(no_arvore->esquerda, valor, no_arvore);
    }
    else {
      printf("O elemento já está na árvore!\n");
    }
  }
}

void pre_ordem(no* no_arvore){
  if(no_arvore==NULL)
    return;

  printf("\n%d",no_arvore->chave);
  pre_ordem(no_arvore->esquerda);
  pre_ordem(no_arvore->direita);
}

void em_ordem(no* no_arvore){
  if(no_arvore==NULL)
    return;

  em_ordem(no_arvore->esquerda);
  printf("\n%d",no_arvore->chave);
  em_ordem(no_arvore->direita);
}

void pos_ordem(no* no_arvore){
  if(no_arvore==NULL)
    return;

  pos_ordem(no_arvore->esquerda);
  pos_ordem(no_arvore->direita);
  printf("\n%d",no_arvore->chave);
}

int main(){

  insere(arvore.raiz, 15, NULL);
  insere(arvore.raiz, 11, NULL);
  insere(arvore.raiz, 16, NULL);
  insere(arvore.raiz, 10, NULL);
  insere(arvore.raiz, 9, NULL);

  printf("PRE-ORDEM:");
  pre_ordem(arvore.raiz);
  printf("\n");

  printf("EM-ORDEM:");
  em_ordem(arvore.raiz);
  printf("\n");

  printf("POS-ORDEM:");
  pos_ordem(arvore.raiz);
  printf("\n");

  return 0;
}

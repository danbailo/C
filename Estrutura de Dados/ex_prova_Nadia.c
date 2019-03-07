#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNo{
    char chave;
    struct SNo *prox;
}SNo;

 typedef struct Pilha{
    SNo *topo;
 }Pilha;

 Pilha * CriaPilha( ){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
 }

 void empilha(Pilha *pilha, char c){
    SNo *novo = (SNo*) malloc(sizeof(SNo));
    novo->chave = c;
    //verifica se a pilha estah vazia
    if( pilha->topo == NULL ){
        novo->prox = NULL;
        pilha->topo = novo;
        return;
    }else{
        novo->prox = pilha->topo;
        pilha->topo = novo;
        return;
    }
 }

 void desempilha(Pilha *pilha){
     SNo *Aux = pilha->topo;
    //verifica se a pilha estah vazia
    if(pilha->topo == NULL){
        return;
    }else{
        pilha->topo = pilha->topo->prox;
        free(Aux);
    }
 }


 int verifica(char e[], Pilha *p){
    int i;
    for(i=0;i<strlen(e);i++){

        if((e[i] == '(') || (e[i] == '[') ||( e[i] == '{')){
            empilha(p, e[i]);
        }else{
            if(((e[i] == ')' ) || (e[i] == ']') || (e[i] == '}')) && (p->topo == NULL)){
            return 0;
            }else {
                if((e[i] == ')') && (p->topo->chave == '(')){
                    desempilha(p);
                }else{
                    if((e[i] == '}') && (p->topo->chave == '{')){
                        desempilha(p);
                    }else{
                        if((e[i] == ']') && (p->topo->chave == '[')){
                            desempilha(p);
                        }
                    }
                }

            }

        }
    }
    if( p->topo == NULL){
        return 1;
   }else{

    return 0;

   }


 }
int main(){

    Pilha *Pilha;
    Pilha = CriaPilha ();

    char exp[] = "[[]";

    if ( verifica( exp, Pilha) == 1){
        printf("Balanceada\n");
    }else{
        printf("Nao Balanceada\n");
    }
}

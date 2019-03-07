#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
    int chave;
    struct SNo *FE;
    struct SNo *FD;
}SNo;

SNo *Raiz = NULL;

void preOrdem(SNo *R) {
    if(R != NULL) { // cp
        printf("%d ", R->chave);
        preOrdem(R->FE);
        preOrdem(R->FD);
    }
}

void emOrdem(SNo *R) {
    if(R != NULL) { // cp
        emOrdem(R->FE);
        printf("%d ", R->chave);
        emOrdem(R->FD);
    }
}

void posOrdem(SNo *R) {
    if(R != NULL) { // cp
        posOrdem(R->FE);
        printf("%d ", R->chave);
        posOrdem(R->FD);
    }
}

SNo * busca(SNo *R, int valor) {

    if(R == NULL) { // cp
        printf("O elemento não estah na árvore!\n");
        return NULL;
    }
    else if(valor > R->chave)
        return busca(R->FD, valor);
    else if(valor < R->chave)
        return busca(R->FE, valor);
    else {
        printf("O elemento está contido na árvore!\n");
        return R;
    }
}

SNo *getMaior(SNo *R) {
    if(R == NULL) // arvore vazia
        return NULL;
    if(R->FD == NULL) //olha FD se esta NULL
        return R;
    return getMaior(R->FD); // anda com o R
}

// retornando um inteiro, ao invés de um SNo
int getMaior2(SNo *R) {
    if(R == NULL) // arvore vazia
        return 0;
    if(R->FD == NULL) //olha FD se esta NULL
        return (R->chave);
    return getMaior2(R->FD); // anda com o R
}

SNo *getMenor(SNo *R) {
    if(R == NULL) // arvore vazia
        return NULL;
    if(R->FE == NULL)
        return R;
    return getMenor(R->FE);
}

int altura(SNo *R) {
    int ae, ad;

    if(R == NULL) // cp
        return 0;

    ae = altura(R->FE);
    ad = altura(R->FD);
    if(ae > ad)
        return ae + 1;
    else
        return ad + 1;
}

// funcao para buscar o pai de um dado No
SNo *getPai(SNo *Pain, SNo *No) {
    if(Pain == NULL)
        return NULL;
    if(Pain->FE == No || Pain->FD == No)
        return Pain;
    else {
        if(No->chave < Pain->chave)
            return getPai(Pain->FE, No);
        else if(No->chave > Pain->chave)
            return getPai(Pain->FD, No);
    }
}

// funcao que insere um no na arvore
void insere(SNo *R, int valor, SNo *Pai) {

    if(R == NULL) { // condicao de parada
        SNo *Novo = (SNo *)malloc(sizeof(SNo));
        Novo->chave = valor;
        Novo->FD = NULL;
        Novo->FE = NULL;
        if(Pai == NULL) {
            Raiz = Novo;
            return;
        }
        else if(valor > Pai->chave)
            Pai->FD = Novo;
        else if(valor < Pai->chave)
            Pai->FE = Novo;
    }
    else if(valor > R->chave) {
        insere(R->FD, valor, R);
    }
    else if(valor < R->chave) {
        insere(R->FE, valor, R);
    }
    else {
        printf("O elemento já está na árvore!\n");
    }
}

// insere usando ponteiro duplo, passar localmente ou globalmente por parâmetro o endereço da &Raiz
void insere2(int valor, SNo **R){
    if(*R == NULL){
        *R = (SNo*) malloc(sizeof(SNo));
        *R->chave = valor;
        *R->FE = NULL;
        *R->FD = NULL;
    }
    else if(valor > (*R)->chave) //ando para direita
        insere2(valor, &(*R)->FD);
    else if(valor < (*R)->chave)  //ando para esquerda
        insere2(valor, &(*R)->FE);
    else  // elemento jah existe na arvore
        printf("O elemento %d ja esta contido na arvore.\n", (*R)->chave);
}


// outra forma de implementar a funcao insere
//SNo* criarNo(int valor){
//    SNo *Novo = (SNo *)malloc(sizeof(SNo));
//    Novo->chave = valor;
//    Novo->FD = NULL;
//    Novo->FE = NULL;
//    return Novo;
//}

//void insere3(SNo *R, int valor) {
//    if(R->chave>valor){
//        if(R->FD==NULL){
//            R->FD=criarNo(valor);
//        }
//        else{
//            insere3(R->FD,valor);
//        }
//    }
//    else if(R->chave<valor){
//        if(R->FE==NULL){
//            R->FE=criarNo(valor);
//        }
//        else{
//            insere3(R->FE,valor);
//        }
//    }
//    else{
//        printf("Jah existe!\n");
//    }
//}

int main() {

    insere(Raiz, 50, NULL);
    insere(Raiz, 85, NULL);
    insere(Raiz, 80, NULL);
    preOrdem(Raiz);
    printf("\n");
    emOrdem(Raiz);
    printf("\n");
    int temp = getMaior2(Raiz);
    printf("O maior elemento é: %d\n",temp);
    printf("%d\n", altura(Raiz));


    insere2(10, &Raiz)
    return 0;
}

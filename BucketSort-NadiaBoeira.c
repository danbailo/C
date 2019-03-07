#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct SNo{
        int chave;
        struct SNo *prox;
}SNo;

typedef struct Lista{
        SNo *Inicio;
        SNo *Fim;
}Lista;

Lista *crialista(){
        Lista *lista = (Lista *) (malloc(sizeof(Lista)));
        lista->Inicio = NULL;
        lista->Fim = NULL;

        return lista;
}

void enfileira(Lista *lista, int valor){
    SNo *Novo = (SNo *) malloc(sizeof(SNo));
    Novo->chave = valor;
    Novo->prox = NULL;

    if(lista->Inicio == NULL){
      lista->Inicio = Novo;
      lista->Fim = Novo;
      return;
    }else{
        lista->Fim->prox = Novo;
        lista->Fim = Novo;
        return;
    }
 }

void insereOrdenado(int valor, Lista *lista){
    SNo *Aux = lista->Inicio;
    SNo *Ant = NULL;

    SNo *Novo = (SNo *) malloc(sizeof(SNo));
    Novo->chave = valor;
    Novo->prox= NULL;

    //Verifica se a Lista est� Vazia
    if (lista->Inicio == NULL){
        lista->Inicio = Novo;
        lista->Fim = Novo;

     }else if (Aux->chave > Novo->chave ){
         lista->Inicio = Novo;
         Novo->prox = Aux;

     }else{
        while((Aux != NULL) && (Aux->chave < Novo->chave)){
            Ant = Aux;
            Aux = Aux->prox;
        }
        Ant->prox = Novo;
        Novo->prox = Aux;
        }
}

int desenfileira(Lista *lista, int vet[],int cont) {
    SNo *Temp = lista->Inicio;
    SNo *Aux = NULL;

    if(lista->Inicio == NULL) {
        return cont;
    }
    while(Temp != NULL) {
        vet[cont]= Temp->chave;
        //printf("\n%dL", Temp->chave);
        Aux = Temp;
        Temp = Temp->prox;
        free(Aux);
        cont++;
    }
    return cont;
}

void bucketsort(int vet[], int tam_vet, Lista *vet_lista[], int tam_vet_lista){
    int  i, j=0, k=0, maior, casa, exp, pos,cont = 0;
    // descobre o maior numero do vetor
    for(i=0; i< tam_vet; i++){
       if(i == 0){
        maior = vet[i];
       }else if (vet[i]>maior){
            maior = vet[i];
       }
    }
    //descobre a quantidade de casas do maior numero
    casa = maior;
    while(casa>0){
        casa = (casa/10);
        cont++;
    }

    exp =(pow(10,(cont-1)));

    for(i=0;i<tam_vet;i++){
        pos = vet[i]/exp;
        insereOrdenado(vet[i], vet_lista[pos]);
    }

    for(i=0;i<tam_vet_lista;i++){

      j =  desenfileira(vet_lista[i], vet, j);
    }
}

int main(){

    int vet[10] = {231,-403,3578,4556,12828,3,608889,1234,62098757,909},i;

    Lista *vet_lista[10];

    for(i=0;i<10;i++){
        vet_lista[i] = crialista();
    }
    printf("Antes de Ordenar Bucket: ");
    for (i=0;i<10;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");

    bucketsort(vet, 10, vet_lista, 10);

    printf("\n");
    printf("Depois de Ordenar Bucket: ");
    for (i=0;i<10;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

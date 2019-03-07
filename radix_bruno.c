#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define QTD_BUCKETS 10

typedef struct SNo{
        int chave;
        struct SNo *prox;
}SNo;

typedef struct Fila{
        SNo *Inicio;
        SNo *Fim;
}Fila;

// funcao insere alocando no final da lista
void insere(Fila *F,int valor){
    SNo *Novo = (SNo *) malloc(sizeof(SNo));
    Novo->chave = valor;
    Novo->prox = NULL;

    if(F->Inicio == NULL){
      F->Inicio = Novo;
      F->Fim = Novo;
      return;
    }else{
        F->Fim->prox = Novo;
        F->Fim = Novo;
        return;
    }

 }

void imprime(Fila *F) {
    SNo *temp = F->Inicio;

    if(temp == NULL) {
        printf("Nada a imprimir, balde vazio!\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ",temp->chave);
        temp = temp->prox;
    }
    printf("\n");
}

// inserir todos as chaves das Filas no vetor em uma nova ordem
int * varreFilas(Fila *vetorFilas[], int vet[]) {
	int i=0,f;
	for(f=0;f<10;f++){
		SNo *temp = vetorFilas[f]->Inicio;
		if(temp == NULL) {
        	//printf("V ");
    	}
    	while(temp != NULL) {
    		//printf("%d ",temp->chave);
       		vet[i] = temp->chave;
       		temp = temp->prox;
       		i++;
       }
    }
    return vet;
}

Fila *criaFilas(){
        Fila *F = (Fila *) malloc(sizeof(Fila));
        F->Inicio = NULL;
        F->Fim = NULL;

        return F;
}

Fila *desenfileira(Fila *vetorFilas[]){
	int f;
	for(f=0;f<10;f++){
		imprime(vetorFilas[f]);
		vetorFilas[f]->Inicio = NULL;
		vetorFilas[f]->Fim= NULL;
    }
    return vetorFilas;
}

int * radix(Fila *vetorFilas[], int vet[]){
	int i, j, maior=0, qtdDigitos=0, bucket;

	for(i=0; i<10; i++){
		if(vet[i]>maior){
			maior=vet[i];
		}
	}
	//printf("\nMAIOR: %d\n",maior);

	while(maior>0){
		maior=maior/10;
		qtdDigitos++;
	}
	//printf("QTD DIGITOS: %d \n",qtdDigitos);

	for(j=0;j<qtdDigitos;j++){
	 	for(i=0;i<10;i++){
	 		bucket = (vet[i] / (int)pow(10.0, j) ) % 10;
	 		insere(vetorFilas[bucket],vet[i]);
		}
		vet = varreFilas(vetorFilas,vet);
		printf("\nBUCKETS:\n", j);
		vetorFilas = desenfileira(vetorFilas);
		printf("\nITERATION %d - VETOR ORDENADO DEPOIS DE VARRER AS FILAS:\n", (j+1));
		for(i=0;i<10;i++){
			printf("%d ",vet[i]);
		}
		printf("\n");
	}
	return vet;
}

int main(){
	int vet[10] = {12,545,91,89,56,4,23,78,6,723},i,j;
    Fila *vetorFilas[QTD_BUCKETS];

    for(i=0;i<QTD_BUCKETS;i++)
       vetorFilas[i] = criaFilas();

	for(j=0;j<10;j++)
		printf("VETOR ORIGINAL: %d ",vet[j]);

	radix(vetorFilas, vet);
}

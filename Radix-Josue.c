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

// funcao insere alocando no final da lista
void insere(Lista *lista,int valor){
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

void imprime(Lista *lista) {
    SNo *temp = lista->Inicio;

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

int * varreFilas(Lista *vet_lista[], int vet[]) {
	int i=0,f;
	for(f=0;f<10;f++){
		SNo *temp = vet_lista[f]->Inicio;
		if(temp == NULL) {
        	//printf("Nada a remover da Fila %d, balde vazio!\n",f);
    	}
    	while(temp != NULL) {
       	 	//printf("%d ",temp->chave);
       		vet[i]= temp->chave;
       		temp = temp->prox;
       }
       i++;
    }

    return vet;
    printf("\n");
}

Lista *crialista(){
        Lista *lista = (Lista *) malloc(sizeof(Lista));
        lista->Inicio = NULL;
        lista->Fim = NULL;

        return lista;
}

int desenfileira(Lista *vet_lista[]){
	int i=0,f;
	for(f=0;f<10;f++){
		vet_lista[f]->Inicio = NULL;
		vet_lista[f]->Fim= NULL;
       i++;
    }
    imprime(vet_lista[f]);

}

void radix(Lista *vet_lista[], int vet[]){
	int i,maior=0,cont=-9,j,elv=1,num,pos,x=0,k, l,qtdDigitos=0,bucket;

	for(i=0; i<10; i++){
		if(vet[i]>maior){
			maior=vet[i];
		}
	}
	printf("\n%d\n",maior);

	while(maior>0){
		maior=maior/10;
		qtdDigitos++;
	}
	printf("%d \n",qtdDigitos);


	for(j=0;j<2;j++){
	 	for(i=0;i<10;i++){
	 		bucket=vet[i]%10;
	 		insere(vet_lista[bucket],vet[i]);
	 		vet[i]=vet[i]/10;
	 		printf("%d ",vet[i]);
		}
		printf("\n");
		vet = varreFilas(vet_lista,vet);

	}
	printf("\n");
	printf("\nBuckets: \n");
	for(i=0;i<10;i++){
		imprime(vet_lista[i]);
	}

	/*for(i=0; i<10; i++){
		 if(vet[i]>maior){
			maior=vet[i];
			}
		cont++;
		}
		printf("\n%d\n",maior);

    while(maior > 0){
        maior = maior/10;
        cont++;
    }
    printf("%d\n",cont);

	for(i=1;i<cont;i++){
		elv=elv*10;
		x=elv/10;
        printf("Pegando valores da casa de %d \n", x);
        for(j=0;j<10;j++){
            if(vet[j]<0)
            	num = vet[j]%elv;

            printf("Numero: %d | ", vet[j]);
            num = vet[j]%elv;
            pos = num/x;
            printf("pos %d\n", pos);
            insere(vet_lista[pos], vet[j]);
		}
		k = 0;
		l=0;

		printf("\n");
	}*/

}

int main(){

	int vet[10] = {12,545,91,89,56,4,23,78,6,723},i,j;
//12,545,91,89,56,4,23,78,6,723 2,5,1,9,6,4,3,8,6,3
    Lista *vet_lista[10];

    for(i=0;i<10;i++){
       vet_lista[i] = crialista();
    }

	for(j=0;j<10;j++){
		printf("%d ",vet[j]);
	}
	radix(vet_lista, vet);

}

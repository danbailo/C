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

Lista *crialista(){
        Lista *lista = (Lista *) malloc(sizeof(Lista));
        lista->Inicio = NULL;
        lista->Fim = NULL;

        return lista;
}

int desenfileira(Lista *lista){
    SNo *Temp;
    SNo *Aux = NULL;
    Temp = lista->Inicio;

    if ( lista->Inicio == NULL){
        //printf("Fila Vazia, nada para desenfileirar!\n");
        return;

    }else{
        if(lista->Inicio == lista->Fim){
            lista->Inicio = lista->Fim = NULL;
            Aux = Temp;
            free(Temp);
            return Aux->chave;
        }else{
            lista->Inicio = lista->Inicio->prox;
            Aux = Temp;
            free(Temp);
            return Aux->chave;
        }
    }
}

void radix(Lista *vet_lista[], int vet[]){
	int i,maior=0,cont=-9,j,elv=1,num,pos,x=0,k, l,c;
	for(i=0; i<10; i++){
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
           // if(vet[j]<0){
            //num = vet[j]%elv;
            //}
            //printf("Numero: %d | ", vet[j]);
            num = vet[j]%elv;
            pos = num/x;
            printf("%d - Posicao %d\n",c++, pos);
            insere(vet_lista[pos], vet[j]);

		}
		c=0;
		k = 0;
		l=0;
		/*do{
            while(vet_lista[l]->Inicio != NULL && k> 10){
               vet[k] = desenfileira(vet_lista[l]);

                printf("Algarismo %d\n", vet[k]);
               k++;
               l++;
            }
		}while(l<10);*/
		printf("\n");
}


}

int main(){

	int vet[10] = {12,545,91,89,56,4,23,78,6,1123},i,j;

    Lista *vet_lista[10];

    for(i=0;i<10;i++){
       vet_lista[i] = crialista();

    }
	for(j=0;j<10;j++){
		printf("%d ",vet[j]);
	}
	radix(vet_lista, vet);

	for(j=0;j<10;j++){
		printf("%d ",vet[j]);
	}


}


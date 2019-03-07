#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	int i;
	int pos;
	int valor;
	// int qtd=6;
	// Lista *vetor[6];
	int qtd;

	printf("Quantas listas deseja criar ? \n");
	scanf("%d",&qtd);
	Lista *vetor[qtd];
	printf("qtd:%d\n", qtd);
	for(i=0; i<qtd; i++){
		vetor[i] = criaLista();
	}
	insere(vetor[3],13);
	insere(vetor[3],23);
	insere(vetor[3],44);
	printf("\n");
	imprime(vetor[3]);
	printf("Digite a lista que você deseja remover o elemento:\n");
	scanf("%d",&pos);
	if(pos>qtd){
		printf("Impossível!");
		return 0;
	}
	printf("Digite o valor que você deseja remover:\n");
	scanf("%d",&valor);
	remover(vetor[pos],valor);
	// printf("O elemento %d não está contido na lista!",valor);
	// insere(vetor[3],45);
	// imprime(vetor[3]);
	// remover(vetor[3],12);


}

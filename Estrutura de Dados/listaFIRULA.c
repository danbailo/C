#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

void lista(Lista *vetor[], int qtd){

  // int i;
  int pos;
  int op;
  int valor;
  printf("O que deseja fazer ?\n");
  printf("[1]Inserir elementos\n");
  printf("[2]Imprimir elementos\n");
  printf("[3]Buscar elementos\n");
  printf("[4]Remover elementos\n");
  printf("[5]Sair\n");
  scanf("%d", &op);
  switch(op){
    case 1:
      printf("Digite a lista que você deseja manipular:\n");
      scanf("%d",&pos);
      if(pos>qtd){
        printf("Foram criadas somente %d listas!", qtd);
        return;
      }
      printf("Digite o valor no qual você deseja inserir:\n");
      scanf("%d",&valor);
      insere(vetor[pos],valor);
    break;

    case 2:
      // pos = qtd;
      printf("Digite a lista que você deseja imprimir:\n");
      scanf("%d",&pos);
      if(pos>qtd){
        printf("Foram criadas somente %d listas!", qtd);
        return;
      }
      imprime(vetor[pos]);
    break;

    case 3:
      printf("Digite a lista que você deseja buscar o elemento:\n");
      scanf("%d",&pos);
      if(pos>qtd){
        printf("Foram criadas somente %d listas!", qtd);
        return;
      }
      printf("Digite o valor que você deseja buscar:\n");
      scanf("%d",&valor);
      busca(vetor[pos],valor);
    break;

    case 4:
      printf("Digite a lista que você deseja remover o elemento:\n");
      scanf("%d",&pos);
      if(pos>qtd){
        printf("Foram criadas somente %d listas!", qtd);
        return;
      }
      printf("Digite o valor que você deseja remover:\n");
      scanf("%d",&valor);
      remover(vetor[pos],valor);
    break;

    case 5:
      printf("Saindo...");
      exit(1);
    break;

    default:
      printf("Por favor, digite uma opção valida!\n");
      return;
    break;
  }
}

int main(){

  int i;
  int qtd;
  int cont=-999;
  // int valor;

  printf("Digite quantas listas deseja criar:\n");
  do{
    scanf("%d",&qtd);
    if(qtd==0){
      printf("Digite um valor diferente de zero!\n");
    }
  }while(qtd==0);
	Lista *vetor[qtd];
	for(i=0; i<qtd; i++){
		vetor[i] = criaLista();
	}
  do{
    lista(vetor, qtd);
    printf("\nDeseja continuar ? [1]Sim,[2]Não\n");
    scanf("%d",&cont);
    if(cont==2)
      printf("Saindo...");
  }while(cont!=2);
}

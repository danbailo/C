#include <stdio.h>
#include <stdlib.h>

typedef struct SNo{
  int chave;
  struct SNo *prox;
}SNo;

SNo *Inicio = NULL;

int insere(int valor){
  SNo *Novo = (SNo *)malloc(sizeof(SNo));
  Novo->chave = valor;
  Novo->prox = Inicio;
  Inicio = Novo;
  return 1;
}

void imprime(){
  SNo *Temp = Inicio;
  if(Temp==NULL){
    printf("Nada para imprimir, a lista está vazia!\n");
    return;
  }
    while(Temp!=NULL){
      printf("%d ",Temp->chave);
      Temp=Temp->prox;
    }
}

int busca(int valor){
  SNo *Temp = Inicio;
  if(Temp==NULL){
    printf("Nada para buscar, a lista está vazia!\n");
    return 0;
  }
  while(Temp!=NULL){
  if(Temp->chave==valor){
      printf("\nO elemento %d ESTÁ na lista!",valor);
      return 1;
    }
    Temp=Temp->prox;
  }
  printf("\nO elemento %d NÃO ESTÁ na lista!",valor);
  return 0;
}

void remover(int valor){
  SNo *Temp = Inicio;
  SNo *Ant = NULL;
  if(Temp==NULL){
    printf("Nada para remover, a lista está vazia!\n");
    return;
  }
  while(Temp!=NULL){
  if(Temp->chave==valor){
    if(Temp==Inicio){
      Inicio=Inicio->prox;
    }
    else{
      Ant->prox=Temp->prox;
    }
      free(Temp);
      return;
    }
    Ant=Temp;
    Temp=Temp->prox;
  }
  return;
}

int main(){

  int op,n;

  printf("Digite a opção desejada\n");
  printf("[1]Inserir Elementos\n");
  printf("[2]Imprimir Elementos\n");
  printf("[3]Buscar Elementos\n");
  printf("[4]Remover Elementos\n");
  printf("[5]Sair\n");
  scanf("%d",&op);
  switch (op) {
    case 1:
    op=-999;
    system("clear");
    printf("Digite o valor que dejesa inserir na lista: ");
    scanf("%d",&n);
    insere(n);
    do{
      printf("Dejesa inserir mais valores na lista ? [1]Sim [0]Não\n");
      scanf("%d",&op);
      printf("\n");
      if(op==1){
        printf("Digite o valor que dejesa inserir na lista: ");
        scanf("%d",&n);
        insere(n);
      }
    }while(op!=0);
    system("clear");
    main();
    break;

    case 2:
    op=-999;
    printf("\n");
    imprime();
    printf("\n");
    main();
    printf("\n");
    break;

    case 3:
    op=-999;
    system("clear");
    printf("Digite o valor que dejesa buscar na lista: ");
    scanf("%d",&n);
    busca(n);
    do{
      printf("\nDejesa buscar mais valores na lista ? [1]Sim [0]Não\n");
      scanf("%d",&op);
      printf("\n");
      if(op==1){
        printf("Digite o valor que dejesa buscar na lista: ");
        scanf("%d",&n);
        busca(n);
      }
    }while(op!=0);
    system("clear");
    main();
    break;

    case 4:
    op=-999;
    printf("\nDigite o valor que dejesa remover na lista: ");
    scanf("%d",&n);
    remover(n);
    do{
      printf("\nDejesa remover mais valores na lista ? [1]Sim [0]Não\n");
      scanf("%d",&op);
      printf("\n");
      if(op==1){
        printf("Digite o valor que dejesa remover na lista: ");
        scanf("%d",&n);
        remover(n);
      }
    }while(op!=0);
    system("clear");
    main();
    break;

    case 5:
    system("clear");
    return 0;
    break;

    default :
    system("clear");
    printf("Por favor, digite uma opção válida!\n");
    main();
    break;
  }
  return 0;
}

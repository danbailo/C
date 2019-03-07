#include <stdio.h>
#include <stdlib.h>
// #include "revisao_p2.h"

int main(){

  int op,p,valor,cont=1;

  while(cont!=0){
    printf("Digite a opção desejada\n");
    printf("[1]Printar\n");
    printf("[2]Inserir\n");
    printf("[3]Buscar\n");
    printf("[4]Remover\n");
    printf("[5]Sair\n");
    scanf("%d",&op);
    printf("\n");

      switch (op) {

        case 1:
          // system("clear");
          printf("Deseja usar qual percurso?\n");
          printf("[1]Pre ordem\n");
          printf("[2]Em ordem\n");
          printf("[3]Pos ordem\n");
          scanf("%d",&p);
          if(p==1)
            pre_ordem(raiz);
          else if(p==2)
            em_ordem(raiz);
          else if(p==3)
            pos_ordem(raiz);
        break;

        case 2:
          printf("Digite o valor você deseja inserir na árvore:\n");
          printf("Valor: ");
          scanf("%d",&valor);
          insere(raiz,valor,NULL);
          printf("\n");
        break;

        case 3:
          printf("Digite o valor você deseja buscar na árvore:\n");
          printf("Valor: ");
          scanf("%d",&valor);
          busca(raiz,valor);
        break;

        case 4:
        printf("Digite o valor você deseja remover na árvore:\n");
        printf("Valor: ");
        scanf("%d",&valor);
        remover(&raiz,valor);
        break;

        case 5:
          printf("Saindo...");
          exit(1);
        break;

        default:
          printf("Por favor, digite uma opção valida!\n");
        break;
      }
    printf("\nDeseja continuar? [1]Sim ou [0]Não\n");
    scanf("%d",&cont);
    printf("\n");
    // system("clear");
    if(cont==0){
      printf("Saindo...");
      return cont;
    }
  }

  return 0;
}

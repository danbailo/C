#include <stdio.h>

int soma_valoresptr(int *a,int *b){
  printf("\na: %p\nb: %p",a,b);
  printf("\nO resultado da soma é %d",*a+*b);
  return (*a+*b);
}

int soma_valores(int a,int b){
  printf("\nO resultado da soma é %d",a+b);
  return (a+b);
}

int subtrai_valores(int a,int b){
  printf("\nO resultado da subtração é %d",a-b);
  return (a-b);
}

int multiplica_valores(int a,int b){
  printf("\nO resultado da multiplicação é %d",a*b);
  return (a*b);
}

int divide_valores(float a,float b){

  if(b==0){
    while(1){
      printf("\nDigite um valor diferente de zero!\n");
      scanf("%f",&b);
      if(b!=0){
        printf("\nO resultado da divisão é %.2f",a/b);
        break;
      }
    }
  }
  else{
    printf("\nO resultado da divisão é %.2f",a/b);
  }
  return (a/b);
}

int main(){

  int n1,n2;
  int op;
  int cont;

  do{
    printf("\nDigite dois valores:\n");scanf("%d%d", &n1,&n2);
    printf("\nDigite a operação que você deseja fazer:\n");
    printf("[1]Soma\n");
    printf("[2]Subtração\n");
    printf("[3]Multiplicação\n");
    printf("[4]Divisão\n");
    printf("[5]Soma ponteiros\n");
    scanf("%d", &op);
    switch (op) {
      case 1 :
      soma_valores(n1,n2);
      break;

      case 2:
      subtrai_valores(n1,n2);
      break;

      case 3:
      multiplica_valores(n1,n2);
      break;

      case 4:
      divide_valores(n1,n2);
      break;

      case 5:
      printf("\nn1: %p\nn2: %p",&n1,&n2);
      soma_valoresptr(&n1,&n2);
      break;

      default:
      while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5){
        printf("\nPor favor, digite alguma opção valida !\n");
        scanf("%d", &op);
        switch (op) {
          case 1 :
          soma_valores(n1,n2);
          break;

          case 2:
          subtrai_valores(n1,n2);
          break;

          case 3:
          multiplica_valores(n1,n2);
          break;

          case 4:
          divide_valores(n1,n2);
          break;

          case 5:
          soma_valoresptr(&n1,&n2);
          break;
        }
      }
    }
    printf("\n\nDeseja continuar, [1]Sim ou [2]Não ?");
    scanf("%d", &cont);
  }while(cont==1);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){

  char nome[32];
  int i;

  printf("Digite o nome da pessoa: ");
  gets(nome);
  printf("Digite a idade da pessoa: ");
  scanf("%d",&i);

  if(i>0 && i<=10){
    printf("O nome da pessoa é %s e deverá pagar R$30,00",nome);
  }
  else if(i>10 && i<=29){
    printf("O nome da pessoa é %s e deverá pagar R$60,00",nome);
  }
  else if(i>29 && i<=45){
    printf("O nome da pessoa é %s e deverá pagar R$120,00",nome);
  }
  else if(i>45 && i<=59){
    printf("O nome da pessoa é %s e deverá pagar R$150,00",nome);
  }
  else if(i>59 && i<=65){
    printf("O nome da pessoa é %s e deverá pagar R$250,00",nome);
  }
  else if(i>65){
    printf("O nome da pessoa é %s e deverá pagar R$400,00",nome);
  }
  else{
    printf("Não existe idade negativa!");
  }
}

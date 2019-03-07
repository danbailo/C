#include <stdio.h>

struct estrutura{
  char nome[32];
  int idade;

}teste;

int main() {

  printf("Digite um nome, seguido da idade:\n");
  gets(teste.nome);
  scanf("%d",&teste.idade);
  if(teste.idade > 0){
    printf("Você já bate punheta né safado ?");
  }
  else{
    printf("Nem tem pinto ainda kkk");
  }

  return 0;
}

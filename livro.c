//Exemplo de Deslocamento de bits
#include <stdio.h>

int main(void){
  unsigned int i;
  int j;

  i=1;
  //Deslocamentos à esquerda
  for(j=0;j<4;j++){
    i=i<<1; //Desloca i de 1 à esquerda que é o mesmo que multiplicar por 2
    printf("Deslocamento à esquerda %d: %d\n",j,i);
  }
  //Deslocamentos à direita
  for(j=0;j<4;j++){
    i=i>>1; //Desloca i de 1 à direita que é o mesmo que dividir por 2
    printf("Deslocamento à direita %d: %d\n",j,i);
  }
}

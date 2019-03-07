//Calcule a média de 3 sensores de temperatura utilizando funções;
#include <stdio.h>

float media(float *a, float *b, float *c){
  return (*a+*b+*c)/3;
}

int main() {

  float n1,n2,n3;

  for(int i=0; i<24; i++){
    for(int j=0; j<1; j++){
      printf("Digite três temperaturas em ºCelsius:\n");
      scanf("%f",&n1);scanf("%f",&n2);scanf("%f",&n3);
    }
    printf("A média da temperatura as %d;00hrs é %.2f ºC",i+1,media(&n1,&n2,&n3));
    printf("\n");
    printf("\n");
  }
  return 0;
}

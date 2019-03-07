#include <stdio.h>

int main(){

  float a,b;

  printf("Digite dois números\n");scanf("%f%f",&a,&b);

  //Isso funciona pois 0 em C é falso, e como é falso o if, vai direto pro else
  if(b){
    printf("\n%.2f\n",a/b);
  }
  else{
    printf("Não existe divisão por 0");
  }

}

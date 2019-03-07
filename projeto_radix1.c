//Nome: Daniel de Leon Bailo da Silva
//RGA: 201718050216
//RADIX SORT

#include <stdio.h>

int main(){
  //Declaração e atribuição do bucket para "segurar" os números para ordenar;
  int bucket[10]={0,1,2,3,4,5,6,7,8,9};
  //Declaração e atribuição do vetor que será ordenado;
  int vetor[12]={19,19800,2448,331,22,321,1110,533,424,825,626,7};
  //Declaração dos vetores que servirão para a manipulação das ordenações;
  int n[10];
  int m[10];
  int k[10];
  int l[10];
  //Declaração dos contadores de iterações;
  int i,j, cont = 0;

  printf("Vetor não ordenado: [ ");
  for(i=0; i<12; i++){
    printf("%d ",vetor[i]);
  }
  printf("]");
  printf("\n");

  for(i=0; i<10; i++){
    for(j=0; j<12; j++){
      if((vetor[j]%10)/1==bucket[i]){//Primeira passada para pegar somente o digito da unidade;
        n[cont] = vetor[j];
        cont++;
      }
    }
  }

  cont = 0;

  for(i=0; i<10; i++){
    for(j=0; j<12; j++){
      if((n[j]%100)/10==bucket[i]){//Segunda passada para pegar somente o digito da dezena;
        m[cont] = n[j];
        cont++;
      }
    }
  }

  cont = 0;

  for(i=0; i<10; i++){
    for(j=0; j<12; j++){
      if((m[j]%1000)/100==bucket[i]){//Terceira passada para pegar somente o digito da centena;
        k[cont] = m[j];
        cont++;
      }
    }
  }

  cont = 0;

  for(i=0; i<10; i++){
    for(j=0; j<12; j++){
      if((k[j]%10000)/1000==bucket[i]){//Quarta passada para pegar somente o digito da milhar;
        l[cont] = k[j];
        cont++;
      }
    }
  }
  printf("\n");

  printf("Ordenando --------->[ ");
  for(i=0; i<12; i++){
    printf("%d ",n[i]);
  }
  printf("]");

  printf("\n");
  printf("\n");

  printf("Ordenando --------->[ ");
  for(i=0; i<12; i++){
    printf("%d ",m[i]);
  }
  printf("]");

  printf("\n");
  printf("\n");

  printf("Ordenando --------->[ ");
  for(i=0; i<12; i++){
    printf("%d ",k[i]);
  }
  printf("]");

  printf("\n");
  printf("\n");

  printf("....Vetor ordenado: [ ");
  for(i=0; i<12; i++){
    printf("%d ",l[i]);
  }
  printf("]");

  return 0;
}

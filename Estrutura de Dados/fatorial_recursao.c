#include<stdio.h>

double fatorial(int n){
  double vfat;
  if ( n <= 1 ) //Caso base: fatorial de n <= 1 retorna 1
   return (1);
  else{ //Chamada recursiva
    vfat = n * fatorial(n - 1);
  return (vfat);
  }
}

int main(){

  double flag;
  flag = fatorial(0);
  printf("%.lf ",flag);

  return 0;
}

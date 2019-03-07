#include <stdio.h>
#include <stdlib.h>

int main(){

  int i;
  FILE *p;
  p = fopen("/home/daniel/Documentos/Algoritmos/C/teste.txt","a");
  if(p==NULL){
    printf("Erro!");
    exit(1);
  }

  for(i=0; i<(26); i++){
    printf("%c,",(97+i));
    fputc((97+i),p);
  }
  fclose(p);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *input = fopen("xmed.txt", "r"); //Arquivo de entrada.
  FILE *output = fopen("transferindo.txt", "w"); //Arquivo de saída.
  // char temp[50]={"teste"};
  // fgets(temp,50,input);
  char texto[1001] = "1"; //Uma string larga o suficiente para extrair o texto total de cada linha.
  unsigned int linha_selecionada = atoi(texto);
  unsigned int linha_atual = 1;
  while(fgets(texto, 1001, input) != NULL){
    if(linha_atual != linha_selecionada){
      fputs(texto, output);
    }
    memset(texto, 0, sizeof(char) * 1001);
    linha_atual += 1;
  }
  fclose(input);
  fclose(output);
  remove("xmed.txt");
  rename("transferindo.txt", "xmed.txt");
  return 0;
}

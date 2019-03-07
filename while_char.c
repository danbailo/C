#include <stdio.h>

int esperando_ch();

int main(){

  esperando_ch();

}

int esperando_ch(){
  char ch;

  ch='\0';//Inicializa ch

  while(ch!='a'){
    ch=getchar();
  }
  printf("\nVocê digitou um a");
  return ch;
}

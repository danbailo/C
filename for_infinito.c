#include <stdio.h>

int main(){
  char ch;

  ch='\0';

  for(;;){
    ch=getchar();//obtém um carectere;

    if(ch=='a'){
      break;//sai do laço;
    }
  }
  printf("\nVocê digitou um a");
}

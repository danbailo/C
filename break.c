#include <stdio.h>

int main(){
  int t;

  for (t=0; t<100; t++){
    printf("%d\n", t);
    if(t==10){
      break;
    }
  }
}

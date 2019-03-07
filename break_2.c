#include <stdio.h>

int main(){
  int t,count;

  for (t=0; t<5; t++){
    count = 1;
    for(;;){
      printf("%d",count);
      count++;
      if(count==10){
        break;
      }
    }
  }
}

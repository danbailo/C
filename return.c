#include <stdio.h>

int teste(int a, int b){
    if(a>b)
    return 0;
    else if (a<b)
    return 1;

    return 1;
}

int main(){

  teste(5,10);
  return 0;
}

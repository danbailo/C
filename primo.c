#include<stdio.h>

void primo(int n){
  int p=0;

  for (int i=1; i<=n; i++) {
    if (n % i == 0) {
     p++;
    }
  }
  if (p == 2)
    printf("O número %d é primo!\n", n);
  else
    printf("O número %d não é primo!\n", n);
}

int main(){

  primo(1);
  primo(2);
  primo(3);
  primo(4);
  primo(5);
  primo(6);
  primo(7);
  primo(8);
  primo(9);
  primo(10);
  primo(11);

  return 0;
}

#include <stdio.h>
#include <string.h>

void pad(char *s, int length);

int main(void){
  char str[80];

  strcpy(str, "Isto é um teste");
  pad(str, 80);
  printf("%d", strlen(str));
}

void pad(char *s, int length){
  int l;

  l = strlen(s); //encontra o comprimento;

  while(l<length){
    s[l] = ' '; //insere um espaço;
    l++;
  }
  s[l] = '\0'; //strings precisam terminar com um nulo;
}

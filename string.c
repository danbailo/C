#include <stdio.h>
#include <string.h>

int main(){

  char s1[80], s2[80];

  gets(s1);
  gets(s2);
  getchar();

  //strlen(s1 ou s2):
  //Retorna o tamanho da string;
  printf("Comprimentos: %d %d\n", strlen(s1), strlen(s2));

  //strcmp(s1,s2):
  //Retorna 0(falso) se s1 e s2 são iguais, por isso colocar a negação,
  //para retornar 1(verdadeiro) e aprovar a condição e assim irá printar;
  //menor que 0 se s1<s2; maior que 0 se s1>s2;
  if(!strcmp(s1, s2)) printf("As strings são iguais\n");

  //strcat(s1,s2):
  //Concatena s2 ao final de s1;
  strcat(s1, s2);

  printf("%s\n", s1);

  //strcpy(s1,s2):
  //Copia s2 em s1;
  strcpy(s1, "Isso é um teste.\n");
  printf(s1);

  //strchr(s1,ch):
  //Retorna um ponteiro para a primeira ocorrência de ch em s1.
  if(strchr("alo", 'o')) printf ("o está em alo\n");

  //strstr(s1,s2):
  //Retorna um ponteiro para a primeira ocorrência de s2 em s1.
  if(strstr("ola aqui", "ola")) printf ("ola encontrado");
}

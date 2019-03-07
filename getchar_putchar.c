#include  <stdio.h>
int main( )
 {
 char c;
 printf("Digite uma letra ou numero, que eu vou descobrir se um numero uma letra: ");
 c = getchar();
if((c >= '0') && (c<='9'))
printf("EU SOU um numero");
else printf("Nao SOU um numero");
 return 0;

} 

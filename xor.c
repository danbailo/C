#include<stdio.h>

int main(){
    int a = 2;
    int b = 5;

    printf("a = %d, b = %d\n",a,b);
    
    a = a^b;
    b = a^b;
    a = a^b;

    printf("a = %d, b = %d\n",a,b);
    
    return 0;
}

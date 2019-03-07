#include <stdio.h>

void radixsort(int vetor[], int tamanho) {
  int i;
  int b[tamanho];
  int maior = vetor[0];
  int exp = 1;

  

  for (i = 0; i < tamanho; i++) {
    if (vetor[i] > maior)
      maior = vetor[i];
  }
  while (maior/exp > 0) {
    int bucket[10] = { 0 };
      for (i = 0; i < tamanho; i++)
        bucket[(vetor[i] / exp) % 10]++;
      for (i = 1; i < 10; i++)
        bucket[i] += bucket[i - 1];
      for (i = tamanho - 1; i >= 0; i--)
        b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
      for (i = 0; i < tamanho; i++)
        vetor[i] = b[i];
    exp *= 10;
  }
}

void printArray(int vetor[], int tamanho){
  int i;
  printf("[ ");
  for (i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
  printf("]\n");
}

int main(){
  int v[]={10, 2, 303, 4021, 293, 1, 0, 429, 480, 92, 2999, 14};
  radixsort(v, 12);
  printArray(v, 12);

  return 0;
}

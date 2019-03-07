#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct SNo{
  char Nome[30];
  int idade;
  char tipo[2];
  char fatorRh[15];
  float qtdSangue;
  struct SNo *FE;
  struct SNo *FD;
}SNo;

struct SNo No;
struct SNo Noo;

SNo *Raiz = NULL;

void insere(SNo *R, char *nome, int idade, char tipo[], char fatorRh[], float quantidade, SNo *Pai) {

    if(R == NULL) { // condicao de parada

        SNo *Novo = (SNo *)malloc(sizeof(SNo));
        strcpy(Novo->Nome,nome);
        Novo->idade = idade;
        strcpy(Novo->tipo,tipo);
        strcpy(Novo->fatorRh,fatorRh);
        Novo->qtdSangue = quantidade;

        Novo->FD = NULL;
        Novo->FE = NULL;
        if(Pai == NULL) {
            Raiz = Novo;
            return;
        }
        else if(idade > Pai->idade)
            Pai->FD = Novo;
        else if(idade < Pai->idade)
            Pai->FE = Novo;
    }
    else if(idade > R->idade) { //anda direita
        insere(R->FD, nome, idade, tipo, fatorRh, quantidade, R);
    }
    else if(idade < R->idade) { //anda esquerda
        insere(R->FE, nome, idade, tipo, fatorRh, quantidade, R);
    }
    else {
        printf("O elemento já está na árvore!\n");
    }
}

// int search(SNo *R, int value, char *nome){
//   if(R==NULL){//Condição de parada;
//     // printf("\nO elemento %d não está na árvore!", value);
//     return 0;
//   }
//   else if(value > R->idade){
//     search(R->FD, value, nome);
//     // return 0;
//   }
//   else if(value < R->idade){
//     search(R->FE, value, nome);
//     // return 0;
//   }
//   else{
//     // printf("\nO elemento %d está na árvore!", value);
//     return 1;
//   }
//   // return 0;
// }

// int search(SNo *R, char *nome){
//   int value = atoi(nome);
//   if(R==NULL){//Condição de parada;
//     printf("\nO elemento %d não está na árvore!", value);
//     return 0;
//   }
//   else if(value > R->idade){
//     search(R->FD, nome);
//     // return 0;
//   }
//   else if(value < R->idade){
//     search(R->FE, nome);
//     // return 0;
//   }
//   else(0){
//     printf("\nO elemento %d está na árvore!", value);
//     return 1;
//   }
//   // return 0;
// }

void listWord(SNo *tree, char *word){
    if (tree) {
        /* If tree is not NULL... */

        /* recursively process FE subtree if present.. */
        if (tree->FE)
            listWord(tree->FE, word);

        /* then check the current SNo.. */
        if (strstr(tree->Nome, word)) {
            printf(" specific word %s: \n", word);
            printf("\n\t\t  id is :%d ", tree->idade);
        }

        /* then recursively process the FD subtree if present. */
        if (tree->FD)
            listWord(tree->FD, word);
    } else
        printf("list is empty");
}

void emOrdem(SNo *R){
    if(R!=NULL){ //cp
        emOrdem(R->FE);
        printf("%s, %d, %s, %s, %.2f\n",R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);
        emOrdem(R->FD);
    }
    return;
}

SNo *getSmall(SNo *R){
  if(R == NULL) // arvore vazia
      return NULL;
  if(R->FE == NULL)
      return R;
  return getSmall(R->FE);
}

SNo* deleteNode(SNo *R, int idade){
  // base case and stop condition
  if (R == NULL)
    return R;

  // If the idade to be deleted is smaller than the R's idade,
  // then it lies in FE subtree
  if (idade < R->idade)
      R->FE = deleteNode(R->FE,idade);

  // If the idade to be deleted is greater than the R's idade,
  // then it lies in FD subtree
  else if (idade > R->idade)
      R->FD = deleteNode(R->FD,idade);

  // if idade is same as R's idade, then This is the R
  // to be deleted
  else{
    // R with only one child or no child
    if (R->FE == NULL){
      SNo *temp = R->FD;
      free(R);
      return temp;
    }
    else if (R->FD == NULL){
      SNo *temp = R->FE;
      free(R);
      return temp;
    }

    // R with two children: Get the inorder successor (smallest
    // in the FD subtree)
    SNo* temp = getSmall(R->FD);
    // Copy the inorder successor's content to this R
    R->idade = temp->idade;

    // Delete the inorder successor
    R->FD = deleteNode(R->FD,idade);
  }
  return R;
}

// SNo* abb_retira(SNo* R, int valor){
//   if (R == NULL)
//     return NULL;
//   else if (R->idade > valor)
//     R->FE = abb_retira(R->FE, valor);
//   else if (R->idade < valor)
//     R->FD = abb_retira(R->FD, valor);
//   else { /* achou o nó a remover */
//     if (R->FE == NULL && R->FD == NULL) {/* nó sem filhos */
//       free (R);
//       R = NULL;
//       // free (Raiz);
//       // Raiz = NULL;
//     }
//     else if (R->FE == NULL) {/* nó só tem filho à direita */
//       SNo* temp = R;
//       R = R->FD;
//       free (temp);
//     }
//     else if (R->FD == NULL) {/* só tem filho à esquerda */
//       SNo* temp = R;
//       R = R->FE;
//       free (temp);
//     }
//     else {/* nó tem os dois filhos */
//       SNo* aux = R->FE;
//       while (aux->FD != NULL) {
//         aux = aux->FD;
//     }
//     R->idade = aux->idade; /* troca os valores dos nós */
//     aux->idade = valor;
//     R->FE = abb_retira(R->FE,valor);
//     }
//   }
//   return R;
// }

SNo* abb_retira(SNo* R,SNo* pai, int valor){
  if (R == NULL)
    return NULL;
  else if (R->idade > valor)
    R->FE = abb_retira(R->FE,R, valor);
  else if (R->idade < valor)
    R->FD = abb_retira(R->FD,R, valor);
  else {
  	if(pai==NULL){//é o nó raiz
      // Raiz = NULL;
  		Raiz=R->FD;
  		free(R);
  	}
    else if (R->FE == NULL && R->FD == NULL) {
      if(pai->FD==R){
      	pai->FD = NULL;
      }
      else{
      	pai->FE = NULL;
      }
      free(R);
    }
    else if (R->FE == NULL) {
      if(pai->FD==R){
      	pai->FD = R->FD;
      }
      else{
      	pai->FE = R->FD;
      }
      free(R);
    }
    else if (R->FD == NULL) {
      if(pai->FD==R){
      	pai->FD = R->FE;
      }
      else{
      	pai->FE = R->FE;
      }
      free(R);
    }
    else {
      SNo* aux = R->FE;
      while (aux->FD != NULL) {
        aux = aux->FD;
	     }
	   R->idade = aux->idade;
	   aux->idade = valor;
	   R->FE = abb_retira(R->FE,R,valor);
	  }
  }
  return R;
}

// funcao pega maior
SNo** getMaior(SNo **No) {
  SNo **Temp = No;

  while((*Temp)->FD != NULL)
    Temp = &(*Temp)->FD; // caminha para direita

  return Temp;

}
// funcao remover da ABB com ponteiro duplo

void remover(SNo **R, int idade) {

  if(*R == NULL) // cp
    printf("O elemento nao estah contido na arvore!\n");

  if(idade == (*R)->idade) {
    if((*R)->FD == NULL) { // FD nulo
      *R = (*R)->FE;
      //free((*R)->FE);
    }
    else if((*R)->FE == NULL) { // FE nulo
      *R = (*R)->FD;
      //free((*R)->FD);
    }
    else { // tem dois filhos
      SNo **maior = getMaior(&(*R)->FE);
      (*R)->idade = (*maior)->idade; // troca
      remover(maior, (*maior)->idade);
    }
  }
  else if(idade < (*R)->idade)
    remover(&(*R)->FE, idade);
  else
    remover(&(*R)->FD, idade);
}

float sangue_doado=0;

float mostrar_sangue(SNo *R){
  if(R==NULL){
    return 0;
  }
  if(R!=NULL){
    printf("oi");
    if(R->FD != NULL){
      sangue_doado += R->qtdSangue;
      mostrar_sangue(R->FD);
    }
    if(R->FE != NULL){
      sangue_doado += R->qtdSangue;
      mostrar_sangue(R->FE);
    }
  }
  return sangue_doado;
}

int main(){

  char nome[30]= "daniel";
  char tipo[2]= "A";
  char fatorRh[15]= "negativo";
  strcpy(No.Nome,nome);
  // printf("%s",No.Nome);
  No.idade = 18;
  // printf("%d",No.idade);
  strcpy(No.tipo,tipo);
  strcpy(No.fatorRh,fatorRh);
  No.qtdSangue = 346;

  char nomee[30]= "naul";
  char tipoo[2]= "B";
  char fatorRhh[15]= "positivo";
  strcpy(Noo.Nome,nomee);
  Noo.idade = 35;
  strcpy(Noo.tipo,tipoo);
  strcpy(Noo.fatorRh,fatorRhh);
  Noo.qtdSangue = 500;

  // funfou
  insere(Raiz, No.Nome, No.idade, No.tipo, No.fatorRh, No.qtdSangue, NULL);
  insere(Raiz, Noo.Nome, Noo.idade, Noo.tipo, Noo.fatorRh, Noo.qtdSangue, NULL);
  // insere(Raiz, Noo.Nome, Noo.idade, Noo.tipo, Noo.fatorRh, Noo.qtdSangue, NULL);
  emOrdem(Raiz);

  printf("sangue total:%.f",mostrar_sangue(Raiz));

  // printf("\nremovi\n\n");
  // remover(&Raiz,35);
  // deleteNode(Raiz,18);
  // abb_retira(Raiz,NULL,18);
//
  // emOrdem(Raiz);



  // listWord(Raiz,No.Nome);

  // char teste[5];
  // scanf("%s",teste);
  // int recebe_teste;
  // printf("variavel char: %s\n",teste);
  //
  // recebe_teste = atoi(teste);
  //
  // printf("recebe_teste:%d",recebe_teste);

  return 0;
}

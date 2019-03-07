#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct SNo {
  char Nome[30];
  int idade;
  char tipo[2];
  char fatorRh[15];
  float qtdSangue;
  int chave;
  int codigo;
  int altura;
  struct SNo *FE;
  struct SNo *FD;
  struct SNo *prox;
}SNo;

typedef struct Lista{
  SNo *inicio;
  SNo *fim;
  int tam_lista;
}Lista;

Lista *criaLista(){
  Lista *L = (Lista*)malloc(sizeof(Lista));
  L->inicio = NULL;
  L->fim = NULL;
  L->tam_lista=0;
  return L;
}

struct SNo No;
Lista *L1;

SNo *novo_arvore(char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo);

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get altura of the tree
int altura(SNo *N){
    if (N == NULL)
        return 0;
    return N->altura;
}

// A utility function to get maximum of two integers
int max(int a, int b){
  return (a > b)? a : b;
}

// A utility function to FD rotate subtree rooted with y
// See the diagram given above.
SNo *FD_rotacao(SNo *y){
     SNo *x = y->FE;
     SNo *T2 = x->FD;

    // Perform rotation
    x->FD = y;
    y->FE = T2;

    // Update alturas
    y->altura = max(altura(y->FE), altura(y->FD))+1;
    x->altura = max(altura(x->FE), altura(x->FD))+1;

    // Return new root
    return x;
}

// A utility function to FE rotate subtree rooted with x
// See the diagram given above.
SNo *FE_rotacao(SNo *x){
     SNo *y = x->FD;
     SNo *T2 = y->FE;

    // Perform rotation
    y->FE = x;
    x->FD = T2;

    //  Update alturas
    x->altura = max(altura(x->FE), altura(x->FD))+1;
    y->altura = max(altura(y->FE), altura(y->FD))+1;

    // Return new root
    return y;
}

// Get _balance factor of node N
int get_balance( SNo *R){
    if (R == NULL)
        return 0;
    return altura(R->FE) - altura(R->FD);
}

SNo *insere_arvore(SNo **R, char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo){
    /* 1.  Perform the normal BST rotation */
    if (*R == NULL)
        return (*R)=(novo_arvore(nome, idade, tipo, fatorRh, quantidade, codigo));

    if (codigo < (*R)->codigo)
        insere_arvore(&(*R)->FE, nome, idade, tipo, fatorRh, quantidade, codigo);
    else if (codigo > (*R)->codigo)
        insere_arvore(&(*R)->FD, nome, idade, tipo, fatorRh, quantidade, codigo);
    else // Equal chaves not allowed
        return (*R);

    /* 2. Update altura of this ancestor node */
    (*R)->altura = 1 + max(altura((*R)->FE),altura((*R)->FD));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = get_balance(*R);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && codigo < ((*R)->FE->codigo))
        return FD_rotacao(*R);

    // Right Right Case
    if (balance < -1 && codigo > ((*R)->FD->codigo))
        return FE_rotacao(*R);

    // Left Right Case
    if (balance > 1 && codigo > (*R)->FE->codigo)
    {
        (*R)->FE =  FE_rotacao((*R)->FE);
        return FD_rotacao(*R);
    }

    // Right Left Case
    if (balance < -1 && codigo < (*R)->FD->codigo)
    {
        (*R)->FD = FD_rotacao((*R)->FD);
        return FE_rotacao(*R);
    }

    /* return the (unchanged) node pointer */
    return (*R);
}

/* Given a non-empty binary search tree, return the
   node with menorimum chave value found in that tree.
   Note that the entire tree does not need to be
   searched. */
SNo *menor_valorSNo( SNo* R){
  SNo* temp = R;
  /* loop down to find the FEmost leaf */
  while (temp->FE != NULL)
    temp = temp->FE;

  return temp;
}

// Recursive function to delete a node with given chave
// from subtree with given root. It returns root of
// the modified subtree.
SNo *remover_arvore( SNo* root, int codigo){
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the codigo to be deleted is smaller than the
    // root's codigo, then it lies in FE subtree
    if ( codigo < root->codigo )
        root->FE = remover_arvore(root->FE, codigo);

    // If the codigo to be deleted is greater than the
    // root's codigo, then it lies in FD subtree
    else if( codigo > root->codigo )
        root->FD = remover_arvore(root->FD, codigo);

    // if codigo is same as root's codigo, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->FE == NULL) || (root->FD == NULL) )
        {
             SNo *temp = root->FE ? root->FE :
                                             root->FD;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the FD subtree)
             SNo* temp = menor_valorSNo(root->FD);

            // Copy the inorder successor's data to this node
            root->codigo = temp->codigo;

            // Delete the inorder successor
            root->FD = remover_arvore(root->FD, temp->codigo);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->altura = 1 + max(altura(root->FE),
                           altura(root->FD));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = get_balance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && get_balance(root->FE) >= 0)
        return FD_rotacao(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->FE) < 0)
    {
        root->FE =  FE_rotacao(root->FE);
        return FD_rotacao(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->FD) <= 0)
        return FE_rotacao(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->FD) > 0)
    {
        root->FD = FD_rotacao(root->FD);
        return FE_rotacao(root);
    }

    return root;
}

//funcao para criar um novo no em uma lista
SNo *novo_lista(char *nome, int idade, char tipo[], char fatorRh[], float quantidade/*, int codigo*/){
  SNo* temp = (SNo*)malloc(sizeof(SNo));
  strcpy(temp->Nome,nome);
  temp->idade = idade;
  strcpy(temp->tipo,tipo);
  strcpy(temp->fatorRh,fatorRh);
  temp->qtdSangue = quantidade;
  temp->chave = idade;
  // temp->codigo = 0;
  temp->prox = NULL;
  return temp;
}

//funcao para inserir um no em uma lista
void insere_lista(Lista *L, char *nome, int idade, char tipo[], char fatorRh[], float quantidade/*, int codigo*/){
  SNo *novo = novo_lista(nome, idade, tipo, fatorRh, quantidade/*, codigo*/);
  novo->codigo = L->tam_lista;
  L->tam_lista++;
  if(L->inicio==NULL){//Primeira inserção;
    L->inicio = novo;
  }
  else{
    L->fim->prox = novo;
  }
  L->fim = novo;
}

//funcao para remover um noem uma lista
void remover_lista(Lista *L, int valor){
  SNo *temp = L->inicio;
  SNo *ant = NULL;
  if(temp == NULL){
    printf("\nNenhum paciente está cadastrado no banco de dados!\n");
    return;
  }
  while(temp!=NULL){
    if(temp->codigo==valor){
      if(temp==L->inicio){
        L->inicio=L->inicio->prox;
      }
      else{
        if(temp==L->fim){
          // ant->prox=temp->prox;
          L->fim = ant;
        }
        ant->prox=temp->prox;
      }
      printf("O paciente de código %d foi removido do banco de dados!\n", valor);
      free(temp);
      return;
    }
    ant=temp;
    temp=temp->prox;
  }
  printf("O paciente de código %d não está cadastrado no banco de dados!\n", valor);
  return;
}

//funcao para imprimir o conteudo do no de uma lista
void imprime_lista(Lista *L){
  SNo *temp = L->inicio;
  if(temp == NULL){
    printf("Nenhum paciente está cadastrado no banco de dados!");
    return;
  }
  while(temp!=NULL){
    printf("\n%s, %d, %s, %s, %.2f, %d",temp->Nome,temp->idade,temp->tipo,temp->fatorRh,temp->qtdSangue,temp->codigo);
    temp = temp->prox;
  }
}

//funcao para inserir um novo no em uma arvore ABB
SNo *novo_arvore(char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo){
  SNo *temp = (SNo*)malloc(sizeof(SNo));
  strcpy(temp->Nome,nome);
  temp->idade = idade;
  strcpy(temp->tipo,tipo);
  strcpy(temp->fatorRh,fatorRh);
  temp->qtdSangue = quantidade;
  temp->codigo = codigo;
  temp->altura = 1;
  temp->FD = NULL;
  temp->FE = NULL;
  return temp;
}

// funcao para inserir em uma arvore ABB
// SNo *insere_arvore(SNo **R, char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo){
//   if(*R == NULL) { // condicao de parada
//     return *R=novo_arvore(nome, idade, tipo, fatorRh, quantidade, codigo);
//   }
//   else if(idade > (*R)->idade) { //anda FD
//       insere_arvore(&(*R)->FD, nome, idade, tipo, fatorRh, quantidade, codigo);
//   }
//   else if(idade < (*R)->idade) { //anda FE
//       insere_arvore(&(*R)->FE, nome, idade, tipo, fatorRh, quantidade, codigo);
//   }
//   else{
//     printf("\nPaciente já se encontra no banco de dados!\n");
//     return (*R);
//   }
//   return (*R);
// }

// funcao para percorrer a arvore usando a estrategia em-Ordem
void em_ordem(SNo *R){
    if(R!=NULL){ //cp
        em_ordem(R->FE);
        printf("\n%s, %d, %s, %s, %.2f, %d",R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue,R->codigo);
        em_ordem(R->FD);
    }
    // if(R==NULL){
    //   printf("Nenhum paciente está cadastrado no banco de dados!");
    //   return;
    // }
  return;
}

// // funcao para percorrer a arvore usando a estrategia pre-Ordem
// void pre_ordem(SNo *R){
//     if(R!=NULL){ //cp
//       printf("\n%s, %d, %s, %s, %.2f, %d",R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue,R->codigo);
//         pre_ordem(R->FE);
//         pre_ordem(R->FD);
//     }
//   return;
// }

// funcao para buscar um paciente por nome
int busca_nome(SNo *R, char *nome){

  if (R == NULL){
    printf("\nNenhum paciente está cadastrado no banco de dados!\n");
    return 0;
  }
  if (R->FE)
    busca_nome(R->FE, nome);

  /* then check the current SNo.. */
  if (strstr(R->Nome, nome)) {
    printf("\nNome completo: %s", R->Nome);
    printf("\nIdade: %d ", R->idade);
    printf("\nTipo sanguíneo: %s ", R->tipo);
    printf("\nFator RH: %s ", R->fatorRh);
    printf("\nQuantidade de sangue doada: %.2f", R->qtdSangue);
    printf("\nCódigo do paciente: %d\n", R->codigo);
    return 1;
  }
  if (R->FD)
    busca_nome(R->FD, nome);

  return 0;
}

//funcao para remover um paciente por codigo
// int remover_arvore(SNo **r, int valor){
//
//   if(*r == NULL){   // esta verificacao serve para caso o valor nao exista na arvore.
//       return 0;
//   }
//   int RE = remover_arvore(&(*r)->FE, valor);
//
//   int RD = remover_arvore(&(*r)->FD, valor);
//   if(valor==(*r)->codigo){
//     // se nao eh menor nem maior, logo, eh o valor que estou procurando! :)
//     SNo *pAux = *r;// quem programar No Embarcadero vai ter que declarar o pAux No inicio do void! :[
//     if (((*r)->FE == NULL) && ((*r)->FD == NULL)){//no folha
//       free(pAux);
//       (*r) = NULL;
//     }
//     else{// so tem o filho da FD
//       if ((*r)->FE == NULL){
//         (*r) = (*r)->FD;
//         pAux->FD = NULL;
//         free(pAux);
//         pAux = NULL;
//       }
//       else{//so tem filho da FE
//         if ((*r)->FD == NULL){
//           (*r) = (*r)->FE;
//           pAux->FE = NULL;
//           free(pAux);
//           pAux = NULL;
//         }
//         else{//Escolhi fazer o maior filho direito da subarvore FE.
//           SNo *eAux = (*r)->FE;
//           pAux = eAux;
//           SNo *dAux = (*r)->FD;
//           SNo *iAux = eAux->FD;
//           eAux->FD = dAux;
//           //insere o iaux no daux
//           if(iAux!=NULL){
//             //insere_no(daux,iaux);
//             while(dAux!=NULL){
//               if(iAux->codigo < eAux->codigo){
//                 if(eAux->FE == NULL){
//                   eAux->FE = iAux;
//                   break;
//                 }
//                 else{
//                   eAux = eAux->FE;
//                 }
//               }
//               else{
//                 if(eAux->FD == NULL){
//                   eAux->FD = iAux;
//                   break;
//                 }
//                 else{
//                   eAux = eAux->FD;
//                 }
//               }
//             }
//           }
//           // printf("AUX CHAVE:%d",eAux->chave);
//           free((*r));
//           *r = pAux;
//         }
//       }
//     }
//     return 1;
//   }
//   if (RE || RD)
//     return 1;
//   else
//     return 0;
// }

// Funcao que soma todos os elementos
float somaNo(SNo* R) {
  float res = 0;
  if (R == NULL)
    return 0;

  res = (R->qtdSangue + somaNo(R->FE) + somaNo(R->FD));
  return res;
}

//total sangue doado pelo tipo que o usuario pedir
float qtotal = 0;
float quantsangue(SNo *R, char temp[]){
	if(R == NULL)
		return 0;

	quantsangue(R->FE,temp);

  if(!strcmp(R->tipo,temp))
		qtotal += R->qtdSangue;

  quantsangue(R->FD,temp);
  return qtotal;
}

SNo *passar_lista_p_arvore(Lista *L){
  SNo *temp = L->inicio;
  SNo *ans = NULL;
  if(L->inicio == NULL){
    printf("Nenhum paciente está cadastrado no banco de dados!");
    return NULL;
  }

  while(temp!=NULL){
    insere_arvore(&ans,temp->Nome,temp->idade,temp->tipo,temp->fatorRh,temp->qtdSangue,temp->codigo);
    // printf("%s\n",temp->Nome);
    temp = temp->prox;
  }
  return ans;
}

//funcao que le um arquivo e adiciona os dados numa lista
void leArquivo(char * nome_arquivo) {

  FILE * ent;
  int l=1;
  SNo temp;
  //garantir que a string de tamanho 2 SNo.tipo é terminada nula
  temp.tipo[1]='\0';
  ent = fopen(nome_arquivo,"r");
  if(ent == NULL){
    printf("Verifique o nome e o caminho do arquivo!\n");
    exit(-1);
  }
  else{
    printf("\nArquivo lido com sucesso!\n");
  }
  char buff[256];
  //para cada linha do arquivo até o final
  while((fgets(buff,256,ent))){
    if(strlen(buff)==255){
      printf("Erro, a linha de um arquivo nao pode ultrapassar 256 caracteres\n");
      exit(-1);
    }
    //captura uma string no max 30 caracteres, um inteiro, um caracter, outra string max 8 chars, e um float
		int res=sscanf(buff,"%30[^,],%i,%c,%8[^,],%f",temp.Nome,&temp.idade,temp.tipo,temp.fatorRh,&temp.qtdSangue);
		//se o scanf capturar 5 variávei, ou seja, a linha tem um formato válido
		if(res==5){
      insere_lista(L1,temp.Nome,temp.idade,temp.tipo,temp.fatorRh,temp.qtdSangue/*,temp.codigo*/);
		}
    else{
      printf("linha %i do arquivo tem um formato incorreto e foi ignorada\n",l);
    }
    l++;
    }
    fclose(ent);
}

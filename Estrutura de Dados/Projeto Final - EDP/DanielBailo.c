/* Autor: Daniel de Leon Bailo da Silva */
/* Autor: Josué de Paulo Bailo da Silva */
/* RGA: 201718050216 */
/* RGA: 201718050208 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNo {
  char Nome[30];
  int idade;
  char tipo[2];
  char fatorRh[15];
  float qtdSangue;
  int chave;
  int codigo;
  struct SNo *FE;
  struct SNo *FD;
  struct SNo *prox;
}SNo;

typedef struct Lista{
  SNo *inicio;
  SNo *fim;
  int tam_lista;
}Lista;

struct SNo No;
Lista *L1;

Lista *criaLista(){
  Lista *L = (Lista*)malloc(sizeof(Lista));
  L->inicio = NULL;
  L->fim = NULL;
  L->tam_lista=0;
  return L;
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
  temp->FD = NULL;
  temp->FE = NULL;
  return temp;
}

// funcao para inserir em uma arvore ABB
SNo *insere_arvore(SNo **R, char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo){
  if(*R == NULL) { // condicao de parada
    return *R=novo_arvore(nome, idade, tipo, fatorRh, quantidade, codigo);
  }
  else if(idade > (*R)->idade) { //anda FD
      insere_arvore(&(*R)->FD, nome, idade, tipo, fatorRh, quantidade, codigo);
  }
  else if(idade < (*R)->idade) { //anda FE
      insere_arvore(&(*R)->FE, nome, idade, tipo, fatorRh, quantidade, codigo);
  }
  else{
    printf("\nPaciente já se encontra no banco de dados!\n");
    return (*R);
  }
  return (*R);
}

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

  return 1;
}

//funcao para remover um paciente por codigo
int remover_arvore(SNo **r, int valor){

  if(*r == NULL){   // esta verificacao serve para caso o valor nao exista na arvore.
      return 0;
  }
  int RE = remover_arvore(&(*r)->FE, valor);

  int RD = remover_arvore(&(*r)->FD, valor);
  if(valor==(*r)->codigo){
    // se nao eh menor nem maior, logo, eh o valor que estou procurando! :)
    SNo *pAux = *r;// quem programar No Embarcadero vai ter que declarar o pAux No inicio do void! :[
    if (((*r)->FE == NULL) && ((*r)->FD == NULL)){//no folha
      free(pAux);
      (*r) = NULL;
    }
    else{// so tem o filho da FD
      if ((*r)->FE == NULL){
        (*r) = (*r)->FD;
        pAux->FD = NULL;
        free(pAux);
        pAux = NULL;
      }
      else{//so tem filho da FE
        if ((*r)->FD == NULL){
          (*r) = (*r)->FE;
          pAux->FE = NULL;
          free(pAux);
          pAux = NULL;
        }
        else{//Escolhi fazer o maior filho direito da subarvore FE.
          SNo *eAux = (*r)->FE;
          pAux = eAux;
          SNo *dAux = (*r)->FD;
          SNo *iAux = eAux->FD;
          eAux->FD = dAux;
          //insere o iaux no daux
          if(iAux!=NULL){
            //insere_no(daux,iaux);
            while(dAux!=NULL){
              if(iAux->codigo < eAux->codigo){
                if(eAux->FE == NULL){
                  eAux->FE = iAux;
                  break;
                }
                else{
                  eAux = eAux->FE;
                }
              }
              else{
                if(eAux->FD == NULL){
                  eAux->FD = iAux;
                  break;
                }
                else{
                  eAux = eAux->FD;
                }
              }
            }
          }
          // printf("AUX CHAVE:%d",eAux->chave);
          free((*r));
          *r = pAux;
        }
      }
    }
    return 1;
  }
  if (RE || RD)
    return 1;
  else
    return 0;
}

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

int main() {

  L1 = criaLista();
  char nomeArquivo[20];
  int op,cont=1;
  SNo *arvore;

  while(cont!=0){
    printf("Digite a opção desejada\n");
    printf("[1]Ler o banco de dados\n");
    printf("[2]Printar\n");
    printf("[3]Inserir\n");
    printf("[4]Buscar\n");
    printf("[5]Remover\n");
    printf("[6]Sangue total doado\n");
    printf("[7]Limpar tela\n");
    printf("[8]Sair\n");
    scanf("%d",&op);
    printf("\n");

      switch (op) {
        case 1:
          printf("Qual o nome do arquivo: ");
          scanf("%s",nomeArquivo);
          leArquivo(nomeArquivo);
          arvore = passar_lista_p_arvore(L1);
        break;

        case 2:
          arvore = passar_lista_p_arvore(L1);
          em_ordem(arvore);
          printf("\n");
        break;

        case 3:
          printf("Digite os dados do usuário que você deseja inserir no banco de dados\n\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome); //o espaço entre a primeira aspa dupla e a porcentagem
          printf("Idade: ");          //limpa o buffer do teclado e assim tbm é possivel
          scanf("%d",&No.idade);      //ler strings com espaços
          printf("Tipo sanguíneo: ");
          scanf("%s",No.tipo);
          printf("Fator RH: ");
          scanf("%s",No.fatorRh);
          printf("Quantidade de sangue doada: ");
          scanf("%f",&No.qtdSangue);
          insere_lista(L1, No.Nome, No.idade, No.tipo, No.fatorRh, No.qtdSangue);
          arvore = passar_lista_p_arvore(L1);
          printf("\nPaciente inserido com sucesso!\n");
        break;

        case 4:
          printf("Digite o nome do usuário que você deseja buscar\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome);
          busca_nome(arvore,No.Nome);
          // if(verifica_nome(arvore,No.Nome) != 1)
            // printf("\nO paciente citado não está cadastrado no banco de dados!\n\n");
        break;

        case 5:
          printf("Digite o nome do usuário que você deseja remover\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome);
          if(!busca_nome(arvore,No.Nome)){
            printf("Paciente não encontrado no banco de dados \n");
            break;
          }
          printf("\nAgora, digite o código do paciente que você deseja remover\n");
          printf("Código: ");
          scanf("%d",&No.codigo);
          printf("\n");
          remover_lista(L1,No.codigo);
          remover_arvore(&arvore,No.codigo);
          arvore = passar_lista_p_arvore(L1);
        break;

        case 6:
          printf("Sangue total doado: ");
          printf("%.2fml\n",somaNo(arvore));
          printf("Tipo sanguíneo: ");
          scanf("%s",No.tipo);
          quantsangue(arvore,No.tipo);
          printf("\nA quantidade total de sangue doado do tipo %s foi de %.2fml\n",No.tipo,qtotal);
          qtotal = 0;
        break;

        case 7:
          system("clear");
        break;

        case 8:
          printf("Saindo...");
          exit(1);
        break;

        default:
          printf("Por favor, digite uma opção valida!\n");
        break;
      }
    printf("\nDeseja continuar? [1]Sim ou [0]Não\n");
    scanf("%d",&cont);
    printf("\n");
    // system("clear");
    if(cont==0){
      printf("Saindo...");
      return cont;
    }
  }
	return 0;
}

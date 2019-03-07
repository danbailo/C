#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define MAX 1000


typedef struct SNo {
	int id;
    char Nome[30];
    int idade;
    char tipo[3];
    char fatorRh[15];
    float qtdSangue;
    struct SNo *FE;
	struct SNo *FD;
}SNo;

SNo *Raiz = NULL;
struct SNo Temp;

void preOrdem(SNo *R){
	if(Raiz == NULL)
		printf("Nenhum doador cadastrado.\n");
	if(R == NULL)
		return;

	printf("%d %s, %d, %s, %s, %.2f\n",R->id,R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);
	preOrdem(R->FE);
	preOrdem(R->FD);
}

void emOrdem(SNo *R){
	if(R == NULL)
		return;

	preOrdem(R->FE);
	printf("%d %s, %d, %s, %s, %.2f\n",R->id,R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);
	preOrdem(R->FD);
}

void posOrdem(SNo *R){
	if(R == NULL)
		return;

	preOrdem(R->FE);
	preOrdem(R->FD);
	printf("%d %s, %d, %s, %s, %.2f\n",R->id,R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);
}
////////////////////////////insere AVL//////////////////////////


int altura( SNo *R ){

	int altura_esq = 0;
	int altura_dir = 0;

	if (R == NULL){
	return 0;
	}

	if( R->FE ){
		int	altura_esq = altura( R->FE );
	}else if ( R->FD ){
		int altura_dir = altura( R->FD );
	}

	if(altura_esq > altura_dir){
		return altura_esq +1;
	}else{
			return  altura_dir +1;
	}


}

/*int altura(SNo* R) {
  if (R == NULL)
    return -1;
  int esq = altura(R->FE);
  int dir = altura(R->FD);

  if(esq < dir){
  	return dir +1;
  }else{
  	return esq +1;
  }

}
*/

int fator_bal( SNo *R )
{
	int fator = 0;

	if ( R->FE )
		fator += altura( R->FE );

	if ( R->FD )
		fator -= altura( R->FD );

	return fator;
}


SNo *rotacionar_esq_esq( SNo *R ){
	SNo *temp = R;
	SNo *esq_ptr = temp->FE;

	temp->FE = esq_ptr->FD;
	esq_ptr->FD = temp;

	return esq_ptr;
}

SNo *rotationar_esq_dir(SNo *R ){
	SNo *temp = R;
	SNo *esq_ptr = temp->FE;
	SNo *dir_ptr = esq_ptr->FD;

	temp->FE = dir_ptr->FD;
	esq_ptr->FD = dir_ptr->FE;
	dir_ptr->FE = esq_ptr;
	dir_ptr->FD = temp;

	return dir_ptr;
}

SNo *rotacionar_dir_esq( SNo *R){
	SNo *temp = R;
	SNo *dir_ptr = temp->FD;
	SNo *esq_ptr = dir_ptr->FE;

	temp->FD = esq_ptr->FE;
	dir_ptr->FE = esq_ptr->FD;
	esq_ptr->FD = dir_ptr;
	esq_ptr->FE = temp;

	return esq_ptr;
}


SNo *rotacionar_dir_dir( SNo *R ){
	SNo *temp = R;
	SNo *dir_ptr = temp->FD;
	temp->FD = dir_ptr->FE;
	dir_ptr->FE = temp;

	return dir_ptr;
}

SNo *balancear_no( SNo *R ){
	SNo * no_balanceado = NULL;

	if ( R->FE )
		R->FE = balancear_no( R->FE);

	if ( R->FD )
		R->FD = balancear_no( R->FD );

	int fator = fator_bal( R );

	if ( fator >= 2 )
	{
		/* pesando pra esquerda */

		if ( fator_bal( R->FE ) <= -1 )
			no_balanceado = rotationar_esq_dir( R );
		else
			no_balanceado = rotacionar_esq_esq( R );

	}
	else if( fator <= -2 )
	{
		/* pesando pra direita */

		if( fator_bal( R->FD ) >= 1 )
			no_balanceado = rotacionar_dir_esq( R );
		else
			no_balanceado = rotacionar_dir_dir( R );

	}
	else
	{
		no_balanceado = R;
	}

	return no_balanceado;
}



void balancear_tree( SNo *R ){
	SNo * nova_raiz = NULL;

	nova_raiz = balancear_no( R );

	if( nova_raiz != R ){
	R = nova_raiz;
	}
}

//////////////////////////////fim//////////////////////////////

void insere(SNo *R, SNo *Pai){

	SNo *novo= (SNo*)malloc(sizeof(SNo));
	novo->id = Temp.id;
	strcpy(novo->Nome,Temp.Nome);
	novo->idade = Temp.idade;
	strcpy(novo->tipo,Temp.tipo);
	strcpy(novo->fatorRh,Temp.fatorRh);
	novo->qtdSangue = Temp.qtdSangue;
	novo->FD = NULL;
	novo->FE = NULL;

	if(Raiz == NULL){
		Raiz = novo;
		return;
	}

	if(R == NULL){
		if(Temp.id > Pai->id){
			Pai->FD = novo;
			return;
		}
		else
		if(Temp.id < Pai->id){
			Pai->FE = novo;
			return;
		}

	}

	if(Temp.id > R->id)
		insere(R->FD,R);
	if (Temp.id < R->id)
		insere(R->FE,R);

	balancear_tree(Raiz);
}

void LerArquivo(char * arquivo) {
    FILE * arq;  // variavel usada para manipular o arquivo em disco
    char c, temp[50]; // variavel temporaria para guardar cada campo

	int campo, t, val;  // indica em que posicao do vetor eu devo inserir o registro, campo, temp t esta sendo lida
    float val2;

    arq = fopen(arquivo,"r"); //abre o arquivo no modo leitura
    if(arq == NULL) {
        printf("Arquivo de backup n�o encontrado!\nCaso for o primeiro acesso um ser� criado ao encerrar o programa.\n");
        return;
    }

    printf("Arquivo de backup lido com sucesso!\n\n");
    //inicializando contadores
    campo = 0;
    t = 0;

    while((c=fgetc(arq)) != EOF) { //enquanto nao chegar ao fim do arquivo (END-OF-FILE)
        if(c == ';' || c== '\n') {
            temp[t] = '\0'; // carrega a string que esta em temp
            if(campo == 0) {
                strcpy(Temp.Nome,temp);
            }
            else if(campo == 1) {
                val = atoi(temp);
                Temp.idade = val;
            }
            else if(campo == 2) {
                strcpy(Temp.tipo,temp);
            }
            else if(campo == 3) {
                strcpy(Temp.fatorRh,temp);
            }
            else if(campo == 4) {
                val2 = atof(temp);
                Temp.qtdSangue = val2;
            }

           	strcpy(temp,""); // limpar temp para comecar a ler o novo campo
            t = 0;
            ++campo;
            if(campo > 4) // reseta o contador campo
                campo = 0;

        }
        else {
            temp[t] = c;  // apenas copia o caracter lido para temp
            ++t;
        }
        if(c == '\n'){
        	Temp.id++;
        	//printf("%d %s, %d, %s, %s, %.2f\n",Temp.id,Temp.Nome,Temp.idade,Temp.tipo,Temp.fatorRh,Temp.qtdSangue);
        	insere(Raiz,NULL); // insere a linha na arvore
		}

    }

    /*if(c== EOF){
        	Temp.id++;
        	//printf("%d %s, %d, %s, %s, %.2f\n",Temp.id,Temp.Nome,Temp.idade,Temp.tipo,Temp.fatorRh,Temp.qtdSangue);
        	insere(Raiz,NULL); // insere a linha na arvore
	}*/
    fclose(arq);
}



SNo *salvarArvore(char *arquivo,SNo *R){
	if(Raiz == NULL){
		printf("Nenhum doador cadastrado.\n");
		return NULL;
	}

	if(R == NULL)
		return NULL;
	printf(arquivo,"%s;%d;%s;%s;%.2f\n",R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);

	//printf("%s, %d, %s, %s, %.2f\n",R->Nome,R->idade,R->tipo,R->fatorRh,R->qtdSangue);
	salvarArvore(arquivo,R->FE);
	salvarArvore(arquivo,R->FD);
}

void *salvarDados(char *arquivo,SNo *R){
	FILE * arq;

	arq = fopen(arquivo,"w"); //abre o arquivo no modo leitura
    if(arq == NULL) {
        printf("Arquivo de backup n�o criado!\n");
        return;
    }

    salvarArvore(arq,R);
    fclose(arq);
}

SNo *buscaid(SNo *R,int valor){
	if(R!=NULL){
		if(R->id == valor)
			return R;

		if(valor > R->id)
			return	buscaid(R->FD,valor);
		if(valor < R->id){
			return buscaid(R->FE,valor);
		}
	}

	return NULL;
}

SNo *buscapai(SNo *R,int valor,SNo *Pai){
	if(R!=NULL){
		if(R->id == valor)
			return Pai;

		if(valor > R->id)
			return	buscapai(R->FD,valor,R);
		if(valor < R->id){
			return buscapai(R->FE,valor,R);
		}
	}

	return NULL;
}

SNo *buscamaior(SNo *R){
	if(R->FD == NULL){
		return R;
	}else buscamaior(R->FD);
}

SNo *buscapmaior(SNo *R,SNo *Pai){
	if(R->FD == NULL){
		return Pai;
	}else buscapmaior(R->FD,R);
}


SNo *buscamenor(SNo *R){
	if(R->FE == NULL){
		return R;
	}else buscamenor(R->FE);
}

SNo *buscapmenor(SNo *R,SNo *Pai){
	if(R->FE == NULL){
		return Pai;
	}else buscapmenor(R->FE,R);
}

void remover(SNo *R,int valor,SNo *Pai){

	SNo *temp,*temp1,*maior,*pmaior,*pai,*menor,*pmenor;
	temp = buscaid(R,valor);
	temp1=temp;
	if(temp != NULL){
		if( (temp->FD == NULL) && (temp->FE == NULL) ) {
			pai = buscapai(R,valor,NULL);

			if(temp->id > pai->id)
				pai->FD = NULL;
			else
				pai->FE = NULL;

			free(temp);
			return;
		}
		else{
			if(temp->FE == NULL){
				if(temp->id == Raiz->id){
					Raiz = temp->FD;
					free(temp);
				}else{

				pai = buscapai(R,valor,NULL);
				if(pai->FE != NULL)
					if(pai->FE->id == temp->id){
						pai->FE = temp->FD;
						free(temp);
					}
				if(pai->FD != NULL)
					if(pai->FD->id == temp->id){
						printf("Pai FD id = %d\n",pai->FD->id);
						pai->FD = temp->FD;
						printf("Pai FD id = %d\n",pai->FD->id);
						free(temp);
					}
				}
			}else
			if(temp->FD == NULL){
				if(temp->FE = Raiz->FE){
					Raiz = temp->FE;
					free(temp);
				}else{
				pai = buscapai(R,valor,NULL);
				if(pai->FE != NULL)
					if(pai->FE->id == temp->id){
						pai->FE = temp->FE;
						free(temp);
					}
				if(pai->FD != NULL)
					if(pai->FD->id == temp->id){
						pai->FD = temp->FE;
						free(temp);
					}
				}
			}
			if((temp->FD !=NULL) && (temp->FE != NULL)){
				if(temp->id == Raiz->id){
					menor = buscamenor(temp->FD);
					pmenor = buscapai(R,menor->id,NULL);
					temp->id = menor->id;
					strcpy(temp->fatorRh,menor->fatorRh);
					temp->idade = menor->idade;
					strcpy(temp->Nome,menor->Nome);
					temp->qtdSangue = menor->qtdSangue;
					strcpy(temp->tipo,menor->tipo);
					pmenor->FE = NULL;
					free(menor);
				}else
				{
					menor= buscamenor(temp->FD);
					temp->id = menor->id;
					strcpy(temp->fatorRh,menor->fatorRh);
					temp->idade = menor->idade;
					strcpy(temp->Nome,menor->Nome);
					temp->qtdSangue = menor->qtdSangue;
					strcpy(temp->tipo,menor->tipo);
					menor->id = temp1->id;
					strcpy(menor->fatorRh,temp1->fatorRh);
					menor->idade = temp1->idade;
					strcpy(menor->Nome,temp1->Nome);
					menor->qtdSangue = temp1->qtdSangue;
					strcpy(menor->tipo,temp1->tipo);
					remover(R,valor,NULL);
				}
			}
		}
	}
}


SNo *buscartipo(SNo *R,char tipo[],char fatorRh[]){

		if(R!=NULL){
		if(strcmp(R->tipo,tipo) == 0 && strcmp(R->fatorRh,fatorRh) == 0){
			return R;
		}
		printf("Nomes = %s\n",R->Nome);
		return buscartipo(R->FD,tipo,fatorRh);
		return buscartipo(R->FE,tipo,fatorRh);

	}

	return NULL;
}

SNo *buscarnome(SNo *R,char Nome[]){


	if(R!=NULL){
		if(strcmp(R->Nome,Nome) == 0){
			return R;
		}
	//	printf("Nomes = %s\n",R->Nome);
		return buscarnome(R->FD,Nome);
		return buscarnome(R->FE,Nome);

	}

	return NULL;
}



int main(int argc, char **argv) {
	setlocale(LC_ALL, "Portuguese");
	LerArquivo("xmed.txt");
	int op = 1;
	int idremove;
	int v =0;

    printf("::::Banco de sangue::::\n\n");

	while(op!=0){
		printf("O que deseja fazer?\n");
		printf("1- Cadastrar Doador.\n");
		printf("2- Buscar doador por nome.\n");
		printf("3- Buscar doador por tipo sanguineo e fatorRh.\n");
		printf("4- Listar doadores.\n");
		printf("5- Remover doador.\n");
		printf("6- Altura.\n");
		printf("0- Sair e salvar modifica��es!\n");

		scanf("%d",&op);
		setbuf(stdin,NULL);

		switch(op){
			case 0: break;
			case 1: {
				v = rand() % MAX;
				int w = BuscarId(Raiz,v);
				if (v == w){
					v = rand() % MAX;
				}else{
				setbuf(stdin,NULL);
				printf("Nome do doador: ");
				gets(Temp.Nome);
				setbuf(stdin,NULL);
				printf("Idade: ");
				scanf("%d",&Temp.idade);
				setbuf(stdin,NULL);
				printf("Tipo sanguineo: ");
				gets(Temp.tipo);
				setbuf(stdin,NULL);
				printf("FatorRh: ");
				gets(Temp.fatorRh);
				setbuf(stdin,NULL);
				printf("Quantidade de sangue doado: ");
				scanf("%f",&Temp.qtdSangue);
				setbuf(stdin,NULL);
				//Temp.id++;
				Temp.id = v;
				insere(Raiz,NULL);
				printf("Cadastrado com sucesso.\n");
			}
				break;
			}
			case 2: {
				printf("Digite o nome: ");
				gets(Temp.Nome);
				printf("%s\n",Temp.Nome);
				setbuf(stdin,NULL);
				if(buscarnome(Raiz,Temp.Nome) == NULL){
					printf("Doador n�o encontrado.\n");
				}else
					printf("Doador encontrado.\n");
				break;
			}
			case 3:	{
				printf("Digite o tipo sanguineo: ");
				gets(Temp.tipo);
				setbuf(stdin,NULL);
				printf("Digite o fatorRh: ");
				gets(Temp.fatorRh);
				setbuf(stdin,NULL);
				buscartipo(Raiz,Temp.tipo,Temp.fatorRh);
				break;
			}
			case 4: {
				preOrdem(Raiz);
				printf("\n\n");
				break;
			}
			case 5:{
				printf("Digite o ID do doador para removelo: ");
				scanf("%d",&idremove);
				setbuf(stdin,NULL);
				remover(Raiz,idremove,NULL);
				break;
			}
			case 6:{
				printf("Altura:%d\n",altura(Raiz));
				break;
			}
			default: {
				printf("Op��o invalida!\n");
				break;
			}
		}
	}

	salvarDados("backup.txt",Raiz);
	return(0);
}

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>

typedef struct paciente{
	int idade;
	char nome[50];
	char tipo_sangue[3];
	char fator_rh[10];
	float quantidade_doada;
	int codigo;
}paciente;

typedef struct bloco{
	paciente chave;
	struct bloco *prox;
	struct bloco *ant;
}bloco;

typedef struct lista{
	struct bloco *inicio;
	struct bloco *fim;
} lista;

typedef struct blocoA{
	paciente chave;
	int fb;//fator de balanceamento
	int altura;//altura de cada nó
	struct blocoA *dir;
	struct blocoA *esq;
}blocoA;

typedef struct arvore{
	struct blocoA *raiz;
}arvore;


int alt = 0;//variavel para verificação da altura
float quantidadedoadasangue = 0;//variavel para qnt total de um tipo de sangue

//Função para ler os pacientes nesta lista e por seus respectivos codigos
void inserelista(char nome[], int idade, char sangue[], char rh[], float quant, lista *l){
	bloco *novo = (bloco*)malloc(sizeof(bloco));
	if(l->inicio == NULL){
		strcpy(novo->chave.nome,nome);
		novo->chave.idade = idade;
		novo->chave.codigo = 1;
		strcpy(novo->chave.tipo_sangue,sangue);
		strcpy(novo->chave.fator_rh,rh);
		novo->chave.quantidade_doada = quant;
		novo->prox = NULL;
		novo->ant = NULL;
		l->inicio = novo;
		l->fim = novo;
	}
	else{
		strcpy(novo->chave.nome,nome);
		novo->chave.idade = idade;
		novo->chave.codigo = l->inicio->chave.codigo + 1;
		strcpy(novo->chave.tipo_sangue,sangue);
		strcpy(novo->chave.fator_rh,rh);
		novo->chave.quantidade_doada = quant;
		novo->prox = l->inicio;
		novo->ant = NULL;
		l->inicio->ant = novo;
		l->inicio = novo;
	}
}

//Inserir na arvore de acordo os codigos dos pacientes
void inserearvore(paciente *pacientes, arvore *a, blocoA *corre, blocoA *pai){
	if(corre == NULL){
		if(pai == NULL){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->altura = 1;
			novo->esq = NULL;
			novo->dir = NULL;
			a->raiz = novo;
			return;
		}
		if(pacientes->codigo > pai->chave.codigo){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->altura = pai->altura + 1;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->dir = novo;
			return;
		}
		if(pacientes->codigo < pai->chave.codigo){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->altura = pai->altura + 1;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->esq = novo;
			return;
		}

	}
	if(pacientes->codigo > corre->chave.codigo){
		inserearvore(pacientes,a, corre->dir, corre);
	}
	else{
		inserearvore(pacientes,a, corre->esq, corre);
	}

}

//Inserir na arvore pela idade
void inserearvoreidade(paciente *pacientes, arvore *a, blocoA *corre, blocoA *pai){
	if(corre == NULL){
		if(pai == NULL){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->esq = NULL;
			novo->dir = NULL;
			a->raiz = novo;
			return;
		}
		if(pacientes->idade > pai->chave.idade){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->dir = novo;
			return;
		}
		if(pacientes->idade < pai->chave.idade){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = *pacientes;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->esq = novo;
			return;
		}

	}
	if(pacientes->idade > corre->chave.idade){
		inserearvoreidade(pacientes,a, corre->dir, corre);
	}
	else{
		inserearvoreidade(pacientes,a, corre->esq, corre);
	}

}

//Função busca pelo nome do paciente
blocoA *buscanome(char nome[],int verif, blocoA *corre, arvore *a){
	if(a->raiz == NULL)
		return NULL;

	if(corre != NULL){
		buscanome(nome,verif,corre->esq, a);
		verif = strcmp (corre->chave.nome, nome);//Se der 0 encontrou
			if(verif == 0){
				printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
				return corre;
			}
		buscanome(nome,verif,corre->dir, a);
	}

}
//Função busca pelo nome do paciente retornando o pai
blocoA *buscanomepai(char nome[],int verif, blocoA *corre, blocoA *pai, arvore *a){
	if(a->raiz == NULL)
		return NULL;

	if(corre != NULL){
		buscanomepai(nome,verif,corre->esq, corre, a);
		verif = strcmp (corre->chave.nome, nome);//Se der 0 encontrou
			if(verif == 0){
				printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
				return pai;
			}
		buscanomepai(nome,verif,corre->dir, corre, a);
	}

}

//Funçaõ busca pelo codigo do paciente
blocoA *buscacodigo(int cod, blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Nenhum Paciente cadastrado");
		return NULL;
	}

	if(corre == NULL){
        printf("Paciente Nao encontrado!\n");
        return NULL;
    }

    if(cod > corre->chave.codigo)
        return buscacodigo(cod,corre->dir, a);

	if(cod < corre->chave.codigo)
        return buscacodigo(cod,corre->esq, a);

    printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
    return corre;

}
//Funçaõ busca pelo codigo do paciente retornando o pai
blocoA *buscacodigopai(int cod, blocoA *corre, blocoA *pai, arvore *a){
	if(a->raiz == NULL){
		printf("Nenhum Paciente cadastrado");
		return NULL;
	}

	if(corre == NULL){
        printf("Paciente Nao encontrado!\n");
        return NULL;
    }

    if(cod > corre->chave.codigo)
        return buscacodigopai(cod,corre->dir,corre, a);

	if(cod < corre->chave.codigo)
        return buscacodigopai(cod,corre->esq,corre, a);

    printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
    return pai;
}

void buscasangue(char sang[], int verif, blocoA *corre, arvore *a){
	if(a->raiz == NULL)
		return;

	if(corre != NULL){
		buscasangue(sang,verif,corre->esq, a);
		verif = strcmp (corre->chave.tipo_sangue, sang);//Se der 0 encontrou
			if(verif == 0)
				printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
		buscasangue(sang,verif,corre->dir, a);
	}

}

void buscarh(char rh[], int verif, blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Nenhum Paciente cadastrado");
		return;
	}

	if(corre != NULL){
		buscarh(rh,verif,corre->esq, a);
		verif = strcmp (corre->chave.fator_rh, rh);//Se der 0 encontrou
			if(verif == 0)
				printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
		buscarh(rh,verif,corre->dir, a);
	}

}
//imprimir arvore emordem
void imprimearvore(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia");
		return;
	}

	if(corre != NULL){
		imprimearvore(corre->esq, a);
		printf("%s  %d       %s          %s   %.2f                %d\n", corre->chave.nome, corre->chave.idade, corre->chave.tipo_sangue, corre->chave.fator_rh, corre->chave.quantidade_doada,corre->chave.codigo);
		imprimearvore(corre->dir, a);
	}
}

//total sangue doado pelo tipo que o usuario pedir
// quantsangue(sangueqt,-1,0, arvore->raiz, arvore);
void quantsangue(char tipo[], int verif, float qtotal, blocoA *corre, arvore *a){
	if(a->raiz == NULL)
		return;

	if(corre != NULL){
		quantsangue(tipo,verif,qtotal,corre->esq, a);
		verif = strcmp (corre->chave.tipo_sangue, tipo);//verif = 0 tipo_sangue = tipo
			if(verif == 0){
				qtotal = qtotal + corre->chave.quantidade_doada;
				//printf("Total doado de %s eh de: %.2f \n",tipo,qtotal);
				quantidadedoadasangue = qtotal;
			}
		quantsangue(tipo,verif,qtotal,corre->dir, a);
	}
}
//pegar maior elemento
blocoA *maiorcod(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia!!");
		return NULL;
	}

	if(corre->dir != NULL)
		maiorcod(corre->dir,a);
	else
		return corre;
}

//pegar pai do maior elemento
blocoA *maiorcodpai(blocoA *corre, blocoA *pai, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia!!");
		return NULL;
	}

	if(corre->dir != NULL)
		maiorcodpai(corre->dir,corre,a);
	else
		return pai;
}
//Pegar menor elemento
blocoA *menorcod(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia!!");
		return NULL;
	}

	if(corre->esq != NULL)
		menorcod(corre->esq,a);
	else
		return corre;
}
//Pegar pai do menor elemento
blocoA *menorcodpai(blocoA *corre,blocoA *pai, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia!!");
		return NULL;
	}

	if(corre->esq != NULL)
		menorcodpai(corre->esq, corre, a);
	else
		return pai;
}
//Função para remover
void removercod(int cod, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia!");
		return;
	}
	//Caso for a raiz o elemento a ser eliminado, mecher na subarvore esq
	if(a->raiz->chave.codigo == cod){
		if(a->raiz->dir == NULL && a->raiz->dir == NULL){//Caso so tiver a raiz
			free(a->raiz);
			a->raiz = NULL;
			return;
		}
		if(a->raiz->esq != NULL){
			blocoA *troca = maiorcod(a->raiz->esq,a);//salvar maior da subarvore esq
			blocoA *trocapai = maiorcodpai(a->raiz->esq,NULL,a);//salvar pai do troca
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				a->raiz->chave = troca->chave;//arvore recebe o maior da subarvore esq
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				a->raiz->chave = troca->chave;//arvore recebe o maior da subarvore esq
				a->raiz->esq = troca->esq;
				free(troca);
				return;
			}
		}
	}
	//Caso for a raiz o elemento a ser eliminado, mecher na subarvore dir
	if(a->raiz->chave.codigo == cod){
		if(a->raiz->dir != NULL){
			blocoA *troca = menorcod(a->raiz->dir,a);//salvar maior da subarvore dir
			blocoA *trocapai = menorcodpai(a->raiz->dir, NULL,a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				a->raiz->chave = troca->chave;//arvore recebe o maior da subarvore dir
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				a->raiz->chave = troca->chave;//arvore recebe o maior da subarvore dir
				a->raiz->dir = troca->dir;
				free(troca);
				return;
			}
		}
	}
	//eliminar folha
	blocoA *trocacorre = buscacodigo(cod,a->raiz,a);
	blocoA *trocapai = buscacodigopai(cod,a->raiz,NULL,a);//salvar pai do trocacorre
	if(trocacorre->dir == NULL && trocacorre->esq == NULL){//Caso for folha so apaga
		if(trocapai->dir == trocacorre)//apontar o pai da folha pra NULL
			trocapai->dir = NULL;
		if(trocapai->esq == trocacorre)//apontar o pai da folha pra NULL
			trocapai->esq = NULL;
		free(trocacorre);//Pai ainda apontando pro trocacorre
		return;
	}
	//Caso nao for a raiz o elemento a ser eliminado
	//Caso for a busca o elemento a ser eliminado, mecher na subarvore esq
	if(trocacorre->chave.codigo == cod){
		if(trocacorre->esq != NULL){
			blocoA *troca = maiorcod(trocacorre->esq,a);//salvar maior da subarvore esq
			blocoA *trocapai = maiorcodpai(trocacorre->esq, NULL, a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				trocacorre->chave = troca->chave;//arvore recebe o maior da subarvore esq
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				trocacorre->chave = troca->chave;//arvore recebe o maior da subarvore esq
				trocacorre->esq = troca->esq;
				free(troca);
				return;
			}
		}
	}
	//Caso for a busca o elemento a ser eliminado, mecher na subarvore dir
	if(trocacorre->chave.codigo == cod){
		if(trocacorre->dir != NULL){
			blocoA *troca = menorcod(trocacorre->dir,a);//salvar maior da subarvore dir
			blocoA *trocapai = menorcodpai(trocacorre->dir, NULL, a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				trocacorre->chave = troca->chave;//arvore recebe o maior da subarvore dir
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				trocacorre->chave = troca->chave;//arvore recebe o maior da subarvore dir
				trocacorre->dir = troca->dir;
				free(troca);
				return;
			}
		}
	}
	printf("Paciente nao existe para remover");
	return;
}
//mesma função da removercod, mas agora com nome
void removernome(char nome[], arvore *a){
	if(a->raiz == NULL){//Se estiver vazia
		printf("Arvore vazia!");
		return;
	}
	//verif ira salvar o nome buscado
	blocoA *verif = buscanome(nome,-1,a->raiz,a);
	if(verif == a->raiz){
		if(a->raiz->dir == NULL && a->raiz->dir == NULL){//Caso so tiver a raiz
			free(a->raiz);
			a->raiz = NULL;
			return;
		}
		if(a->raiz->esq != NULL){//ira realizar a troca pela subarvore esq
			blocoA *troca = maiorcod(a->raiz->esq,a);//salvar maior da subarvore esq
			blocoA *trocapai = maiorcodpai(a->raiz->esq, NULL, a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				a->raiz->chave = troca->chave;//raiz recebe o maior da subarvore esq
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				a->raiz->chave = troca->chave;//raiz recebe o maior da subarvore esq
				a->raiz->esq = troca->esq;
				free(troca);
				return;
			}
		}
		if(a->raiz->dir != NULL){//ira realizar a troca pela subarvore dir
			blocoA *troca = menorcod(a->raiz->dir,a);//salvar menor da subarvore dir
			blocoA *trocapai = menorcodpai(a->raiz->dir,NULL,a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				a->raiz->chave = troca->chave;//raiz recebe o maior da subarvore dir
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				a->raiz->chave = troca->chave;//raiz recebe o maior da subarvore dir
				a->raiz->dir = troca->dir;
				free(troca);
				return;
			}
		}
	}
	//Caso não for a raiz o elemento a ser deletado
	if(verif != a->raiz){
		blocoA *trocapai = buscanomepai(nome,-1,a->raiz,NULL,a);
		if(verif->dir == NULL && verif->esq == NULL){//Caso for a folha
			if(trocapai->dir == verif)
				trocapai->dir = NULL;
			if(trocapai->esq == verif)
				trocapai->esq = NULL;
			free(verif);
			return;
		}
		if(verif->esq != NULL){
			blocoA *troca = maiorcod(verif->esq,a);//salvar maior da subarvore esq
			blocoA *trocapai = maiorcodpai(verif->esq,NULL,a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				verif->chave = troca->chave;//verif recebe o maior da subarvore esq
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				verif->chave = troca->chave;//verif recebe o maior da subarvore esq
				verif->esq = troca->esq;
				free(troca);
				return;
			}
		}
		if(verif->dir != NULL){
			blocoA *troca = maiorcod(verif->dir,a);//salvar maior da subarvore dir
			blocoA *trocapai = maiorcodpai(verif->dir, NULL, a);
			if(troca->dir == NULL && troca->esq == NULL){//caso for folha
				verif->chave = troca->chave;//verif recebe o menor da subarvore dir
				if(trocapai->dir == troca)
					trocapai->dir = NULL;
				if(trocapai->esq == troca)
					trocapai->esq = NULL;
				free(troca);
				return;
			}
			if(troca->dir != NULL || troca->esq != NULL){//caso nao for folha
				verif->chave = troca->chave;//verif recebe o menor da subarvore dir
				verif->dir = troca->dir;//
				free(troca);
				return;
			}
		}
	}
	printf("Paciente nao existe para remover");
	return;

}

lista *crialista(){
	lista *l =(lista*)malloc (sizeof(lista));
	l->inicio = NULL;
	return l;
}

arvore *criaarvore(){
	arvore *a = (arvore*)malloc (sizeof(arvore));
	a->raiz = NULL;
	return a;
}
//pegar a altura da arvore total
void contaraltura(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia, altura 0!");
		return;
	}

    if(corre != NULL) {
        contaraltura(corre->esq, a);
		if(corre->dir == NULL && corre->esq == NULL){
			if(alt < corre->altura)
				alt = corre->altura;
		}
        contaraltura(corre->dir, a);

    }
}
//Contar a altura de um no especifico *arrumar
void contaralturano(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia, altura 0!");
		return;
	}

    if(corre != NULL) {
        contaralturano(corre->esq, a);
		if(corre->dir == NULL && corre->esq == NULL){
			if(alt < corre->altura)
				alt = corre->altura;
		}
        contaralturano(corre->dir, a);

    }
}

void ArrumarFatorBalanceamento(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Nada a balancear!!");
		return;
	}
	if(corre != NULL){
		ArrumarFatorBalanceamento(corre,a);
		if(corre->dir == NULL && corre->esq == NULL)
			corre->fb = 0;
		else{
			corre->fb;
		}
	}

}

void deixaravl(blocoA *corre, arvore *a){

}

//Função ler arquivo Bruno Brandoli
void leArquivo(char * nome_arquivo, lista *l) {
    FILE * ent;  // variavel usada para manipular o arquivo em disco
    char c, temp[50]; // variavel temporaria para guardar cada campo
    int campo, t, val;  // indica em que posicao do vetor eu devo inserir o registro, campo, temp t esta sendo lida
    float val2;
	struct paciente p;

    ent = fopen(nome_arquivo,"r"); //abre o arquivo no modo leitura
    if(ent == NULL) {
        printf("Verifique o nome e o caminho do arquivo!\n");
        return;
    }

    //inicializando contadores
    campo = 0;
    t = 0;

    while((c=fgetc(ent)) != EOF) { //enquanto nao chegar ao fim do arquivo (END-OF-FILE)
        if(c == ',' || c == '\n') {
            temp[t] = '\0'; // carrega a string que esta em temp
            if(campo == 0) {
                strcpy(p.nome,temp);
            }
            else if(campo == 1) {
                val = atoi(temp); // converte para inteiro
                p.idade = val;
            }
            else if(campo == 2) {
                strcpy(p.tipo_sangue,temp);
            }
            else if(campo == 3) {
                strcpy(p.fator_rh,temp);
            }
            else if(campo == 4) {
                val2 = atof(temp); // converte para float
                p.quantidade_doada = val2;
            }
            strcpy(temp,""); // limpar temp para comecar a ler o novo campo
            t = 0;

            ++campo;
            if(campo > 4) // reseta campo em 0
                campo = 0;

            if(c == '\n') { // quando atinge para pular a linha, insere na arvore
                inserelista(p.nome, p.idade, p.tipo_sangue, p.fator_rh, p.quantidade_doada, l);
            }

        }
        else {
            temp[t] = c;  // apenas copia o caracter lido para temp
            ++t;
        }
    }
    fclose(ent);  // fecha o arquivo depois de ter lido para a memoria
}

int main(){
	//setlocale(LC_ALL, "Portuguese");float fica com , em vez de .
	arvore *arvore = criaarvore();
	lista *lista = crialista();
	char nomeArquivo[20];
	system("clear");
    printf("Qual o nome do arquivo: ");
    scanf("%s",&nomeArquivo[20]);
    setbuf(stdin, NULL);//para limpar buffer do teclado
	leArquivo(nomeArquivo,lista);


	//TESTE
	/*
	bloco *temp = lista->fim;
		while(temp != NULL){
			inserearvoreidade(&temp->chave, arvore, arvore->raiz, NULL);
			temp = temp->ant;
		}
	blocoA *ver = buscanomepai("Barry Allen",-1,arvore->raiz,NULL,arvore);
	printf("\n%s",ver->chave.nome);
	contaraltura(arvore->raiz, arvore);
	printf("\n%d",alt);*/


	//Ver ordem de inserção
	int ordem;
	do{
		system("clear");
		printf("GOSTARIA DE INSERIR NA ARVORE POR: \n");
		printf("1-ORDEM DE CHEGADA\n");
		printf("2-ORDEM DE IDADE\n");
		scanf("%d",&ordem);
		if(ordem == 1){
			//Passar os pacientes para a arvore agora com seus respectivos codigos
			bloco *temp = lista->fim;
			while(temp != NULL){
				inserearvore(&temp->chave, arvore, arvore->raiz, NULL);
				temp = temp->ant;
			}
		}
		if(ordem == 2){
			//Passar os pacientes para a arvore agora com suas respectivas idades
			bloco *temp = lista->fim;
			while(temp != NULL){
				inserearvoreidade(&temp->chave, arvore, arvore->raiz, NULL);
				temp = temp->ant;
			}
		}
		}
	while(ordem != 1 && ordem != 2);



	//Começo do laço menu
	int condicao;
	do{
		system("clear");
		printf("                   'HOSPITAL XMED'\n");
		printf("OQUE DESEJA FAZER?\n");
		printf("1-IMPRIMIR TODOS PACIENTES\n");
		printf("2-BUSCAR PACIENTES\n");
		printf("3-DELETAR PACIENTES\n");
		printf("4-IMPRIMIR QUANTIDADE DE SANGUE\n");
		printf("5-ATUALIZAR DADOS PACIENTES\n");
		printf("6-CADASTRAR PACIENTE\n");
		printf("7-SAIR\n");
		int codigo;
		scanf("%d", &codigo);
		setbuf(stdin, NULL);
		if(codigo == 1){
			system("clear");
			printf("Nome:        Idade:   Sangue:    RH:        Quantidade:         Codigo:\n");
			imprimearvore(arvore->raiz, arvore);
			printf("\n");
		}
		if(codigo == 2){
			system("clear");
			printf("BUSCAR POR: \n");
			printf("1-NOME\n");
			printf("2-TIPO SANGUINEO\n");
			printf("3-FATOR RH\n");
			printf("4-CODIGO PACIENTE\n");
			int cod1;
			scanf("%d", &cod1);
			setbuf(stdin, NULL);
			if(cod1 == 1){
				system("clear");
				printf("Informe o nome do paciente: ");
				char name[50];
				scanf("%[^\n]s", &name);
				setbuf(stdin, NULL);
				buscanome(name, -1, arvore->raiz, arvore);

			}
			if(cod1 == 2){
				system("clear");
				printf("Informe o tipo sanguineo do paciente: ");
				char sang[2];
				scanf("%s",&sang);
				setbuf(stdin, NULL);
				buscasangue(sang,-1,arvore->raiz,arvore);
			}
			if(cod1 == 3){
				system("clear");
				printf("Informe o fator Rh do paciente: ");
				char rh[10];
				scanf("%s",&rh);
				setbuf(stdin, NULL);
				buscarh(rh,-1,arvore->raiz,arvore);
			}
			if(cod1 == 4){
				system("clear");
				int cod;
				printf("Informe o codigo do paciente: ");
				scanf("%d",&cod);
				setbuf(stdin, NULL);
				buscacodigo(cod,arvore->raiz,arvore);
			}

		}
		if(codigo == 3){
			system("clear");
			printf("DELETAR PACIENTES PELO?\n");
			printf("1-NOME\n");
			printf("2-CODIGO\n");
			int cod9;
			scanf("%d",&cod9);
			setbuf(stdin, NULL);
			if(cod9 == 1){
				system("clear");
				printf("INFORME O NOME DO PACIENTE: ");
				char codename[50];
				scanf("%[^\n]s",&codename);//Para pegar espaço
				setbuf(stdin, NULL);//limpar buffer do teclado
				buscanome(codename,-1,arvore->raiz,arvore);
				printf("\nDESEJA MESMO APAGAR ESSE PACIENTE?\n");
				printf("1-SIM\n");
				printf("2-NAO\n");
				int delete;
				scanf("%d",&delete);
				setbuf(stdin, NULL);
				if(delete == 1){
					removernome(codename,arvore);
					system("clear");
					printf("DELETADO\n");

				}
				if(delete == 2)
					system("clear");
			}
			if(cod9 == 2){
				system("clear");
				printf("INFORME O CODIGO DO PACIENTE: ");
				int code;
				scanf("%d",&code);
				setbuf(stdin, NULL);//limpar buffer do teclado
				buscacodigo(code,arvore->raiz,arvore);
				printf("\nDESEJA MESMO APAGAR ESSE PACIENTE?\n");
				printf("1-SIM\n");
				printf("2-NAO\n");
				int delete;
				scanf("%d",&delete);
				setbuf(stdin, NULL);
				if(delete == 1){
					removercod(code,arvore);
					system("clear");
					printf("DELETADO\n");

				}
				if(delete == 2)
					system("clear");
			}
		}
		if(codigo == 4){
			system("clear");
			printf("QUAL TIPO DE SANGUE?\n");
			printf("1-A\n");
			printf("2-B\n");
			printf("3-O\n");
			printf("4-AB\n");
			int cod2;
			scanf("%d",&cod2);
			setbuf(stdin, NULL);
			if(cod2 == 1){
				system("clear");
				char sangueqt[3] = "A";
				quantsangue(sangueqt,-1,0, arvore->raiz, arvore);
				printf("Quantidade total de A doada eh de: %f\n",quantidadedoadasangue);
			}
			if(cod2 == 2){
				system("clear");
				char sangueqt[3] = "B";
				quantsangue(sangueqt,-1,0, arvore->raiz, arvore);
				printf("Quantidade total de B doada eh de: %f\n",quantidadedoadasangue);
			}
			if(cod2 == 3){
				system("clear");
				char sangueqt[3] = "O";
				quantsangue(sangueqt,-1,0, arvore->raiz, arvore);
				printf("Quantidade total de O doada eh de: %f\n",quantidadedoadasangue);
			}
			if(cod2 == 4){
				system("clear");
				char sangueqt[3] = "AB";
				quantsangue(sangueqt,-1,0, arvore->raiz, arvore);
				printf("Quantidade total de AB doada eh de: %f\n",quantidadedoadasangue);
			}
		}
		if(codigo == 5){
			system("clear");
			printf("INFORME O CODIGO DO PACIENTE: ");
			int codpac;
			scanf("%d",&codpac);
			setbuf(stdin, NULL);
			blocoA *pacienteupdate = buscacodigo(codpac,arvore->raiz,arvore);
			printf("\n");
			printf("QUAL DADO DESEJA ATUALIZAR?\n");
			printf("1-NOME\n");
			printf("2-IDADE\n");
			printf("3-TIPO SANGUINEO\n");
			printf("4-FATOR RH\n");
			printf("5-QUANTIDADE DOADA\n");
			int update;
			scanf("%d",&update);
			setbuf(stdin, NULL);
			char updatenome[50];
			int updateidade;
			char updatetiposangue[3];
			char updatetiporh[10];
			float updatequantidade;
			if(update == 1){
				system("clear");
				printf("INFORME O NOVO NOME: ");
				scanf("%[^\n]s",&updatenome);//para pegar espaços
				setbuf(stdin, NULL);//limpar buffer teclado
				strcpy(pacienteupdate->chave.nome,updatenome);
				printf("\nNOME ATUALIZADO");
			}
			if(update == 2){
				system("clear");
				printf("INFORME A NOVA IDADE: ");
				scanf("%d",&updateidade);//para pegar espaços
				setbuf(stdin, NULL);//limpar buffer teclado
				pacienteupdate->chave.idade = updateidade;
				printf("\nIDADE ATUALIZADA");
			}
			if(update == 3){
				system("clear");
				printf("INFORME O NOVO TIPO SANGUINEO: ");
				scanf("%s",&updatetiposangue);//para pegar espaços
				setbuf(stdin, NULL);//limpar buffer teclado
				strcpy(pacienteupdate->chave.tipo_sangue,updatetiposangue);
				printf("\nTIPO SANGUINEO ATUALIZADO");
			}
			if(update == 4){
				system("clear");
				printf("INFORME O NOVO FATOR RH: ");
				scanf("%s",&updatetiporh);//para pegar espaços
				setbuf(stdin, NULL);//limpar buffer teclado
				strcpy(pacienteupdate->chave.fator_rh,updatetiporh);
				printf("\nFATOR RH ATUALIZADO");
			}
			if(update == 5){
				system("clear");
				printf("INFORME A NOVA QUANTIDADE DE SANGUE DOADA: ");
				scanf("%f",&updatequantidade);//para pegar espaços
				setbuf(stdin, NULL);//limpar buffer teclado
				pacienteupdate->chave.quantidade_doada = updatequantidade;
				printf("\nQUANTIDADE DE SANGUE DOADA ATUALIZADA");
			}
		}
		if(codigo == 6){//cadastrando pacientes apenas na arvore inserecodigo
			system("clear");
			char novonome[50];
			int novoidade;
			char novotiposangue[3];
			char novotiporh[10];
			float novoquantidade;
			paciente novopaciente;
			printf("INFORME O NOME PACIENTE: ");
			scanf("%[^\n]s",&novonome);//para pegar espaços
			strcpy(novopaciente.nome,novonome);
			setbuf(stdin, NULL);//limpar buffer teclado

			printf("\nINFORME A IDADE DO PACIENTE: ");
			scanf("%d",&novoidade);
			novopaciente.idade = novoidade;
			setbuf(stdin, NULL);//limpar buffer teclado

			printf("\nINFORME O TIPO SANGUINEO DO PACIENTE: ");
			scanf("%s",&novotiposangue);
			strcpy(novopaciente.tipo_sangue,novotiposangue);
			setbuf(stdin, NULL);//limpar buffer teclado

			printf("\nINFORME O FATOR RH DO PACIENTE: ");
			scanf("%s",&novotiporh);
			strcpy(novopaciente.fator_rh,novotiporh);
			setbuf(stdin, NULL);//limpar buffer teclado

			printf("\nINFORME A QUANTIDADE DE SANGUE DOADA DO PACIENTE: ");
			scanf("%f",&novoquantidade);
			novopaciente.quantidade_doada = novoquantidade;
			setbuf(stdin, NULL);//limpar buffer teclado

			blocoA *novocod = maiorcod(arvore->raiz,arvore);
			novopaciente.codigo = novocod->chave.codigo + 1;
			inserearvore(&novopaciente, arvore, arvore->raiz, NULL);
			system("clear");
			printf("CADASTRADO COM SUCESSO!");
		}
		if(codigo == 7){
			system("clear");
			printf("OBRIGADO");
			return 0;
		}
		printf("\n");
		printf("Deseja realizar outra operacao?\n");
		printf("1-SIM\n");
		printf("2-NAO\n");
		scanf("%d", &condicao);
		setbuf(stdin, NULL);
		if(condicao == 2){
			system("clear");
			printf("OBRIGADO");
		}
	}
	while(condicao == 1);
	//Fim do laço menu

	return 0;
}

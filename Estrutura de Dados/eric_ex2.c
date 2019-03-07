#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>

// Uma estrutura para a chave
typedef struct intchar{
	int operando;
	char operador;
}intchar;

// Uma estrutura de lista
typedef struct bloco{
	char chave;
	int posicao;
	struct bloco *prox;
	struct bloco *ant;
} bloco;

// Uma estrutura para varias listas
typedef struct lista{
	struct bloco *inicio;
	struct bloco *fim;
} lista;

//Uma estrutura de arvore
typedef struct blocoA{
	char chave;
	int ordem;
	int calc;
	struct blocoA *dir;
	struct blocoA *esq;
}blocoA;

//Uma estrutura para varias arvores
typedef struct arvore{
	struct blocoA *raiz;
}arvore;


int quantidadeoperadores = 0;

//inserelista duplamente encadeado onde o fim sempre é o primeiro elemento inserido
// ex:           NULL <- | 9 | -> | 8 | -> | 7 | -> NULL
// 7,8,9       inicio -> |   | <- |   | <- |   | <- fim
void inserelista(char valor, lista *l){
	bloco *novo = (bloco *) malloc(sizeof(bloco));
	if(l->inicio == NULL){
		novo->chave = valor;
		novo->prox = NULL;
		novo->ant = NULL;
		novo->posicao = 1;
		l->inicio = novo;
		l->fim = novo;
	}
	else{
		novo->chave = valor;
		novo->prox = l->inicio;
		novo->ant = NULL;
		novo->posicao = l->inicio->posicao + 1;
		l->inicio->ant = novo;
		l->inicio = novo;
	}

}

void inserelistanaposicao(char valor, int number, lista *l){
	bloco *novo = (bloco *) malloc(sizeof(bloco));
	if(l->inicio == NULL){
		novo->chave = valor;
		novo->prox = NULL;
		novo->ant = NULL;
		novo->posicao = number;
		l->inicio = novo;
		l->fim = novo;
	}
	else{
		novo->chave = valor;
		novo->prox = l->inicio;
		novo->ant = NULL;
		novo->posicao = number;
		l->inicio->ant = novo;
		l->inicio = novo;
	}

}

void inserearvore(char valor, int numero, arvore *a, blocoA *corre, blocoA *pai){
	if(corre == NULL){
		if(pai == NULL){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = valor;
			novo->ordem = numero;
			novo->calc = -1;
			novo->esq = NULL;
			novo->dir = NULL;
			a->raiz = novo;
			return;
		}
		if(numero > pai->ordem){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = valor;
			novo->ordem = numero;
			novo->calc = -1;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->dir = novo;
			return;
		}
		if(numero < pai->ordem){
			blocoA *novo = (blocoA *) malloc (sizeof(blocoA));
			novo->chave = valor;
			novo->ordem = numero;
			novo->calc = -1;
			novo->esq = NULL;
			novo->dir = NULL;
			pai->esq = novo;
			return;
		}

	}
	if(numero > corre->ordem){
		inserearvore(valor, numero, a, corre->dir, corre);
	}
	else{
		inserearvore(valor, numero, a, corre->esq, corre);
	}

}
void imprimelista(lista *l){
	bloco *temp = l->fim;
	if(temp == NULL){
		printf("Nada a imprimir!\n");
		return;
	}
	while(temp != NULL){
		printf(" %c ", temp->chave);
		temp = temp->ant;
	}
	printf("\n");
}

void imprimelistalegal(lista *l){
	bloco *temp = l->fim;
	if(temp == NULL){
		printf("Nada a imprimir!\n");
		return;
	}
	while(temp != NULL){
		printf("|V:%c P:%d| ", temp->chave, temp->posicao);
		temp = temp->ant;
	}
	printf("\n");
}

void imprimearvore(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia");
		return;
	}

	if(corre != NULL){
		imprimearvore(corre->esq, a);
		printf("%c ", corre->chave);
		imprimearvore(corre->dir, a);
	}
}

void imprimearvorefolhas(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia");
		return;
	}


	if(corre != NULL){
		imprimearvorefolhas(corre->esq, a);
		if(corre->esq == NULL && corre->dir == NULL)
			printf("%c ", corre->chave);
		imprimearvorefolhas(corre->dir, a);
	}
}

void imprimearvorenos(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia");
		return;
	}


	if(corre != NULL){
		imprimearvorenos(corre->esq, a);
		if(corre->esq != NULL || corre->dir != NULL)
			printf("%c ", corre->chave);
		imprimearvorenos(corre->dir, a);
	}
}

void calculo(blocoA *corre, arvore *a){
	if(a->raiz == NULL){
		printf("Arvore vazia");
		return;
	}

	if(corre != NULL){
		imprimearvorefolhas(corre->esq, a);
		if(corre->esq == NULL && corre->dir == NULL)
			printf("%c ", corre->chave);
		imprimearvorefolhas(corre->dir, a);
	}
}

void arrumarexpressao(lista *l, lista *ll){
	bloco *temp = l->fim;
	bloco *abriu = l->fim;
	bloco *fechou = l->fim;
	bloco *guarda = l->fim;

	while(temp != NULL){
		if(temp->chave == '(')
			abriu = temp;
		if(temp->chave == ')'){
			fechou = temp;
			break;
		}
		temp = temp->ant;
	}
	guarda = abriu;
	abriu = abriu->ant;
	while(abriu != fechou){
		inserelistanaposicao(abriu->chave, abriu->posicao, ll);
		abriu = abriu->ant;
	}
	/*temp = l->fim->ant;
	while(temp != NULL){
		if(temp->ant->chave == '('){
			temp->ant = fechou->ant;
			return;
		}
		if(temp->ant->chave == ')'){
			l->fim->ant = fechou->ant;
			return;
		}
		temp = temp->ant;
	}*/

	if(guarda->prox != NULL){
		temp = guarda->prox;
		temp->ant = fechou->ant;
	}


}

lista *crialista(){
	lista *l = (lista*)malloc(sizeof(lista));
	l->inicio = NULL;
	return l;
}

arvore *criaarvore(){
	arvore *a = (arvore*)malloc(sizeof(arvore));
	a->raiz = NULL;
	return a;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int a=0,b=0,c=0;
	char verificando;
	arvore *va[3];

	lista *listainicial = crialista();
	arvore *arvore_de_expressao = criaarvore();

	for(b = 0; b <= 2; b++)
		va[b] = criaarvore();

	//PARA O USUARIO DIGITAR SUA EXPRESSÃO
	printf("\n");
	printf("OBS: PARA PARAR ; DEVE PRESSIONAR!\n");
	printf("\n");
	printf("Informe sua conta: ");
	do
	{
	scanf("%c", &verificando);
	if(verificando != ';')
		inserelista(verificando, listainicial);
	}while(verificando != ';' );
	printf("\n");

	/*
	inserelista('(', listainicial);
	inserelista('(', listainicial);
	inserelista('9', listainicial);
	inserelista('/', listainicial);
	inserelista('3', listainicial);
	inserelista(')', listainicial);
	inserelista('+', listainicial);
	inserelista('(', listainicial);
	inserelista('2', listainicial);
	inserelista('*', listainicial);
	inserelista('2', listainicial);
	inserelista(')', listainicial);
	inserelista(')', listainicial);*/
	printf("expressao: ");
	imprimelista(listainicial);

	//////////////////////////////
	bloco *temp = listainicial->fim;
	while(temp != NULL){
		if(temp->chave == '+' || temp->chave == '-' || temp->chave == '/' || temp->chave == '*')
			quantidadeoperadores = quantidadeoperadores + 1;
		temp = temp->ant;
	}
	/////////////////////////////
	lista *vl[a];
	for(a = 1; a <= quantidadeoperadores; a++)
		vl[a] = crialista();


	for(a = 1; a<= quantidadeoperadores; a++){
		arrumarexpressao(listainicial, vl[a]);
		printf("expressao: ");
		imprimelista(listainicial);
	}

	for(a = 1; a<= quantidadeoperadores; a++)
		imprimelista(vl[a]);

	lista *listao = crialista();
	for(c = quantidadeoperadores; c >= 1; c--){
		while(vl[c]->fim != NULL){
			inserelistanaposicao(vl[c]->fim->chave, vl[c]->fim->posicao, listao);
			vl[c]->fim = vl[c]->fim->ant;
		}
	}
	printf("\n");
	imprimelista(listao);
	imprimelistalegal(listao);

	bloco *temp2= listao->fim;
	while(temp2 != NULL){
		if(temp2->chave == '+' || temp2->chave == '-' || temp2->chave == '*' || temp2->chave == '/')
			inserearvore(temp2->chave, temp2->posicao, arvore_de_expressao, arvore_de_expressao->raiz, NULL);
		temp2 = temp2->ant;
	}

	temp2 = listao->fim;
	while(temp2 != NULL){
		if(temp2->chave != '+' && temp2->chave != '-' && temp2->chave != '*' && temp2->chave != '/')
			inserearvore(temp2->chave, temp2->posicao, arvore_de_expressao, arvore_de_expressao->raiz, NULL);
		temp2 = temp2->ant;
	}
	printf("\n");
	printf("Folhas: ");
	imprimearvorefolhas(arvore_de_expressao->raiz, arvore_de_expressao);
	printf("\n");
	printf("Nos: ");
	imprimearvorenos(arvore_de_expressao->raiz, arvore_de_expressao);
	printf("\n");
	printf("Arvore: ");
	imprimearvore(arvore_de_expressao->raiz, arvore_de_expressao);
	printf("\n");

}

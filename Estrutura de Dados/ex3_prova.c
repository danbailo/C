// Exercício 3 - P1 - Estrutura de Dados
// Nome : Daniel de Leon Bailo da Silva
// RGA: 201718050216
#include<stdio.h>
#include<stdlib.h>

typedef struct SNo{
	struct SNo* prox;
	char chave;
}SNo;

typedef struct Pilha{
	SNo* topo;
}Pilha;

Pilha* criaPilha(){
	Pilha* p=(Pilha*)malloc(sizeof(Pilha));
	p->topo=NULL;
	return p;
}
void insere(Pilha* P,char valor){
	SNo* novo = (SNo*)malloc(sizeof(SNo));
	novo->chave = valor;
	if(P->topo != NULL){
		novo->prox = P->topo;
	}
	P->topo = novo;
}
SNo* remover(Pilha* P){
	SNo* temp = P->topo;
	if(temp != NULL){
		P->topo = P->topo->prox;
	}
	return temp;
}
int validade(char* valor){
	Pilha *P = criaPilha();
	int i = 0;
	char caractere;
	while( (caractere = valor[i++]) ){
		if(caractere == '(' || caractere == '{' || caractere == '['){
			if(caractere == '('){
				insere(P,'(');
			}
			else if(caractere == '{'){
				insere(P,'{');
			}
			else{
				insere(P,'[');
			}
		}
		else if(caractere == ']' || caractere == ')' || caractere == '}'){
			SNo *aux = remover(P);
			if(aux == NULL){
				return 0;
			}
			if( caractere ==')'){
				if(aux->chave != '('){
					return 0;
				}
			}
			else if(caractere == '}'){
				if(aux->chave != '{'){
					return 0;
				}
			}
			else{
				if(aux->chave != '['){
					return 0;
				}
			}
		}
	}
	if(P->topo == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){

	char valor[] = "[[[[[[[[[[[[((((((((()))))))))]]]]]]]{{{}}}]]]]1232][][[]({}))]";
	char flag = validade(valor);

	if(flag){//se for 1(true) retorna valido
		printf("Valido\n");
	}
	else{//se for 0(false) retorna invalido
		printf("inValido\n");
	}
	return 0;
}

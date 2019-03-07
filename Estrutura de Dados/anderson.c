#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct No{
	struct No* prox;
	char val;
}No;
typedef struct Pilha{
	No* topo;
}Pilha;
Pilha* criarPilha(){
	Pilha* p=(Pilha*)malloc(sizeof(Pilha));
	p->topo=NULL;
	return p;
}
void empilhar(Pilha* p,char v){
	No* n=(No*)malloc(sizeof(No));
	n->val=v;
	if(p->topo!=NULL){
		n->prox=p->topo;
	}
	p->topo=n;
}
No* desempilhar(Pilha*p){
	No*ans=p->topo;
	if(ans!=NULL){
		p->topo=p->topo->prox;
	}
	return ans;
}
bool pcheck(char* str){
	Pilha*p=criarPilha();
	int i=0;
	char c;
	while( (c=str[i++]) ){
		if(c=='('||c=='{'||c=='['){
			if(c=='('){
				empilhar(p,'(');
			}
			else if(c=='{'){
				empilhar(p,'{');
			}
			else{
				empilhar(p,'[');
			}
		}
		else if(c==')'||c=='}'||c==']'){
			No *aux= desempilhar(p);
			if(aux == NULL){
				return false;
			}
			if( c==')'){
				if(aux->val != '('){
					return false;
				}
			}
			else if(c=='}'){
				if(aux->val != '{'){
					return false;
				}
			}
			else{
				if(aux->val != '['){
					return false;
				}
			}
		}
	}
	if(p->topo==NULL){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	char  str[64];
	fgets(str,64,stdin);
	if(pcheck(str)){
		printf("valido\n");
	}
	else{
		printf("invalido\n");
	}
}

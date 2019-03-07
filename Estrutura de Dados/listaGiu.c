#include "lista.h"
void criaLista( Lista *L){
	L->inicio=0;
	L->fim=0;
}

void Inserir( Lista *L, int n){
    Celula* ans = malloc(sizeof(Celula));
    ans->valor=n;
    if(!L->inicio&&!L->fim){
    	L->inicio=ans;
    	L->fim=ans;
    }
    else{
    	L->fim->proximo=ans;
    	L->fim=ans;
    }
}

void Remover (Lista *L, int n){
    Celula* ant=NULL;
    Celula* at=L->inicio;
    int f=0;
    if(at==NULL){
        printf("Lista vazia\n");
    }
    else if(at->proximo==NULL){
        if(at->valor==n){
            criaLista(L);
            free(at);
            at=NULL;
            f=1;
        }
    }

    while(at!=NULL){
    	if(at->valor==n){
            f=1;
    		if(ant!=NULL&&at->proximo!=NULL){//No meio
    			ant->proximo=at->proximo;
    			free(at);
                ant=at->proximo;
                if(ant!=NULL){
                    at=ant->proximo;
                }
                else{
                    at=ant;
                }
    		}
            else if(ant==NULL&&ant->proximo!=NULL){//No comeco
                L->inicio=at->proximo;
                ant=at;
                if(at->proximo!=NULL){
                    at=at->proximo;
                }
                else{
                    at=NULL;
                }
                free(ant);
                ant=NULL;
            }
            else if(at->proximo==NULL){//No final
                L->fim=ant;
                ant->proximo=NULL;
                at=NULL;
            }

    	}
        else{
        	ant=at;
        	at=at->proximo;
        }
    }
    if(!f)printf("Lista nao mudou\n");
    else Imprime(L);
}

int Tamanho( Lista *L){
    Celula* at=L->inicio;
    int i=0;
    while(at!=NULL){
    	i++;
    	at=at->proximo;
    }
    return i;
}

int Busca(Lista *L, int n){
    Celula* at=L->inicio;
    int i=0;
    int f=0;
    while(at!=NULL){
    	if(at->valor==n){
    		printf("%i\n",i);
    		f=1;
    	}
    	i++;
    	at=at->proximo;
    }
    return f;
}

void Imprime( Lista *L){
    Celula* at=L->inicio;
    putchar('|');
    while(at!=NULL){
    	printf("%i",at->valor);
    	if(at->proximo!=NULL){
    		printf("->");
    	}
    	at=at->proximo;
    }
    printf("|\n");
}
void Menu (Lista* L){
    int c;
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Buscar\n");
    printf("4 - Tamanho\n");
    printf("5 - Imprimir\n");
    printf("Digite uma das opcoes:");

    scanf("%i",&c);
    switch(c){
    	case 0:
    		exit(0);
    	case 1:
    		printf("Digite o numero a ser inserido:");
    		scanf("%i",&c);
    		Inserir(L,c);
    		break;
    	case 2:
    		printf("Digite o numero a ser removido:");
    		scanf("%i",&c);
    		Remover(L,c);
    		break;
    	case 3:
    		printf("Digite o número a ser procurado:");
    		scanf("%i",&c);
    		if(!Busca(L,c)){
                printf("Valor nao encontrado\n");
            }
    		break;
    	case 4:
    		printf("Tamanho lista:%i\n",Tamanho(L));
    		break;
    	case 5:
    		Imprime(L);
    		break;
        default:
            printf("opcao invalida\n");
    }
    printf("Aperte enter para continuar\n");
    getchar();
    getchar();
}

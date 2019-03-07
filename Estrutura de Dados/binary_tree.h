#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node;

node *root=NULL;

void insert_node(node* r, int value, node* father){
  if(r==NULL){//condicao de parada
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->right = NULL;
    new_node->left = NULL;
    if(father == NULL){ //isso quer dizer que a raiz nao é mais NULL
      root = new_node;  // pois recebe o proprio no da primeira chamada;
      return;           // logo, a raiz sera o primeiro no;
    }
    else if(value > father->data)
      father->right = new_node;
    else if(value < father->data)
      father->left = new_node;
  }
  else if(value > r->data){
    insert_node(r->right, value, r);
  }
  else if(value < r->data){
    insert_node(r->left, value, r);
  }
  else{
    printf("\nThis value is already contained in the tree!");
    return;
  }
}

void preOrder(node* r){
  if(r==NULL)
    return;

  printf("\n%d",r->data);
  preOrder(r->left);
  preOrder(r->right);
}

void postOrder(node *r){
  if(r==NULL)
    return;

  postOrder(r->left);
  postOrder(r->right);
  printf("\n%i",r->data);
}

void inOrder(node *r){
  if(r==NULL)
    return;

  inOrder(r->left);
  printf("%i\n",r->data);
  inOrder(r->right);
}

int search(node *r, int value){
  if(r==NULL){//Condição de parada;
    printf("\nO elemento %d não está na árvore!", value);
    return 0;
  }
  else if(value > r->data){
    search(r->right, value);
    // return 0;
  }
  else if(value < r->data){
    search(r->left, value);
    // return 0;
  }
  else{
    printf("\nO elemento %d está na árvore!", value);
    return 1;
  }
  return 0;
}

int get_large(node *r){//maior elemento com função int;
  if(r==NULL)//arvore vazia;
    return 0;

  if(r->right==NULL){//Condição de parada;
    return r->data;
  }
  return get_large(r->right);//retornar a empilhada das recursões;
}

void print_large(){
  printf("\nO maior elemento da árvore é %d",get_large(root));
}

int get_small(node *r){
  if(r==NULL)//arvore vazia;
    return 0;

  if(r->left==NULL){//Condição de parada;
    return r->data;
  }
  return get_small(r->left);
}

void print_small(){
  printf("\nO menor elemento da árvore é %d",get_small(root));
}

int height(node *r){
  int height_right,height_left;

  if(r==NULL)
    return 0;

  height_right = height(r->right);
  height_left = height(r->left);

  if(height_right>height_left){
    // printf("A altura da árvore é %d",AD);
    return (height_right+1);
  }
  else{
    // printf("A altura da árvore é %d",AE);
    return (height_left+1);
  }
}

void print_height(){
  printf("\nA altura da árvore é %d",height(root));
}

void delete_node(node *r, int value, node *father){
	if(r == NULL){
		printf("\n\tA arvore esta vazia, nâo tem elementos para serem removidos");
		return;
	}
  else if(r->data == value){
    if(r->right == NULL && r->left == NULL){
      if(father->left->left == NULL && father->left->right == NULL){
        free(r);
        father->left = NULL;
      }
      if(father->right->right == NULL && father->right->left == NULL){
        free(r);
        father->right = NULL;
      }
    }
  }
  else if(value < r->data){
    delete_node(r->left, value, r);
  }
  else if(value > r->data){
    delete_node(r->right, value, r);
  }

	printf("\n");
}

node* abb_retira(node* r, int value){
  if (r == NULL)
    return NULL;
  else if (r->data > value)
    r->left = abb_retira(r->left, value);
  else if (r->data < value)
    r->right = abb_retira(r->right, value);
  else { /* achou o nó a remover */
    if (r->left == NULL && r->right == NULL) {/* nó sem filhos */
      free (r);
      r = NULL;
    }
    else if (r->left == NULL) {/* nó só tem filho à direita */
      node* temp = r;
      r = r->right;
      free (temp);
    }
    else if (r->right == NULL) {/* só tem filho à esquerda */
      node* temp = r;
      r = r->left;
      free (temp);
    }
    else {/* nó tem os dois filhos */
      node* aux = r->left;
      while (aux->right != NULL) {
        aux = aux->right;
    }
    r->data = aux->data; /* troca os valuees dos nós */
    aux->data = value;
    r->left = abb_retira(r->left,value);
    }
  }
  return r;
}

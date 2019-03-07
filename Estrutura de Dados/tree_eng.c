// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int key;
  struct node *left;
  struct node *right;
  int index;
}node;

struct tree{
  node* root;
  int index;
}tree;

void start_tree(){
  tree.root = NULL;
  tree.index = 0;
}

// tree.root = NULL;

// A utility function to create a new BST node
node *newNode(int item){
  node *temp = (node *)malloc(sizeof(node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// A utility function to do inorder traversal of BST
void inOrder(node *root){
  if (root == NULL)
    return;

  inOrder(root->left);
  printf("%d \n", root->key);
  inOrder(root->right);
}

void preOrder(node *root){
  if(root == NULL)
    return;

  printf("%d \n",root->key);
  preOrder(root->left);
  preOrder(root->right);
}

// C function to search a given key in a given BST
node* search(node* root, int key){
  // Base Cases: root is null or key is present at root
  if(root == NULL){
    printf("the value %d NOT are present in tree",key);
    return root;
  }

  // Key is greater than root's key
  else if (root->key < key)
    return search(root->right, key);

  // Key is smaller than root's key
  else if (root->key > key)
    return search(root->left, key);

  else{// Base Cases: root is null or key is present at root
    printf("the value %d are present in tree",key);
    return root;
  }
}

/* A utility function to insert a new node with given key in BST */
node* insert(node* node, int key){

  // first insertion for define the root of tree
  if(tree.root == NULL){
    tree.root = newNode(key);
  }
  /* If the tree is empty, return a new node */
  if (node == NULL){
    return newNode(key);
  }
  /* Otherwise, recur down the tree */
  if (key < node->key)
    node->left  = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  /* return the (unchanged) node pointer */
  return node;
}

int get_large(node* root) {
  node *temp = root;

  /* loop down to find the leftmost leaf */
  while (temp->right != NULL) {
    temp = temp->right;
  }
  return(temp->key);
}

int get_small(node* root) {
  node *temp = root;

  /* loop down to find the leftmost leaf */
  while (temp->left != NULL) {
    temp = temp->left;
  }
  return(temp->key);
}

node *getLarge(node *root) {
  if(root == NULL) // arvore vazia
      return NULL;
  if(root->right == NULL)
      return root;
  return getLarge(root->right);
}

node *getSmall(node *root){
  if(root == NULL) // arvore vazia
      return NULL;
  if(root->left == NULL)
      return root;
  return getSmall(root->left);
}

int height(node *node){
  int height_right,height_left;

  if(node==NULL) // Base case and stop condition
    return 0;

  height_right = height(node->right);
  height_left = height(node->left);

  if(height_right>height_left)
    return (height_right+1);
  else
    return (height_left+1);
}

int depth(node *node, int key){//r igual ao nó, para condição de parada
  int height_right,height_left;

  if(node==NULL) // Base case and stop condition
    return 0;

  height_right = depth(node->right, key);
  height_left = depth(node->left, key);

  if(height_right>height_left){
    return (height_right+1);
  }
  else{
    return (height_left+1);
  }
}

node* deleteNode(node* root, int key){
  // base case and stop condition
  if (root == NULL)
    return root;

  // If the key to be deleted is smaller than the root's key,
  // then it lies in left subtree
  if (key < root->key)
      root->left = deleteNode(root->left, key);

  // If the key to be deleted is greater than the root's key,
  // then it lies in right subtree
  else if (key > root->key)
      root->right = deleteNode(root->right, key);

  // if key is same as root's key, then This is the node
  // to be deleted
  else{
    // node with only one child or no child
    if (root->left == NULL){
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL){
      node *temp = root->left;
      free(root);
      return temp;
    }

    // node with two children: Get the inorder successor (smallest
    // in the right subtree)
    node* temp = getSmall(root->right);
    // Copy the inorder successor's content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void print_height(){
  printf("\nthe height of this tree is %d",height(tree.root));
}

// void print_depth(){
//   printf("\nthe depth of this tree is %d",depth(tree.root,key));
// }

// Driver Program to test above functions
int main(){


  /* Let us create following BST
            50
         /     \
        30      70
        /  \    /  \
      20   40  60   80 */
  // start_tree();
  printf("index:%d",tree.index);
  insert(tree.root, 12);
  insert(tree.root, 52);
  insert(tree.root, 231);
  insert(tree.root, 45);
  insert(tree.root, 5);
  insert(tree.root, 8);
  insert(tree.root, 9);
  printf("index:[%d]",tree.index);

  // printf("root=%d\n",root->key);
  // print inoder traversal of the BST
  printf("inOrder:\n");
  inOrder(tree.root);

  printf("preOrder:\n");
  preOrder(tree.root);

  printf("\nsmall: %d ",getSmall(tree.root)->key);
  printf("\nlarge: %d ",getLarge(tree.root)->key);
  printf("\n");
  search(tree.root,30);
  printf("\n");
  search(tree.root,45);
  print_height();
  printf("\n");
  deleteNode(tree.root,12);
  printf("\n");
  printf("inOrder:\n");
  inOrder(tree.root);

  printf("preOrder:\n");
  preOrder(tree.root);

  deleteNode(tree.root,9);
  printf("\n");
  printf("inOrder:\n");
  inOrder(tree.root);

  printf("preOrder:\n");
  preOrder(tree.root);
  printf("\nnew root is: %d",tree.root->key);
  return 0;

}

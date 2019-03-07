
// C program to delete a node from AVL Tree
#include<stdio.h>
#include<stdlib.h>
#include "final.h"
// An AVL tree node

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get altura of the tree
int altura( SNo *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

// A utility function to FD rotate subtree rooted with y
// See the diagram given above.
 SNo *FD_rotacao( SNo *y)
{
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
 SNo *FE_rotacao( SNo *x)
{
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
int get_balance( SNo *R)
{
    if (R == NULL)
        return 0;
    return altura(R->FE) - altura(R->FD);
}

SNo* insere_arv(SNo *R, char *nome, int idade, char tipo[], char fatorRh[], float quantidade, int codigo){
    /* 1.  Perform the normal BST rotation */
    if (R == NULL)
        return(novo_arvore(nome, idade, tipo, fatorRh, quantidade, codigo));

    if (codigo < R->codigo)
        R->FE  = insere_arv(R->FE, nome, idade, tipo, fatorRh, quantidade, codigo);
    else if (codigo > R->codigo)
        R->FD = insere_arv(R->FD, nome, idade, tipo, fatorRh, quantidade, codigo);
    else // Equal chaves not allowed
        return R;

    /* 2. Update altura of this ancestor node */
    R->altura = 1 + max(altura(R->FE),altura(R->FD));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = get_balance(R);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && codigo < R->FE->codigo)
        return FD_rotacao(R);

    // Right Right Case
    if (balance < -1 && codigo > R->FD->codigo)
        return FE_rotacao(R);

    // Left Right Case
    if (balance > 1 && codigo > R->FE->codigo)
    {
        R->FE =  FE_rotacao(R->FE);
        return FD_rotacao(R);
    }

    // Right Left Case
    if (balance < -1 && codigo < R->FD->codigo)
    {
        R->FD = FD_rotacao(R->FD);
        return FE_rotacao(R);
    }

    /* return the (unchanged) node pointer */
    return R;
}

/* Given a non-empty binary search tree, return the
   node with menorimum chave value found in that tree.
   Note that the entire tree does not need to be
   searched. */
 SNo * menor_valorSNo( SNo* R)
{
     SNo* temp = R;

    /* loop down to find the FEmost leaf */
    while (temp->FE != NULL)
        temp = temp->FE;

    return temp;
}

// Recursive function to delete a node with given chave
// from subtree with given root. It returns root of
// the modified subtree.
 SNo* deleteSNo( SNo* root, int codigo)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the codigo to be deleted is smaller than the
    // root's codigo, then it lies in FE subtree
    if ( codigo < root->codigo )
        root->FE = deleteSNo(root->FE, codigo);

    // If the codigo to be deleted is greater than the
    // root's codigo, then it lies in FD subtree
    else if( codigo > root->codigo )
        root->FD = deleteSNo(root->FD, codigo);

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
            root->FD = deleteSNo(root->FD, temp->codigo);
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

/* Driver program to test above function*/
int main(){
   SNo *root = NULL;

  /* Constructing tree given in the above figure */
    root = insere_arv(root, "daniel", 15, "A", "positivo", 123.2, 0);
    root = insere_arv(root, "daniel", 15, "A", "positivo", 123.2, 1);
    root = insere_arv(root, "daniel", 15, "A", "positivo", 123.2, 5);
    // root = insere_arv(root, 5);
    // root = insere_arv(root, 10);
    // root = insere_arv(root, 0);
    // root = insere_arv(root, 6);
    // root = insere_arv(root, 11);
    // root = insere_arv(root, -1);
    // root = insere_arv(root, 1);
    // root = insere_arv(root, 2);

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    em_ordem(root);

    root = deleteSNo(root, 5);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal after deletion of 10 \n");
    em_ordem(root);

    return 0;
}

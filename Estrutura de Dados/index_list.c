// C program to find n'th
// node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Link list node
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

/* Given a reference (pointer to
   pointer) to the head of a list
   and an int, push a new node on
   the front of the list. */
void push(  Node** head_ref,
                    int new_data)
{

    // allocate node
      Node* new_node =
            (  Node*) malloc(sizeof(  Node));

    // put in the data
    new_node->data = new_data;

    // link the old list
    // off the new node
    new_node->next = (*head_ref);

    // move the head to point
    // to the new node
    (*head_ref) = new_node;
}

// Takes head pointer of
// the linked list and index
// as arguments and return
// data at index
int GetNth(Node *head,int index){
    Node *current = head;

     // the index of the
     // node we're currently
     // looking at
    int count = 0;
    while (current != NULL){

      if (count == index)
        return(current->data);

      count++;
      current = current->next;
    }

    /* if we get to this line,
       the caller was asking
       for a non-existent element
       so we assert fail */
    assert(0);
}

void print_list(  Node* head){
    Node *temp = head;

  while(temp!=NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }

}

// Driver Code
int main()
{

    // Start with the
    // empty list
      Node* head = NULL;

    // Use push() to construct
    // below list
    // 1->12->1->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    // print_list(head);
    printf("\n");
    // Check the count
    // function
    printf("Element at index 3 is %d",GetNth(head, 3));
    getchar();
}

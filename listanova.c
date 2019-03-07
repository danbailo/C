#include<stdio.h>
#include<stdlib.h>

typedef struct dataNode{
  int id;
}DataNode;

typedef struct node{
  DataNode data;
  struct node *next;
}Node;

typedef struct list{
  int size;
  Node* head;
}List;

List* createList();
void push(List* list, DataNode data);
void printList(List* list);

List* createList(){
  List* list = (List*)malloc(sizeof(List));
  list->size=0;
  list->head=NULL;

  return list;
}

void push(List* list, DataNode data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = list->head;
  list->head = node;
  list->size++;
}

void printList(List* list){
  Node* pointer = list->head;

  if(pointer==NULL)
    printf("Lista vazia");

  while(pointer!=NULL){
    printf("%d",pointer->data.id);
    pointer = pointer->next;
  }

  printf("\n");

}

int main(){
  List* lista = createList();
  DataNode data;

  data.id=23;
  push(lista,data);

  printList(lista);
}

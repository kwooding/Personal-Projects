#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//Creating the variable fields for each node within the linked list. gives each node a data value and sets a previous and next node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

//Creates a new node with an assigned data value that is an integer and returns the node with its current position unknown
Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}
//allows you to assign a node to be deleted and using the head node as reference it deletes the given node and moves pointers to point correctly
void deleteNode(Node **head_ref, Node *del_node){
    if(*head_ref == NULL || del_node == NULL){
        return;
    }

    if(*head_ref == del_node){
        *head_ref = del_node->next;
    }

    if(del_node->next != NULL){
        del_node->next->prev = del_node->prev;
    }

    if(del_node->prev == NULL){
        del_node->next->prev == del_node->next;
    }

    free(del_node);
}
//can insert a node at any given postion in the linked list and assigns the proper next and previous nodes
void insertNode(Node **head_ref,int data,int position){
    Node *newNode = createNode(data);

    if(*head_ref == NULL){
        *head_ref = newNode;
        return;
    }

    if(position <= 0){
        newNode->next = *head_ref;
        (*head_ref)->prev = newNode;
        *head_ref = newNode;
        return;
    }

    Node *current = *head_ref;
    int i;
    for(i = 0; i < position -1; i++){
        current = current->next;
    }

    if(current->next == NULL && i < position - 1){
        current->next = newNode;
        newNode->prev = current;
    }else{
        newNode->next = current->next;
        newNode->prev = current;
        if(current->next == NULL){
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void printList(Node *node){
    printf("List: ");
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){

    Node *head = NULL;
    int length, i;
    int data, postion;
    char continue_choice;

    srand(time(NULL));

    printf("Enter the length of List that you want\n");
    scanf("%d", length);

    for(i =0; i < length; i++){
        data = rand() % 100 + 1;
        insertNode(&head,data,i);
    }

    printf("Initial ");
    printList(head);



}
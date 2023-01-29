#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node *create(){
    Node *new = (Node *)malloc(sizeof(Node));
    printf ("Enter element to add:\n");
    scanf ("%d", &new->data);
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void *insert_beginning (Node **headref){
    Node *new=create();

    if (*headref==NULL)
        (*headref)=new;

    else{
        new->next=(*headref);
        (*headref)->prev=new;
        (*headref)=new;
    }
}

void *insert_left (Node **headref){

    Node *new=create(), *temp=(*headref);

    int key;
    printf ("Enter key to insert left of:\n");
    scanf ("%d", &key);

    while (temp!=NULL && temp->data != key){
        temp=temp->next;
        if (temp==NULL)
        printf ("Key doesn not exist!\n");
    }
    new->next=temp;
    new->prev=temp->prev;
    (temp->prev)->next=new;
    temp->prev=new;
}

void delete (Node **headref){

    Node *temp=(*headref);

    int key;
    printf ("Enter element to delete:\n");
    scanf ("%d", &key);

    if (key==temp->data){
        temp=temp->next;
        temp->prev=NULL;
        free(*headref);
        (*headref)=temp;
    }
    else{
        while (temp!=NULL && temp->data != key){
            temp=temp->next;
        }
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
    }
}

void display (Node **headref){
    Node *ptr=(*headref);

    if (ptr==NULL)
     printf ("List is empty!\n");

    while (ptr!=NULL){
        printf ("%d  ", ptr->data);
        ptr=ptr->next;
    }
}


int main(){

    Node *head=NULL;
    int choice;

    while (1){
        printf ("\n1:Insert\n2:Insert left\n3:Delete\n4:Display\nENTER ANY OTHER NUMBER TO EXIT!\n");
        scanf ("%d",&choice);

        switch (choice){
        case 1:insert_beginning(&head);
        display(&head);
        break;
        
        case 2:insert_left(&head);
        display(&head);
        break;

        case 3:delete(&head);
        display(&head);
        break;
        
        case 4:display(&head);
        break;

        default:exit(0);
        break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create(){
    Node *new = (Node *)malloc(sizeof(Node));
    printf ("Enter element to insert:\n");
    scanf ("%d",&new->data);
    new->next=NULL;
    return new;
}

void push(Node **headref){
    Node *new=create();

    if ((*headref)==NULL)
        (*headref)=new;
    
    else{
        new->next= (*headref);
        (*headref)=new;
    }
}

void pop(Node **headref){
    Node *temp=(*headref);

    if(temp==NULL)
        printf("List is empty!\n");

    else{
        (*headref)=temp->next;
        free(temp);
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

int main (){

    int user_input;
    Node *head=NULL;

    while (1){
        printf ("\n1:Push\n2:Pop\n3.Display\n4.Quit\n");
        scanf ("%d",&user_input);

        switch (user_input){

            case 1: push (&head);
            break;

            case 2: pop (&head);
            break;

            case 3: display(&head);
            break;

            case 4: exit (0);
            break;
         }
    }

    return 0;
}

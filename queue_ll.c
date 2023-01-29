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

void enqueue(Node **headref){
    Node *temp=*headref, *new=create();

    if (temp==NULL)
        (*headref)=new;

    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}
void dequeue(Node **headref){
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

int main(){

    Node *head=NULL;
    int choice;

    while (1){
        printf ("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Quit\n");
        scanf ("%d",&choice);

        switch (choice){

            case 1:enqueue (&head);
            break;

            case 2:dequeue(&head);
            break;

            case 3:display(&head);
            break;

            case 4:exit (0);
            break;

            default:printf ("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
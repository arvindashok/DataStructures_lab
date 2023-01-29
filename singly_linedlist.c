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

void insert_front(Node **headref){
    Node *new=create();

    if ((*headref)==NULL)
        (*headref)=new;
    
    else{
        new->next= (*headref);
        (*headref)=new;
    }
}

void insert_end(Node **headref){
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

void insert_mid(Node **headref){
    Node *temp=*headref, *new=create();
    int key;
    printf ("Enter position to insert:\n");
    scanf("%d",&key);
    
    if (temp==NULL){
        (*headref)=new;
        return;
    }   
    if(key==1){
        new->next=(*headref);
        (*headref)=new;
        return;
    }

    for (int i=1; i<key; i++){
        // if (temp->next==NULL){
        //     break;
        // }
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next==new;

}

void delete_begining (Node **headref){
    Node *temp=(*headref);

    if(temp==NULL)
        printf("List is empty!\n");

    else{
        (*headref)=temp->next;
        free(temp);
    }
}

void delete_end (Node **headref){
    Node *temp=(*headref),*ptr=NULL;
    while (temp->next!=NULL){
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
}

void delete_mid (Node **headref){

    Node *temp=*headref, *prev=NULL;
    int key;

    printf ("Enter element to delete:\n");
    scanf ("%d",&key);

    if (key==temp->data){
        delete_begining(headref);
        return;
    }
    
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}

Node *reverse (Node **headref){
    Node *temp=*headref;
    Node *next=NULL, *prev=NULL;

    while (temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    (*headref)=prev;
}

void sort_data (Node **headref){
    int temp;
    for (Node *first=*headref; first!=NULL; first=first->next){
        for (Node *second=first->next; second!=NULL; second=second->next){
            if (first->data > second->data){
                temp=first->data;
                first->data=second->data;
                second->data=temp;
            }
        }
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

Node *concat (Node **n1, Node **n2){

    if (*n1==NULL) return *n2;

    else if (*n2==NULL) return *n1;

    else{
        Node *temp=*n1;
        while (temp->next!=NULL)
            temp=temp->next;
        temp->next=(*n2);
    }
    return *n1;
}

void second_insert(Node **head){
    int k=1, choice;
    while(k==1){
        printf ("\t  1:Insert\n");
        scanf ("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_front (head);
            break;
        
        default:k++;
            break;
        }
    }
}

int main(){

    int choice;
    Node *head=NULL, *head1=NULL;

    while(1){
        printf("\n1:Insert beginning\n2:Insert at position\n3:Insert end\n4:Display\n5:Delete beginning\n6:Delete element\n7:Delete last\n8:Reverse\n9:Sort\n10:Concatenate\nENTER ANY OTHER NUMBER TO EXIT\n");
        scanf ("%d",&choice);

    switch (choice){

        case 1:insert_front(&head);
        display(&head);
        break;
        
        case 2:insert_mid(&head);
        display(&head);
        break;

        case 3:insert_end(&head);
        display(&head);
        break;

        case 4:display(&head);
        break;
        
        case 5:delete_begining(&head);
        display(&head);
        break;

        case 6:delete_mid(&head);
        display(&head);
        break;

        case 7:delete_end(&head);
        display(&head);
        break;

        case 8:reverse(&head);
        display (&head);
        break;

        case 9:sort_data(&head);
        display (&head);
        break;

        case 10:second_insert(&head1);
        display (&head1);
        head=concat(&head, &head1);
        break;

        default:exit(0);
        break;
    }
    }
    return 0;
}

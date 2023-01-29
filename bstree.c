#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *create(){
    Node *new = (Node *)malloc(sizeof(Node));
    new->left=NULL;
    new->right=NULL;
    return new;
}

Node *insert(Node *root, int val){ 

    Node *new=create();
    new->data=val;  

    if(root==NULL){ 
        root=new; 
        return root; 
    } 
    else{ 
        if(val < root->data){ 
            if(root->left==NULL) 
                root->left=new; 
            else
                root->left=insert(root->left,val);   
        } 
        else if(val > root->data){ 
            if(root->right==NULL)
                root->right=new;
            else
                root->right=insert(root->right,val); 
        }
        return root; 
    }
}

void inorder (Node *root){
    if (root!=NULL){
        inorder (root->left);
        printf ("%d  ",root->data);
        inorder (root->right);
    }
}
void preoder (Node *root){
    if (root!=NULL){
        printf ("%d  ",root->data);
        inorder (root->left);
        inorder (root->right);
    }
}
void postorder (Node *root){
    if (root!=NULL){
        inorder (root->left);
        inorder (root->right);
        printf ("%d  ",root->data);
    }
}

int main(){
    
    Node *root=NULL, *new=create();
    int choice, x;

    while(1){
        printf ("\n1:Insert\n2:In-order\n3:Pre-order\n4:Post-order\nENTER ANY OTHER NUMBER TO EXIT\n");
        scanf ("%d",&choice);

        switch (choice){

        case 1:printf ("Enter element to insert:\n");
            scanf ("%d",&x);
            root=insert(root, x);
            break;

        case 2:inorder(root);
            break;

        case 3:preoder(root);
            break;

        case 4:postorder(root);
            break;
        
        default:exit(0);
            break;
        }
    }

    return 0;
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 3
int a[size],front=-1,rear=-1;

int isEmpty(){
    if(front==-1&&rear==-1){
        return 1;
    }
    else 
    return 0;
}

int isFull(){
    if(front==(rear+1)%size){
        return 1;
    }
    else 
    return 0;
}

void enqueue(int *x){
    if(isFull()){
        printf("Overflow\n");
    }
    else if(isEmpty()){
        rear=front=0;
        a[rear]=*x;
    }
    else{
        rear=(rear+1)%size;
        a[rear]=*x;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Underflow\n");
    }
    else if(rear==front)
    {
        front=-1;
        rear=-1;
    }else{
        front=(front+1)%size;
    }
}

void display()
{
    if(isEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        for(int i=front;i!=rear;i=(i+1)%size){
            printf("%d  ",a[i]);
        }
        printf("%d\n",a[rear]);
    }
}

int main()
{
   int choice,x;

    while(1){
        printf("1:Push\n2:Pop\n3:Display\n4:Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element:\n");
            scanf("%d",&x);
            enqueue(&x);
            break;

            case 2:dequeue();
            break;

            case 3:  display();
            break;

            case 4: exit(0);
            break;

            default: printf("Invalid input");
        }
    }
    return 0;
}

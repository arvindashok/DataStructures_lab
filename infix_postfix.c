#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 50
int top=-1;
char stack[size];
void push(char value){
    stack[++top]=value;
}
char pop(){
    return(stack[top--]);
}
int pr(char symbol){
    if(symbol=='^'){
        return 3;
    }
    else if(symbol=='*'||symbol=='/'){
        return 2;
    }
    else if(symbol=='+'||symbol=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
void main(){
    int i=0,k=0;
    char infix[50],postfix[50];
    char ch,elem;
    
    printf("\nEnter the infix expression: ");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
           push(ch); 
        }
        else
        
            if(isalnum(ch))
            {
                postfix[k++]=ch;
            }
            else
            
                if(ch==')')
                {
                    while(stack[top]!='(')
                    {
                        postfix[k++]=pop();

                    }
                    elem=pop();
                }
                else
                {
                    while(pr(stack[top])>=pr(ch))
                    {
                       postfix[k++]=pop(); 
                    }
                    push(ch);
                }
            
        
    }
    while(stack[top]!='#')
    {
       postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("\nThe postfix expression is %s",postfix);
    
}
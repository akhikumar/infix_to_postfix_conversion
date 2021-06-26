#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char * arr;
};

int isEmpty(struct stack * sp)
{
    if(sp->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack * sp)
{
    if(sp->top==sp->size-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack * sp, char element)
{
    if(isFull(sp))
    {
        printf("stack is overflow\n");
        
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=element;
    }
}
int pop(struct stack * sp)
{
    if(isEmpty(sp))
    {
        printf("stack is underflow\n");
        
    }
    else
    {
        char val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
char  stackTop(struct stack * sp) //
{
    return sp->arr[sp->top];
}
int isOperator(char  infix) //
{
    if(infix=='+' || infix=='-'||infix=='*'||infix=='/')
    {
        return 1;

    }
    else
    return 0;
}
int precedence(char  infix) //
{
    if(infix=='*' || infix=='/')
    {

    return 3;
    }
    else if(infix=='+' || infix=='-')
    {

    return 2;
    }
    else
    {

    return 0;
    }

}
char * infixToPostfix(char *infix)
{
    struct stack * sp=(struct stack *) malloc(sizeof(struct stack));
    sp->size=15;
    sp->top=-1;
    sp->arr=(char *) malloc(sp->size * sizeof(char));
    char * postfix=(char *) malloc((strlen(infix)+1) * sizeof(char)); // here we add +1 to strlen(infix) because there is also \0 character in c language but strlen only calculate the length of only character;
     int i=0;
     int j=0;
     while(infix[i]!='\0')
     {
         if(!isOperator(infix[i]))
         {
             postfix[j]=infix[i];
             j++;
             i++;

         }
         else{
             if(precedence(infix[i])>precedence(stackTop(sp)))
             {
                 push(sp,infix[i]);
                 i++;
             }
             else
             {
                 postfix[j]=pop(sp);
                 j++;
             }
         }
     }
     while(!isEmpty(sp))
     {
         postfix[j]=pop(sp);
         j++;
     }
     postfix[j]='\0';

     return postfix;

}
int main(){
    char * infix="a+b/c+d*c*h+p/i/y*r";
     
     printf("The postfix expression are: %s",infixToPostfix(infix));
    return 0;
}
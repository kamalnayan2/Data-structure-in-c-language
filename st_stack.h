#include<stdio.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    return 1;
    else 
    return 0;
}
int isful(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    else 
    return 0;
}
void push(struct stack *ptr,int val)
{
    int isf=isful(ptr);
    if(isf==1)
    {
        printf("stack is overflow\n");
    }
    else
    {
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr)
{
    int temp,ise=isempty(ptr);
    if(ise==1)
    printf("the stack is underflow\n");
    else
    {
        temp=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return temp;
    }
}
void display(struct stack *ptr)
{
    int i;
    for(i=0;i<(ptr->top+1);i++)
    printf("%d\t",ptr->arr[i]);
}
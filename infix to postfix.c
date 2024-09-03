#include<conio.h>
#include<stdio.h>
# define max 20
typedef struct
{
    int data[max];
    int top;
}stack;

void initstack(stack *ps)
{
    ps->top=-1;
}

int isEmpty(stack *ps)
{
    return(ps->top==-1);
}

int isFull(stack *ps)
{
    return(ps->top==max-1);
}

int pop(stack *ps)
{
    return(ps->data[ps->top--]);
}

void push(stack *ps,int n)
{
    ps->data[++ps->top]=n;
}

int stackTop(stack  *ps)
{
    return(ps->data[ps->top]);
}

int priority(char ch)
{
    switch(ch)
    {
        case '(':return 0;
        case '+':
        case '-':
        case '*':return 1;
        case '/':
        case '%':return 2;
        case '^':return 3;
    }
    return 0;
}

void convert(char in[20],char post[20])
{
    int i,j=0;
    char ch,ch1;
    stack s;
    initstack(&s);

    for(i=0;in[i]!='\0';i++)
    {
        ch=in[i];
        switch(ch)
        {
            case '(':push(&s,ch);
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':

            if(isEmpty(&s))
            push(&s,ch);
            else
            {
                while(priority(stackTop(&s))>=priority(ch))
                post[j++]=pop(&s);
                push(&s,ch);
            }
            break;
            case ')':
            while((ch1=pop(&s))!='(')
            post[j++]=ch1;
            break;
            default:post[j++]=ch;
        }
    }

    while(!isEmpty(&s))
    post[j++]=pop(&s);
    post[j]='\0';

}

void main()
{
    char infix[20],postfix[20];
    printf("\n enter the infix expression :");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("\n The postfix expression is %s",postfix);
    getch();
}
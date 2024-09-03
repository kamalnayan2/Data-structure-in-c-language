#include<stdio.h>
#include<stdlib.h>
struct queue 
{
    int r;
    int f;
    int size;
    int arr[5];
};
int isful(struct queue *ptr)
{
    if(ptr->r==ptr->size-1)
    return 1;
    else
    return 0;
}
int isempty(struct  queue *ptr)
{
    if (ptr->f==ptr->r)
    {
        return 1;
    }
    else
    return 0;
    
}

void enque (struct queue *ptr,int val)
{
    if (isful(ptr)==1)
    {
        printf("queue is overflow\n");
    }
    else{
        ptr->r=ptr->r+1;
        ptr->arr[ptr->r]=val;
    }
}
int deque (struct queue *ptr)
{
    if (isempty(ptr)==1)
    {
        return printf("Queue is full\n");
    }
    else{
        ptr->f=ptr->f+1;
        return ptr->arr[ptr->f];
    }
}
void displayarr(struct queue *ptr)
{
    int i;
    for(i=ptr->f;i<ptr->r;i++)
    printf("%d",ptr->arr[i]);
}
void main()
{
    int val,wh;
   struct queue *q;
   q->r=-1;
   q->f=-1;
   printf("enter the no of element:");
   scanf("%d",&q->size);
   
   while(wh!=0)
   {
   printf("\n1.insert element\n2.delete the element\n3.display\n0.exit\n\nenter the choice:");
   scanf("%d",&wh);
   switch(wh)
   {
   case 1:
   printf("enter the element:");
    scanf("%d",&val);
    enque(q,val);
    break;
    case 2:
    printf("delete element is %d",deque(q));
    break;
    case 3:
    displayarr(q);
    break;
    case 0:
    exit(0);
    break;
    }
   getch();

   }
}

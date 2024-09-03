#include<stdio.h>
#include<stdlib.h>
void insertarr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
}
void displayarr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("\n%d",arr[i]);
    printf("\n"); 
}
void insertion(int arr[],int n,int ele,int index,int capicity)
{
    int i;
    if(capicity<index)
    {
        printf("insertion is not possible"); 
    }
    else
    {
    for(i=n-1;i>=index;i--)
    arr[i+1]=arr[i];
    arr[index]=ele;
    printf("the new array is...\n");
    displayarr(arr,n+1);
    }
} 
/// @brief 
void main()
{
    int arr[100],n,ele,index;
    printf("enter the no of element\n");
    scanf("%d",&n);
    printf("enter the element\n");
    insertarr(arr,n);
    displayarr(arr,n);
    printf("enter the position of element to enter: ");
    scanf("%d",&index);
    printf("enter the new element: ");
    scanf("%d",&ele);
    insertion(arr,n,ele,index,100);
    getch();
}